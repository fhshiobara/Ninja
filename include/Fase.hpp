//
//  Fase.hpp
//  Ninja
//
//  Created by Edison Shiobara on 11/09/26.
//

#ifndef Fase_hpp
#define Fase_hpp

#include <stdio.h>
#include <vector>
#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "SingleFrameAnimation.hpp"
#include "Plataforma.hpp"
#include "Limites.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"

class Fase{
protected:
    std::vector<Inimigo*> vEntidades;
    std::vector<Inimigo*>::iterator it;
    Gerenciadores::GerenciadorColisoes* pGC;
    SingleFrameAnimation* fundo;
    std::vector<Plataforma*> vPlats;
    std::vector<Plataforma*>::iterator itP;
    Jogador* pJog;
    Limites* pLim;
    sf::Clock relogio;



public:
    Fase();
    virtual ~Fase();

    // Loop principal da fase: enquanto a janela estiver aberta,
    // trata os eventos, atualiza a logica e renderiza o quadro.
    void rodar();

    // Le os eventos da janela (SFML) e os repassa para o jogador.
    void tratarEventos();

    // Atualiza a logica de jogo de um quadro (movimento, colisoes, IA basica).
    virtual void atualizar(float dt);

    // Desenha o quadro atual (cenario, plataformas, jogador e inimigos).
    virtual void renderizar();

    virtual void executar()=0;
    //void criarInimigosMagos();
    void criarPlataformas();
    virtual void criarCenario();
    virtual void criarInimigos()=0;

    float gridmap(int aux);

};

#endif /* Fase_hpp */
