/**
 */
////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "stackTrace.h"



////////////////////////////////////////////////////////////////////////////////
// Private Variables
////////////////////////////////////////////////////////////////////////////////
const static int _StackTrace_Max_Trace = 4096;

////////////////////////////////////////////////////////////////////////////////
// Private Functions Head
////////////////////////////////////////////////////////////////////////////////
static void _StackTrace_Show();


////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////
static void _StackTrace_Show() {
#if defined(_WIN32) || defined(_WIN64)
	fprintf(stderr, "StackTrace not implemented yet to Windows System.");
	
#elif  defined(unix) || defined(__unix) || defined(__unix__) // Unix (Linux, *BSD, Mac OS X)

  void *array[10];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, StackTrace_Get_MaxTrace());
  strings = backtrace_symbols(array, size);

  fprintf(stderr, "StackTrace: Obtained %zd stack frames.\n", size);
  fprintf(stderr, "StackTrace::");
  for (i = 0; i < size; i++)
     fprintf (stderr, "%s\n", strings[i]);

  free (strings);

#endif
	//_Exit(EXIT_FAILURE); // terminates programming without calling nothing more
	exit(EXIT_FAILURE);
}




////////////////////////////////////////////////////////////////////////////////
// Construct Functions
////////////////////////////////////////////////////////////////////////////////







////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////
void StackTrace_Init() {
	const char msgError[62] = "Stack_Trace: An error occured while setting a signal handler.";
	if(signal(SIGABRT, StackTrace_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGABRT", SIGABRT);
	}
	if(signal(SIGFPE, StackTrace_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGFPE", SIGFPE);
	}
	if(signal(SIGILL, StackTrace_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGILL", SIGILL);
	}
	if(signal(SIGINT, StackTrace_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGINT", SIGINT);
	}
	if(signal(SIGSEGV, StackTrace_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGSEGV", SIGSEGV);
	}
	if(signal(SIGTERM, StackTrace_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGTERM", SIGTERM);
	}
}

void StackTrace_Catch_Signal(const int signal) {
	fprintf(stderr, "****************************************\n");
	fprintf(stderr, "************* Stack Trace **************\n");
	fprintf(stderr, "****************************************\n");
	fprintf(stderr, "Stack_Trace: Signal Catch: %d\n", signal);
	_StackTrace_Show();
}

int StackTrace_Get_MaxTrace() {
	return _StackTrace_Max_Trace;
}

/*
void StackTrace_Set_MaxTrace(const int maxTrace) {
	if(maxTrace < 10) {
		Error("StackTrace: MAX_TRACE variable less than 10. - maxTrace: %d\n", maxTrace);
	} else {
		_StackTrace_Max_Trace = maxTrace;
	}
} */














