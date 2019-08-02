#include "memoryManager.h"

// GC_H is a defense macro of #include <gc.h>

void MM_Init() {
#ifdef GC_H
	GC_INIT();
#endif
}

void *MM_Malloc(const size_t nbytes) {
#ifdef GC_H
	return GC_MALLOC(nbytes);
#else
	return malloc(nbytes);
#endif
}

void MM_Free(void *ptr) {
#ifdef GC_H
	GC_FREE(ptr);
#else
	free(ptr);
#endif
}

void MM_GC() {
#ifdef GC_H
	GC_gcollect(); // Explicitly force a garbage collection. 
#endif
}


