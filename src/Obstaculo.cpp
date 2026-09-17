//
//  Obstaculo.cpp
//  Ninja
//
//  Created by Edison Shiobara on 05/09/26.
//

#include "Obstaculo.hpp"

Obstaculo::Obstaculo():danoso(false),sprite(NULL){}

Obstaculo::~Obstaculo(){}

bool Obstaculo::getDanoso(){
    return danoso;
}

void Obstaculo::render(){
    if(sprite!=NULL){
        sprite->render();
    }
}
