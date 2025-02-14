#include "tp.h"
#include "MKL25Z4.H"

int sent [4] = {1,2,3,4};
int senh [4] = {5,6,7,8};

int temp [3];
int hume [3];

int senstemp(){

    SIM -> SCGC5 |= SIM_SCGC5_PORTE_MASK;
    for(int i; i < 4; i++){
    
        PORTE -> PCR[sent[i]] |= (1<<8); 
        PTE -> PDDR &=~(1u<<sent[i]); // entrada
    }
    int aux = PTE -> PDIR & (1 << sent[3]);
    if(aux == 1){

        for(int i = 0; i<3 ; i++){
            temp[i] = PTE -> PDIR & (1 << sent[i]);
        }
      int aux1 = temp[0] * 1;
      int aux2 = temp[1] * 2;
      int aux3 = temp[2] * 4;
      int auxt = aux1 + aux2 + aux3;

      switch (auxt) {
      case 0:    return 'v';    break;
      case 1:    return 'v';    break;
      case 2:    return 'a';    break;
      case 3:    return 'a';    break;
      case 4:    return 'n';    break;
      case 5:    return 'n';    break;
      case 6:    return 'r';    break;
      case 7:    return 'r';    break;

      default:
    
        break;
      }
    } else {
        return 0;
    }
}

int senshum(){
    SIM -> SCGC5 |= SIM_SCGC5_PORTB_MASK;   
        for(int i; i < 4; i++){

            PORTB -> PCR[senh[i]] |= (1<<8); 
            PTB -> PDDR &=~(1u<<senh[i]); // entrada
        }
        int aux = PTB -> PDIR & (1 << senh[3]);
        if(aux == 0){
    
            for(int i = 0; i<3 ; i++){
                hume[i] = PTB -> PDIR & (1 << senh[i]);
            }
          int aux1 = hume[0] * 1;
          int aux2 = hume[1] * 2;
          int aux3 = hume[2] * 4;
          int auxt = aux1 + aux2 + aux3;
    
          switch (auxt)
          {
          case 0:    return 'v';    break;
          case 1:    return 'v';    break;
          case 2:    return 'a';    break;
          case 3:    return 'a';    break;
          case 4:    return 'n';    break;
          case 5:    return 'n';    break;
          case 6:    return 'r';    break;
          case 7:    return 'r';    break;
    
          default:
            break;
          }
        } else {
            return 0;
        }
    }