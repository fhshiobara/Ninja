//
//  Personagem.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Personagem.hpp"
Personagem::Personagem():hp(3),vivo(true),nochao(true){
    
}

Personagem::~Personagem(){}

void Personagem::tomarDano(){
    if(hp>0){
        hp--;
    }
    if(hp<=0){
        vivo=false;
    }
    
}

void Personagem::gravidade(){
    if(!nochao){
        vel.y = 1.f;
        this->mover();
    }
}


