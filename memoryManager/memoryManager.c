#include "memoryManager.h"

// GC_H is a defense macro of #include <gc.h>

void MM_Init() {
#ifdef GC_H
	//GC_INIT();
#endif
}

void *MM_Malloc(const size_t nbytes) {
#ifdef GC_H
	//return GC_MALLOC(nbytes);
	return malloc(nbytes);
#else
	return malloc(nbytes);
#endif
}

void *MM_Realloc(void *old, const size_t new_size) {
#ifdef GC_H
	//return GC_REALLOC(old, new_size);
	return realloc(old, new_size);
#else
	return realloc(old, new_size);
#endif
}

void MM_Free(void *ptr) {
#ifdef GC_H
	// GC_FREE(ptr); // DO NOTHING // quando é o gc que está sendo usado, o free não faz nada, usar o GC_FREE, se quiser forçar o deslocamento
#else
	free(ptr);
#endif
}

void MM_GC() {
#ifdef GC_H
	GC_gcollect(); // Explicitly force a garbage collection. 
#endif
}


