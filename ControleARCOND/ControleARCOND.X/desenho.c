#include "desenho.h"
#include "lcd.h"


// Rotina de incialização
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
 
    
	//Cada linha é representada por um caracter
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
        
   lcdCommand(0x40); //Configura para a primeira posição de memória
    //Envia cada uma das linhas em ordem
    for (i = 0; i < 8; i++) {
        lcdChar(v100[i]);
    }
   lcdCommand(0x48); //Configura para a primeira posição de memória
   for (i = 0; i < 8; i++) {
        lcdChar(v75[i]);
    }
   lcdCommand(0x50); //Configura para a primeira posição de memória
   for (i = 0; i < 8; i++) {
        lcdChar(v50[i]);
    }
   lcdCommand(0x58); //Configura para a primeira posição de memória
   for (i = 0; i < 8; i++) {
        lcdChar(v25[i]);
    }
   lcdCommand(0x60); //Configura para a primeira posição de memória
   for (i = 0; i < 8; i++) {
        lcdChar(aquecer[i]);
    }
      lcdCommand(0x68); //Configura para a primeira posição de memória
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

