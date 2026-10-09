/*                      ==============WARNINGs==============

        1. User terminals may not support ANSI codes or the SetCustomColorMode() functions
           Check the $TERM, $COLORTERM, or tput colors variables before trying

        2. There is no cross-platform support as of now 10/4/2026. This uses only the conio.h
           header file for keyboard checking on windows
*/

#pragma once
#include <iostream>
#include <string>
#include <cmath>

// Windows
#ifdef _WIN32
#include <conio.h>
int _cdecl getch() { return _getch(); }
int _cdecl kbhit() { return _kbhit(); }
#endif

using str = std::string;

namespace Scriptum
{

    // MISCELLANEOUS ===========================

    // used at the end of a command (if preferable)
    inline const str CLEARFX = "\x1b[0m"; // DOES NOT clear the screen
    inline const str CLEAR_SCR = "\x1b[2J";

    // Types of spaces
    inline const str NEWLINE = "\n";
    inline const str TAB = "\t";
    inline const str BACKSPACE = "\b";
    inline const str VERT_TAB = "\v";
    inline const str PIXEL = "  "; // basically a pixel

    // BASE COLORS (FOREGROUND) ===========================
    inline const str BLACK = "30";
    inline const str RED = "31";
    inline const str GREEN = "32";
    inline const str YELLOW = "33";
    inline const str BLUE = "34";
    inline const str MAGENTA = "35";
    inline const str CYAN = "36";
    inline const str WHITE = "37";

    // BRIGHT COLORS (FOREGROUND) ===========================
    inline const str BRIGHT_BLACK = "90";
    inline const str BRIGHT_RED = "91";
    inline const str BRIGHT_GREEN = "92";
    inline const str BRIGHT_YELLOW = "93";
    inline const str BRIGHT_BLUE = "94";
    inline const str BRIGHT_MAGENTA = "95";
    inline const str BRIGHT_CYAN = "96";
    inline const str BRIGHT_WHITE = "97";

    // BASE COLORS (BACKGROUND) ===========================
    inline const str BG_BLACK = "40";
    inline const str BG_RED = "41";
    inline const str BG_GREEN = "42";
    inline const str BG_YELLOW = "43";
    inline const str BG_BLUE = "44";
    inline const str BG_MAGENTA = "45";
    inline const str BG_CYAN = "46";
    inline const str BG_WHITE = "47";

    // TEXT STYLES ===========================
    inline const str BOLD = "1";
    inline const str DIM = "2";
    inline const str ITALIC = "3";
    inline const str UNDERLINE = "4";
    inline const str SLOW_BLINK = "5";
    inline const str REVERSE = "7";
    inline const str HIDDEN = "8";
    inline const str STRIKETHROUGH = "9";

    // BG AND FG ===========================
    inline const str BACKGROUND = "\x1b[48;";
    inline const str FOREGROUND = "\x1b[38;";

    // COLOR LIST ===========================
    str GREYSCALE[25] = {
        "\x1b[48;5;232m",
        "\x1b[48;5;233m",
        "\x1b[48;5;234m",
        "\x1b[48;5;235m",
        "\x1b[48;5;236m",
        "\x1b[48;5;237m",
        "\x1b[48;5;238m",
        "\x1b[48;5;239m",
        "\x1b[48;5;240m",
        "\x1b[48;5;241m",
        "\x1b[48;5;242m",
        "\x1b[48;5;243m",
        "\x1b[48;5;244m",
        "\x1b[48;5;245m",
        "\x1b[48;5;246m",
        "\x1b[48;5;247m",
        "\x1b[48;5;248m",
        "\x1b[48;5;249m",
        "\x1b[48;5;250m",
        "\x1b[48;5;251m",
        "\x1b[48;5;252m",
        "\x1b[48;5;253m",
        "\x1b[48;5;254m",
        "\x1b[48;5;255m"};

    
    // ======================================================
    // FUNCTIONS
    // ======================================================

    // readablity reasons
    template <typename T>
    inline str string(T value) { return std::to_string(value); }

    // Clear all effects
    inline void ClearFX() { std::cout << CLEARFX; }

    template <typename MESSAGE, typename END, typename... ARGS>
    inline void PrintFX(MESSAGE message, END end, ARGS... codes)
    {
        std::cout << "\x1b[";                          // starter
        ((std::cout << ";" << codes), ...);            // fold expression
        std::cout << "m" << message << CLEARFX << end; // message
    }
    
