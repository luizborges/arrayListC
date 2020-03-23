#include "strUtil.h"
#include <assert.h>
#include <headers/memoryManager.h>
#include <headers/error.h>
#include <headers/stackTracer.h>



#define _ printf("Get here...: %d\n", __LINE__);


void test1();
void test2();
void test3();

int main(void) {
	MM_Init();
	StackTracer_Init();
 	test1();
 	test2();
 	test3();
  return 0;
}

void test1() {
	 printf("\n===================================\n");
	printf("Func: %s\n", __func__);
	printf("===================================\n");
}

void test2() {
  printf("\n===================================\n");
  printf("Func: %s\n", __func__);
  printf("===================================\n");
  
}

void test3(void) {
  printf("\n===================================\n");
  printf("Func: %s\n", __func__);
  printf("===================================\n");
  
}
//8

