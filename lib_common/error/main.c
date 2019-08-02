#include "error.h"
#include <assert.h>



#define _ printf("Get here...: %d\n", __LINE__);


void test1();
void test2();
void test3();

int main(void) {
 	test1();
 	test2();
 	test3();
  return 0;
}

void test1() {
  printf("\"%s\"\n", __func__);
  Error("%s %s %s %d", "Jesus", "is", "God", 3);
}

void test2() {
  Error("Test Error without arguments");
}

void test3(void) {
  printf("\"%s\"\n", __func__);
  
}













