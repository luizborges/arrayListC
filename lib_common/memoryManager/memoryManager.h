/**
 */
#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdlib.h>
#include <gc.h>

extern void  MM_Init();
extern void *MM_Malloc(const size_t nbytes);
extern void  MM_Free(void *ptr);
extern void  MM_GC(); // Explicitly force a garbage collection. 

#ifdef __cplusplus
}
#endif
#endif // MEMORY_MANAGER_H

