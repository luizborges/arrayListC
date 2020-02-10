#include "fileUtil.h"

char *FileUtil_Get_Line (FILE *file) {
	fpos_t pos;
    int lineSize, i;
    char *line;
    
    i = fgetpos(file, &pos);
    if (i != 0) { Error("fgetpos.\nError in get the pos of init of reading file.\n");}
    
    // procura o final da linha
    for (lineSize = 0;
    	 (i = getc(file)) && (i != '\n' && i != EOF);
         ++lineSize);
    
    if (lineSize == 0 && i == EOF) {
    	return NULL; // se a linha é vazia e fim do arquivo
    }
    
    line = MM_Malloc(lineSize +2);
    if(line == NULL) {
    	Error("Allocate space for new line. - Line Size: %d", lineSize);
    }
    
    i = fsetpos(file, &pos); // seta o arquivo no comeco da linha
    if (i != 0) { Error("Set fsetpos to the begging of the line in file.");}
    
    for (i = 0; i <= lineSize; ++i) {
        line[i] = getc(file); // preenche a string com os dados da linha
    }
    
    line[i] = '\0'; // seta o caractere de final de linha
    
    return line;
}








