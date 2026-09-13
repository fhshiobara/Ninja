//
//  Plataforma.cpp
//  Ninja
//
//  Created by Edison Shiobara on 05/09/26.
//

#include "Plataforma.hpp"

Plataforma::Plataforma():ativa(true),sprite(NULL),terra(NULL){
    id = 2;
    this->setTam(CoordF(3000.f,100.f));
    this->setPos(CoordF(150.f,800.f));
    hitbox = new sf::RectangleShape;
    hitbox->setSize(sf::Vector2f(3000.f,100.f));
    hitbox->setOrigin(0.f,0.f);
    hitbox->setPosition(pos.x, pos.y);
    hitbox->setFillColor(sf::Color::Black);
    sprite = new SingleFrameAnimation("../assets/Telas/terrafinal.png", CoordF(pos.x,pos.y), CoordF(900,400), 1.0);
    
}

Plataforma::Plataforma(CoordF p,CoordF t):ativa(true),terra(NULL){
    this->setTam(t);
    this->setPos(p);
    hitbox = new sf::RectangleShape;
    hitbox->setSize(sf::Vector2f(t.x,t.y));
    hitbox->setPosition(p.x, p.y);
    hitbox->setOrigin(0.f,0.f);
    hitbox->setFillColor(sf::Color::Green);
    sprite = new SingleFrameAnimation("../assets/Telas/terrafinal.png", CoordF(pos.x-36,pos.y-60), CoordF(t.x+80,400), 1.0);
    if(pos.y-20+tam.y<1060){
        terra = new SingleFrameAnimation("../assets/Telas/terra.png", CoordF(pos.x-60,pos.y+tam.y+50), CoordF(t.x+120,300), 1.0);
        
    }
    
}

Plataforma::~Plataforma(){
    if(sprite){
        delete sprite;
        sprite = NULL;
    }
    if(terra){
        delete terra;
        terra = NULL;
    }
}

void Plataforma::executar(){
    pGG->render(hitbox);
}

void Plataforma::obstruir(Personagem* pJog){
    if(!ativa){
        return;
    }

    CoordF posJog = pJog->getPos();
    CoordF tamJog = pJog->getTam();
    CoordF posPlat = this->getPos();
    CoordF tamPlat = this->getTam();

        // Jogador: pos é o CENTRO do sprite (Animation centraliza a origem)
    float esqJog   = posJog.x - tamJog.x / 2.f;
    float dirJog   = posJog.x + tamJog.x / 2.f;
    float topoJog  = posJog.y - tamJog.y / 2.f;
    float baseJog  = posJog.y + tamJog.y / 2.f;

        // Plataforma: pos é o CANTO SUPERIOR ESQUERDO (hitbox usa origin 0,0)
    float esqPlat  = posPlat.x;
    float dirPlat  = posPlat.x + tamPlat.x;
    float topoPlat = posPlat.y;
    float basePlat = posPlat.y + tamPlat.y;

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
        //pJog->frearHorizontal();

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
    pJog->frearHorizontal();
}//funcao feita pelo claude

void Plataforma::update(float dt){}

void Plataforma::render(){
    /*if(hitbox){
        pGG->render(hitbox);
    }*/
    
    if(sprite){
        sprite->render();
    }
    if(terra){
        terra->render();
    }
    
}
