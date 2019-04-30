#ifndef __HEX_WIN_H__
#define __HEX_WIN_H__


typedef union {
    uint8_t     u8data;
    uint16_t    u16data;
    uint32_t    u32data;
    struct {
        uint32_t b0 :1; uint32_t b1 :1; uint32_t b2 :1; uint32_t b3 :1;
        uint32_t b4 :1; uint32_t b5 :1; uint32_t b6 :1; uint32_t b7 :1;
        uint32_t b8 :1; uint32_t b9 :1; uint32_t b10:1; uint32_t b11:1;
        uint32_t b12:1; uint32_t b13:1; uint32_t b14:1; uint32_t b15:1;
        uint32_t b16:1; uint32_t b17:1; uint32_t b18:1; uint32_t b19:1;
        uint32_t b20:1; uint32_t b21:1; uint32_t b22:1; uint32_t b23:1;
        uint32_t b24:1; uint32_t b25:1; uint32_t b26:1; uint32_t b27:1;
        uint32_t b28:1; uint32_t b29:1; uint32_t b30:1; uint32_t b31:1;
    } BIT_ARRAY;
} HEX_DATA_UNION;



WINDOW*
CreateHexWindow (
    void
    );

#endif
