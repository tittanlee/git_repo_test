#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <curses.h>

#include "hexwin.h"



#if 0
typedef union {
    uint8_t     u8data;
    uint16_t    u16data;
    uint32_t    u32data;
    struct {
        uint32_t      b0 :1; uint32_t      b1 :1; uint32_t      b2 :1; uint32_t      b3 :1;
        uint32_t      b4 :1; uint32_t      b5 :1; uint32_t      b6 :1; uint32_t      b7 :1;
        uint32_t      b8 :1; uint32_t      b9 :1; uint32_t      b10:1; uint32_t      b11:1;
        uint32_t      b12:1; uint32_t      b13:1; uint32_t      b14:1; uint32_t      b15:1;
        uint32_t      b16:1; uint32_t      b17:1; uint32_t      b18:1; uint32_t      b19:1;
        uint32_t      b20:1; uint32_t      b21:1; uint32_t      b22:1; uint32_t      b23:1;
        uint32_t      b24:1; uint32_t      b25:1; uint32_t      b26:1; uint32_t      b27:1;
        uint32_t      b28:1; uint32_t      b29:1; uint32_t      b30:1; uint32_t      b31:1;
    } BIT_ARRAY;
} HEX_DATA_UNION;


int main() 
{
    HEX_DATA_UNION  *HexDataUnion;
    uint8_t   stroffset = 0;
    uint8_t   value[] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
    };
    int        width = 4;
    int        totalbytes;
    int        index;
    char hexstr[3 * 16];
    
    memset (hexstr, sizeof(hexstr), 0);
    
    totalbytes = width * 2;
    HexDataUnion = (HEX_DATA_UNION *) &value;
    for (index = 0; index < 0x10; index += width) {
        
        HexDataUnion = (HEX_DATA_UNION *) (value + index);
        switch (width) {
            case 1:
                snprintf(&hexstr[stroffset], totalbytes + 1, "%02X", HexDataUnion->u8data);
                stroffset += totalbytes;
                hexstr[stroffset] = ' ';
                stroffset += 1;
            break;
            
            case 2:
                snprintf(&hexstr[stroffset], totalbytes + 1, "%04X", HexDataUnion->u16data);
                stroffset += totalbytes;
                hexstr[stroffset] = ' ';
                stroffset += 1;
            break;
            
            case 4:
                snprintf(&hexstr[stroffset], totalbytes + 1, "%08X", HexDataUnion->u32data);
                stroffset += totalbytes;
                hexstr[stroffset] = ' ';
                stroffset += 1;
            break;
        }
    }
    hexstr[stroffset] = 0;
    
    printf ("hexstr = %s, stroffset = %d\n", hexstr, stroffset);

    return 0;

}
#endif













//
// Hex window background and foreground
//
#define HEX_TEXT_FOCUS   1
#define HEX_TEXT_UNFOCUS 2


WINDOW*
CreateHexWindow (
    void
    )
{
    WINDOW *Win;

    Win = newwin(20, 60, 0, 0);

    init_pair(HEX_TEXT_UNFOCUS, COLOR_YELLOW, COLOR_BLUE);
    init_pair(HEX_TEXT_FOCUS, COLOR_YELLOW, COLOR_RED);

    wbkgd(Win, COLOR_PAIR(HEX_TEXT_UNFOCUS));

    return Win;
}

void
UpdateHexData (
    WINDOW          *Win,
    uint8_t         *data,
    uint16_t        len
    )
{
    HEX_DATA_UNION        *HexDataUnion;
    uint8_t               stroffset = 0;
    int                   width = 1;
    int                   totalbytes;
    int                   index;
    int                   y = 0;
    char hexstr[3 * 16];
    
    memset (hexstr, sizeof(hexstr), 0);
    
    totalbytes = width * 2;
    HexDataUnion = (HEX_DATA_UNION *) data;

    // while (len -= 16) {
        for (index = 0; index < 0x10; index += width) {
            HexDataUnion = (HEX_DATA_UNION *) (data + index);
            switch (width) {
                case 1:
                    snprintf(&hexstr[stroffset], totalbytes + 1, "%02X", HexDataUnion->u8data);
                    stroffset += totalbytes;
                    hexstr[stroffset] = ' ';
                    stroffset += 1;
                    break;

                case 2:
                    snprintf(&hexstr[stroffset], totalbytes + 1, "%04X", HexDataUnion->u16data);
                    stroffset += totalbytes;
                    hexstr[stroffset] = ' ';
                    stroffset += 1;
                    break;

                case 4:
                    snprintf(&hexstr[stroffset], totalbytes + 1, "%08X", HexDataUnion->u32data);
                    stroffset += totalbytes;
                    hexstr[stroffset] = ' ';
                    stroffset += 1;
                    break;
            }
        }
        hexstr[stroffset] = 0;

        wattron(Win, COLOR_PAIR(HEX_TEXT_UNFOCUS));
        mvwaddstr (Win, y++, 0, hexstr);
        wattroff(Win, COLOR_PAIR(HEX_TEXT_UNFOCUS));
        wrefresh(Win);
    // }
    
    // printf ("hexstr = %s, stroffset = %d\n", hexstr, stroffset);

}
