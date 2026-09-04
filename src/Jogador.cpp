//
//  Jogador.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Jogador.hpp"

Jogador::Jogador():pontos(0){
    id=1;
    animacao.addNewAnimation(Animation_ID::walk,"assets/Samurai/RUN.png",16);
    animacao.addNewAnimation(Animation_ID::idle,"assets/Samurai/IDLE.png",10);
    animacao.addNewAnimation(Animation_ID::hurt,"assets/Samurai/HURT.png",4);
    animacao.addNewAnimation(Animation_ID::attack,"assets/Samurai/ATTACK 1.png",7);
}
Jogador::~Jogador(){}


void Jogador::update(float dt){
    
}
void Jogador::executar(){}
