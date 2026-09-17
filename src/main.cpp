#include <iostream>
#include "FasePrimeira.hpp"

int main(){
    time_t t;
    srand(time(NULL));

    Fase* pFase = new FasePrimeira();
    pFase->rodar();
    delete pFase;

    return 0;
}
