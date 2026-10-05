//
//  Espinho.cpp
//  Ninja
//
//  Created by Edison Shiobara on 17/09/26.
//

#include "Espinho.hpp"


Espinho::Espinho():afiado(1){
    id = 4;
    danoso = true;
    sprite = new SingleFrameAnimation("../assets/Telas/espinhos.png",CoordF(800,700),CoordF(300,200), 1.0);
}
Espinho::Espinho(CoordF p,int a){
    id = 4;
    afiado =a;
    this->setPos(p);
    pos.y = pos.y-40;
    pos.x = pos.x+20;
    danoso = true;
    if(afiado==0){
        sprite = new SingleFrameAnimation("../assets/Telas/espinhospequenos.png",CoordF(p),CoordF(200,50), 1.0);
    }
    else{
        sprite = new SingleFrameAnimation("../assets/Telas/espinhosvermelhos.png",CoordF(p),CoordF(200,50), 1.0);

    }
    this->setTam(CoordF(250.f,50.f));
    /*
    hitbox = new sf::RectangleShape;
    hitbox->setSize(sf::Vector2f(200,50));
    hitbox->setOrigin(0,0);
    hitbox->setPosition(p.x+tam.x/2,p.y+800);
    
    hitbox->setFillColor(sf::Color::Green);
     */
}

Espinho::~Espinho(){
    if(sprite){
        delete sprite;
        sprite = NULL;
    }
}

void Espinho::obstruir(Personagem* pJog){
    pJog->tomarDano();
    
}

void Espinho::executar(){
    
}

void Espinho::update(float dt){}
