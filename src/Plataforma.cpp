//
//  Plataforma.cpp
//  Ninja
//
//  Created by Edison Shiobara on 05/09/26.
//

#include "Plataforma.hpp"

Plataforma::Plataforma():ativa(true){
    this->setTam(CoordF(500.f,100.f));
    this->setPos(CoordF(600.f,500.f));
    hitbox = new sf::RectangleShape;
    hitbox->setSize(sf::Vector2f(500.f,100.f));
    hitbox->setOrigin(0.f,0.f);
    hitbox->setPosition(pos.x, pos.y);
    hitbox->setFillColor(sf::Color::Blue);
    
}

Plataforma::Plataforma(CoordF p,CoordF t):ativa(true){
    this->setTam(t);
    this->setPos(p);
    hitbox = new sf::RectangleShape;
    hitbox->setSize(sf::Vector2f(t.x,t.y));
    hitbox->setPosition(p.x, p.y);
    hitbox->setOrigin(0.f,0.f);
    hitbox->setFillColor(sf::Color::Green);
}

Plataforma::~Plataforma(){}

void Plataforma::executar(){
    pGG->render(hitbox);
}

void Plataforma::obstruir(Jogador* pJog){
    if(!ativa){
        return;
    }

    CoordF posJog = pJog->getPos();
    CoordF tamJog = pJog->getTam();
    CoordF posPlat = this->getPos();
    CoordF tamPlat = this->getTam();

    float esqJog   = posJog.x - tamJog.x / 2.f;
    float dirJog   = posJog.x + tamJog.x / 2.f;
    float topoJog  = posJog.y - tamJog.y / 2.f;
    float baseJog  = posJog.y + tamJog.y / 2.f;

    float esqPlat  = posPlat.x - tamPlat.x / 2.f;
    float dirPlat  = posPlat.x + tamPlat.x / 2.f;
    float topoPlat = posPlat.y - tamPlat.y / 2.f;
    float basePlat = posPlat.y + tamPlat.y / 2.f;

    bool sobrepondoX = dirJog > esqPlat && esqJog < dirPlat;
    bool sobrepondoY = baseJog > topoPlat && topoJog < basePlat;

    if(!sobrepondoX || !sobrepondoY){
        return; // nao esta encostando, nada a fazer
    }

    float sobraEsquerda = dirJog - esqPlat;   // jogador entrou vindo da esquerda
    float sobraDireita  = dirPlat - esqJog;   // jogador entrou vindo da direita
    float sobraCima     = baseJog - topoPlat; // jogador entrou vindo de cima
    float sobraBaixo    = basePlat - topoJog; // jogador entrou vindo de baixo

    float menorSobraX;
    if(sobraEsquerda < sobraDireita){
        menorSobraX = sobraEsquerda;
    } else {
        menorSobraX = sobraDireita;
    }

    float menorSobraY;
    if(sobraCima < sobraBaixo){
        menorSobraY = sobraCima;
    } else {
        menorSobraY = sobraBaixo;
    }

    if(menorSobraX < menorSobraY){
        // a menor invasao foi horizontal -> empurra pro lado
        if(sobraEsquerda < sobraDireita){
            pJog->setPos(CoordF(esqPlat - tamJog.x / 2.f, posJog.y));
        } else {
            pJog->setPos(CoordF(dirPlat + tamJog.x / 2.f, posJog.y));
        }
        pJog->frearHorizontal();

    } else {
        // a menor invasao foi vertical -> empurra pra cima ou pra baixo
        if(sobraCima < sobraBaixo){
            pJog->setPos(CoordF(posJog.x, topoPlat - tamJog.y / 2.f));
            pJog->aterrissar();       // pousou em cima
        } else {
            pJog->setPos(CoordF(posJog.x, basePlat + tamJog.y / 2.f));
            pJog->frearVertical();    // bateu a cabeça por baixo
        }
    }
}//funcao feita pelo claude

void Plataforma::update(float dt){}
