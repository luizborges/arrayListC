/**
 */
////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "arrayList.h"

////////////////////////////////////////////////////////////////////////////////
// Private Functions Head
////////////////////////////////////////////////////////////////////////////////
static void  ArrayList_Error(const char *func, const int line);
static void  ArrayList_Print(const arrayList_t list, const int pos, const char *func, const int line);
static int   ArrayList_Position_Especial(const arrayList_t list, const int pos);
static void  ArrayList_Check(const arrayList_t list, const int pos, const char *func);
static void  ArrayList_Position(const arrayList_t list, const int pos);
static void  ArrayList_Create_First_Cell(arrayList_t list, const char *func);
static void  ArrayList_Create_Cell(arrayList_t list, const int pos, const char *func);
static void *ArrayList_Delete_Cell(arrayList_t list, const int pos);


////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////
static void
ArrayList_Error(const char *func, const int line) {
	printf("ERROR - Func: \"%s\" - Line: %d\n", func, line);
	abort();
}

static void
ArrayList_Print(const arrayList_t list, const int pos,
				const char *func, const int line) {
	printf("ArrayList Print:: CellPos: %d | Len: %d | Pos: %d | Func: \"%s\"" 
            "| Line: %d | cell: %p | head->next: %p | tail: %p\n",
		list->pos, list->len, pos, func, line, list->cell, 
        list->head->next, list->tail);
}


static void 
ArrayList_Check(const arrayList_t list, const int pos, const char *func) {
    // check list integridade
    if(list == NULL) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }
    if(list->len < 0) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }
    if(list->head == NULL) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }
    if(list->tail == NULL) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }
    if(list->len == 0 && list->head != list->tail) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }
    if(list->pos != -1 && list->cell == NULL) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }
    if(list->pos == -1 && list->cell != NULL) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }
    if(list->pos < -1) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }
    if(list->pos >= list->len) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }

    // checa posicao integridade
    if(pos < 0) {/* ERROR MSG*/ ArrayList_Error(func, __LINE__); }
}

static int
ArrayList_Position_Especial(const arrayList_t list, const int pos) {
  if(list->len == 0)   return 1; // checa se a lista está vazia
  if(list->len == 1)   return 1; // checa se a lista tem somente 1 elemento
  if(list->pos == pos) return 1; // quando a posição requerida é a posição de referência
  
  
  if(pos == 0) { // check se é a posição inicial do arranjo
    list->cell = list->head->next;
    list->pos  = 0;
    return 1;
  }
  
  if(pos == list->len -1) { // check se é a última célula do arranjo
    list->cell = list->tail;
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
    list->cell = list->tail->prev;
    list->pos  = pos;
    return 1;
  }
  
  return 0; // não é uma posição especial
}

