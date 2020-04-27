/**
 */
////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "stackTracer.h"



////////////////////////////////////////////////////////////////////////////////
// Private Variables
////////////////////////////////////////////////////////////////////////////////
const static int _stackTracer_Max_Trace = 4096;

typedef struct {
	int id; // o id sempre tem que ser maior que zero para identificar se está vazio ou não.
	char name[16];
} _stackTracer_signal_o;

static _stackTracer_signal_o _signal[StackTracer_Max_Signal];

typedef struct {
	char file[256];
	char func[256];
	int  line;
	bool init; // true - foi inicializado e usado | false - otherwise
} _stackTracer_line_o;

static _stackTracer_line_o _line;
////////////////////////////////////////////////////////////////////////////////
// Private Functions Head
////////////////////////////////////////////////////////////////////////////////
static void _StackTracer_Show();
static void _StackTracer_Signal_Init();
static int  _StackTracer_Signal_Add(const int id, const char *name);

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////
static void _StackTracer_Show() {
#if defined(_WIN32) || defined(_WIN64)
	fprintf(stderr, "StackTracer not implemented yet to Windows System.");
	
#elif  defined(unix) || defined(__unix) || defined(__unix__) // Unix (Linux, *BSD, Mac OS X)

  void *array[10];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, StackTracer_Get_MaxTrace());
  strings = backtrace_symbols(array, size);

  fprintf(stderr, "StackTracer: Obtained %zd stack frames.\n", size);
  fprintf(stderr, "StackTracer:\n");
  for (i = 0; i < size; i++) {
     fprintf (stderr, "%s\n", strings[i]);
  }

  free (strings);

#endif
	//_Exit(EXIT_FAILURE); // terminates programming without calling nothing more
	exit(EXIT_FAILURE);
}


static void _StackTracer_Signal_Init() {
	for(int i=0; i <16; ++i) {
		_signal[i].id = -1;
		strcpy(_signal[i].name, "");
	}
}

/**
 * Insere ou sobrescreve o valor em uma dada posição na estrutura que guarda os signais com nomes.
 * O tamanho máximo de armazenagem é o valor da variável StackTracer_Max_Signal
 * Da maneira como está, sobrescreve um valor ou insere mais um novo sinal
 * @return: Em caso de erro retorna um valor negativo.
 * Em caso de sucesso, retorna a posição do array em que foi colocado o sinal.
 */
static int _StackTracer_Signal_Add(const int id, const char *name) {
	int pos = 0;
	
	// check errors
	if(id < 0) return -1;
	if(name == NULL) return -2;
	if(strlen(name) < 5) return -3;
	if(strcmp(name, "     ") == 0) return -4;
	
	// insert in signal array
	// insere na primeira posição vazia ou se encontrar o valor do sinal. o que acontecer antes.
	for(pos=0; pos < StackTracer_Max_Signal; ++pos) {
		if(_signal[pos].id == -1 || _signal[pos].id == id) { // verifica se a posição no array está vazia ou se já existe uma posição que contenha o valor dado
			_signal[pos].id = id;
			strncpy(_signal[pos].name, name, 15); // tamanho max de _signal[pos].name -1
			break;
		}
	}
	
	if(pos >= StackTracer_Max_Signal) { // verifica se conseguiu inserir no array
		return -StackTracer_Max_Signal;
	}
	
	return pos;
}


////////////////////////////////////////////////////////////////////////////////
// Construct Functions
////////////////////////////////////////////////////////////////////////////////







////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////
void StackTracer_Init() {
	_StackTracer_Signal_Init();
	
	const char msgError[62] = "Stack_Trace: An error occured while setting a signal handler.";
	if(signal(SIGABRT, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGABRT", SIGABRT);
	}
	_StackTracer_Signal_Add(SIGABRT, "SIGABRT");
	
	if(signal(SIGFPE, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGFPE", SIGFPE);
	}
	_StackTracer_Signal_Add(SIGFPE, "SIGFPE");
	
	if(signal(SIGILL, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGILL", SIGILL);
	}
	_StackTracer_Signal_Add(SIGILL, "SIGILL");
	
	if(signal(SIGINT, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGINT", SIGINT);
	}
	_StackTracer_Signal_Add(SIGABRT, "SIGABRT");
	
	if(signal(SIGSEGV, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGSEGV", SIGSEGV);
	}
	_StackTracer_Signal_Add(SIGSEGV, "SIGSEGV");
	
	if(signal(SIGTERM, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGTERM", SIGTERM);
	}
	_StackTracer_Signal_Add(SIGTERM, "SIGTERM");
	
	_line.init = false; // inicializa o tracer line sempre como false
}

void StackTracer_Catch_Signal(const int signal) {
	fprintf(stderr, "****************************************\n");
	fprintf(stderr, "************* Stack Tracer *************\n");
	fprintf(stderr, "****************************************\n");
	
	///////////////////////////////////////////////////////////////////////////////////////////
	// imprime a linha que deu o erro, se utilizado o tracer line
	///////////////////////////////////////////////////////////////////////////////////////////
	if(_line.init == true)
	{
	//	fprintf(stderr, "****************************************\n");
	//	fprintf(stderr, "************* Tracer Line  *************\n");
	//	fprintf(stderr, "****************************************\n");
		fprintf(stderr, "File: \"%s\"\n", _line.file);
		fprintf(stderr, "Func: \"%s\"\n", _line.func);
		fprintf(stderr, "Line: %d\n\n", _line.line);
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////
	// imprime o nome do sinal se ele existir
	///////////////////////////////////////////////////////////////////////////////////////////
	int pos = -1;
	for(pos = 0; pos < StackTracer_Max_Signal; ++pos) { // percorre o array
		if(_signal[pos].id == signal) { // verifica se o nome existe
			fprintf(stderr, "StackTracer: Signal Name: \"%s\" - Signal Catch: %d\n", _signal[pos].name, signal);
			break;
		}
	}
	
	if(pos < 0 || pos >= StackTracer_Max_Signal) { // imprime msg default para o caso de não existir nome para o singal
		fprintf(stderr, "StackTracer: Signal Catch: %d\n", signal);
	}
	
	_StackTracer_Show();
}

int StackTracer_Get_MaxTrace() {
	return _stackTracer_Max_Trace;
}

void StackTracer_Line(const char *file,
	 				const char *func,
					const int line)
{
	if(file == NULL) { Error("File is NULL"); }
	if(func == NULL) { Error("Function is NULL"); }
	if(line < 1)	 { Error("Line is lesser than 1.\nLine is %d", line); }
	
	_line.init = true;
	
	strncpy(_line.file, file, 256);
	strncpy(_line.func, func, 256);
	_line.line = line;
}
/*
void StackTracer_Set_MaxTrace(const int maxTrace) {
	if(maxTrace < 10) {
		Error("stackTracer: MAX_TRACE variable less than 10. - maxTrace: %d\n", maxTrace);
	} else {
		_stackTracer_Max_Trace = maxTrace;
	}
} */














