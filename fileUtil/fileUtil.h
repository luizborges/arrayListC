/**
 */
#ifndef FILEUTIL_H
#define FILEUTIL_H

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <headers/error.h>
#include <headers/memoryManager.h>
////////////////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Structs
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Typedefs
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Constructs
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

/**
 * Returns a new line of the file.
 * Creates a new line.
 * If line is empty, returns '\0'
 * Return include the '\n'
 * If the file is end - return NULL
 */
extern char*
FileUtil_Get_Line(FILE *file);


/**
 * Abre um arquivo ou trata de um arquivo já aberto e insere todo o seu contéudo em uma string.
 * Ao final insere o character '\0'.
 * Ao final de todas as operações, o arquivo é fechado - fclose
 * O character EOF não é inserido no arranjo retornado.
 * @param type: pode somente ser duas strings:
 *              "file" : quando o tipo var for uma variável do tipo FILE*
 *              "file_name" : quando o tipo var for o nome de um arquivo para ser aberto
 */
extern char*
FileUtil_StrMap(const void *var,
				const char *type);


/**
 * Lê uma string do arquivo e insere na variável str.
 * Insere os characteres encontrados no arquivo até enocntrar uma das condições finais.
 * que são:
 * encontrar o character '\0' ou o EOF (fim do arquivo) ou inserir size -1 characteres.
 * @arg str: string que será inserido os valores.
 * @arg size: número máximo de characteres que pode ser inserido na string.
 * É inserido no máximo size -1 characteres.
 * @arg f: file pointer
 * @return 0: não encontrou o fim do arquivo e encontrou o fim da string, ou seja o
 * character '\0'.
 * -1: encontrou o fim do arquivo, character EOF.
 * 1: não encontrou o fim do arquivo, porém o tamanho da string não foi suficiente para
 * conter toda a string, ou seja, o character '\0' não foi encontrado no arquivo.
 */
extern int
FileUtil_Get_Str(char *str,
				 const long size,
				 FILE *f);

#ifdef __cplusplus
}
#endif
#endif // FILEUTIL_H

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////





