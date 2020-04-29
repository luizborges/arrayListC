#include "fileUtil.h"

////////////////////////////////////////////////////////////////////////////////
// Enum
////////////////////////////////////////////////////////////////////////////////

enum FileUtil_Type_t {
	file,
	file_name
};




////////////////////////////////////////////////////////////////////////////////
// functions
////////////////////////////////////////////////////////////////////////////////
char*
FileUtil_Get_Line (FILE *file)
{
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


char*
FileUtil_StrMap(const void *var,
				const char *type_)
{
	/////////////////////////////////////////////////////////////////////////////////
	// verifica os argumentos
	/////////////////////////////////////////////////////////////////////////////////
	if(var == NULL) {
		Error("parameter var is NULL.\nvar = %p", var);
	}
	
	enum FileUtil_Type_t type = -1;
	if(strcmp(type_, "file") == 0) {
		type = file;
	}
	else if(strcmp(type_, "file_name") == 0) {
		type = file_name;
	}
	else {
		Error("parameter type is wrong.\nUse \"file\" or \"file_name\" in accordance with type desired.\n"
				"see documentation to more details.\ntype: \"%s\"\n", type_);
	}
	
	
	/////////////////////////////////////////////////////////////////////////////////
	// padroniza os arugmentos para um tratamento comum
	/////////////////////////////////////////////////////////////////////////////////
	char *fname = NULL; // usada para guardar o nome do arquivo, caso necessario
	FILE *file_ = NULL; // usada para tratamento igual dos dois tipos
	switch(type) {
		case file:
			file_ = (FILE*)var;
			break;
		case file_name:
			fname = (char*)var;
			file_ = fopen(fname, "r");
			if(file_ == NULL) {
				Error("error in open file.\nfile_name: \"%s\"", fname);
			}
			break;
		default:
			Error("parameter type is wrong.\nUse file or file_name in accordance with type desired.\n"
				"see documentation to more details.\ntype code: %d\n", type);
	}
	
	/////////////////////////////////////////////////////////////////////////////////
	// descobre o número de bytes para o fim do arquivo
	/////////////////////////////////////////////////////////////////////////////////
	long int sizeCurrent = ftell(file_); // descobre o tamanho do arquivo por agora
	fpos_t pos;
	int error = fgetpos(file_, &pos);
	if(error != 0) {
		if(type == file) {
			Error("error in keep position of file.\nfgetpos error code: %d\nfile pointer: %p",
					error, file_);
		} else {
			Error("error in keep position of file.\nfgetpos error code: %d\nfile name: \"%s\"",
					error, fname);
		}
	}
	
	error = fseek(file_, 0, SEEK_END); // vai até o fim do arquivo
	if(error != 0) {
		switch(type) {
			case file: Error("error in get the end of file.\nfseek error code: %d\nfile pointer: %p",error, file_);
			case file_name: Error("error in get the end of file.\nfseek error code: %d\nfile name: \"%s\"", error, fname);
		}
	}
	
	long int sizeFile = ftell(file_); // descobre o tamanho total
	if(sizeFile == -1L) {
		switch(type) {
			case file: Error("error in get the size of file.\nftell returned: %ld\nfile pointer: %p",sizeFile, file_);
			case file_name: Error("error in get the size of file.\nftell returned: %ld\nfile name: \"%s\"", sizeFile, fname);
		}
	}
	
	sizeFile = sizeFile -sizeCurrent +1; // 1 pois a subtração retira 1 e 1 para guardar o charactere '\0'
	
	error = fsetpos(file_, &pos); // recupera a posição do arquivo inicial
	if(error != 0) {
		if(type == file) {
			Error("error in restored position of file.\nfsetpos error code: %d\nfile pointer: %p",
					error, file_);
		} else {
			Error("error in restored position of file.\nfsetpos error code: %d\nfile name: \"%s\"",
					error, fname);
		}
	}
	
	/////////////////////////////////////////////////////////////////////////////////
	// cria a string e insere o valor conteúdo do arquivo nela
	/////////////////////////////////////////////////////////////////////////////////
	char *str = MM_Malloc(sizeFile);
	if(str == NULL) {
		switch(type) {
			case file: Error("error in allocate memory to resulted string\nfile pointer: %p",sizeFile, file_);
			case file_name: Error("error in allocate memory to resulted string\nfile name: \"%s\"", sizeFile, fname);
		}
	}
	
	size_t read = fread(str, 1, sizeFile, file_);
	if(read != (sizeFile -1)) {
		switch(type) {
			case file: Error("error in difference of bytes read.\nfread: %ld\nsizeFile: %ld\nsizeFile - fread: %ld\nfile pointer: %p",sizeFile, file_);
			case file_name: Error("error in difference of bytes read.\nfread: %ld\nsizeFile: %ld\nsizeFile - fread: %ld\nfile name: \"%s\"", read, sizeFile, sizeFile - read, fname);
		}
	}

	str[sizeFile-1] = '\0'; // insere o charactere de fim de string na última linha
	fclose(file_); // fecha o arquivo

	return str;
}


int
FileUtil_Get_Str(char *str,
				 const long size,
				 FILE *f)
{
	if(str == NULL) {
		Error("Argument 1 of function, \"str\" is NULL.");
	}
	
	if(size < 1) {
		Error("Argument 2 of function, \"size\" is less than 1."
		"size is %li", size);
	}
	
	int i = 0;
	for(; i < size-1; ++i)
	{
		str[i] = fgetc(f);
		if(str[i] == '\0') { // encontra o fim da string
			return 0;
		}
		
		if(str[i] == EOF) { // encontra o fim do arquivo
			str[i+1] = '\0';
			return -1;
		}
	}
	
	// trata quando o tamanho da string não é suficiente até achar o fim da string
	str[i] = '\0';
	return 1;
}
































