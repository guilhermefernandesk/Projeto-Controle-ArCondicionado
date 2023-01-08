#include "modo.h"
#include "lcd.h"
#include "ssd.h"

#define L_ON 0x0F
#define L_OFF 0x08

void modo (int m){
    lcdPosition(1,11);
    switch(m){
        case 0:
            lcdString("Auto");
        break;
        case 1:
            lcdString("*");
            lcdString("   ");

        break;
        case 2:
            lcdChar(4);
            lcdChar(4);
            lcdString("  ");
        break;
        case 3:
            lcdChar(5);
            lcdString("   ");                        
        break;
        default:
        break;
                        
    }  
}
