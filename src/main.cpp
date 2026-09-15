#include <iostream>
#include "FasePrimeira.hpp"

int main(){
    srand(0);

    Fase* pFase = new FasePrimeira();
    pFase->rodar();
    delete pFase;

    return 0;
}
