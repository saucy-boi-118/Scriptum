#include "..\src\scriptum.hpp"
using namespace Scriptum::ANSI;

// Output availiable colors
void OutputColors256()
{
    printfx("256 BIT COLORS", BOLD, UNDERLINE);
    std::cout << NEWLINE;
    for (int i = 0; i < 256; ++i)
        std::cout << "\x1b[48;5;" << string(i) << "m  " << CLEARFX;
    std::cout << NEWLINE;
}

// Outputs both bright and basic colors
void OutputColorsBASIC()
{
    int i;
    // Basic 30 - 37
    printfx("BASIC FOREGROUND", BOLD, UNDERLINE);
    std::cout << NEWLINE;
    for (i = 30; i <= 37; ++i)
        std::cout << "\x1b[" << string(i) << "m()" << CLEARFX;
    std::cout << NEWLINE;

    // Bright 90 - 97
    printfx("BRIGHT FOREGROUND", BOLD, UNDERLINE);
    std::cout << NEWLINE;
    for (i = 90; i <= 97; ++i)
        std::cout << "\x1b[" << string(i) << "m()" << CLEARFX;
    std::cout << NEWLINE;

    // Background 40 - 47
    printfx("BACKGROUND COLORS", BOLD, UNDERLINE);
    std::cout << NEWLINE;
    for (i = 40; i <= 47; ++i)
        std::cout << "\x1b[" << string(i) << "m  " << CLEARFX;
    std::cout << NEWLINE;
}

void OutputTextStyles()
{
    printfx("TEXT STYLES", BOLD, UNDERLINE);
    std::cout << NEWLINE;
    for (int i = 1; i <= 9; ++i)
        std::cout << "\x1b[" << string(i) << "mTEXT" << CLEARFX << NEWLINE;
}

void OutputGreyScale()
{
    printfx("GREYSCALE", BOLD, UNDERLINE);
    std::cout << NEWLINE;
    for (int i = 232; i < 256; ++i)
    {
        std::cout << "\x1b[48;5;" << string(i) << "m  " << CLEARFX;
        std::cout << " x1b[48;5;" << string(i) << "m  " << CLEARFX << NEWLINE;
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

int main() {

    // Output all color options
    OutputOptionsALL();

    return 0;
}