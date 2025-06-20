#include <avr/io.h>
#include "bits.h"
#include "Semaforo.h"

void semaforoInit(void){
    for(int d=1; d<=5;d++){
        SETBIT(DDRC, d, 1);    // Configura PC1 a PC5 como saída
        SETBIT(PORTC, d, 0);   // Inicializa desligado
    }
}

void setLight(unsigned char bit, unsigned char value){
    SETLIGHT(PORTC, bit, value);
}



