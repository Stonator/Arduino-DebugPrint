
#ifndef _DebugPrint_h
#define _DebugPrint_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "arduino.h"
#else
    #include "WProgram.h"
#endif

#include <Print.h>

/// Class used for debug printing
class CDebugPrint : public Print
{
private:
    Print *m_pDebugPrint;

private:
    CDebugPrint();

public:
    CDebugPrint(Print *p_pDebugPrint);

    // Overrides
public:
    virtual size_t write(uint8_t c);
};

// Define and initialize a debug instance with the name "Debug" in your application. Set it to zero if debugging is not used.
extern CDebugPrint *DebugPrint;

// Create and configure debug printer instance
//CDebugPrint *DebugPrint;


// Helper macros for debug printing
#ifndef NDEBUG
    #define DPRINT(...)    (DebugPrint != 0 ? DebugPrint->print(__VA_ARGS__) : 0)   // debug print
    #define DPRINTLN(...)  (DebugPrint != 0 ? DebugPrint->println(__VA_ARGS__) : 0) // debug print with new line
#else
    #define DPRINT(...)
    #define DPRINTLN(...)
#endif


// Flash string utility macro, see https://forum.arduino.cc/index.php?topic=110307.0
#define FS(x) (const __FlashStringHelper*)(x) // Convert a string stored in Flash (PROGMEM) to a flash string helper pointer

// Example:
// const char FlashString[] PROGMEM = { "string" };
// Serial.print(FS(FlashString));

// Use F("") type strings for logging to move strings into flash instead of RAM
// Example:
// DPRINTLN(F("My debug string in flash memory"));

#endif
