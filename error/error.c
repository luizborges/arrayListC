/**
 */
////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "error.h"

////////////////////////////////////////////////////////////////////////////////
// Private Variables
////////////////////////////////////////////////////////////////////////////////
static char ErrorInfo[1024] = "";
static char ErrorMsg[4096] = "";


////////////////////////////////////////////////////////////////////////////////
// Private Functions Head
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////
// Construct Functions
////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////
  // configurações gerais da lista
  //////////////////////////////////////////////////////////////////////////////
 
////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////
void Error_(const char *file, const int line,
            const char *func, ...) {
  va_list msgUserArgs;
  //////////////////////////////////////////////////////////////////////////////
  // time information
  //////////////////////////////////////////////////////////////////////////////
  time_t timer = time(NULL);
  const char *strTimer = asctime(localtime(&timer));
  
  //////////////////////////////////////////////////////////////////////////////
  // file & line & function information
  //////////////////////////////////////////////////////////////////////////////
  // 1024 - is a size of string ErrorInfo - always check this size
  // se a string resultante for maior que o size of string o restante que é maior será descartado
  snprintf(ErrorInfo, 1024, "File: \"%s\"\nFunction: \"%s\"\nLine: %d", file, func, line);
  
  //////////////////////////////////////////////////////////////////////////////
  // user msg information
  //////////////////////////////////////////////////////////////////////////////
  // se a string resultante for maior que o size of string o restante que é maior será descartado
  va_start(msgUserArgs, func);
  char *msgUser = va_arg(msgUserArgs, char*);
  vsnprintf(ErrorMsg, 4096, msgUser, msgUserArgs); // size of ErrorMsg - 4096
  va_end(msgUserArgs);
  
  //////////////////////////////////////////////////////////////////////////////
  // user msg information
  //////////////////////////////////////////////////////////////////////////////
  fprintf(stderr, "ERROR %s\n%s\nTime Error: %s\n", ErrorMsg, ErrorInfo, strTimer);
    
  abort();
}




















