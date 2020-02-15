#include "abstractFactoryCommon.h"

void *Abstract_Factory_Common(enum Factory_Product_Common_t fp) {
	void *class = NULL;
	
	switch(fp) {
		case ArrayList:
			class = ArrayList_noSync_New_Interface();
			break;
		case Map:
			class = Map_ArrayList_noSync_New_Interface();
			break;
		default: Error("Abstract Factory Common - Not Factory Product Valid: %d\n", (int)fp);
	}
	
	if(class != NULL) { // se não ocorreu problema
		return class;
	}
	
	switch(fp) {
		case ArrayList:
			Error("Cannot Create a ArrayList object.\n");
		case Map:
			Error("Cannot Create a Map object.\n");
		default: Error("Abstract Factory Common - Not Factory Product Valid: %d\n", (int)fp);
	}
	
	return NULL;
}

