//
//  Entidade.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Entidade.hpp"

Entidade::Entidade():pos(0.f,0.f),vel(0.f,0.f),olhandoesquerda(false){
    
}

Entidade::~Entidade(){
    
}

void Entidade::sincronizar(){
    if(hitbox!=NULL){
        hitbox->setPosition(pos.x, pos.y);
    }
}

void Entidade::mover(){
    pos.x = pos.x+vel.x;
    pos.y = pos.y+vel.y;
}

void Entidade::render(){
    animacao.render();
}
