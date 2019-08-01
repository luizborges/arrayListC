#include "memoryManager.h"


void MM_Init() {
	GC_INIT();
}

void *MM_Malloc(const size_t nbytes) {
	return GC_MALLOC(nbytes);
}

void MM_Free(void *ptr) {
	GC_FREE(ptr);
}



