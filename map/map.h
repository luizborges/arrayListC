/**
 * @author: luiz borges
 * @descr: interface para arrayList
 */
#ifndef MAP_H
#define MAP_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void *this; // guarda o objeto criado pela classe real

	// funções da interface
	void  *(*Get) (const void *this, const char *key);
	void  *(*Set) (void *this, const char *key, const void *content); // se não existe a chave, cria ela
	void  *(*Del) (void *this, const int pos);
	char **(*Key) (const void *this, int *numKeys); // numKeys = número de chaves existentes no map
	void   (*End) (void *this);
 	
} map_o;


typedef map_o* map_t;



#ifdef __cplusplus
}
#endif
#endif // MAP_H
