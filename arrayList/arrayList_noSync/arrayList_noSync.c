/**
 */
////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "arrayList_noSync.h"

////////////////////////////////////////////////////////////////////////////////
// Private Functions Head
////////////////////////////////////////////////////////////////////////////////
static void  ArrayList_noSync_Error(const ArrayList_noSync_t list, const int line);
//static void  ArrayList_noSync_Print(const ArrayList_noSync_t list, const int pos, const char *func, const int line);
static int   ArrayList_noSync_Position_Especial(const ArrayList_noSync_t list, const int pos);
static void  ArrayList_noSync_Check(const ArrayList_noSync_t list, const int pos);
static void  ArrayList_noSync_Position(const ArrayList_noSync_t list, const int pos);
static void  ArrayList_noSync_Create_Last_Cell(ArrayList_noSync_t list, const int pos);
static void *ArrayList_noSync_delete_Cell(ArrayList_noSync_t list, const int pos);


////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////
static void
ArrayList_noSync_Error(const ArrayList_noSync_t list, const int line) {
  if(list == NULL) {
    fprintf(stderr, "ERROR: - Func: \"ArrayList_noSync_New\" - Line: %d\n", line);
  } else {
	  fprintf(stderr, "ERROR - Func: \"%s\" - Line: %d\n", list->func, line);
	}
	abort();
}

/*
static void
ArrayList_noSync_Print(const ArrayList_noSync_t list, const int pos,
				const char *func, const int line) {
	printf("ArrayList Print:: CellPos: %d | Len: %d | Pos: %d | Func: \"%s\"" 
            "| Line: %d | cell: %p | head->next: %p | tail: %p\n",
		list->pos, list->len, pos, func, line, list->cell, 
        list->head->next, list->tail);
} */

static void 
ArrayList_noSync_Check(const ArrayList_noSync_t list, const int pos) {
    // check list integridade
    if(list == NULL) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->len < 0) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->head == NULL) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->head->prev != NULL) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->tail == NULL) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->tail->next != NULL) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__);} 
    if(list->len == 0 && list->head->next != list->tail) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->len == 0 && list->tail->prev != list->head) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->len == 0 && list->pos != -1) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->pos != -1 && list->cell == NULL) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->pos == -1 && list->cell != NULL) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->pos < -1) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
    if(list->pos >= list->len) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }

    // checa posicao integridade
    if(pos < 0) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); }
}

static int
ArrayList_noSync_Position_Especial(const ArrayList_noSync_t list, const int pos) {
  if(list->pos == pos) return 1; // quando a posição requerida é a posição de referência
  
  if(list->len == 0) { // checa se a lista está vazia
    ArrayList_noSync_Error(list, __LINE__);
  }
  
  if(pos == 0) { // check se é a posição inicial do arranjo
    list->cell = list->head->next;
    list->pos  = 0;
    return 1;
  }
  
  if(pos == list->len -1) { // check se é a última célula do arranjo
    list->cell = list->tail->prev;
    list->pos  = pos;
    return 1;
  }
  
  if(pos == list->pos +1) { // se é uma única célula posterior da célula de referência
    list->cell = list->cell->next;
    list->pos  = pos;
    return 1;
  }
  
  if(pos == list->pos -1) { // se é a célula anterior a célula de de referência
    list->cell = list->cell->prev;
    list->pos  = pos;
    return 1;
  }
  
  if(pos == 1) { // se é a posição 1
    list->cell = list->head->next->next;
    list->pos  = pos;
    return 1;
  }
  
  if(pos == list->len -2) { // se é a penúltima célula do arranjo
    list->cell = list->tail->prev->prev;
    list->pos  = pos;
    return 1;
  }
  
  return 0; // não é uma posição especial
}

