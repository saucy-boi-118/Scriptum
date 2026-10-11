#include "scriptum.hpp"
using namespace Scriptum;
int i,j;

// Defining bounds
const int WIDTH = 75;
const int HEIGHT = 50;

struct Rectangle 
{
    int x, y, w, h;

    void Draw() 
    { // filled rectangle
        ANSI::move(x,y);
        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++)
                ANSI::mvprintfx(j+x,i+y,ANSI::PIXEL,ANSI::BLUE);
    }
};

void box() 
{
    ANSI::move(0,0); // top left

    for (i = 0; i < HEIGHT; i++)
            for (j = 0; j < WIDTH; j++)
            {
                if (i == 1 || i == HEIGHT-1)
                    ANSI::mvprintfx(j,i,"-", ANSI::WHITE);
                else if (j == 1 || j == WIDTH-1)
                    ANSI::mvprintfx(j,i,"|", ANSI::WHITE);
            }
}

int main() 
{
    /* PIXELS are 3 across and 2 height??*/

    
    while(!kbhit()) 
    {
        ANSI::clear();
        box();



        // Keyboard checking
        switch(getch()) 
        {
            case 'q': ANSI::end(); break;
        }
    }


    return 0;
}


