#ifndef DEBUG_H
#define DEBUG_H

#include "parameters.h"
#include "Stream.h"

class Debug
{
public:
  static void setup(Stream *s);
  static void print(char *);
  static void println(char *);

private:
  //Debug();

  static Stream * stream;
};

#endif
