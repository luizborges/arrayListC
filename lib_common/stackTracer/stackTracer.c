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

////////////////////////////////////////////////////////////////////////////////
// Private Functions Head
////////////////////////////////////////////////////////////////////////////////
static void _StackTracer_Show();


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
void StackTracer_Init() {
	const char msgError[62] = "Stack_Trace: An error occured while setting a signal handler.";
	if(signal(SIGABRT, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGABRT", SIGABRT);
	}
	if(signal(SIGFPE, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGFPE", SIGFPE);
	}
	if(signal(SIGILL, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGILL", SIGILL);
	}
	if(signal(SIGINT, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGINT", SIGINT);
	}
	if(signal(SIGSEGV, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGSEGV", SIGSEGV);
	}
	if(signal(SIGTERM, StackTracer_Catch_Signal) == SIG_ERR) {
	    Error("%s Signal Name: %s - Signal ID: %d", msgError, "SIGTERM", SIGTERM);
	}
}

void StackTracer_Catch_Signal(const int signal) {
	fprintf(stderr, "****************************************\n");
	fprintf(stderr, "************* Stack Tracer *************\n");
	fprintf(stderr, "****************************************\n");
	fprintf(stderr, "StackTracer: Signal Catch: %d\n", signal);
	_StackTracer_Show();
}

int StackTracer_Get_MaxTrace() {
	return _stackTracer_Max_Trace;
}

/*
void StackTracer_Set_MaxTrace(const int maxTrace) {
	if(maxTrace < 10) {
		Error("stackTracer: MAX_TRACE variable less than 10. - maxTrace: %d\n", maxTrace);
	} else {
		_stackTracer_Max_Trace = maxTrace;
	}
} */














