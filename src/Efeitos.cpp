//
//  Efeitos.cpp
//  Ninja
//
//  Created by Edison Shiobara on 28/09/26.
//

#include "Efeitos.hpp"
Efeitos::Efeitos():tempoDecorrido(0.f), ativo(false),duracao(3.f){
    id =5;
    animacao.addNewAnimation(Animation_ID::idle,"../assets/Effect/statusfx_stunned_sheet.png",8);
}

Efeitos::~Efeitos(){}

void Efeitos::executar(){
    
}

void Efeitos::update(float dt){
    Animation_ID estado;
    if(ativo){
        estado=Animation_ID::idle;
        animacao.update(estado, olhandoesquerda, pos, dt);
    }
    
    
}

void Efeitos::setAtivo(bool a){
    ativo = a;
}

void Efeitos::ativar(){
    if(!ativo){
        ativo = true;
        tempoDecorrido = 8* 0.15;
    }
}
