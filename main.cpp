#include <iostream>
#include "Sculptor.h"

using namespace std;

int main(void)
{  
    Sculptor vaca(100, 100, 100);

   // corpo
   vaca.setColor(0.7, 0.48, 0.3, 1.0);
   vaca.putBox(0, 12, 1, 20, 10, 18);
   vaca.setColor(1, 1, 1, 1.0);
   vaca.putBox(0, 1, 1,  -5, 18, 10);

   // cabeça
   vaca.setColor(0.7, 0.48, 0.3, 1.0);
   vaca.putBox(2, 10, 20, 28, 13, 20);
   vaca.setColor(1, 1, 1, 1.0); // cor dos chifres
   vaca.putBox( 0, 2,  25, 28, 19, 23);  // chifre esquerdo
   vaca.putBox( 10, 12,  25, 28, 19, 23); // chifre direito

   // pernas
   vaca.setColor(1, 1, 1, 1.0);
   vaca.putBox(8, 12, 0, 5, 3, 10);    // traseiras
   vaca.putBox(0, 4, 0, 5, 3, 10);     // traseiras
   vaca.putBox(8, 12, 14, 19, 3, 10);  // dianteiras
   vaca.putBox(0, 4, 14, 19, 3, 10);   // dianteiras 

   // olhos
   vaca.setColor(1, 1, 1, 1.0);
   vaca.putVoxel(3, 27, 17);  // olho branco
   vaca.putVoxel(8, 27, 17);  // olho branco

   vaca.setColor(0, 0, 0, 1.0);
   vaca.putVoxel(2, 27, 17);  // olho preto
   vaca.putVoxel(9, 27, 17);  // olho preto

   vaca.writeOFF("vaca.off");
     return 0;
}
