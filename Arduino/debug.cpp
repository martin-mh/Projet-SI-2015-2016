#include "debug.h"

Stream * Debug::stream = 0;

void Debug::print(char * text)
{
  #if DEBUG_MODE
  stream->print(text);
  #endif
}

void Debug::println(char * text)
{
  #if DEBUG_MODE
  stream->println(text);
  #endif
}

void Debug::setup(Stream * s)
{
  stream = s;
}

