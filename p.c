#include "p.h"
#include "MKL25Z4.h"        //error?

int interr = 0;

int dis1[7] = {1,2,3,4,5,6,7};
int dis2[7] = {8,9,10,11,12,13,14};

for(int i = 0; i < 7; i++){
    PORTD -> PCR[dis1[i]] |= (1<<8);
    PORTD -> PCR[dis2[i]] |= (1<<8);
    PTD -> PDDR |= (1u<<dis1[i]);
    PTD -> PDDR |= (1u<<dis1[i]);
}

int bcd[10][7] = {
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,0,0,1,1},
};



int asc(){
    int t,s,i,j;

    while(interr = 0){
//------------------------------------------------------------
    for ( t = 0; t < 10; t++) {
        for ( s = 0; s < 7; s++){
            if(bcd[t][s]){
                PTD -> PSOR |= (1u<<dis2[s]);                       //DECENA
            } else {
                PTD -> PCOR (1<<dis2[s]);
            }
        }
//------------------------------------------------------------
            for( i = 0; i<10 ;i++){
                for( j = 0; j<7 ;j++){
                    if(bcd[i][j]){
                        PTD -> PSOR |= (1u<<dis1[j]);
                    } else {                                        //UNIDAD
                        PTD -> PCOR (1<<dis1[j]);
                    }   
                }
                for (int d = 3000000; d > 0; d--);/         //delay de ¿¿1seg??
            }
//------------------------------------------------------------   
    }
}
}

PORTA_IRQHandler(){
    if(PORTA -> ISFR & (1<<30)){
        PORTA -> ISFR |= (1<<30);
        interr = 1;
    }
}