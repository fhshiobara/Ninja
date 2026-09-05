//
//  Plataforma.hpp
//  Ninja
//
//  Created by Edison Shiobara on 05/09/26.
//

#ifndef Plataforma_hpp
#define Plataforma_hpp

#include <stdio.h>
#include "Obstaculo.hpp"

class Plataforma:public Obstaculo{
protected:
    bool ativa;
public:
    Plataforma();
    ~Plataforma();
    
    void executar() override;
    void obstruir(Jogador* pJog) override;
    
    };

#endif /* Plataforma_hpp */
