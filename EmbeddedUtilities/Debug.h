#ifndef EMBEDDEDCOMMON_DEBUG_H
#define EMBEDDEDCOMMON_DEBUG_H

#include <stdint.h>

/**
 * \file Debug.h
 * 
 * Implement print functions and compile with -DDEBUG=1
 * to have debug messages printed.
 */

void
printString(const char *);

void
printChar(char);

void
printHex32(uint32_t);

void
printDec32(uint32_t);

void
printDec32Signed(int32_t);

void
printUInt16(uint16_t);

void
printDec16(uint16_t);

void
printHex16(uint16_t);

void
printDec8(uint8_t);

void
printBin8(uint8_t);

void
printHex8(uint8_t);

void
printPtr(void *);

void
printNewLine(void);

void
printLine(const char *);

#ifndef DEBUG
#warning "define DEBUG=1 to enable debug messages or DEBUG=0 to disable them"
#warning "disabling debug messages by default"
#define DEBUG (0)
#endif

/**
 * This macro ensures that all calls to print functions are
 * removed in the optimizing step if no debug messages are needed.
 * Therefore, no implementation for those functions is required
 * as long as you compile with DEBUG=0.
 * The advantage of the macro is that the compiler still sees
 * all the code when DEBUG is disabled and checks for correctness.
 */

#define debug(format_type, argument) \
do \
  {\
    if (DEBUG) \
      print ## format_type(argument);\
  }\
  while(0)

#define debugString(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printString(message);                                                 \
    }                                                                         \
  while (0)

#define debugUInt16(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printUInt16(message);                                                 \
    }                                                                         \
  while (0)

#define debugNewLine(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printNewLine(message);                                                 \
    }                                                                         \
  while (0)

#define debugDec16(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printDec16(message);                                                 \
    }                                                                         \
  while (0)

#define debugHex16(message) \
  do \
  { \
    if (DEBUG) \
      printHex16(message); \
  } \
  while (0)

#define debugDec8(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printDec8(message);                                                 \
    }                                                                         \
  while (0)

#define debugHex8(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printHex8(message);                                                 \
    }                                                                         \
  while (0)

#define debugHex32(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printHex32(message);                                                 \
    }                                                                         \
  while (0)

#define debugDec32(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printDec32(message);                                                 \
    }                                                                         \
  while (0)

#define debugDec32Signed(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printDec32Signed(message);                                                 \
    }                                                                         \
  while (0)

#define debugChar(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printChar(message);                                                 \
    }                                                                         \
  while (0)

#define debugBin8(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printBin8(message);                                                 \
    }                                                                         \
  while (0)

#define debugLine(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printLine(message);                                                 \
    }                                                                         \
  while (0)

  #define debugPtr(message)                                                  \
  do                                                                          \
    {                                                                         \
      if (DEBUG)                                                              \
        printPtr(message);                                                 \
    }                                                                         \
  while (0)

#endif // EMBEDDEDCOMMON_DEBUG_H
