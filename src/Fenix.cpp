//
//  Fenix.cpp
//  Ninja
//
//  Created by Edison Shiobara on 06/10/26.
//

#include "Fenix.hpp"

Fenix::Fenix():altura(5),aux(0){
    animacao.addNewAnimation(Animation_ID::idle, "../assets/Passaro/IDLE.png", 4);
    animacao.addNewAnimation(Animation_ID::walk, "../assets/Passaro/WALK.png", 4);
    animacao.addNewAnimation(Animation_ID::attack, "../assets/Passaro/ATTACK.png", 8);
    animacao.addNewAnimation(Animation_ID::death, "../assets/Passaro/DEATH.png", 9);
    animacao.addNewAnimation(Animation_ID::hurt, "../assets/Passaro/COMEMORAR.png", 4);
    nochao = false;
    pos = CoordF(800,600);
    this->nochao = false;
    this->setTam(CoordF(60.f,150.f));
    hitbox->setSize(sf::Vector2f(tam.x,tam.y));
    this->criarAtaque(CoordF(120.f,80.f), 6 * 0.15f, 4 * 0.15f);
    
}
Fenix::Fenix(CoordF p){
    animacao.addNewAnimation(Animation_ID::idle, "../assets/Passaro/IDLE.png", 4);
    animacao.addNewAnimation(Animation_ID::walk, "../assets/Passaro/WALK.png", 4);
    animacao.addNewAnimation(Animation_ID::attack, "../assets/Passaro/ATTACK.png", 8);
    animacao.addNewAnimation(Animation_ID::death, "../assets/Passaro/DEATH.png", 9);
    animacao.addNewAnimation(Animation_ID::hurt, "../assets/Passaro/COMEMORAR.png", 4);
    nochao = false;
    pos = CoordF(800,600);
    this->nochao = false;
    this->setPos(p);
    hitbox->setSize(sf::Vector2f(tam.x,tam.y));
    this->criarAtaque(CoordF(120.f,80.f), 6 * 0.15f, 4 * 0.15f);
}

Fenix::~Fenix(){}

void Fenix::update(float dt){
    Animation_ID estadoAtual;
    if(vivo){
        if(tomandoDano){
            estadoAtual = Animation_ID::hurt;
        }else if(this->estaAtacando()){
            estadoAtual = Animation_ID::attack;
        } else if(estaAndando()){
            estadoAtual = Animation_ID::walk;
        }/*
        else if(!nochao){
            estadoAtual = Animation_ID::jump;
        }*/
        
        else {
            estadoAtual = Animation_ID::idle;
        }
        animacao.update(estadoAtual, olhandoesquerda, pos, dt);

        
    }else{
        estadoAtual = Animation_ID::death;
        aux++;
        if(aux<=220){
            animacao.update(estadoAtual, olhandoesquerda, pos, dt);

        }
        
    }
    
}

void Fenix::executar(){
    if(estaStunado()) return;

    // sem gravidade, sem pular, sem nochao
    vel.x = olhandoesquerda ? -1.f : 1.f;
   // vel.y = 0.f;// ou uma ondulação, ex.: sin(tempo) * 0.5f
    this->mover();
    //vel.y=0;
}
void Fenix::danificar(Jogador* pJog){
    //aq quero que se está em cima do jogador a ave de um dash pra baixo.
    if((pJog->getPos().y<this->getPos().y)){
        vel.y = -0.3;
    }
    else if(this->getPos().y+100<pJog->getPos().y){
        vel.y=0.3f;
    }//isso fez o negocio ficar senoidal, eu acho
    //ta bom, lembra o suficiente um seno
}


