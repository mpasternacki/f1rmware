/* nick_plasma.c
 * original provided by Grigori Goronzy <greg@geekmind.org> */
/* adapted for rad1o by Hans-Werner "hw" Hilse <hwhilse@gmail.com> */
#include <stdint.h>

#include <rad1olib/pins.h>
#include <rad1olib/light_ws2812_cortex.h>
#include <rad1olib/setup.h>

#include <r0ketlib/config.h>
#include <r0ketlib/print.h>
#include <r0ketlib/render.h>
#include <r0ketlib/display.h>
#include <r0ketlib/keyin.h>

#include "usetable.h"

#define INT_MAX 2147483647

static short sintab[] = {
    0 , 3 , 6 , 9 , 12 , 15 , 18 , 21 , 24 , 28 , 31 , 34 , 37 , 40 , 43 ,
    46 , 48 , 51 , 54 , 57 , 60 , 63 , 65 , 68 , 71 , 73 , 76 , 78 , 81 ,
    83 , 85 , 88 , 90 , 92 , 94 , 96 , 98 , 100 , 102 , 104 , 106 , 108 ,
    109 , 111 , 112 , 114 , 115 , 116 , 118 , 119 , 120 , 121 , 122 ,
    123 , 124 , 124 , 125 , 126 , 126 , 127 , 127 , 127 , 127 , 127 ,
    127 , 127 , 127 , 127 , 127 , 127 , 126 , 126 , 125 , 124 , 124 , 123
        , 122 , 121 , 120 , 119 , 118 , 117 , 115 , 114 , 112 , 111 , 109 ,
    108 , 106 , 104 , 102 , 100 , 99 , 97 , 94 , 92 , 90 , 88 , 86 , 83 ,
    81 , 78 , 76 , 73 , 71 , 68 , 65 , 63 , 60 , 57 , 54 , 52 , 49 , 46 ,
    43 , 40 , 37 , 34 , 31 , 28 , 25 , 22 , 18 , 15 , 12 , 9 , 6 , 3 ,
    0 , -2 , -6 , -9 , -12 , -15 , -18 , -21 , -24 , -27 , -30 , -33 ,
    -36 , -39 , -42 , -45 , -48 , -51 , -54 , -57 , -60 , -62 , -65 ,
    -68 , -70 , -73 , -76 , -78 , -81 , -83 , -85 , -88 , -90 , -92 ,
    -94 , -96 , -98 , -100 , -102 , -104 , -106 , -107 , -109 , -111 ,
    -112 , -114 , -115 , -116 , -118 , -119 , -120 , -121 , -122 , -123 ,
    -124 , -124 , -125 , -126 , -126 , -127 , -127 , -127 , -127 , -127 ,
    -127 , -127 , -127 , -127 , -127 , -127 , -126 , -126 , -125 , -124 ,
    -124 , -123 , -122 , -121 , -120 , -119 , -118 , -117 , -115 , -114 ,
    -113 , -111 , -109 , -108 , -106 , -104 , -103 , -101 , -99 , -97 ,
    -95 , -92 , -90 , -88 , -86 , -83 , -81 , -79 , -76 , -74 , -71 ,
    -68 , -66 , -63 , -60 , -57 , -55 , -52 , -49 , -46 , -43 , -40 ,
    -37 , -34 , -31 , -28 , -25 , -22 , -19 , -16 , -12 , -9 , -6 , -3 ,
};

// integer square root
static unsigned isqrt(unsigned val) {
    unsigned temp, g = 0, b = 0x8000, bshft = 15;
    do {
        if (val >= (temp = (((g << 1) + b)<<bshft--))) {
           g += b;
           val -= temp;
        }
    } while (b >>= 1);
    return g;
}

#define RAINBOW_STRIDE 9
#define RAINBOW_BRIGHTNESS 96
/* step is just an increasing step; target will be written to, and
 * should hold three values */
void rainbow(int step, uint8_t *target) {
     uint8_t stage = step / RAINBOW_STRIDE;
     uint8_t waxing;
     step %= RAINBOW_STRIDE;
     waxing = step * RAINBOW_BRIGHTNESS / RAINBOW_STRIDE; /* should give 0 to 255 */
     target[stage%3] = (RAINBOW_BRIGHTNESS - waxing);
     target[(stage+1)%3] = waxing;
     target[(stage+2)%3] = 0;
}

#include "nick_blinken_morse.inc"
const uint8_t *morse(char ch)
{
     if (  ch < ' ' || ch > 'z' ) {
          ch = '#';             /* nonexistent code */
     }
     return morse_t[ch - ' '];
}

uint16_t morse_len;
uint8_t morse_seq[512];

#define TYPE_CMD    0
#define TYPE_DATA   1

static void plasma(unsigned int t) {
    int i, j;

    uint8_t pattern[] = {
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0
    };

    for ( uint8_t i=0 ; i<5 ; i++ ) {
         rainbow(t+4-i, pattern+(i+2)*3);
    }
    pattern[21] = morse_seq[(t>>1)%morse_len];
    pattern[22] = pattern[21];
    pattern[23] = pattern[21];
    for ( int i = 0 ; i < 3*8 ; i++ ) {
         pattern[i] >>= 3;
    }
    ws2812_sendarray(pattern, sizeof(pattern));

    lcdWrite(TYPE_CMD,0x2C);
    for (j = 0; j < RESY; j++)
        for (i = 0; i < RESX; i++) {
            int color = (128 + sintab[(i+t) % 256] + 128 + sintab[(j+128+sintab[t%256]) % 256]) >> 1;
            int r = 128 + sintab[(color + t) % 256];
            int g = 128 + sintab[(color * 7 + t) % 256];
            int b = 128 + sintab[(color * 2 + t) % 256];
            int v = (r & 0b11100000) | ((g & 0b11100000) >> 3) | ((b & 0b11000000) >> 6);
            if(lcdGetPixel(i, j) == GLOBAL(nickfg)) v = v ^ 0xFF;
            lcdWrite(TYPE_DATA, v);
        }
}

void ram(void)
{
    unsigned int t = 0;
    uint8_t pattern_off[] = {
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0,
         0, 0, 0
    };
    

    morse_len = 0;
    for ( char *ch = nickname ; *ch ; ch++ ) {
         const uint8_t *code = morse(*ch);
         if ( code[0] == 0 ) {
              continue;
         }
         for ( int i = 0 ; i < code[0] ; i++ ) {
              morse_seq[morse_len++] = code[i+1];
         }
         for ( int i = 0 ; i < 3 ; i++ ) {
              morse_seq[morse_len++] = 0;
         }
    }
    /* double space between repetitions */
    for ( int i=0 ; i < 11 ; i++ ) {
         morse_seq[morse_len++] = 0;
    }

    setExtFont(GLOBAL(nickfont));
    int dx=DoString(0,0,GLOBAL(nickname));
    dx=(RESX-dx)/2;
    if(dx<0)
        dx=0;
    int dy=(RESY-getFontHeight())/2;

    SETUPgout(RGB_LED);

    lcdClear();
    lcdFill(GLOBAL(nickbg));
    setTextColor(GLOBAL(nickbg),GLOBAL(nickfg));
    lcdSetCrsr(dx,dy);
    lcdPrint(GLOBAL(nickname));
    lcdDisplay();

    // display plasma
    lcd_select();
    
    for (;;) {
        plasma(t++);
        delayms(10);
        char key = getInputRaw();
        if (key == BTN_ENTER) {
            lcd_deselect();
            setTextColor(0xFF,0x00);
            ws2812_sendarray(pattern_off, sizeof(pattern_off));
            return;
        }
    }

}
