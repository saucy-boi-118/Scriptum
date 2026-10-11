#pragma once
#include <iostream>
#include <string>
using str = std::string;
#include <cmath>

// KEYBOARD INPUT
// Windows
#ifdef _WIN32
#include <conio.h>
int _cdecl getch() { return _getch(); }
int _cdecl kbhit() { return _kbhit(); }
#endif

namespace Scriptum {
    // Printing effects and other ANSI related functions
    namespace ANSI 
    {
        // PROTOTYPES===========================
        
        template <typename MESSAGE, typename... ARGS>
        inline void printfx(MESSAGE message, ARGS... codes);

        template <typename MESSAGE, typename... ARGS>
        inline void mvprintfx(int x, int y, MESSAGE message, ARGS... codes);

        template <typename T>
        inline str string(T value);

        inline void clear();

        inline void end();

        inline void move(int x, int y);

        typedef struct {short r,g,b;}Color;

        inline void colorMode(Color color, str TARGET);

        inline void colorMode(short code, str TARGET);

        char getChar(std::string str, int character);

        // MISCELLANEOUS ===========================

        // used at the end of a command (if preferable)
        inline const str CLEARFX = "\x1b[0m"; // DOES NOT clear the screen
        inline const str DELETE_CH = "\x1b[1D\x1b[P";

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
        
        // readablity reasons
        template <typename T>
        inline str string(T value) { return std::to_string(value); }

        // Move the cursor to position x, y
        inline void move(int x, int y) {std::cout << "\x1b[" << string(y) << ";" << string(x) << "H";}
        
        // Move the cursor to position x, y and printfx
        template <typename MESSAGE, typename... ARGS>
        inline void mvprintfx(int x, int y, MESSAGE message, ARGS... codes) {
            std::cout << "\x1b[" << string(y) << ";" << string(x) << "H";
            printfx(message, codes...);
        }

        // prints things with the effects
        template <typename MESSAGE, typename... ARGS>
        inline void printfx(MESSAGE message, ARGS... codes) {
            std::cout << "\x1b[";                          // starter
            ((std::cout << ";" << codes), ...);            // fold expression
            std::cout << "m" << message << CLEARFX; // message
        }

        // clears effects and screen and moves the cursor to (0,0)
        inline void clear() {std::cout << "\x1b[0;0H\x1b[0J" << CLEARFX;}

        // end the program
        inline void end() {clear(); abort();}

        // creates a color mode
        // WARNING: does not clear up effects will leak into next effects

        // RGB true color version
        inline void colorMode(Color color, str TARGET) {
            std::cout << TARGET << "2;" << string(color.r) << ";" << string(color.g) << ";" << string(color.b) << "m";
        }

        // 256 Color palette overload
        inline void colorMode(short code, str TARGET) {
            std::cout << TARGET << "5;" << string(code) << "m";
        }
    
        char getChar(std::string str, int character) {
            std::string::iterator it = str.begin();

            for (int i = 0; i < character; i++)
                it++;

            return *it;
        }
    }

    // Drawing Capabilities 2D
    namespace Draw
    {}

    // Text interface library
    namespace TUI
    {}
}