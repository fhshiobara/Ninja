//
//  Jogador.hpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#ifndef Jogador_hpp
#define Jogador_hpp

#include <stdio.h>
#include "Personagem.hpp"

class Jogador:public Personagem{
protected:
    int pontos;
    bool atacando;
    bool andandoDireita;
    bool andandoEsquerda;
    bool pulando;
    float tempoAtaque;
public:
    Jogador();
    ~Jogador();
    
    void atacar();
    void pular();
    
    void update(float dt) override;
    void executar() override;
    
    bool estaAtacando();
    bool estaAndando();
    void setAndandoDireita(bool a);
    void setAndandoEsquerda(bool a);
    
    void setPulando(bool a);
    bool getPulando();
};

#endif /* Jogador_hpp */
