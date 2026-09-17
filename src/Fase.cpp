//
//  Fase.cpp
//  Ninja
//
//  Created by Edison Shiobara on 11/09/26.
//

#include "Fase.hpp"


Fase::Fase():pGC(NULL),fundo(NULL),pJog(NULL),pLim(NULL){
    vEntidades.clear();
    vPlats.clear();
    vObstaculo.clear();
    pLim = new Limites();
}
Fase::~Fase(){
    for(itP=vPlats.begin();itP!=vPlats.end();itP++){
        delete (*itP);
        (*itP) = NULL;
    }
    vPlats.clear();

    for(it=vEntidades.begin();it!=vEntidades.end();it++){
        delete (*it);
        (*it) = NULL;
    }
    for(itO=vObstaculo.begin();itO!=vObstaculo.end();itO++){
        delete (*it);
        (*it) = NULL;
    }
    vEntidades.clear();

    delete pLim;
    pLim = NULL;

    delete pJog;
    pJog = NULL;

    delete fundo;
    fundo = NULL;
    
}

void Fase::criarCenario(){
    fundo = new SingleFrameAnimation("../assets/Telas/fase1.png",CoordF(0.f,0.f),CoordF(4000.f,1080.f),1.0);
}
void Fase::criarPlataformas(){
    int aux = 4000 /(rand()%3 + 5);
    pJog = new Jogador();
    pJog->setPos(CoordF(50.f,500.f));
    for(int i=-10; i<=4000;i= i+aux){
        Plataforma* pNova = NULL;
        pNova = new Plataforma(CoordF(i,gridmap(rand()%4)),CoordF(aux,300));
        vPlats.push_back(pNova);
    }
}

void Fase::tratarEventos(){
    sf::Event evento;
    while(pGraphicM->getWindow()->pollEvent(evento)){

        if(evento.type == sf::Event::Closed){
            pGraphicM->closeWindow();
        }
        else if(evento.type == sf::Event::KeyPressed){
            if(evento.key.code == sf::Keyboard::Right){
                pJog->setAndandoDireita(true);
            }
            else if(evento.key.code == sf::Keyboard::Left){
                pJog->setAndandoEsquerda(true);
            }
            else if(evento.key.code == sf::Keyboard::Z){
                pJog->pular();
            }
            else if(evento.key.code == sf::Keyboard::X){
                pJog->atacar();
            }
            else if(evento.key.code == sf::Keyboard::Space){
                pJog->defender();
            }
        }
        else if(evento.type == sf::Event::KeyReleased){
            if(evento.key.code == sf::Keyboard::Right){
                pJog->setAndandoDireita(false);
            }
            else if(evento.key.code == sf::Keyboard::Left){
                pJog->setAndandoEsquerda(false);
            }
            else if(evento.key.code==sf::Keyboard::Space){
                pJog->setDefendendo(false);
            }
        }
    }
}

void Fase::criarObstaculos(){
    // Verifica se existem plataformas para evitar erro
    if (vPlats.empty()) return;

    int quantidadeEspinhos = 5; // Defina a quantidade desejada
    
    // Proteção: se houver menos plataformas do que espinhos solicitados,
    // reduz a quantidade de espinhos para o total de plataformas
    if (quantidadeEspinhos > static_cast<int>(vPlats.size())) {
            quantidadeEspinhos = static_cast<int>(vPlats.size());
        }

    // Cria um vetor temporário apenas com os índices de 0 até o tamanho de vPlats
    std::vector<int> indicesDisponiveis;
        for (size_t i = 0; i < vPlats.size(); i++) {
            indicesDisponiveis.push_back(static_cast<int>(i));
        }

    // Sorteia os espinhos
    for(int i = 0; i < quantidadeEspinhos; i++){
        // Sorteia um número baseado em quantas opções AINDA restam
        int posicaoSorteio = rand() % indicesDisponiveis.size();
        
        // Pega o índice real da plataforma correspondente àquela posição
        int indiceDaPlataforma = indicesDisponiveis[posicaoSorteio];
        
        // Remove essa opção da lista de disponíveis (para não ser sorteada de novo)
        indicesDisponiveis.erase(indicesDisponiveis.begin() + posicaoSorteio);

        // Acessa a plataforma sorteada
        Plataforma* platEscolhida = vPlats[indiceDaPlataforma];

        CoordF p = platEscolhida->getPos();
        p.x = p.x + (platEscolhida->getTam().x / 2);
        p.y = p.y - 40;
        
        Espinho* pEsp = new Espinho(p);
        vObstaculo.push_back(pEsp);
    }
}
void Fase::atualizar(float dt){
    pJog->update(dt);
    pJog->executar();

    for(it=vEntidades.begin();it!=vEntidades.end();it++){
        (*it)->olhar(pJog);
        (*it)->danificar(pJog);
        (*it)->update(dt);
    }

    for(itP=vPlats.begin();itP!=vPlats.end();itP++){
        (*itP)->obstruir(pJog);
        for(it=vEntidades.begin();it!=vEntidades.end();it++){
            (*itP)->obstruir(*it);
        }
    }
    /*
    for(itO=vObstaculo.begin();itO!=vObstaculo.end();itO++){
        (it*)->executar();
    }*/

    if(pLim){
        pLim->executar(pJog);
    }

    // roda a logica especifica de cada fase (ataques, comportamento dos inimigos, etc.)
    executar();
}

void Fase::renderizar(){
    pGraphicM->clear();
    pGraphicM->seguirCamera(pJog->getPos(), CoordF(4000, 1080));

    if(fundo){ fundo->render(); }

    for(itP=vPlats.begin();itP!=vPlats.end();itP++){
        //(*itP)->renderHitbox();
        (*itP)->render();
        
    }

    //pJog->renderHitbox();
    pJog->render();
    if(pJog->getAtaque()!=NULL){ pJog->getAtaque()->render(); }

    for(it=vEntidades.begin();it!=vEntidades.end();it++){
        //(*it)->renderHitbox();
        (*it)->render();
        if((*it)->getAtaque()!=NULL){ (*it)->getAtaque()->render(); }
    }
    for(itO=vObstaculo.begin();itO!=vObstaculo.end();itO++){
        (*itO)->render();
    }

    pGraphicM->usarViewPadrao();
    pGraphicM->display();
}

void Fase::rodar(){
    relogio.restart();
    while(pGraphicM->windowopen()){
        tratarEventos();

        float dt = relogio.restart().asSeconds();
        atualizar(dt);

        renderizar();
    }
}


float Fase::gridmap(int aux){
    if(aux == 0){return 700.f;}
    else if(aux == 1){return 730.f;}
    else if(aux == 2){return 790.f;}
    else if(aux == 3){return 760.f;}

    return 700.f;
}
