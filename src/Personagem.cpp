//
//  Personagem.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Personagem.hpp"
Personagem::Personagem():hp(3),vivo(true),nochao(true),subindo(false),tempoSubida(0.f),atacando(false),andandoDireita(false),andandoEsquerda(false),tempoAtaque(0.f),atk(NULL){
    
}

Personagem::~Personagem(){
    if(atk!=NULL){
        delete atk;
        atk = NULL;
    }
}

void Personagem::tomarDano(){
    if(hp>0){
        hp--;
    }
    if(hp<=0){
        vivo=false;
    }
    
}

void Personagem::gravidade(){
    if(!nochao){
        vel.y = 1.f;
        this->mover();
    }
}

void Personagem::aterrissar(){
    nochao = true;
    this->frearVertical();
}

void Personagem::iniciarSubida(float tempo,float velocidade){
    if(nochao && !subindo){
        subindo = true;
        tempoSubida = tempo;
        vel.y = velocidade * (-1);
        nochao = false;
    }
    
}

void Personagem::atualizarSubida(float dt){
    if(subindo){
        tempoSubida = tempoSubida-dt;
        if(tempoSubida<=0.f){
            subindo = false;
            vel.y=0.f;
        }
    }
}

bool Personagem::getSubindo(){
    return subindo;
}

//subidos de jogador
bool Personagem::estaAndando(){
    return andandoDireita || andandoEsquerda;
}

bool Personagem::estaAtacando(){
    return atacando;
}

void Personagem::setAndandoDireita(bool valor){
    frearHorizontal();
    andandoDireita = valor;
    if(valor){ olhandoesquerda = false; }
}

void Personagem::setAndandoEsquerda(bool valor){
    frearHorizontal();
    andandoEsquerda = valor;
    if(valor){ olhandoesquerda = true; }
}

void Personagem::atacar(){
    if(!atacando){
        atacando = true;
        tempoAtaque = 6 * 0.15f;
        if(atk!=NULL){
            // gera (reposiciona/liga) a hitbox temporária na frente do personagem,
            // do lado pra onde ele está olhando
            atk->ativar(pos, tam, olhandoesquerda);
        }
    }
}

void Personagem::pular(){
    this->iniciarSubida(0.50f,1.f);
}

void Personagem::criarAtaque(CoordF tamanhoAtaque, float duracao){
    // aloca o Ataque uma única vez (elemento "estático" do personagem).
    // Cada subclasse chama isso no seu construtor, escolhendo o tamanho da
    // própria hitbox de ataque, e a partir daí ele só é ativado/desativado.
    if(atk==NULL){
        atk = new Ataque(tamanhoAtaque, duracao);
    }
}

void Personagem::atualizarAtaque(float dt){
    if(atacando){
        tempoAtaque -= dt;
        if(tempoAtaque <= 0.f){
            atacando = false;
            if(atk!=NULL){
                atk->desativar();
            }
        }
    }
    if(atk!=NULL){
        atk->update(dt);
    }
}

Ataque* Personagem::getAtaque(){
    return atk;
}
