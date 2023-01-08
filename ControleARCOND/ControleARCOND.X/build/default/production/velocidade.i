# 1 "velocidade.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.35/packs/Microchip/PIC18Fxxxx_DFP/1.2.26/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "velocidade.c" 2
# 1 "./velocidade.h" 1



void velocidade (int vel);
# 1 "velocidade.c" 2

# 1 "./lcd.h" 1


  void lcdCommand(char value);
  void lcdChar(char value);
  void lcdString(char msg[]);
  void lcdNumber(int value);
  void lcdPosition(int line, int col);
  void lcdInit(void);
# 2 "velocidade.c" 2



void velocidade (int vel){
    lcdPosition(1,0);

        if(vel>768){
            lcdChar(3);
            lcdChar(2);
            lcdChar(1);
            lcdChar(0);
        }
        if(vel>512 && vel<768){
            lcdChar(3);
            lcdChar(2);
            lcdChar(1);
            lcdString(" ");
        }
        if(vel>256 && vel<512){
            lcdChar(3);
            lcdChar(2);
            lcdString(" ");
            lcdString(" ");
        }
        if(vel>0 && vel<256){
            lcdChar(3);
            lcdString(" ");
            lcdString(" ");
            lcdString(" ");
        }
        if(vel == 0){
            lcdString(" ");
            lcdString(" ");
            lcdString(" ");
            lcdString(" ");
        }
}