static void
ArrayList_noSync_Position(const ArrayList_noSync_t list, const int pos) {
  if(ArrayList_noSync_Position_Especial(list, pos) == 1) return;
  
  int is = -1; // is:: 0 = pos | 1 = head | -1 = tail
  int diff = abs(list->len - pos);
  
  if(pos < diff) {// verifica se o mais proximo é o início ou o final da lista
    diff = pos;
    is = 1;
  }

  if(abs(list->pos - pos) < diff) {// verifica se o mais próximo é o item atual ou o fim ou comeco da lista
    diff = pos - list->pos;
    is = 0;
  }

  switch(is) { // seta o item atual para o mais próximo e a posicão dele na lista
    case  0: break;
    case  1: list->cell = list->head->next; list->pos = 0; break;
    case -1: list->cell = list->tail->prev; list->pos = list->len -1; break;
    default: /*ERROR*/ ArrayList_noSync_Error(list, __LINE__);
  }

  // seta ao item escolhido
  if(list->pos <= pos) { // a posicão alvo é maior que a posicão mais próxima
    for(;list->pos < pos && list->pos < list->len-1; list->pos += 1) {
      list->cell = list->cell->next;
    }
  } else { // a posicão alvo é menor que a posicão mais próxima
    for(;list->pos > pos && list->pos > 0; list->pos -= 1) {
      list->cell = list->cell->prev;
    }
  }
}

static void
ArrayList_noSync_Create_Last_Cell(ArrayList_noSync_t list, const int pos) {
  if(pos < list->len && list->len > 0) {return;} // check if is necessary to run the function
  int i;
  
  for(i = list->len -1; i < pos; ++i) {
    list->cell = MM_Malloc(sizeof(ArrayList_noSync_cell_t));
    if(list->cell == NULL) {/*ERROR*/ ArrayList_noSync_Error(list, __LINE__);}
    list->cell->content = NULL; // seta o contéudo da nova célula
    list->cell->prev    = list->tail->prev; // seta a célula anterior a nova célula
    list->cell->next    = list->tail; // seta a célula posterior a nova célula 
    
    list->tail->prev->next = list->cell; // insere a nova célula como sendo posterior à antiga célula anterior a célula tail
    list->tail->prev       = list->cell; // insere a nova célula como sendo a célula anterior a célula tail
  }
  
  list->len = pos +1; // atualiza o novo tamanho da lista
  list->pos = pos; // atualiza a nova posição da célula de referência
}


static void*
ArrayList_noSync_delete_Cell(ArrayList_noSync_t list, const int pos) {
  if(pos >= list->len) {return NULL;} // check if is necessary to run the function
  
  ArrayList_noSync_Position(list, pos); // pega a célula na posição que será removida
  ArrayList_noSync_cell_t *cellDel = list->cell; // seta a célula que será removida
  cellDel->prev->next = cellDel->next; // config a célula anterior a célula que será removida
  cellDel->next->prev = cellDel->prev; // config a célula posterior a célula que será removida
  
  if(list->len == 1) { // quando a lista somente tem 1 elemento | lista vazia
    list->cell = NULL;
    list->pos  = -1;
  } else if(pos == list->len -1) { // quando a célula removida for a última | lista NÃO vazia
    list->cell = list->tail->prev; // a célula de referência se torna a última célula da lista
    list->pos  = pos -1;
  } else { // quando a célula removida não for a última  | lista NÃO vazia
    list->cell = cellDel->next; // a célula de referência se torna a célula posterior a célula removida
  }
  
  list->len -= 1; // atualiza o tamanho da lista
  void *contentDel = cellDel->content; // guarda o conteúdo da célula quer será deletada
  MM_Free(cellDel); // remove a célula que será deletada
  return contentDel;
}



////////////////////////////////////////////////////////////////////////////////
// Construct Functions
////////////////////////////////////////////////////////////////////////////////

