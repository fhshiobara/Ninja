//
//  Limites.cpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#include "Limites.hpp"

Limites::Limites():tamMapa(4000,1080){
    lims.clear();
    criarLimitesMapa();
}

Limites::~Limites(){
    it = lims.begin();
    while(it!=lims.end()){
        delete (*it);
        (*it) = NULL;
    }
}


void Limites::criarLimitesMapa(){
    for(int i=0;i<2;i++){
        Plataforma* pPlat = new Plataforma;
        pPlat->setTam(CoordF(4000,10));
        if(i==0){
            pPlat->setPos(CoordF(0.f,1070.f));
        }else{
            pPlat->setPos(CoordF(0.f,0.f));
        }
    }
    for(int j=0;j<2;j++){
        Plataforma* pPlat = new Plataforma;
        pPlat->setTam(CoordF(10,1080));
        if(j==0){
            pPlat->setPos(CoordF(0.f,0.f));
        }else{
            pPlat->setPos(CoordF(3090.f,0.f));
        }
        
    }
}

void Limites::executar(Personagem* pJog){
    for(it=lims.begin();it!=lims.end();it++){
        (*it)->obstruir(pJog);
    }
}
