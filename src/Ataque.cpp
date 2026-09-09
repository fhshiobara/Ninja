//
//  Ataque.cpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#include "Ataque.hpp"

Ataque::Ataque(CoordF t,CoordF p,float duracao, float dt):tempo(0.f){
    hitbox->setPosition(sf::Vector2f(p.x,p.y));
    hitbox->setSize(sf::Vector2f(t.x,t.y));
    hitbox->setOutlineColor(sf::Color::Red);
}
Ataque::~Ataque(){}

void Ataque::update(float dt){
}

