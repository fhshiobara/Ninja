//
//  Portal.cpp
//  Ninja
//
//  Created by Edison Shiobara on 05/10/26.
//

#include "Portal.hpp"

Portal::Portal():pronto(false){
    danoso = false;
    sprite = new SingleFrameAnimation("../assets/Telas/portal.png",CoordF(3600,300),CoordF(300,300),1.0);
}

Portal::~Portal(){
    if(sprite){
        delete sprite;
        sprite = NULL;
    }
}

void Portal::executar(){}
void Portal::update(float dt){}
void Portal::obstruir(Personagem* pJog){}
