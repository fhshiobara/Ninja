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

void FasePrimeira::executar(){
    for(it=vEntidades.begin();it!=vEntidades.end();it++){
        (*it)->executar();
    }
}

void FasePrimeira::criarInimigos(){
    for(int i=0;i<numMagos;i++){
        Mago* pMago = new Mago(CoordF(900+rand()%3100,690));
        vEntidades.push_back(pMago);
    }
}

