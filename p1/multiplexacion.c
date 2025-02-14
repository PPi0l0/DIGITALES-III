int matriz [4][4] = {
    {7,8,9,},
    {4,5,6,},
    {1,2,3,},
};
int filas [3] = {1,2,3};
int colum [3] = {5,6,7};

int leds [4] = {8,9,10,11};

for(int i = 0; i < 3; i++){
    PORTA -> PCR[filas[i]] |= (1 << 8); 
    PTA -> PDDR &= ~(1u << filas[i]);
    PTA -> PSOR |= (1u<< filas[i]);
    
    PORTA -> PCR[colum[i]] |= (1 << 8); 
    PTA -> PDDR |= (1u << colum[i]);
    PTA -> PSOR |= (1u<< colum[i]);
}

for(int l = 0; l < 4; l++){
    PORTA -> PCR[leds[i]] |= (1 << 8);
    PTA -> PDDR &= ~(1u << leds[i]); 
}

int main(){
    for(int i = 0; i < 3 ; i++){
        PTA -> PSOR &=~(1u<<filas[i]);

        for(int j = 0; j < 3 ; j++){
            int aux = PTA -> PDIR & (1 << colum[i]);
            if(aux == 0){
                switch (matriz[j][i])
                {
                case 1:
                    PTA -> PSOR |= (1u<<leds[0]);
                    PTA -> PCOR (1<<leds[1]);
                    PTA -> PCOR (1<<leds[2]);
                    PTA -> PCOR (1<<leds[3]);
                break;
                case 2:
                    PTA -> PCOR (1<<leds[0]);
                    PTA -> PSOR |= (1u<<leds[1]);
                    PTA -> PCOR (1<<leds[2]);
                    PTA -> PCOR (1<<leds[3]);
                break;
                case 3:
                    PTA -> PSOR |= (1u<<leds[0]);
                    PTA -> PSOR |= (1u<<leds[1]);
                    PTA -> PCOR (1<<leds[2]);
                    PTA -> PCOR (1<<leds[3]);
                break;
                case 4:
                    PTA -> PCOR (1<<leds[0]);
                    PTA -> PCOR (1<<leds[1]);
                    PTA -> PSOR |= (1u<<leds[2]);
                    PTA -> PCOR (1<<leds[3]);
                break;
                case 5:
                    PTA -> PSOR |= (1u<<leds[0]);
                    PTA -> PCOR (1<<leds[1]);
                    PTA -> PSOR |= (1u<<leds[2]);
                    PTA -> PCOR (1<<leds[3]);
                break;
                case 6:
                    PTA -> PCOR (1<<leds[0]);
                    PTA -> PSOR |= (1u<<leds[1]);
                    PTA -> PSOR |= (1u<<leds[2]);
                    PTA -> PCOR (1<<leds[3]);
                break;
                case 7:
                    PTA -> PSOR |= (1u<<leds[0]);
                    PTA -> PSOR |= (1u<<leds[1]);
                    PTA -> PSOR |= (1u<<leds[2]);
                    PTA -> PCOR (1<<leds[3]);
                break;
                case 8:
                    PTA -> PCOR (1<<leds[0]);
                    PTA -> PCOR (1<<leds[1]);
                    PTA -> PCOR (1<<leds[2]);
                    PTA -> PSOR |= (1u<<leds[3]);
                break;
                case 9:
                    PTA -> PCOR (1<<leds[0]);
                    PTA -> PCOR (1<<leds[1]);
                    PTA -> PCOR (1<<leds[2]);
                    PTA -> PSOR |= (1u<<leds[3]);
                break;
                
                default:
                    break;
                }
            }
        }
        PTA -> PSOR |= (1u<<filas[i]);
    }

}
