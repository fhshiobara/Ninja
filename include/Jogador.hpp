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
    bool defendendo;
    float tempoDefesa;

public:
    Jogador();
    ~Jogador();
    
    void executar() override;
    void update(float dt)override;
    
    bool golpeAereo();
    void defender();
    void setDefendendo(bool a);
    
};

#endif /* Jogador_hpp */
