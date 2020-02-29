/**
 * @author: luiz borges
 * @descr: interface para mapList
 */
#ifndef MAP_H
#define MAP_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void *self; // guarda o objeto criado pela classe real

	// funções da interface
	void  *(*Get)    (const void *self, const char *key);
	void  *(*Set)    (void *self, const char *key, const void *content); // se não existe a chave, cria ela
	void  *(*Del)    (void *self, const char *key);
	char **(*Key)    (const void *self, int *numKeys); // numKeys = número de chaves existentes no map
	bool   (*HasKey) (const void *self, const char *key);
	void   (*Clean)  (void *self); // libera todas as chaves - porém não destroi o map
	void   (*End)    (void *self);
 	
} map_o;


typedef map_o* map_t;



#ifdef __cplusplus
}
#endif
#endif // MAP_H

