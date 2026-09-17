//
//  Espinho.cpp
//  Ninja
//
//  Created by Edison Shiobara on 17/09/26.
//

#include "Espinho.hpp"


Espinho::Espinho():afiado(1){
    id = 4;
    danoso = true;
    sprite = new SingleFrameAnimation("../assets/Telas/espinhos.png",CoordF(800,700),CoordF(300,200), 1.0);
}
Espinho::Espinho(CoordF p):afiado(1){
    id = 4;
    this->setPos(p);
    pos.y = pos.y-40;
    danoso = true;
    sprite = new SingleFrameAnimation("../assets/Telas/espinhospequenos.png",CoordF(p),CoordF(200,70), 1.0);
    this->setTam(CoordF(250.f,100.f));
}

Espinho::~Espinho(){
    if(sprite){
        delete sprite;
        sprite = NULL;
    }
}

void Espinho::obstruir(Personagem* pJog){
    
}

void Espinho::executar(){
    
}

void Espinho::update(float dt){}
