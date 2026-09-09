//
//  Ataque.cpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#include "Ataque.hpp"

Ataque::Ataque(CoordF t,CoordF p,float duracao, float dt):tempo(duracao){
    // tam e pos são os mesmos atributos que Jogador/Mago usam,
    // então renderHitbox() e getPos()/getTam() já funcionam de graça.
    this->setTam(t);
    this->setPos(p);
    hitbox->setSize(sf::Vector2f(t.x,t.y));
    hitbox->setFillColor(sf::Color::Transparent);
    hitbox->setOutlineColor(sf::Color::Red);
    hitbox->setOutlineThickness(1.0f);
}
Ataque::~Ataque(){}
 
void Ataque::update(float dt){
    tempo -= dt;
}
 
void Ataque::executar(){

}
 
bool Ataque::acabou()const{
    return tempo <= 0.f;
}