ArrayList_noSync_t ArrayList_noSync_New() {
  ArrayList_noSync_t list = MM_Malloc(sizeof(ArrayList_noSync_o));
  if(list == NULL) {ArrayList_noSync_Error(NULL, __LINE__);}
  
  //////////////////////////////////////////////////////////////////////////////
  // cria a célula cabeça
  //////////////////////////////////////////////////////////////////////////////
  ArrayList_noSync_cell_t *cell = MM_Malloc(sizeof(ArrayList_noSync_cell_t));
  if(cell == NULL) {ArrayList_noSync_Error(NULL, __LINE__);}
  
  cell->content = NULL;
  cell->next = NULL;
  cell->prev = NULL;
  
  list->head = cell; // insere a célula cabeca
  
  //////////////////////////////////////////////////////////////////////////////
  // cria a célula final - tail cell
  //////////////////////////////////////////////////////////////////////////////
  cell = MM_Malloc(sizeof(ArrayList_noSync_cell_t));
  if(cell == NULL) {ArrayList_noSync_Error(NULL, __LINE__);}
  
  cell->content = NULL;
  cell->next = NULL;
  cell->prev = list->head; // faz com que a célula prévia da final aponte para a cabeça
  list->head->next = cell; // faz com que a célula cabeça aponte para a célula tail como sendo a próxima 
  list->tail = cell; // seta a célula tail
  
  //////////////////////////////////////////////////////////////////////////////
  // configurações gerais da lista
  //////////////////////////////////////////////////////////////////////////////
  list->len  = 0; // estabelece o tamanho da lista como zero
  list->cell = NULL;
  list->pos  = -1; // estabelece que a célula de referência não está definida
  strcpy(list->func, "ArrayList_noSync_New"); // grava a função entrada pela lista

  return list;
}

/**
 * Cria um tipo para a interface arrayList.
 */
arrayList_t  ArrayList_noSync_New_Interface() {
	arrayList_t arrayList = MM_Malloc(sizeof(arrayList_o));
	if(arrayList == NULL) {
		Error("Allocation Space for Interface.");
	}
	
	// insere os objetos dentro da interface
	ArrayList_noSync_t arrayList_noSync = ArrayList_noSync_New();
	if(arrayList_noSync == NULL) {
		Error("Create interface self: arrayList_noSync object");
	}
	arrayList->self = arrayList_noSync;
	
	// insere as funções
	arrayList->Get   = ArrayList_noSync_get;
	arrayList->Set   = ArrayList_noSync_set;
	arrayList->Add   = ArrayList_noSync_add;
	arrayList->Del   = ArrayList_noSync_del;
	arrayList->Len   = ArrayList_noSync_len;
	arrayList->End   = ArrayList_noSync_end;
	arrayList->Clean = ArrayList_noSync_clean;
	
	return arrayList;
}

////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////
/**
 * Retorna o item do tipo
 */
void *ArrayList_noSync_get(const void *_list, const int pos) {
  const ArrayList_noSync_t list = (const ArrayList_noSync_t)_list;
  strcpy(list->func, "ArrayList_noSync_get"); // grava a função pública que chamou, para o caso de erro
  ArrayList_noSync_Check(list, pos);
  if(pos >= list->len) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); } // integridade do Get
  
  ArrayList_noSync_Position(list, pos);
  return list->cell->content;
}


void *ArrayList_noSync_set(void *_list,
                    const int pos,
                    const void *content) {
  ArrayList_noSync_t list = (ArrayList_noSync_t)_list;
  strcpy(list->func, "ArrayList_noSync_set"); // grava a função pública que chamou, para o caso de erro
  void *lastContent = NULL;
  ArrayList_noSync_Check(list, pos);
  
  if(pos < list->len) { // verifica se é necessário criar novas células
    ArrayList_noSync_Position(list, pos); // faz a célula referência estar na posição demandada
    lastContent = list->cell->content; // guarda o contéudo que será retornado
  } else { // cria novas células
    ArrayList_noSync_Create_Last_Cell(list, pos);
  }
  
  list->cell->content = (void*)content; // atualiza o conteúdo da nova célula
  return lastContent;
}

