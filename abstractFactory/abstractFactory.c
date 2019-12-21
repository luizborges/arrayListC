#include "abstractFactory.h"

void *Abstract_Factory(enum Factory_Product_t fp) {
	void *class = NULL;
	
	switch(fp) {
		case ArrayList:
			class = ArrayList_noSync_New_Interface();
			break;
		case Map:
			class = Map_ArrayList_noSync_New_Interface();
		default: Error("Abstract Factory - Not Factory Product Valid: %d\n", (int)fp);
	}
	
	return class;
}

