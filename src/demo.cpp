#include <iostream>
#include "styles.hpp" // include for ANSI
using namespace Scriptum;
typedef struct {int x,y,w,h;} RECT;

int main() {
    
    // PrintFX("Hey whats up", NEWLINE, BLUE, UNDERLINE, BOLD, BG_WHITE);
    // MovPrintFX(10,10,PIXEL, NEWLINE, BG_BLUE);


    /* PIXELS are 3 across and 2 height??
    MovPrintFX(0,0,PIXEL,"",BG_BLUE); 
    MovPrintFX(3,0,PIXEL,"",BG_RED); 
    MovPrintFX(0,2,PIXEL,"",BG_GREEN);
    */

    PrintFX("\u25FC", "", BOLD);

    /*
    while(!kbhit()) 
    {
        Clear();
        MovPrintFX(p.x,p.y,PIXEL,"",BG_BLUE);
        switch(getch()) 
        {
            case 's': p.y += 1; break;
            case 'w': p.y -= 1; break;
            case 'q': End(); break;
        }
    }
    */

    

    // TO DO
    // 1. MOUSE FUNCTIONS ./
    // 2. CUSTOM DRAWING (LINES, SQUARES, CIRCLE, TRIANGLE)
    // 3. SNAKE
    


    return 0;
}


