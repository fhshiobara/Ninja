//
//  Ente.cpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#include "Ente.hpp"

Ente::Ente():id(0),pGG(Gerenciadores::GerenciadorGrafico::getInstance()),hitbox(NULL),tam(0.f,0.f){
}
Ente::~Ente(){
    if(hitbox!=NULL){
        delete hitbox;
        hitbox = NULL;
    }
}

void Ente::setPGG(Gerenciadores::GerenciadorGrafico* p){
    pGG= p;
}

void Ente::desenhar(){
    if(pGG->windowopen()){
        if(hitbox!=NULL){
            pGG->render(hitbox);
        }else{
            std::cout<<"hitbox nao existe ainda"<<std::endl;
        }
    }std::cout<<"erro, janela ainda nao foi aberta"<<std::endl;
}

void Ente::criarHitbox(){
    hitbox = new sf::RectangleShape;
    hitbox->setOrigin(0.f,0.f);
    hitbox->setPosition(0.f,0.f);
    hitbox->setOutlineColor(sf::Color::Green);
    hitbox->setOutlineThickness(1.0f);
}

