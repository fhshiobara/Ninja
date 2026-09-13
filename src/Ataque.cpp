//
//  Ataque.cpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#include "Ataque.hpp"

Ataque::Ataque(CoordF tamanho, float duracao):tempo(0.f),duracaoBase(duracao),ativo(false){
    // tam e pos são os mesmos atributos que Jogador/Mago usam,
    // então renderHitbox() e getPos()/getTam() já funcionam de graça.
    this->setTam(tamanho);
    hitbox->setSize(sf::Vector2f(tamanho.x,tamanho.y));
    hitbox->setFillColor(sf::Color::Transparent);
    hitbox->setOutlineColor(sf::Color::Red);
    hitbox->setOutlineThickness(1.0f);
}
Ataque::~Ataque(){}

void Ataque::ativar(CoordF posPersonagem, CoordF tamanhoPersonagem, bool olhandoesquerda){
    // distância do centro do personagem até o centro da hitbox de ataque:
    // metade do personagem + metade do ataque, pra ela ficar "colada" na frente dele
    float offsetX = (tamanhoPersonagem.x/2.f) + (tam.x/2.f);

    CoordF novaPos = olhandoesquerda
        ? CoordF(posPersonagem.x - offsetX, posPersonagem.y)
        : CoordF(posPersonagem.x + offsetX, posPersonagem.y);

    this->setPos(novaPos);
    tempo = duracaoBase;
    ativo = true;
}

void Ataque::desativar(){
    ativo = false;
}

bool Ataque::estaAtivo()const{
    return ativo;
}

void Ataque::update(float dt){
    if(ativo){
        tempo -= dt;
        if(tempo <= 0.f){
            ativo = false;
        }
    }
}

void Ataque::executar(){

}

void Ataque::render(){
    if(ativo){
        this->renderHitbox();
    }
}

bool Ataque::acabou()const{
    return !ativo;
}
