#include "fileUtil.h"
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
  printf("\"%s\"\n", __func__);
  char nin[100] = "/media/borges/data/cloud/Mega/programming/c/lib_common/baseLibC/fileUtil/main.c";
  FILE *fin = fopen(nin, "r");
  printf("BEGIN OF THE FILE\n\"");
  char *line;
  while((line = FileUtil_Get_Line(fin)) != NULL) {
  	printf("%s", line);
  }
  printf("\"\nEND OF FILE\n");
}

void test2() {
  printf("\n===================================\n");
  printf("Func: %s\n", __func__);
  printf("===================================\n");
  char nin[100] = "/media/borges/data/cloud/Mega/programming/c/lib_common/baseLibC/fileUtil/main.c";
  
  char *str = FileUtil_StrMap(nin, "file_name");
  printf("BEGIN OF FILE:\n");
  printf("\"%s\"",str);
  printf("\nEND OF FILE\n");
}

void test3(void) {
  printf("\n===================================\n");
  printf("Func: %s\n", __func__);
  printf("===================================\n");
  
  char nin[100] = "/media/borges/data/cloud/Mega/programming/c/lib_common/baseLibC/fileUtil/main.c";
  FILE *fin = fopen(nin, "r");
  
  char *line;
  while(strcmp(line = FileUtil_Get_Line(fin), "void test3(void) {\n") != 0);
  
  char *str = FileUtil_StrMap(fin, "file");
  printf("REST OF FILE:\n");
  printf("\"%s\"",str);
  printf("\nEND OF FILE\n");
}
//8

