//
//  Plataforma.cpp
//  Ninja
//
//  Created by Edison Shiobara on 05/09/26.
//

#include "Plataforma.hpp"

Plataforma::Plataforma():ativa(false){}

Plataforma::~Plataforma(){}

void Plataforma::executar(){
    
}

void Plataforma::obstruir(Jogador* pJog){
    float cantoEsq = this->getPos().x;
    if(pJog->getPos().x>cantoEsq || pJog->getPos().x<cantoEsq+(this->tam.x)){
        
    }
        
    
}
