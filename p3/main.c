#include "MKL25Z4.h"
#include "tp.h"

int main(){
    SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
    SIM -> SCGC5 |= SIM_SCGC5_PORTB_MASK;
    SIM -> SCGC5 |= SIM_SCGC5_PORTE_MASK;
    int Ledt [4] = {1,3,5,9};
    int Ledh [4] = {2,4,6,8};

    if(sensTemp() != 0){
        char auxx = sensTemp();
        switch (auxx)
        {
        case 'v':
            PORTE -> PSOR |= (1<<ledt[0]);

            PORTE -> PCOR &=(1<<ledt[1]);
            PORTE -> PCOR &=(1<<ledt[2]);
            PORTE -> PCOR &=(1<<ledt[3]);
            delay(500);
            PORTE -> PCOR &=(1<<ledt[0]);
            delay(500);
            break;
        
        case 'a':
            PORTE -> PSOR |= (1<<ledt[1]);

            PORTE -> PCOR &=(1<<ledt[0]);
            PORTE -> PCOR &=(1<<ledt[2]);
            PORTE -> PCOR &=(1<<ledt[3]);
            delay(500);
            PORTE -> PCOR &=(1<<ledt[1]);
            delay(500);
            break;

        case 'n':
            PORTE -> PSOR |= (1<<ledt[2]);

            PORTE -> PCOR &=(1<<ledt[1]);
            PORTE -> PCOR &=(1<<ledt[0]);
            PORTE -> PCOR &=(1<<ledt[3]);
            delay(500);
            PORTE -> PCOR &=(1<<ledt[2]);
            delay(500);
            break;

        case 'r':
            PORTE -> PSOR |= (1<<ledt[3]);

            PORTE -> PCOR &=(1<<ledt[1]);
            PORTE -> PCOR &=(1<<ledt[2]);
            PORTE -> PCOR &=(1<<ledt[0]);
            delay(500);
            PORTE -> PCOR &=(1<<ledt[3]);
            delay(500);
            break;
        default:
            break;
        }

    } else (senshum() != 0){
if(senshum() != 0){
        char auxz = senshum();
        switch (auxz)
        {
        case 'v':
            PORTB -> PSOR |= (1<<ledh[0]);

            PORTB -> PCOR &=(1<<ledh[1]);
            PORTB -> PCOR &=(1<<ledh[2]);
            PORTB -> PCOR &=(1<<ledh[3]);
            delay(500);
            PORTB -> PCOR &=(1<<ledh[0]);
            delay(500);
            break;
        
        case 'a':
            PORTB -> PSOR |= (1<<ledh[1]);

            PORTB -> PCOR &=(1<<ledh[0]);
            PORTB -> PCOR &=(1<<ledh[2]);
            PORTB -> PCOR &=(1<<ledh[3]);
            delay(500);
            PORTB -> PCOR &=(1<<ledh[1]);
            delay(500);
            break;

        case 'n':
            PORTB -> PSOR |= (1<<ledh[2]);

            PORTB -> PCOR &=(1<<ledh[1]);
            PORTB -> PCOR &=(1<<ledh[0]);
            PORTB -> PCOR &=(1<<ledh[3]);
            delay(500);
            PORTB -> PCOR &=(1<<ledh[2]);
            delay(500);
            break;

        case 'r':
            PORTE -> PSOR |= (1<<ledh[3]);

            PORTB -> PCOR &=(1<<ledh[1]);
            PORTB -> PCOR &=(1<<ledh[2]);
            PORTB -> PCOR &=(1<<ledh[0]);
            delay(500);
            PORTB -> PCOR &=(1<<ledh[3]);
            delay(500);
            break;
        default:
            break;
        }
    }
}
}