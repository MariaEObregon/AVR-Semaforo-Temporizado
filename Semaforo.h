#ifndef SEMAFORO_H
#define SEMAFORO_H

#define RED 5        // Vermelho Semáforo
#define YELLOW 4     // Amarelo Semáforo
#define GREEN 3      // Verde Semáforo
#define RED_PD 2     // Vermelho Pedestre
#define GREEN_PD 1   // Verde Pedestre

#define SETLIGHT(reg, bit, value) value ? (reg|= (1<<bit)):(reg&=~(1<<bit))

void semaforoInit(void);
void setLight(unsigned char bit, unsigned char value);

#endif