# 1 "desenho.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.35/packs/Microchip/PIC18Fxxxx_DFP/1.2.26/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "desenho.c" 2
# 1 "./desenho.h" 1




  void desenhoInit(void);
  void desenhoOn (void);
  void desenhoOff (void);
# 1 "desenho.c" 2

# 1 "./lcd.h" 1


  void lcdCommand(char value);
  void lcdChar(char value);
  void lcdString(char msg[]);
  void lcdNumber(int value);
  void lcdPosition(int line, int col);
  void lcdInit(void);
# 2 "desenho.c" 2




void desenhoInit() {
    int i;

    lcdPosition(0,4);
    lcdString("|");
    lcdPosition(1,4);
    lcdString("|");
    lcdPosition(0,15);
    lcdString("|");
    lcdPosition(1,15);
    lcdString("|");
    lcdPosition(0,5);
    lcdString("Timer OFF");
    lcdPosition(1,5);
    lcdString("Modo:");
    lcdPosition(0,2);
    lcdChar(0xDF);
    lcdString("C");



    char v100[8] = {0b00000,
                    0b01110,
                    0b01110,
                    0b01110,
                    0b01110,
                    0b01110,
                    0b01110,
                    0b00000,};

    char v75[8] = { 0b00000,
                    0b00000,
                    0b00000,
                    0b01110,
                    0b01110,
                    0b01110,
                    0b01110,
                    0b00000,};

    char v50[8] = { 0b00000,
                    0b00000,
                    0b00000,
                    0b00000,
                    0b01110,
                    0b01110,
                    0b01110,
                    0b00000,};

    char v25[8] = { 0b00000,
                    0b00000,
                    0b00000,
                    0b00000,
                    0b00000,
                    0b01110,
                    0b01110,
                    0b00000,};

   char aquecer[8]={0b00010,
                    0b00100,
                    0b01000,
                    0b00100,
                    0b00010,
                    0b00100,
                    0b01000,
                    0b00000,};

    char vent[8] = { 0b00000,
                    0b00000,
                    0b10011,
                    0b11010,
                    0b00100,
                    0b01011,
                    0b11001,
                    0b00000,};

   lcdCommand(0x40);

    for (i = 0; i < 8; i++) {
        lcdChar(v100[i]);
    }
   lcdCommand(0x48);
   for (i = 0; i < 8; i++) {
        lcdChar(v75[i]);
    }
   lcdCommand(0x50);
   for (i = 0; i < 8; i++) {
        lcdChar(v50[i]);
    }
   lcdCommand(0x58);
   for (i = 0; i < 8; i++) {
        lcdChar(v25[i]);
    }
   lcdCommand(0x60);
   for (i = 0; i < 8; i++) {
        lcdChar(aquecer[i]);
    }
      lcdCommand(0x68);
   for (i = 0; i < 8; i++) {
        lcdChar(vent[i]);
    }
}

  void desenhoOn (void){
      lcdPosition(0,5);
      lcdString("Timer ON");
      lcdString(" ");
  }

  void desenhoOff(void){
        lcdPosition(0,5);
        lcdString("Timer OFF");
  }
