//
//  Fase.cpp
//  Ninja
//
//  Created by Edison Shiobara on 11/09/26.
//

#include "Fase.hpp"


Fase::Fase():pGC(NULL),fundo(NULL){
    vEntidades.clear();
    vPlats.clear();
}
Fase::~Fase(){
    vEntidades.clear();
}

void Fase::criarCenario(){
    fundo = new SingleFrameAnimation("../assets/Telas/fase1.png",CoordF(0.f,0.f),CoordF(4000.f,1080.f),1.0);
}
void Fase::criarPlataformas(){
    int aux = 4000 / rand()%8 + 10;
    pJog = new Jogador();
    pJog->setPos(CoordF(50.f,500.f));
    for(int i=0; i<=4000;i= i+aux){
        Plataforma* pNova = NULL;
        pNova = new Plataforma(CoordF(i,gridmap(rand()%4)),CoordF(aux,300));
        vPlats.push_back(pNova);
    }
}


float Fase::gridmap(int aux){
    if(aux == 0){return 700.f;}
    else if(aux == 1){return 800.f;}
    else if(aux == 2){return 600.f;}
    else if(aux == 3){return 550.f;}
    
}
