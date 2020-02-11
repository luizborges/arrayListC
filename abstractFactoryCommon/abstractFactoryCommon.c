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
		default: Error("Abstract Factory - Not Factory Product Valid: %d\n", (int)fp);
	}
	
	return class;
}

