# 1 "modo.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.35/packs/Microchip/PIC18Fxxxx_DFP/1.2.26/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "modo.c" 2
# 1 "./modo.h" 1




void modo (int m);
# 1 "modo.c" 2

# 1 "./lcd.h" 1


  void lcdCommand(char value);
  void lcdChar(char value);
  void lcdString(char msg[]);
  void lcdNumber(int value);
  void lcdPosition(int line, int col);
  void lcdInit(void);
# 2 "modo.c" 2

# 1 "./ssd.h" 1
# 22 "./ssd.h"
 void ssdDigit(char val, char pos);
 void ssdUpdate(void);
 void ssdInit(void);
# 3 "modo.c" 2





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
