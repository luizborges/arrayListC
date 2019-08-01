/**
 */
#ifndef ARRAY_LIST_NOSYNC_H
#define ARRAY_LIST_NOSYNC_H

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "memoryManager/memoryManager.h"
#include "error/error.h"

////////////////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Structs
////////////////////////////////////////////////////////////////////////////////
typedef struct arrayList_noSync_cell_t_{
  void *content;
  struct arrayList_noSync_cell_t_ *next;
  struct arrayList_noSync_cell_t_ *prev;
} arrayList_noSync_cell_t;

typedef struct {
  arrayList_noSync_cell_t *head;
  arrayList_noSync_cell_t *tail;
  int len;

  //============
  arrayList_noSync_cell_t *cell;
  int pos;
  
  //============
  char func[15];
} arrayList_noSync_o;

////////////////////////////////////////////////////////////////////////////////
// Typedefs
////////////////////////////////////////////////////////////////////////////////
typedef arrayList_noSync_o* arrayList_noSync_t;

////////////////////////////////////////////////////////////////////////////////
// Constructs
////////////////////////////////////////////////////////////////////////////////
arrayList_noSync_t ArrayList_noSync_New();


////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////
void *ArrayList_noSync_get(const void *_list, const int pos);
void *ArrayList_noSync_set(void *_list, const int pos, const void *content);
void  ArrayList_noSync_add(void *_list, const int pos, const void *content);
void *ArrayList_noSync_del(void *_list, const int pos);
int   ArrayList_noSync_len(const void *_list);
void  ArrayList_noSync_end(void *_list);

#ifdef __cplusplus
}
#endif
#endif // ARRAY_LIST_NOSYNC_H

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////





