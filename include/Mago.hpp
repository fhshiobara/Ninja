//
//  Mago.hpp
//  Ninja
//
//  Created by Edison Shiobara on 08/09/26.
//

#ifndef Mago_hpp
#define Mago_hpp

#include <stdio.h>
#include "Inimigo.hpp"

class Mago:public Inimigo{
protected:
    int experiencia;
public:
    Mago();
    ~Mago();
    void danificar(Jogador* pJog)override;
    
    void update(float dt)override;
    void executar()override;
    
    
};

#endif /* Mago_hpp */
