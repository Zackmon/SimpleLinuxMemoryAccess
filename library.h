#include "sys/uio.h"
#include <iostream>


#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#  ifdef MODULE_API_EXPORTS
#    define MODULE_API __declspec(dllexport)
#  else
#    define MODULE_API __declspec(dllimport)
#  endif
#else
#  define MODULE_API
#endif

MODULE_API void PrintHelloWorld();
MODULE_API void freeingMemory(char* memoryAddress);
MODULE_API unsigned char* ReadMemory(int pid, char* address, int maxLength);
MODULE_API void WriteMemory (int pid , char* address, unsigned char* value, int valueSize);


#ifdef __cplusplus
}
#endif