void *ArrayList_noSync_add(void *_list,
                   		   const int pos,
		                   const void *content) {
  ArrayList_noSync_t list = (ArrayList_noSync_t)_list;
  strcpy(list->func, "ArrayList_noSync_add"); // grava a função pública que chamou, para o caso de erro
  ArrayList_noSync_Check(list, pos);

  if(pos < list->len) { // insere nova célula em posição já existente
    ArrayList_noSync_Position(list, pos); // encontra a posição mais próxima
    ArrayList_noSync_cell_t *buff = MM_Malloc(sizeof(ArrayList_noSync_cell_t)); // cria nova célula
    if(buff == NULL) {ArrayList_noSync_Error(list, __LINE__);}
    // configura a nova célula
    buff->next = list->cell; // seta o próximo item da nova célula
    buff->prev = list->cell->prev; // seta o item anterior da nova célula
    // insere a nova célula na lista
    list->cell = list->cell->prev; // posiciona a célula de referência para a célula anterior da célula criada
    list->cell->next = buff; // seta para a nova célula a célula anterior na lista
    buff->next->prev = buff; // seta para a nova célula a célula posterior na lista
    
    list->cell = buff; // atualiza a célula de referência
    list->pos  = pos;  // atualiza a posição da célula de referência
    list->len  += 1;   // atualiza o tamanho da lista
  } else { // quando a posição a ser criada é maior que o id da última célula da lista
    ArrayList_noSync_Create_Last_Cell(list, pos);
  }
  
  list->cell->content = (void*)content; // atualiza o conteúdo da célula
  
  return list->cell->content;
}


void *ArrayList_noSync_del(void *_list, const int pos) {
   ArrayList_noSync_t list = (ArrayList_noSync_t)_list;
   strcpy(list->func, "ArrayList_noSync_del"); // grava a função pública que chamou, para o caso de erro
   ArrayList_noSync_Check(list, pos);
   if(list->len == 0) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); } // se a lista está vazia
   if(pos >= list->len) {/* ERROR MSG*/ ArrayList_noSync_Error(list, __LINE__); } // se a posição a ser deletada existe
   
   void *content = NULL; // célula que receberá o conteúdo de retorno da célula a ser deletada
   content = ArrayList_noSync_delete_Cell(list, pos); // remove a célula da lista
   
   if(list->len == 0) { // trata o caso da lista ter ficado vazia
     list->cell = NULL;
     list->pos  = -1;
   }
   
   return content;
}

int ArrayList_noSync_len(const void *_list) {
	const ArrayList_noSync_t list = (const ArrayList_noSync_t)_list;
	strcpy(list->func, "ArrayList_noSync_len"); // grava a função pública que chamou, para o caso de erro
	ArrayList_noSync_Check(list, 0);
	return list->len;
}

void ArrayList_noSync_end(void *_list) {
  ArrayList_noSync_t list = (ArrayList_noSync_t)_list;
  strcpy(list->func, "ArrayList_noSync_end"); // grava a função pública que chamou, para o caso de erro
  ArrayList_noSync_Check(list, 0);
  if(list->len > 0) { // check se a lista está vazia
    ArrayList_noSync_Position(list, 0); // seta a célula de referência para a primeira célula da lista
    for(int i = 0; i < list->len; ++i) {
      ArrayList_noSync_delete_Cell(list, 0); // exclui sempre a primeira célula da lista
    }
  }
  MM_Free(list->head); // remove a célula cabeça
  MM_Free(list->tail); // remove a célula final/tail
  MM_Free(list); // remove a lista
}

void  ArrayList_noSync_clean (void *_list) {
  ArrayList_noSync_t list = (ArrayList_noSync_t)_list;
  strcpy(list->func, "ArrayList_noSync_clean"); // grava a função pública que chamou, para o caso de erro
  ArrayList_noSync_Check(list, 0);
  if(list->len > 0) { // check se a lista está vazia
    ArrayList_noSync_Position(list, 0); // seta a célula de referência para a primeira célula da lista
    int len = list->len;
    for(int i = 0; i < len; ++i) {
      ArrayList_noSync_delete_Cell(list, 0); // exclui sempre a primeira célula da lista
    }
  }
}




















