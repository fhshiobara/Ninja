//
//  Fase.cpp
//  Ninja
//
//  Created by Edison Shiobara on 11/09/26.
//

#include "Fase.hpp"


Fase::Fase(): pGC(Gerenciadores::GerenciadorColisoes::getInstance()), fundo(NULL), pJog(NULL), pLim(NULL) {
    pLim = new Limites();
}

Fase::~Fase() {
    // 1. Pega as referências dos vetores do Gerenciador
    std::vector<Plataforma*>& plats = pGC->getPlataformas();
    std::vector<Inimigo*>& inis = pGC->getInimigos();
    std::vector<Obstaculo*>& obs = pGC->getObstaculos();

    // 2. Deleta todos os objetos alocados
    for (size_t i = 0; i < plats.size(); i++) {
        delete plats[i];
    }
    for (size_t i = 0; i < inis.size(); i++) {
        delete inis[i];
    }
    for (size_t i = 0; i < obs.size(); i++) {
        delete obs[i];
    }

    // 3. Pede para o gerenciador limpar a lista de ponteiros vazios
    pGC->limpar();

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
    pGC->setJogador(pJog);
    pJog->setPos(CoordF(50.f,500.f));
    for(int i=-10; i<=3900;i= i+aux){
        Plataforma* pNova = NULL;
        pNova = new Plataforma(CoordF(i,gridmap(rand()%4)),CoordF(aux,300));
        pGC->adicionarPlataforma(pNova);
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

void Fase::criarObstaculos() {
    std::vector<Plataforma*>& plats = pGC->getPlataformas();
    if (plats.empty()) return;

    int quantidadeEspinhos = 5;
    
    if (quantidadeEspinhos > static_cast<int>(plats.size())) {
        quantidadeEspinhos = static_cast<int>(plats.size());
    }

    std::vector<int> indicesDisponiveis;
    for (size_t i = 0; i < plats.size(); i++) {
        indicesDisponiveis.push_back(static_cast<int>(i));
    }

    for(int i = 0; i < quantidadeEspinhos; i++){
        int posicaoSorteio = rand() % indicesDisponiveis.size();
        int indiceDaPlataforma = indicesDisponiveis[posicaoSorteio];
        indicesDisponiveis.erase(indicesDisponiveis.begin() + posicaoSorteio);

        Plataforma* platEscolhida = plats[indiceDaPlataforma];

        CoordF p = platEscolhida->getPos();
        p.x = p.x + (platEscolhida->getTam().x / 2);
        p.y = p.y - 40;
        
        Espinho* pEsp = new Espinho(p);
        pGC->adicionarObstaculo(pEsp); // <-- Mudança aqui
    }
}
void Fase::atualizar(float dt) {
    pJog->update(dt);
    pJog->executar();

    std::vector<Inimigo*>& inis = pGC->getInimigos();
        for (size_t i = 0; i < inis.size(); i++) {
            inis[i]->olhar(pJog);
            inis[i]->danificar(pJog); // <-- DEVOLVA ESTA LINHA AQUI
            inis[i]->update(dt);
        }

    // 1º RESOLVE DANO E EMPURRÕES (Armadilhas e Inimigos)
    // Se o espinho jogar o boneco um pouco pra baixo, não tem problema...
    pGC->tratarColisoesJogObstaculo();
    pGC->tratarColisoesJogInimigo();
    
    // 2º RESOLVE O CHÃO (Plataformas)
    // ... Porque logo em seguida a plataforma empurra o boneco de volta pra cima!
    pGC->tratarColisoesJogPlataforma();
    pGC->tratarColisoesInimigoPlataforma();

    if (pLim) {
        pLim->executar(pJog);
    }

    executar();
}

void Fase::renderizar() {
    pGraphicM->clear();
    pGraphicM->seguirCamera(pJog->getPos(), CoordF(4000, 1080));

    if (fundo) { fundo->render(); }

    std::vector<Plataforma*>& plats = pGC->getPlataformas();
    for (size_t i = 0; i < plats.size(); i++) {
        //plats[i]->renderHitbox();
        plats[i]->render();
        
    }

    pJog->render();
    if (pJog->getAtaque() != NULL) { pJog->getAtaque()->render(); }

    std::vector<Inimigo*>& inis = pGC->getInimigos();
    for (size_t i = 0; i < inis.size(); i++) {
        inis[i]->render();
        if (inis[i]->getAtaque() != NULL) { inis[i]->getAtaque()->render(); }
    }

    std::vector<Obstaculo*>& obs = pGC->getObstaculos();
    for (size_t i = 0; i < obs.size(); i++) {
        obs[i]->render();
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
