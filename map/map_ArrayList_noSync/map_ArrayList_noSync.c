/**
 */
////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "map_ArrayList_noSync.h"

////////////////////////////////////////////////////////////////////////////////
// Private Functions Head
////////////////////////////////////////////////////////////////////////////////
static void Map_ArrayList_noSync_Check(const Map_ArrayList_noSync_t map, const char *key);
static Map_ArrayList_noSync_cell_t  Map_ArrayList_noSync_Get_Cell_By_Key(const Map_ArrayList_noSync_t map,
                                                                         const char *key, int *arrayIdx);

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////
static void Map_ArrayList_noSync_Check(const Map_ArrayList_noSync_t map, const char *key) {
	if(map == NULL)       { Error("Map_ArrayList_noSync: map is NULL");      }
	if(map->list == NULL) { Error("Map_ArrayList_noSync: map_list is NULL"); }
	if(key == NULL)       { Error("Map_ArrayList_noSync: key is NULL");      }
}

static Map_ArrayList_noSync_cell_t 
Map_ArrayList_noSync_Get_Cell_By_Key(const Map_ArrayList_noSync_t map, 
                                     const char *key, int *arrayIdx) {
	Map_ArrayList_noSync_cell_t cell;
	for(int i = 0; i < ArrayList_noSync_len(map->list); ++i) {
		cell = (Map_ArrayList_noSync_cell_t)ArrayList_noSync_get(map->list, i);
		
		if(strcmp(cell->key, key) == 0) {
			if(arrayIdx != NULL) {
				*arrayIdx = i; // get the index of array
			}
			
			return cell;
		}
	}
	
	if(arrayIdx != NULL) {
		*arrayIdx = -1; // seta o valor para mostrar que não existe correspondência para a chave buscada
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////
// Constructors
////////////////////////////////////////////////////////////////////////////////
Map_ArrayList_noSync_t Map_ArrayList_noSync_New() {
	Map_ArrayList_noSync_t map = (Map_ArrayList_noSync_t)MM_Malloc(sizeof(Map_ArrayList_noSync_o));
	if(map == NULL) {
		Error("map_arrayList_noSync: cannot create map.");
	}
	
	map->list = ArrayList_noSync_New();

	map->lastAccessed = NULL; // inicializa a chave com NULL
	map->lastAccessed_arrayIdx = -5; // inicializa a posição do array
	
	
	return map;
}

/**
 * Instancia uma interface do tipo map_t
 */
map_t Map_ArrayList_noSync_New_Interface() {
	map_t map = (map_t)MM_Malloc(sizeof(map_o));
	if(map == NULL) {
		Error("Allocated Space for Map Interface");
	}
	
	// insere o self
	map->self = (void*)Map_ArrayList_noSync_New();
	
	// insere as funções da interface
	map->Get 	= Map_ArrayList_noSyncget;
	map->Set 	= Map_ArrayList_noSyncset;
	map->Del 	= Map_ArrayList_noSyncdel;
	map->Key 	= Map_ArrayList_noSynckey;
	map->HasKey = Map_ArrayList_noSynchasKey;
	map->End    = Map_ArrayList_noSyncend;
	map->Clean  = Map_ArrayList_noSyncclean;
	
	return map;
}


////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

void *Map_ArrayList_noSyncget (const void *_map, const char *key) {
	Map_ArrayList_noSync_t map = (Map_ArrayList_noSync_t)_map;
	Map_ArrayList_noSync_Check(map, key);
	
	// ótimização da busca, verifica se é a célula requisitada é a última acessada
	if(map->lastAccessed != NULL) {
		if(strcmp(map->lastAccessed->key, key) == 0) {
			return map->lastAccessed->content;
		}
	}
	
	int arrayIdx = -4;
	Map_ArrayList_noSync_cell_t cell = Map_ArrayList_noSync_Get_Cell_By_Key(map, key, &arrayIdx);
	if(cell == NULL) {
		Error("Map_ArrayList_noSync: no key match for self map. key = \"%s\"", key);
	}
	map->lastAccessed = cell; // guarda a última célula acessada
	map->lastAccessed_arrayIdx = arrayIdx; // guarda a posição da última célula acessada
	return cell->content;
}


void *Map_ArrayList_noSyncset (void *_map, const char *key, const void *content) {
	Map_ArrayList_noSync_t map = (Map_ArrayList_noSync_t)_map;
	Map_ArrayList_noSync_Check(map, key);
	Map_ArrayList_noSync_cell_t cell = NULL;
	void *contentOld = NULL;
	int arrayIdx = -2;
	
	// ótimização da busca, verifica se é a célula requisitada é a última acessada
	if(map->lastAccessed != NULL) {
		if(strcmp(map->lastAccessed->key, key) == 0) {
			cell = map->lastAccessed;
		}
	}
	
	if(cell == NULL) { // verifica se a célula já foi encontrada pela otimização
		cell = Map_ArrayList_noSync_Get_Cell_By_Key(map, key, &arrayIdx);
	}
	
	
	if(cell == NULL) { // no exists self key in map - insert self key in map
		cell = MM_Malloc(sizeof(Map_ArrayList_noSync_cell_o));
		if(cell == NULL) {
			Error("Map_ArrayList_noSync: alloc memory for cell.");
		}
		
		cell->key = (char*)MM_Malloc(strlen(key) +1); // aloca espaço para a key do map
		if(cell == NULL) {
			Error("Map_ArrayList_noSync: alloc memory for key.");
		}
		
		strcpy(cell->key, key); // copia a chave para o map
		cell->content = (void*)content; // copia o conteúdo para o map
		
		ArrayList_noSync_add(map->list, 0, cell); // insere a nova célula no map - inserida na posição 0
		arrayIdx = 0;
		
	} else { // key already exists, just insert the content in map
		contentOld = cell->content; // recebe o antigo conteúdo
		cell->content = (void*)content; // atualiza a célula com o novo conteúdo
	}
	
	map->lastAccessed = cell; // guarda a última célula acessada
	map->lastAccessed_arrayIdx = arrayIdx; // guarda a posição da última célula acessada
	
	return contentOld;
}

void *Map_ArrayList_noSyncdel(void *_map, const char *key) {
	Map_ArrayList_noSync_t map = (Map_ArrayList_noSync_t)_map;
	Map_ArrayList_noSync_Check(map, key);
	Map_ArrayList_noSync_cell_t cell = NULL;
	int arrayIdx = -1;
	
	
	// ótimização da busca, verifica se é a célula requisitada é a última acessada
	if(map->lastAccessed != NULL) {
		if(strcmp(map->lastAccessed->key, key) == 0) {
			cell     = map->lastAccessed;
			arrayIdx = map->lastAccessed_arrayIdx;
		}
	}
	
	if(cell == NULL) { // verifica se a célula já foi encontrada pela otimização
		cell = Map_ArrayList_noSync_Get_Cell_By_Key(map, key, &arrayIdx);
	}
	
	if(cell == NULL) { // se não existe a célula a ser deletada
		Error("Map_ArrayList_noSync: no key match for self map. key = \"%s\"", key);
	}
	
	if(arrayIdx == -1) { // verifica se o array é válido
		Error("wrong index to get key on map. - idx = -1.");
	}
	
	ArrayList_noSync_del(map->list, arrayIdx);
	//int mx = ArrayList_noSync_len(map->list);
	//printf("arrayIdx: %d\nmx_bef: %d\n", arrayIdx, mx);
	void *contentOld = cell->content; // recebe o conteúdo antigo
	
#ifndef GC_H // caso o garbage collector não esteja definido
	MM_Free(cell->key);
	MM_Free(cell);
#endif

	map->lastAccessed = NULL; // reinicializa, para evitar bugs
	return contentOld; // retorna o antigo conteúdo
}

char **Map_ArrayList_noSynckey(const void *_map, int *numKeys) {
	Map_ArrayList_noSync_t map = (Map_ArrayList_noSync_t)_map;
	// check args
	if(map == NULL)       { Error("Map_ArrayList_noSync: map is NULL");      }
	if(map->list == NULL) { Error("Map_ArrayList_noSync: map_list is NULL"); }
	if(numKeys == NULL)   { Error("Map_ArrayList_noSync: numKeys is NULL");  }
	
	// discover and keep the keys of map
	*numKeys = ArrayList_noSync_len(map->list);
	if(*numKeys == 0) {
		return NULL; // retorna NULO para mostrar que o map está vazio
	}
	
	char **keys = (char**)MM_Malloc((*numKeys)*sizeof(char*)); // aloca espaço para o arranjo
	if(keys == NULL) {
		Error("Map_ArrayList_noSync: alloc memory for keys.");
	}
	
	for(int i=0; i < *numKeys; ++i) { // copia cada key para o arranjo keys
		Map_ArrayList_noSync_cell_t cell = (Map_ArrayList_noSync_cell_t)ArrayList_noSync_get(map->list, i);
		keys[i] = (char*)MM_Malloc((strlen(cell->key) +1)*sizeof(char)); // aloca espaço para o nome da key
		strcpy(keys[i], cell->key); // copia a célula para o arranjo
	}
	
	return keys;
}

bool Map_ArrayList_noSynchasKey (const void *_map, const char *key) {
	Map_ArrayList_noSync_t map = (Map_ArrayList_noSync_t)_map;
	Map_ArrayList_noSync_Check(map, key);
	
	// ótimização da busca, verifica se é a célula requisitada é a última acessada
	if(map->lastAccessed != NULL) {
		if(strcmp(map->lastAccessed->key, key) == 0) {
			return true;
		}
	}
	
	// se não é a última célula acessada, faz a busca no map inteiro
	int arrayIdx = -3;
	Map_ArrayList_noSync_cell_t cell = Map_ArrayList_noSync_Get_Cell_By_Key(map, key, &arrayIdx);
	if(cell == NULL) {
		return false;
	}
	
	map->lastAccessed = cell; // guarda a última célula acessada
	map->lastAccessed_arrayIdx = arrayIdx; // guarda o id da última célula acessada
	
	return true;
}


void Map_ArrayList_noSyncclean  (void *_map) {
	Map_ArrayList_noSync_t map = (Map_ArrayList_noSync_t)_map;
	// check args
	if(map == NULL)       { Error("Map_ArrayList_noSync: map is NULL");      }
	if(map->list == NULL) { Error("Map_ArrayList_noSync: map_list is NULL"); }
	
	ArrayList_noSync_clean(map->list); // libera toda a memória
	map->lastAccessed = NULL; // seta a chave com NULL
	map->lastAccessed_arrayIdx = -7; // seta posição de inicialização - com código de erro prórpio
	
}


void Map_ArrayList_noSyncend(void *_map) {
#ifdef GC_H
// do nothing - garbage collector does all service alone
#else
	Map_ArrayList_noSync_t map = (Map_ArrayList_noSync_t)_map;
	// check args
	if(map == NULL)       { Error("Map_ArrayList_noSync: map is NULL");      }
	if(map->list == NULL) { Error("Map_ArrayList_noSync: map_list is NULL"); }
	
	ArrayList_noSync_clean(map->list); // libera toda a memória
	map->lastAccessed = NULL; // seta a chave com NULL
	map->lastAccessed_arrayIdx = -6; // inicializa a posição do array
	
	ArrayList_noSync_end(map->list); // seta posição de inicialização - com código de erro prórpio
	MM_Free(map);
#endif
}














