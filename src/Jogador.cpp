//
//  Jogador.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Jogador.hpp"

Jogador::Jogador():pontos(0),andandoEsquerda(false),andandoDireita(false),atacando(false),tempoAtaque(0.f){
    id=1;
    animacao.addNewAnimation(Animation_ID::walk,"../assets/Cavaleiro/RUN.png",8);
    animacao.addNewAnimation(Animation_ID::idle,"../assets/Cavaleiro/IDLE.png",7);
    animacao.addNewAnimation(Animation_ID::hurt,"../assets/Cavaleiro/HURT.png",4);
    animacao.addNewAnimation(Animation_ID::attack,"../assets/Cavaleiro/ATTACK 3.png",6);
    animacao.addNewAnimation(Animation_ID::jump,"../assets/Cavaleiro/JUMP.png",5);
    //pos = CoordF(960.f,900.f);
    pos= CoordF(600,300);
    this->nochao = false;
    this->setTam(CoordF(64.f,64.f));
}
Jogador::~Jogador(){}

bool Jogador::estaAndando(){
    return andandoDireita || andandoEsquerda;
}

bool Jogador::estaAtacando(){
    return atacando;
}

void Jogador::setAndandoDireita(bool valor){
    frearHorizontal();
    andandoDireita = valor;
    if(valor){ olhandoesquerda = false; }
}

void Jogador::setAndandoEsquerda(bool valor){
    frearHorizontal();
    andandoEsquerda = valor;
    if(valor){ olhandoesquerda = true; }
}

void Jogador::update(float dt){
    if(atacando){
        tempoAtaque -= dt;
        if(tempoAtaque <= 0.f){
            atacando = false;
        }
    }

    this->atualizarSubida(dt);

    Animation_ID estadoAtual;
    if(estaAtacando()){
        estadoAtual = Animation_ID::attack;
    } else if(estaAndando()){
        estadoAtual = Animation_ID::walk;
    } else if(!nochao){
        estadoAtual = Animation_ID::jump;
    } else {
        estadoAtual = Animation_ID::idle;
    }

    animacao.update(estadoAtual, olhandoesquerda, pos, dt);
}
void Jogador::executar(){
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


void Jogador::atacar(){
    if(!atacando){
        atacando = true;
        tempoAtaque = 7 * 0.2f;
    }
}

void Jogador::pular(){
    this->iniciarSubida(0.35f,1.f);
}
