#include "velocidade.h"
#include "lcd.h"


void velocidade (int vel){
    lcdPosition(1,0);
    //ajusta o PWM de acordo com o intervalo da temperatura
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