#include "p.h"
#include "MKL25Z4.h"

int main(){

NVIC_EnableIRQ(PORTA_IRQn);
NVIC_EnableIRQ(PORTB_IRQn);

NVIC_SetPriority(PORTA_IRQn,1);
NVIC_SetPriority(PORTB_IRQn,0);

PORTA-> PCR[1] |= PORT_PCR_MUX(1) | PORT_PCR_IRQC(0b1101);
PORTB-> PCR[1] |= PORT_PCR_MUX(1) | PORT_PCR_IRQC(0b1010);

int flag = 0;

while(1){
if(flag == 0){
    if(inte == 0){
        asc();
    } else {
        des();
    }
}

flag = 0;
}

void PORTA_IRQHandler(){
    if(PORTA -> ISFR & (1<<1)){
        PORTA -> ISFR |= (1<<1);
        flag = 1
    }
}

void PORTB_IRQHandler(){
    if(PORTB -> ISFR & (1<<1)){
        PORTB -> ISFR |= (1<<1);
            for (int t = 0; t < 7; t++){
                PTA -> PCOR (1<<dis1[t]);
                PTA -> PCOR (1<<dis2[t]);
            }
    }
}
}
