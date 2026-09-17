//
//  Mago.cpp
//  Ninja
//
//  Created by Edison Shiobara on 08/09/26.
//

#include "Mago.hpp"
#include <math.h>

Mago::Mago():experiencia(2),TempoDash(5.f),Dash(0.f),flg(false){
    id = 3;
    animacao.addNewAnimation(Animation_ID::walk,"../assets/Mago/Run.png",8);
    animacao.addNewAnimation(Animation_ID::attack,"../assets/Mago/Attack1.png",8);
    animacao.addNewAnimation(Animation_ID::attack2,"../assets/Mago/Attack2.png",8);
    animacao.addNewAnimation(Animation_ID::death,"../assets/Mago/Death.png",7);
    animacao.addNewAnimation(Animation_ID::idle,"../assets/Mago/Idle.png",8);
    animacao.addNewAnimation(Animation_ID::jump,"../assets/Mago/Jump.png",2);
    pos = CoordF(800,300);
    this->nochao = false;
    this->setTam(CoordF(60.f,150.f));
    hitbox->setSize(sf::Vector2f(tam.x,tam.y));
    this->criarAtaque(CoordF(120.f,80.f), 6 * 0.15f);
    
}

Mago::Mago(CoordF p):experiencia(2),TempoDash(5.f),Dash(0.f){
    id = 3;
    animacao.addNewAnimation(Animation_ID::walk,"../assets/Mago/Run.png",8);
    animacao.addNewAnimation(Animation_ID::attack,"../assets/Mago/Attack1.png",8);
    animacao.addNewAnimation(Animation_ID::attack2,"../assets/Mago/Attack2.png",8);
    animacao.addNewAnimation(Animation_ID::death,"../assets/Mago/Death.png",7);
    animacao.addNewAnimation(Animation_ID::idle,"../assets/Mago/Idle.png",8);
    animacao.addNewAnimation(Animation_ID::jump,"../assets/Mago/Jump.png",2);
    pos = CoordF(p);
    this->nochao = false;
    this->setTam(CoordF(60.f,150.f));
    hitbox->setSize(sf::Vector2f(tam.x,tam.y));
    this->criarAtaque(CoordF(120.f,80.f), 6 * 0.15f);
}
Mago::~Mago(){}

void Mago::update(float dt){
    this->atualizarAtaque(dt);

    this->atualizarSubida(dt);

    Animation_ID estadoAtual;
    if(this->estaAtacando()){
        estadoAtual = Animation_ID::attack2;
        flg = olhandoesquerda;
    } else if(estaAndando()){
        estadoAtual = Animation_ID::walk;
    } else if(!nochao){
        estadoAtual = Animation_ID::jump;
    }else{
        estadoAtual = Animation_ID::idle;
    }
    if(atacando){
        animacao.update(estadoAtual,flg,pos,dt);
        
    }else{
        animacao.update(estadoAtual, olhandoesquerda, pos, dt);
    }
}


void Mago::danificar(Jogador* pJog){
    int aux;
    float dx = pos.x - pJog->getPos().x;
    float dy = pos.y - pJog->getPos().y;
    float dist = sqrt(dx*dx + dy*dy);
    if(dist<300.f){
        ativo = true;
    }
    if(dist<150.f){
        if(!atacando){
            aux = rand()%2;
            if(aux==0){
                ataque2();
            }else{
                atacar();
            }
        }
        
    }
    
    
}



void Mago::executar(){
    nochao = false;

    if(this->getSubindo()){
        this->mover();
    } else {
        this->gravidade();
    }
    if(atacando){
        andandoDireita = false;
        andandoEsquerda = false;
    }
    else if(olhandoesquerda){
        if(ativo){
            andandoDireita = false;
            andandoEsquerda = true;
        }else{
            andandoDireita = false;
            andandoEsquerda = false;
        }
    }else{
        if(ativo){
            andandoEsquerda = false;
            andandoDireita = true;
        }else{
            andandoEsquerda = false;
            andandoDireita = false;
        }
    }

    if(andandoDireita){
        olhandoesquerda = false;
        this->vel.x = 1.f;
        this->mover();
    }
    if(andandoEsquerda){
        olhandoesquerda=true;
        this->vel.x = -1.f;
        this->mover();
    }
}

void Mago::ataque2(){
    this-> pular();
    if(olhandoesquerda){
        vel.x = 1.8f;
    }else{
        vel.x=-1.8f;
    }
    
    this->atacar();
    
}
