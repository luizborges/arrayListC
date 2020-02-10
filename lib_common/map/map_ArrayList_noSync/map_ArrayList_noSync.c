/**
 */
////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "map_ArrayList_noSync.h"

////////////////////////////////////////////////////////////////////////////////
// Private Functions Head
////////////////////////////////////////////////////////////////////////////////
static void Map_ArrayList_noSync_Check(Map_ArrayList_noSync_t map, const char *key);

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////
static void Map_ArrayList_noSync_Check(Map_ArrayList_noSync_t map, const char *key) {
	if(map == NULL) { Error("Map_ArrayList_noSync: map is NULL"); }
	if(map->list == NULL) { Error("Map_ArrayList_noSync: map_list is NULL"); }
	if(key == NULL) { Error("Map_ArrayList_noSync: key is NULL"); }
}

////////////////////////////////////////////////////////////////////////////////
// Constructors
////////////////////////////////////////////////////////////////////////////////
Map_ArrayList_noSync_t Map_ArrayList_noSync_New() {
	Map_ArrayList_noSync_t map = MM_Malloc(sizeof(Map_ArrayList_noSync_o));
	if(map == NULL) {
		Error("map_arrayList_noSync: Cannot Create Map.");
	}
	
	map->list = ArrayList_noSync_New();
	return map;
}

////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

void *Map_ArrayList_noSyncget (const void *_map, const char *key) {
	Map_ArrayList_noSync_t map = (Map_ArrayList_noSync_t)_map;
	Map_ArrayList_noSync_Check(map, key);
	
	Map_ArrayList_noSync_cell_t cell;
	for(int i = 0; i < ArrayList_noSync_len(map->list); ++i) {
		cell = (Map_ArrayList_noSync_cell_t*)ArrayList_noSync_get(map->list, i);
		
		if(strcmp(cell->key, key) == 0) {
			return (void*)cell->content;
		}
	}
	
	return NULL;
}
























