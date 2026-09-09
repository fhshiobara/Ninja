//
//  Inimigo.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Inimigo.hpp"

Inimigo::Inimigo():maldade(5){}

Inimigo::~Inimigo(){}

void Inimigo::olhar(Jogador* pJog){
    float dx = pos.x - pJog->getPos().x;
    float dy = pos.y - pJog->getPos().y;
    if(dx<0){
        olhandoesquerda = false;
    }
    else{
        olhandoesquerda = true;
    }
}
