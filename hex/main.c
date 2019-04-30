#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <curses.h>

#include "hexwin.h"

static uint8_t HexData[0x100];

int main (int argc, char **argv)
{
    uint16_t    Index;
    WINDOW    *hexwin;

    for (Index = 0; Index < 0x100; Index++) {
        HexData[Index] = Index;
    }


    initscr();
    refresh();

    if (has_colors()) {
        start_color();
    }

    hexwin = CreateHexWindow();
    UpdateHexData (hexwin, HexData, 0x100);
    wrefresh(hexwin);
    


    getch();
    endwin();

    return 0;
}
