/**
 * @author: luiz borges
 * @descr: interface para arrayList
 */
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void *this; // guarda o objeto criado pela classe real

	// funções da interface
	void *(*Get) (const void *this, const int pos);
	void *(*Set) (void *this, const int pos, const void *content); // sobrescreve um elemento já existente no array
	void *(*Add) (void *this, const int pos, const void *content); // adiciona um novo elemento no array
	void *(*Del) (void *this, const int pos);
	int   (*Len) (const void *this);
	void  (*End) (void *this);
 	
} arrayList_o;


typedef arrayList_o* arrayList_t;



#ifdef __cplusplus
}
#endif
#endif // ARRAY_LIST_H

