//
//  Jogador.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Jogador.hpp"

Jogador::Jogador():pontos(0),andando(false),atacando(false){
    id=1;
    animacao.addNewAnimation(Animation_ID::walk,"../assets/Samurai/RUN.png",16);
    animacao.addNewAnimation(Animation_ID::idle,"../assets/Samurai/IDLE.png",10);
    animacao.addNewAnimation(Animation_ID::hurt,"../assets/Samurai/HURT.png",4);
    animacao.addNewAnimation(Animation_ID::attack,"../assets/Samurai/ATTACK 1.png",7);
    //pos = CoordF(960.f,900.f);
    pos= CoordF(600,300);
}
Jogador::~Jogador(){}

bool Jogador::estaAndando(){
    return andando;
}

bool Jogador::estaAtacando(){
    return atacando;
}

void Jogador::update(float dt){
    Animation_ID estadoAtual;

    if (Jogador::estaAtacando()) {
        estadoAtual = Animation_ID::attack;
    } else if (estaAndando()) {
        estadoAtual = Animation_ID::walk;
    } else {
        estadoAtual = Animation_ID::idle;
    }

    animacao.update(estadoAtual, olhandoesquerda, pos, dt);
}
void Jogador::executar(){}

