//
//  Ataque.hpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#ifndef Ataque_hpp
#define Ataque_hpp

#include <stdio.h>
#include "Entidade.hpp"

class Ataque:public Entidade{
protected:
    float tempo;
public:
    Ataque(CoordF t,CoordF p,float duracao, float dt);
    ~Ataque();
    
    void update(float dt);
    
    
};

#endif /* Ataque_hpp */
