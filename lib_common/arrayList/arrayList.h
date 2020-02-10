/**
 */
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../interface/interface.h"

Interface_Make_Head6(arrayList_t,
	void*, get, (const void *list, const int pos),
	void*, set, (void *list, const int pos, const void *content),
	void,  add, (void *list, const int pos, const void *content),
	void*, del, (void *list, const int pos),
	int,   len, (const void *list),
	void,  end, (void *list));

#ifdef __cplusplus
}
#endif
#endif // ARRAY_LIST_H

