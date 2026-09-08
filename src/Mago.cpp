//
//  Mago.cpp
//  Ninja
//
//  Created by Edison Shiobara on 08/09/26.
//

#include "Mago.hpp"

Mago::Mago():experiencia(2){
    id = 3;
    animacao.addNewAnimation(Animation_ID::walk,"../assets/Mago/Run.png",8);
    animacao.addNewAnimation(Animation_ID::attack,"../assets/Mago/Attack1.png",8);
    animacao.addNewAnimation(Animation_ID::attack2,"../assets/Mago/Attack2.png",8);
    animacao.addNewAnimation(Animation_ID::death,"../assets/Mago/Death.png",7);
    animacao.addNewAnimation(Animation_ID::idle,"../assets/Mago/Idle.png",8);
    animacao.addNewAnimation(Animation_ID::jump,"../assets/Mago/Jump.png",2);
    pos = CoordF(800,300);
    this->nochao = false;
    this->setTam(CoordF(88.f,150.f));
    
}
Mago::~Mago(){}

void Mago::update(float dt){
    if(atacando){
        tempoAtaque -= dt;
        if(tempoAtaque <= 0.f){
            atacando = false;
        }
    }

    this->atualizarSubida(dt);

    Animation_ID estadoAtual;
    if(this->estaAtacando()){
        estadoAtual = Animation_ID::attack2;
    } else if(estaAndando()){
        estadoAtual = Animation_ID::walk;
    } else if(!nochao){
        estadoAtual = Animation_ID::jump;
    }else {
        estadoAtual = Animation_ID::idle;
    }

    animacao.update(estadoAtual, olhandoesquerda, pos, dt);
}


void Mago::danificar(Jogador* pJog){}



void Mago::executar(){
    nochao = false;

    if(this->getSubindo()){
        this->mover();
    } else {
        this->gravidade();
    }

    if(andandoDireita){
        this->vel.x = 1.5f;
        this->mover();
    }
    if(andandoEsquerda){
        this->vel.x = -1.5f;
        this->mover();
    }
}