static void
ArrayList_Position(const arrayList_t list, const int pos) {
  if(ArrayList_Position_Especial(list, pos) == 1) return;
  
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
    case -1: list->cell = list->tail; list->pos = list->len -1; break;
    default: /*ERROR*/ abort();
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
ArrayList_Create_First_Cell(arrayList_t list, const char *func) {
	if(list->len > 0) return; // check if cell is empty
	
	list->cell = malloc(sizeof(arrayList_cell_t));
	if(list->cell == NULL) ArrayList_Error(func, __LINE__);
	
	list->cell->content = NULL; // seta como NULL o conteúdo da célula criada
	
	list->head->next = list->cell; // seta a primeira célula como sendo a próxima da cabeça
	list->cell->next = NULL; // seta como null o fim da lista
	list->cell->prev = list->head; // seta o ponteiro anterior para a célula cabeça
	list->tail       = list->cell; // seta a lista final
	list->pos				 = 0;
	list->len			   = 1;
}

static void
ArrayList_Create_Cell(arrayList_t list, const int pos, const char *func) {
  if(pos < list->len) {return;} // check if is necessary to run the function
  
  arrayList_cell_t *buff; // buffer temporário
  for(; list->pos < pos; list->pos += 1) { // cria as novas células da lista
    list->cell->next = malloc(sizeof(arrayList_cell_t));
    if(list->cell->next == NULL) {/*ERROR*/ ArrayList_Error(func, __LINE__);}
    buff = list->cell;
    list->cell = list->cell->next; // atualiza a célula de referência
    list->cell->prev = buff; // seta a célula prévia
    list->cell->next = NULL; // seta a célula posterior
    list->cell->content = NULL; // seta como NULL o conteúdo da célula criada
  }

	list->tail = list->cell;
  list->len = pos +1; // atualiza o numero de celulas da lista
}


static void*
ArrayList_Delete_Cell(arrayList_t list, const int pos) {
  if(pos >= list->len) {return NULL;} // check if is necessary to run the function
  ArrayList_Position(list, pos); // pega a célula na posição que será removida
  
  arrayList_cell_t *cellDel = list->cell; // seta a célula que será removida
  list->cell->prev = list->cell->next; // config a célula anterior a célula que será removida
  if(list->cell->next != NULL) { // trata a lista quando a célula a ser removida não é a última
    list->cell->next->prev = list->cell->prev; // config a célula posterior a célula que será removida
    list->cell = list->cell->next; // config a nova célula de referência
  } else { // trata a lista quando a célula a ser removida é a última célula da lista
    list->tail = list->cell->prev; // config o ponteiro para a última célula da lista
    list->cell = list->tail; // config a nova célula de referência
    list->pos -= 1; // config o novo id da célula de referência
  }
  
  list->len -= 1; // config o novo tamanho da lista
  void *contentDel = cellDel->content; // guarda o conteúdo da célula quer será deletada
  free(cellDel); // remove a célula que será deletada
  return contentDel;
}



////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

arrayList_t ArrayList_New() {
  arrayList_t list = malloc(sizeof(arrayList_to));
  if(list == NULL) ArrayList_Error(__func__, __LINE__);
  
  // cria a célula cabeça
  arrayList_cell_t *cell = malloc(sizeof(arrayList_cell_t));
  if(cell == NULL) {ArrayList_Error(__func__, __LINE__);}
  
  cell->content = NULL;
  cell->prev = NULL;
  cell->next = NULL;

  // insere a célula cabeca
  list->head = cell;
  list->tail = cell;
  list->len  = 0;
  list->cell = NULL;
  list->pos  = -1;

  return list;
}

////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////
/**
 * Retorna o item do tipo
 */
void *ArrayList_Get(const arrayList_t list, const int pos) {
  ArrayList_Check(list, pos, __func__);
  if(pos >= list->len) {/* ERROR MSG*/ ArrayList_Error(__func__, __LINE__); } // integridade do Get
  
  ArrayList_Position(list, pos);
  return list->cell->content;
}


void *ArrayList_Set(arrayList_t list,
                    const int pos,
                    const void *content) {
  void *lastContent = NULL;
  ArrayList_Check(list, pos, __func__);
  
  if(list->len == 0) { // cria a primeira célula - lista vazia
    ArrayList_Create_First_Cell(list, __func__);
  } else { // quando a lista não está vazia
    ArrayList_Position(list, pos);
  }

  if(pos < list->len) { // verifica se é necessário criar novas células
    lastContent = list->cell->content; // guarda o contéudo que será retornado
  } else { // cria novas células
    ArrayList_Create_Cell(list, pos, __func__);
  }
  
  list->cell->content = (void*)content; // atualiza o conteúdo da nova célula
  return lastContent;
}

void ArrayList_Add(arrayList_t list,
                   const int pos,
                   const void *content) {
  ArrayList_Check(list, pos, __func__);
  
  if(list->len == 0) { // cria a primeira célula - lista vazia
    ArrayList_Create_First_Cell(list, __func__);
    list->cell->content = (void*)content; // seta o conteúdo na primeira célula
    return;
  }
  //////////////////////////////////////////////////////////////////////////////
  // quando a lista não está vazia
  //////////////////////////////////////////////////////////////////////////////
  ArrayList_Position(list, pos); // encontra a posição mais próxima

  if(pos < list->len) { // insere nova célula na posição
    arrayList_cell_t *buff = malloc(sizeof(arrayList_cell_t)); // cria nova célula
    if(list->cell == NULL) {ArrayList_Error(__func__, __LINE__);}
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
    ArrayList_Create_Cell(list, pos, __func__);
  }
  
  list->cell->content = (void*)content; // atualiza o conteúdo da célula
}


void *ArrayList_Del(const arrayList_t list, const int pos) {
   ArrayList_Check(list, pos, __func__);
   if(list->len == 0) {/* ERROR MSG*/ ArrayList_Error(__func__, __LINE__); } // se a lista está vazia
   if(pos >= list->len) {/* ERROR MSG*/ ArrayList_Error(__func__, __LINE__); } // se a posição a ser deletada existe
   
   void *content = NULL; // célula que receberá o conteúdo de retorno da célula a ser deletada
   content = ArrayList_Delete_Cell(list, pos); // remove a célula da lista
   
   if(list->len == 0) { // trata o caso da lista ter ficado vazia
     list->cell = NULL;
     list->pos  = -1;
   }
   
   return content;
}

int ArrayList_Len(const arrayList_t list) {
	ArrayList_Check(list, 0, __func__);
	return list->len;
}

void ArrayList_End_(arrayList_t list) {
  ArrayList_Check(list, 0, __func__);
  ArrayList_Position(list, 0); // seta a célula de referência para a primeira célula da lista
  for(int i = 0; i < list->len; ++i) {
    ArrayList_Delete_Cell(list, 0); // exclui sempre a primeira célula da lista
  }
  
  free(list->head); // remove a célula cabeça
  free(list); // remove a lista
}






















