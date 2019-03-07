#include <iostream>
  #define ENABLE_LOG

#ifdef ENABLE_LOG
#define Log(message) std::cout << message
#else
#define Log(message) 
#endif 
