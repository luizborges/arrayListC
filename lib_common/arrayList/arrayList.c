/**
 */

#include "arrayList.h"

Interface_Make_Body6(arrayList_t,
	void*, get, (const void *list, const int pos),
	void*, set, (void *list, const int pos, const void *content),
	void,  add, (void *list, const int pos, const void *content),
	void*, del, (void *list, const int pos),
	int,   len, (const void *list),
	void,  end, (void *list));


