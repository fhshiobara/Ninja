//
//  Inimigo.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Inimigo.hpp"

Inimigo::Inimigo():maldade(5),ativo(false),posAnt(pos),stun(NULL),stunado(false){
    stun = new Efeitos(6 * 0.15f);   // duracao do stun
}

Inimigo::~Inimigo(){
    if(stun!=NULL){
        delete stun;
        stun = NULL;
    }
}

void Inimigo::stunnar(){
    if(stunado) return;              // ja stunnado: nao reinicia o tempo
    stunado = true;

    // cancela o que estava fazendo
    atacando = false;
    tempoAtaque = 0.f;
    if(atk!=NULL){ atk->desativar(); }
    andandoDireita = false;
    andandoEsquerda = false;
    subindo = false;
    vel.x = 0.f;
    vel.y = 0.f;

    if(stun!=NULL){ stun->ativar(pos, tam); }
}

void Inimigo::atualizarStun(float dt){
    if(stunado && stun!=NULL){
        stun->seguir(pos, tam);
        stun->update(dt);
        if(!stun->estaAtivo()){
            stunado = false;
        }
    }
}

bool Inimigo::estaStunado() const{
    return stunado;
}

Efeitos* Inimigo::getStun(){
    return stun;
}

void Inimigo::olhar(Jogador* pJog){
    if(!atacando && !stunado){
        float dx = pos.x - pJog->getPos().x;
        if(dx<0){
            olhandoesquerda = false;
        }
        else{
            olhandoesquerda = true;
        }
    }
}
