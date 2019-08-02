/**
 * @file: main.c
 * @author: Luiz Borges Jr.
 * @description: test and example file
 */

#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <signal.h>
#include "interface.h"

///////////////////////////////////////////////////////////////
////// interface user .h
///////////////////////////////////////////////////////////////
//Interface_Make1(foo_t, void, func, (int i, int f, int c))
Interface_Make2(foo_t,
                void, func, (int i, int f, int c),
                int,  foo, (int i))

Interface_Make21(bar_t,
                 void, funcTest1, (int i),
                 void, funcTest2, (int i),
                 void, funcTest3, (int i),
                 void, funcTest4, (int i),
                 void, funcTest5, (int i),
                 void, funcTest6, (int i),
                 void, funcTest7, (int i),
                 void, funcTest8, (int i),
                 void, funcTest9, (int i),
                 void, funcTest10, (int i),
                 void, funcTest11, (int i),
                 void, funcTest12, (int i),
                 void, funcTest13, (int i),
                 void, funcTest14, (int i),
                 void, funcTest15, (int i),
                 void, funcTest16, (int i),
                 void, funcTest17, (int i),
                 void, funcTest18, (int i),
                 void, funcTest19, (int i),
                 void, funcTest20, (int i),
                 void, funcTest21, (int i))

//#include "interface.c"
///////////////////////////////////////////////////////////////
////// interface user .c
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
////// class user .h
///////////////////////////////////////////////////////////////

//Interface_New_Header(foo_t, func, int*);

void  class_func(int i, int f, int c);
int  class_foo(int i);

///////////////////////////////////////////////////////////////
////// class user .c
///////////////////////////////////////////////////////////////
void class_func(int i, int f, int c) {
	printf("func: %d\n", i+f+c);
}

int class_foo(int i) {
	printf("foo: %d\n", i);
	return i;
}

void funcTest1Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest2Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest3Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest4Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest5Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest6Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest7Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest8Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest9Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest10Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest11Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest12Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest13Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest14Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest15Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest16Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest17Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest18Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest19Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest20Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
void funcTest21Impl(int i) { printf("I am function: %s - param: %d\n", __func__, i); }
///////////////////////////////////////////////////////////////
////// outside 
///////////////////////////////////////////////////////////////
void Trace(int sig);
int main() {
	signal(SIGSEGV, Trace);
	void *i = (void*)main;
	foo_t foo = (foo_t)Interface_New(InterfaceConfig_foo_t, "class_", (void*)i);
//	printf("main::\nrfunc: %p\nafunc: %p\nfaddr: %p\n", main, foo->classImpl, NULL);
	foo->func(100,200,360);
	foo->foo(777);
	
	bar_t bar = Interface_New_Posfix(Interface_Config(bar_t), "Impl", (void*)foo);
	bar->funcTest1(444);
	bar->funcTest2(444);
	bar->funcTest3(444);
	bar->funcTest4(444);
	bar->funcTest5(444);
	bar->funcTest6(444);
	bar->funcTest7(444);
	bar->funcTest8(444);
	bar->funcTest9(444);
	bar->funcTest10(444);
	bar->funcTest11(444);
	bar->funcTest12(444);
	bar->funcTest13(444);
	bar->funcTest14(444);
	bar->funcTest15(444);
	bar->funcTest16(444);
	bar->funcTest17(444);
	bar->funcTest18(444);
	bar->funcTest19(444);
	bar->funcTest20(444);
	bar->funcTest21(444);
//	printf("int: %d\npointer: %d\nfunc-void: %d\nfunc-int: %d\nfunc-double: %d\nfunc-pointer: %d\n", sizeof(int), sizeof(void*), sizeof(void (*)(int, double)), sizeof(int (*)()), sizeof(double (*)()), sizeof(void*(*)()));
//		printf("func name: \"%s\" - numFunc: %d - sizeof: %d\naddr.i: %p\naddr.f: %p\n", InterfaceConfig_foo_t.func[0], InterfaceConfig_foo_t.numFunc, InterfaceConfig_foo_t._sizeof, InterfaceConfig_foo_t.addr[0], InterfaceConfig_foo_t.addr[1]);
//		printf("func name: \"%s\" - numFunc: %d - sizeof: %d\n", InterfaceConfigInit_foo_t[0], InterfaceConfig_foo_t.numFunc, InterfaceConfig_foo_t._sizeof);
//	printf("func name: \"%s\" - numFunc: %d - sizeof: %d\n", InterfaceConfigInit_foo_t[0], InterfaceConfigInitLen_foo_t, InterfaceConfigInitSize_foo_t);
	return 0;
}

void Trace(int sig) {
	void *array[10];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, 10);
  strings = backtrace_symbols (array, size);

  printf ("Obtained %zd stack frames.\n", size);

  for (i = 0; i < size; i++)
     printf ("%s\n", strings[i]);

  free (strings);
  _Exit(1);
}




















