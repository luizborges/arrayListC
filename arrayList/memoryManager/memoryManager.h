/**
 */
#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdlib.h>
#include <gc.h>

void  MM_Init();
void *MM_Malloc(const size_t nbytes);
void  MM_Free(void *ptr);

#ifdef __cplusplus
}
#endif
#endif // MEMORY_MANAGER_H

