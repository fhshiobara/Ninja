//
//  FasePrimeira.cpp
//  Ninja
//
//  Created by Edison Shiobara on 14/09/26.
//

#include "FasePrimeira.hpp"
FasePrimeira::FasePrimeira():numMagos(3){
    criarCenario();
    criarPlataformas();
    criarInimigos();
    criarObstaculos();
}

FasePrimeira::~FasePrimeira(){}

void FasePrimeira::executar() {
    std::vector<Inimigo*>& inis = pGC->getInimigos();
    for (size_t i = 0; i < inis.size(); i++) {
        inis[i]->executar();
    }
}

void FasePrimeira::criarInimigos() {
    for (int i = 0; i < numMagos; i++) {
        Mago* pMago = new Mago(CoordF(900 + rand() % 3100, 690));
        pGC->adicionarInimigo(pMago); // <-- Manda para o gerenciador em vez de vEntidades
    }
}
