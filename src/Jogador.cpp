//
//  Jogador.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Jogador.hpp"

Jogador::Jogador():pontos(0),defendendo(false),tempoDefesa(0.f){
    id=1;
    animacao.addNewAnimation(Animation_ID::walk,"../assets/Cavaleiro/RUN.png",8);
    animacao.addNewAnimation(Animation_ID::idle,"../assets/Cavaleiro/IDLE.png",7);
    animacao.addNewAnimation(Animation_ID::hurt,"../assets/Cavaleiro/HURT.png",4);
    animacao.addNewAnimation(Animation_ID::attack,"../assets/Cavaleiro/ATTACK 3.png",6);
    animacao.addNewAnimation(Animation_ID::jump,"../assets/Cavaleiro/JUMP.png",5);
    animacao.addNewAnimation(Animation_ID::attack2,"../assets/Cavaleiro/ATTACK 1.png",6);
    animacao.addNewAnimation(Animation_ID::defend,"../assets/Cavaleiro/DEFEND.png",6);
    //pos = CoordF(960.f,900.f);
    pos= CoordF(600,300);
    this->nochao = false;
    this->setTam(CoordF(30.f,60.f));
    hitbox->setSize(sf::Vector2f(tam.x,tam.y));
}
Jogador::~Jogador(){}


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


bool Jogador::golpeAereo(){
    return (atacando && !nochao);
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
    if(defendendo){
        estadoAtual=Animation_ID::defend;
    }
    else if(golpeAereo()){
        estadoAtual = Animation_ID::attack;
    }else if(this->estaAtacando()){
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

void Jogador::defender(){
    if(!defendendo){
        defendendo = true;
        tempoDefesa = 6 * 0.15f;

    }
}

void Jogador::setDefendendo(bool a){
    defendendo = a;
}