    // ======================================================
    // CURSOR FUNCTIONS
    // ======================================================

    template <typename MESSAGE, typename END, typename... ARGS>
    inline void MovPrintFX(int x, int y, MESSAGE message, END end, ARGS... codes)
    {
        // First move the cursor to the x and y
        std::cout << "\x1b[" << string(y) << ";" << string(x) << "H";
        PrintFX(message, end, codes...);
    }

    inline void MovCursor(int x, int y) {
        std::cout << "\x1b[" << string(y) << ";" << string(x) << "H";
    }

    inline void ResetCursor() {
        std::cout << "\x1b[0;0H";
    }

    // ======================================================
    // COLORING FUNCTIONS
    // ======================================================

    // Doesn't use any effects but relies on predefined modes set by user
    // Clears all effects when finished
    // Seperates with " " and ends with a NEWLINE
    // Calls CLEARFX() when done
    // You can still use std::cout instead if preferred
    template <typename... ARGS>
    inline void PrintMode(ARGS... messages)
    {
        ((std::cout << " " << messages), ...);
        std::cout << NEWLINE;
        ClearFX();
    }

    // Set a custom color with RGB values
    inline void SetCustomColorMode(short r, short g, short b, str GROUND)
    {
        std::cout << GROUND << "2;" << string(r) << ";" << string(g) << ";" << string(b) << "m";
    }

    // overload for 256 bit color palette
    inline void SetCustomColorMode(short code, str GROUND)
    {
        std::cout << GROUND << "5;" << string(code) << "m";
    }

    // ======================================================
    // RESETTING FUNCTIONS
    // ======================================================

    // Clearing the console and all effects
    inline void Clear()
    {
        std::cout << "\x1b[2J" << "\x1b[1J" << "\x1b[0J";
        ClearFX();
    }

    // Clear effects, clear screen, abort program 
    void End() {ClearFX(); Clear(); ResetCursor(); abort(); }

    // ======================================================
    // OUTPUT OPTION FUNCTIONS
    // ======================================================

    // Output availiable colors
    void OutputColors256()
    {
        PrintFX("256 BIT COLORS", NEWLINE, BOLD, UNDERLINE);
        for (int i = 0; i < 256; ++i)
            std::cout << "\x1b[48;5;" << string(i) << "m  " << CLEARFX;
        std::cout << NEWLINE;
    }

    // Outputs both bright and basic colors
    void OutputColorsBASIC()
    {
        int i;
        // Basic 30 - 37
        PrintFX("BASIC FOREGROUND", NEWLINE, BOLD, UNDERLINE);
        for (i = 30; i <= 37; ++i)
            std::cout << "\x1b[" << string(i) << "m()" << CLEARFX;
        std::cout << NEWLINE;

        // Bright 90 - 97
        PrintFX("BRIGHT FOREGROUND", NEWLINE, BOLD, UNDERLINE);
        for (i = 90; i <= 97; ++i)
            std::cout << "\x1b[" << string(i) << "m()" << CLEARFX;
        std::cout << NEWLINE;

        // Background 40 - 47
        PrintFX("BACKGROUND COLORS", NEWLINE, BOLD, UNDERLINE);
        for (i = 40; i <= 47; ++i)
            std::cout << "\x1b[" << string(i) << "m  " << CLEARFX;
        std::cout << NEWLINE;
    }

    void OutputTextStyles()
    {
        PrintFX("TEXT STYLES", NEWLINE, BOLD, UNDERLINE);
        for (int i = 1; i <= 9; ++i)
            std::cout << "\x1b[" << string(i) << "mTEXT" << CLEARFX << NEWLINE;
    }

    void OutputGreyScale()
    {
        PrintFX("GREYSCALE", NEWLINE, BOLD, UNDERLINE);
        for (int i = 232; i < 256; ++i)
        {
            std::cout << "\x1b[48;5;" << string(i) << "m  " << CLEARFX;
            std::cout << "x1b[48;5;" << string(i) << "m  " << CLEARFX;
        }

        std::cout << NEWLINE;
    }

    void OutputOptionsALL()
    {
        OutputColors256();
        OutputColorsBASIC();
        OutputGreyScale();
        OutputTextStyles();
    }

    // ======================================================
    // MATH AND DRAWING STRUCTS
    // ======================================================
    typedef struct{int x, y;} Vec2;
    
    // ======================================================
    // DRAWING FUNCTIONS
    // ======================================================

    
}
