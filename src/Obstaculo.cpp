//
//  Obstaculo.cpp
//  Ninja
//
//  Created by Edison Shiobara on 05/09/26.
//

#include "Obstaculo.hpp"

Obstaculo::Obstaculo():danoso(false){}

Obstaculo::~Obstaculo(){}

bool Obstaculo::getDanoso(){
    return danoso;
}
