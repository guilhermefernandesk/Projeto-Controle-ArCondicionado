//inclusao das bibliotecas
#include <pic18f4520.h>
#include "lcd.h"
#include "keypad.h"
#include "config.h" 
#include "bits.h"
#include "ssd.h"
#include "timer.h"
#include "velocidade.h"
#include "adc.h"
#include "atraso.h"
#include "desenho.h"
#include "modo.h"
#include "pwm.h"
#include "so.h"

//definindo comandos do lcd
#define L_ON 0x0F
#define L_OFF 0x08
#define L_CLR 0x01
#define L_L1 0x80
#define L_L2 0xC0

void main(void) {
    unsigned int tecla; //variavel para leitura do teclado
    char temp = 16; //variavel par contar o temp
    char slot = 0;  //variavel de execução de atividades
    unsigned  int v=0; //variavel para contar no display
    int m = 0; //variavel de controle dos modos
    int controle = 0; //variavel de controle do tempo
    int vel; //variavel para velocidade do potenciometro
    int d = 0; //variavel para ajuste do tempo no display
    
    lcdInit(); //inicializa lcd
    kpInit(); //inicializa teclado
    ssdInit(); //inicializa os displays
    timerInit(); //inicializa o timer
    adcInit(); //inicializa o adc
    desenhoInit(); //inicializa a biblioteca de layout do lcd
    pwmInit(); //inicializa o pwm
    
    for (;;) {
        timerReset(30000);   
        switch(slot){
            case 0: //contagem do tempo se requisitada
                if(controle != 0){
                    //quando zerar o tempo o buzzer toca 3 vezes
                    if(v==600){ 
                        controle = 0;
                        v = 0;
                        desenhoOff();
                        pwmSet(100);                      
                        atraso_ms(1000);
                        pwmSet(0);
                        atraso_ms(1000);
                        pwmSet(100);                      
                        atraso_ms(1000);
                        pwmSet(0);
                        atraso_ms(1000);
                        pwmSet(100);                      
                        atraso_ms(1000);
                        pwmSet(0);
                    }
                    else{ //diminui o tempo ajustando-se
                        v--;
                        atraso_ms(100);
                    }
                }
                slot = 1; //muda para o display
            break;
            
            case 1: //mostra no display
                ssdDigit(((v/600) %10), 3); //unidade minutos
                ssdDigit(((v/6000)%6), 2);  //dezena minutos
                ssdDigit((((v/36000)%24)%10), 1); //unidade horas
                ssdDigit((((v/36000)%24)/10), 0); //dezena horas
                slot = 2; //muda para o lcd
            break;
            
            case 2: //mostra no lcd a temperatura na primeira linha 
                lcdPosition(0,0);
                lcdChar(((temp/10)%10) + 48); 
                lcdChar ((temp %10) + 48);
                slot = 3; //muda para leitura do teclado
            break;
            
            case 3: //faz a leitura do teclado e suas funções
                kpDebounce();
                if (kpRead() != tecla) {
                    tecla = kpRead();
                    //SW109 aumenta a temperatura até 30ºC
                    if (bitTst(tecla, 0)) {
                        pwmSet(100);
                        atraso_ms(50);
                        pwmSet(0);
                        if(temp != 30){
                            temp++;   
                        }
                    }
                    //SW107 inicia a contagem do timer
                    else if (bitTst(tecla, 1)) {
                        pwmSet(100);
                        atraso_ms(50);
                        pwmSet(0);                        
                        desenhoOn(); //imprime Timer ON no lcd
                        controle = 1;
                        if(d==0){
                            v+=600; //ajuste de 1 minuto
                            d=1;
                        }
                    }
                    //SW105 diminui a temperatura
                    else if (bitTst(tecla, 2)) {
                        pwmSet(100);
                        atraso_ms(50);
                        pwmSet(0);                         
                        if(temp != 15){
                            temp--;                           
                        }   
                    }
                    //SW103 desliga o timer
                    else if (bitTst(tecla, 3)) { 
                        pwmSet(100);
                        atraso_ms(50);
                        pwmSet(0); 
                        desenhoOff();
                        controle = 0;
                    }
                    //SW101 troca os modos de operação
                    else if (bitTst(tecla, 4)) {
                        pwmSet(100);
                        atraso_ms(50);
                        pwmSet(0);  
                        if(m == 3){ //existem 4 modos
                            m = 0;
                        }
                        else{
                          m++;      
                        }          
                    }
                    //SW110 aumenta 5 minutos
                    else if (bitTst(tecla, 5)) {
                        pwmSet(100);
                        atraso_ms(50);
                        pwmSet(0);
                        v+=3000;   
                    }
                    //SW106 diminui 5 minutos
                    else if (bitTst(tecla, 7)) {
                        pwmSet(100);
                        atraso_ms(50);
                        pwmSet(0); 
                        if(v != 0){ 
                            v-=3000;                             
                        }   
                    }
                }
                slot = 4; //muda para velocidade
            break;
            
            case 4: //velocidade do potenciometro
                vel = adcRead(0);
                velocidade(vel);
                slot = 5; //muda para os modos de operações
            break;
            
            case 5: //modo de operação
                modo(m);
                slot = 0;
            break;
         
            default: //padrao
                slot = 0; 
            break;
        }
        ssdUpdate(); //atualiza os displays  
        timerWait();  //espera a contagem do timerReset acabar
    } 
}