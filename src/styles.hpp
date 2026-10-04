#pragma once
#include <iostream>
#include <string>
using str = const std::string;

namespace Scriptum {

    // MISCELANEOUS

    // used at the end of a command (if preferable)
    inline const str CLEAR = "\x1b[0m"; 
    
    // Types of spaces
    inline const str NEWLINE      = "\n";
    inline const str TAB          = "\t";
    inline const str BACKSPACE    = "\b";
    inline const str VERT_TAB     = "\v"; 
    

    // BASE COLORS (FOREGROUND)
    inline const str BLACK   = "30";
    inline const str RED     = "31";
    inline const str GREEN   = "32";
    inline const str YELLOW  = "33";
    inline const str BLUE    = "34";
    inline const str MAGENTA = "35";
    inline const str CYAN    = "36";
    inline const str WHITE   = "37";

    // BRIGHT COLORS (FOREGROUND)
    inline const str BRIGHT_BLACK   = "90";
    inline const str BRIGHT_RED     = "91";
    inline const str BRIGHT_GREEN   = "92";
    inline const str BRIGHT_YELLOW  = "93";
    inline const str BRIGHT_BLUE    = "94";
    inline const str BRIGHT_MAGENTA = "95";
    inline const str BRIGHT_CYAN    = "96";
    inline const str BRIGHT_WHITE   = "97";

    // BASE COLORS (BACKGROUND)
    inline const str BG_BLACK   = "40";
    inline const str BG_RED     = "41";
    inline const str BG_GREEN   = "42";
    inline const str BG_YELLOW  = "43";
    inline const str BG_BLUE    = "44";
    inline const str BG_MAGENTA = "45";
    inline const str BG_CYAN    = "46";
    inline const str BG_WHITE   = "47";

    // TEXT STYLES
    inline const str BOLD          = "1";
    inline const str DIM           = "2";
    inline const str ITALIC        = "3";
    inline const str UNDERLINE     = "4";
    inline const str SLOW_BLINK    = "5";
    inline const str REVERSE       = "7";
    inline const str HIDDEN        = "8";
    inline const str STRIKETHROUGH = "9";

    // FUNCTIONS

    template<typename MESSAGE, typename... ARGS>
    inline void PrintFX(MESSAGE message, ARGS... codes) {
        std::cout << "\x1b["; // starter
        ((std::cout << ";" << codes), ...); // fold expression
        std::cout << "m"  << message << Scriptum::CLEAR; // message
    }

}
