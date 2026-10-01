//
//  Efeitos.cpp
//  Ninja
//
//  Created by Edison Shiobara on 28/09/26.
//

#include "Efeitos.hpp"

Efeitos::Efeitos(float duracao):duracao(duracao),tempoRestante(0.f),ativo(false),offsetY(20.f){
    id = 5;
    animacao.addNewAnimation(Animation_ID::idle,"../assets/Effect/statusfx_stunned_sheet.png",8);
}

Efeitos::~Efeitos(){}

void Efeitos::ativar(CoordF posAlvo, CoordF tamAlvo){
    if(!ativo){                    // se ja esta stunnado, nao reinicia o tempo
        ativo = true;
        tempoRestante = duracao;
    }
    seguir(posAlvo, tamAlvo);
}

void Efeitos::desativar(){
    ativo = false;
    tempoRestante = 0.f;
}

void Efeitos::seguir(CoordF posAlvo, CoordF tamAlvo){
    // pos e o CENTRO (mesma convencao de Entidade): fica logo acima da hitbox do alvo
    pos = CoordF(posAlvo.x, posAlvo.y - tamAlvo.y/2.f - offsetY+100);
}

void Efeitos::update(float dt){
    if(ativo){
        tempoRestante -= dt;
        if(tempoRestante <= 0.f){
            desativar();
            return;
        }
        animacao.update(Animation_ID::idle, olhandoesquerda, pos, dt);
    }
}

void Efeitos::executar(){

}

void Efeitos::render(){
    if(ativo){
        animacao.render();
    }
}

bool Efeitos::estaAtivo() const{
    return ativo;
}

void Efeitos::setDuracao(float d){
    duracao = d;
}
