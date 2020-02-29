#include "arrayList_noSync.h"
#include <assert.h>
#include <headers/stackTracer.h>
#include <headers/arrayList.h>


#define _ printf("Get here...: %d\n", __LINE__);


void test1(ArrayList_noSync_t list);
void test2(ArrayList_noSync_t list);
void test3(ArrayList_noSync_t list);
void test4(ArrayList_noSync_t list_);
void test5();

int main(void) {
	StackTracer_Init();
 	ArrayList_noSync_t list = ArrayList_noSync_New();
 	test1(list);
 	test2(NULL);
 	test3(NULL);
 	test4(NULL); // test interface
 	test5();
  return 0;
}

void test1(ArrayList_noSync_t list) {
  printf("Test 1\n");
  if(list == NULL) {
    list = ArrayList_noSync_New();
  }
  //	for(int i = 0; i < 2345; ++i) ArrayList_noSync_set(list, i, (void*)i);
 	_ ArrayList_noSync_set(list, 2344, "fuck");
 	_ ArrayList_noSync_set(list, 2343, (void*)45);
 	_ ArrayList_noSync_set(list, 2327, "1.23");
 	printf("Len: %d\n", ArrayList_noSync_len(list));
// 	for(int i = 0; i < 2345; ++i) printf("[%d]: %d\n", i, (int)ArrayList_noSync_get(list, i));
  printf("Len: %d\n", ArrayList_noSync_len(list));
  _ ArrayList_noSync_end(list);
  printf("list: %p\n", list);
}

void test2(ArrayList_noSync_t list) {
  printf("Test 2\n");
  if(list == NULL) {
  printf("here??? %d\n", __LINE__);
    _ list = ArrayList_noSync_New();
  }
  for(int i = 0; i < 23345; ++i) ArrayList_noSync_set(list, i, (void*)i);
 	_ ArrayList_noSync_add(list, 2344, "fuck");
 	_ ArrayList_noSync_add(list, 2343, (void*)45);
 	_ ArrayList_noSync_add(list, 2327, "1.23");
 	printf("Len: %d\n", ArrayList_noSync_len(list));
 	assert(ArrayList_noSync_len(list) == 23348);
// 	for(int i = 0; i < 2345; ++i) printf("[%d]: %d\n", i, (int)ArrayList_noSync_get(list, i));
  printf("Len: %d\n", ArrayList_noSync_len(list));
  _ ArrayList_noSync_end(list);
  printf("list: %p\n", list);
}

void test3(ArrayList_noSync_t list) {
  printf("\"%s\"\n", __func__);
  if(list == NULL) {
  printf("here??? %d\n", __LINE__);
    _ list = ArrayList_noSync_New();
  }
  
  _ ArrayList_noSync_add(list, 0, "self");
  assert(ArrayList_noSync_len(list) == 1);
  printf("Content: \"%s\"\n", (char*)ArrayList_noSync_get(list, 0));
  _ ArrayList_noSync_del(list, 0);
  _ ArrayList_noSync_end(list);
}

void test4(ArrayList_noSync_t list_) {
	printf("\"%s\"\n", __func__);
	
	arrayList_t list = ArrayList_noSync_New_Interface();
	
	for(int i=0; i < 1000; ++i) {
		list->Add(list->self, i, (void*)i);
	}
	
	for(int i=0; i < 1000; ++i) {
		int v = (int)list->Get(list->self, i);
		printf("list[%d]: %d\n", i, v);
	}
}

void test5() {
	printf("\n******************************\n");
	printf("\"%s\"\n", __func__);
	printf("******************************\n");
	
	arrayList_t list = ArrayList_noSync_New_Interface();
	list->Clean(list->self);
	
	for(int i=0; i < 1000; ++i) {
		list->Add(list->self, i, (void*)i);
	}
	
	printf("Len: %d\n", list->Len(list->self));
	assert(list->Len(list->self) == 1000);
	list->Clean(list->self);
	printf("Len after clean: %d\n", list->Len(list->self));
	assert(list->Len(list->self) == 0);
}









