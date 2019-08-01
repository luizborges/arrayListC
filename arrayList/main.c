#include "arrayList_noSync.h"
#include <assert.h>



#define _ printf("Get here...: %d\n", __LINE__);


void test1(arrayList_noSync_t list);
void test2(arrayList_noSync_t list);
void test3(arrayList_noSync_t list);

int main(void) {
 	arrayList_noSync_t list = ArrayList_noSync_New();
 	test1(list);
 	test2(NULL);
 	test3(NULL);
  return 0;
}

void test1(arrayList_noSync_t list) {
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

void test2(arrayList_noSync_t list) {
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

void test3(arrayList_noSync_t list) {
  printf("\"%s\"\n", __func__);
  if(list == NULL) {
  printf("here??? %d\n", __LINE__);
    _ list = ArrayList_noSync_New();
  }
  
  _ ArrayList_noSync_add(list, 0, "this");
  assert(ArrayList_noSync_len(list) == 1);
  printf("Content: \"%s\"\n", (char*)ArrayList_noSync_get(list, 0));
  _ ArrayList_noSync_del(list, 0);
  _ ArrayList_noSync_end(list);
}













