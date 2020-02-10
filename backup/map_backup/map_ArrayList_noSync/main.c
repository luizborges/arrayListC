#include "map_ArrayList_noSync.h"
#include <assert.h>
#include <headers/stackTracer.h>


//#define _ printf("Get here...: %d\n", __LINE__);


void test1(Map_ArrayList_noSync_t _map);
void test2(Map_ArrayList_noSync_t _map);
//extern void test3(Map_ArrayList_noSync_t _map);

int main(void) {
	MM_Init();
	StackTracer_Init();
 	Map_ArrayList_noSync_t map = Map_ArrayList_noSync_New();
 	test1(NULL);
 	test2(NULL);
// 	test3(NULL);
  return 0;
}

void test1(Map_ArrayList_noSync_t _map) {
	Map_ArrayList_noSync_t map = Map_ArrayList_noSync_New();
	char num[100];
	int w;
	Map_ArrayList_noSynckey(map, &w);
	printf("map size: %d\nlis size: %d\n", w, ArrayList_noSync_len(map->list));
	
	/*
	for(int i=0; i < 1000000; ++i) {
		sprintf(num, "%d", i);
		Map_ArrayList_noSyncset(map, "i", num);
	} */
	
	printf("******************************\n");
	printf("**** %s\n", __func__);
	printf("******************************\n");
	
//	printf("value: \"%s\"\n", (char*)Map_ArrayList_noSyncget(map, "i"));
	
	int max = 3;
	for(int i=0; i < max; ++i) {
		sprintf(num, "%d", i);
		printf("i: %d of %d\n", i, max);
		Map_ArrayList_noSyncset(map, num, num);
	}
	Map_ArrayList_noSynckey(map, &w);
	printf("map size: %d\nlis size: %d\n", w, ArrayList_noSync_len(map->list));
	
	printf("\n\nGet\n");
	for(int i=0; i < max; ++i) {
		sprintf(num, "%d", i);
		printf("i: %d of %d\n", i, max);
		char *cont = (char*)Map_ArrayList_noSyncget(map, num);
		printf("\tContent[%d]: %s\n", i, cont);
	}
	Map_ArrayList_noSynckey(map, &w);
	printf("map size: %d\nlis size: %d\n", w, ArrayList_noSync_len(map->list));
	
	printf("\n\nDel\n");
	for(int i=0; i < max; i += 2) {
		sprintf(num, "%d", i);
		printf("i: %d of %d\n", i, max);
		char *cont = (char*)Map_ArrayList_noSyncdel(map, num);
		printf("\tContent[%d]: %s\n", i, cont);
	}
	
	Map_ArrayList_noSynckey(map, &w);
	printf("map size: %d\nlis size: %d\n", w, ArrayList_noSync_len(map->list));
	
	printf("\n\nGet\n");
	int numKeys;
	char **keys = Map_ArrayList_noSynckey(map, &numKeys);
	for(int i=0; i < numKeys; ++i) {
		sprintf(num, "%d", i);
		printf("i: %d of %d\n", i, numKeys);
		char *cont = (char*)Map_ArrayList_noSyncget(map, keys[i]);
		printf("\tContent[%d]: %s\n", i, cont);
	}
}

void test2(Map_ArrayList_noSync_t _map) {
	printf("******************************\n");
	printf("**** %s\n", __func__);
	printf("******************************\n");
	
	Map_ArrayList_noSync_t map = Map_ArrayList_noSync_New();
	char str[100];
	int max = 10;
	for(int i=0; i < max; ++i) {
		printf("%d of %d\n", i , max);
		sprintf(str, "%d", i);
		Map_ArrayList_noSyncset(map, str, (void*)i);
	}
	
	int numKeys;
	char **key = Map_ArrayList_noSynckey(map, &numKeys);
	assert(*numKeys == max);
	
	printf("\n\ncheck keys\n");
	for(int i=0; i < max; ++i) {
		printf("%d of %d\n", i , max);
		sprintf(str, "%d", i);
		int r = (int)Map_ArrayList_noSyncget(map, str);
		assert(r == i);
		assert(strcmp(key[i], str) == 0);
	}
	
	printf("\n\nDelete\n");
	for(int i=0; i < max; ++i) {
		printf("%d of %d\n", i , max);
		sprintf(str, "%d", i);
		int r = (int)Map_ArrayList_noSyncdel(map, str);
		key = Map_ArrayList_noSynckey(map, &numKeys);
		assert(r == i);
		assert(numKeys == (max-i-1));
		for(int j=max-numKeys; j < max; ++j) {
			sprintf(str, "%d", j);
			assert(strcmp(key[j], str) == 0);
		}
	}
}












































