#include "abstractFactory.h"

void *Abstract_Factory(enum Factory_Product_t fp) {
	void *class = NULL;
	
	switch(fp) {
		case ArrayList:
			class = Interface_New(Interface_Config(arrayList_t), "ArrayList_noSync_",
					(void*)ArrayList_noSync_New());
			break;
		case Map:
			Error("Abstract Factory - Map not implement yet.");
		default: Error("Abstract Factory - Not Factory Product Valid: %d\n", (int)fp);
	}
	
	return class;
}

