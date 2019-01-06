#include "FeldImpl.h"


int main() {
     Feld* feld1 = new FeldImpl(3);
     std::cout <<"1: " << *feld1 << std::endl;
     for(int i=0; i<feld1->laenge(); i++) {
         (*feld1)[i] = 10*(i+1);
         }
    std::cout <<"2: " << *feld1 << std::endl;
     delete feld1;

   FeldImpl feld2(2), feld3(3);
     for(int i=0; i<feld2.laenge(); i++)
         {
         feld2[i] = 100*(i+1);
        }
   for(int i=0; i<feld3.laenge(); i++)
         {
         feld3[i] = 1000*(i+1);
         }
   std::cout <<"3: " << feld2 << " " << feld3 << std::endl;
    feld2 = std::move(feld3);
     std::cout <<"4: " << feld2 << " " << feld3 << std::endl;
   feld2 = std::move(feld2);
    std::cout <<"5: " << feld2 << std::endl;
}