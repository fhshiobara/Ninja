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
public:
    Jogador();
    ~Jogador();
    
    void atacar();
    
    void update(float dt) override;
    void executar();
};

#endif /* Jogador_hpp */
