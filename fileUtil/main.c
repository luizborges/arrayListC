#include "fileUtil.h"
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
  char nin[100] = "/media/borges/data/cloud/Mega/programming/c/lib_common/baseLibC/fileUtil/main.c";
  FILE *fin = fopen(nin, "r");
  printf("BEGIN OF THE FILE");
  char *line;	
  do {
  	line = FileUtil_Get_Line(fin);
  	printf("%s", line);
  } while(line != NULL);
  
  printf("END OF FILE");
}

void test2() {
  Error("Test Error without arguments");
}

void test3(void) {
  printf("\"%s\"\n", __func__);
  
}













