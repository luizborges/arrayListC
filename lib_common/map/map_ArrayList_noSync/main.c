#include "map_ArrayList_noSync.h"
#include <assert.h>
#include <headers/stackTracer.h>


#define _ printf("Get here...: %d\n", __LINE__);

/*
void test1(map_t map);
void test2(map_t map);
void test3(map_t map); */

int main(void) {
	StackTracer_Init();
 	ArrayList_noSync_t list = ArrayList_noSync_New();
/* 	test1(list);
 	test2(NULL);
 	test3(NULL); */
  return 0;
}












