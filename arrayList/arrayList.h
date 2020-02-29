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
	void *self; // guarda o objeto criado pela classe real

	// funções da interface
	void *(*Get)  (const void *self, const int pos);
	void *(*Set)  (void *self, const int pos, const void *content); // sobrescreve um elemento já existente no array
	void *(*Add)  (void *self, const int pos, const void *content); // adiciona um novo elemento no array
	void *(*Del)  (void *self, const int pos);
	int   (*Len)  (const void *self);
	void  (*End)  (void *self);
	
    void  (*Clean) (void *self); // remove todas as posições do array - sem destruir o array como o End
 	
} arrayList_o;


typedef arrayList_o* arrayList_t;



#ifdef __cplusplus
}
#endif
#endif // ARRAY_LIST_H

