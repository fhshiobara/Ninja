//
//  Fenix.hpp
//  Ninja
//
//  Created by Edison Shiobara on 06/10/26.
//

#ifndef Fenix_hpp
#define Fenix_hpp

#include <stdio.h>
#include "Inimigo.hpp"

class Fenix:public Inimigo{
protected:
    float altura;
    int aux;
public:
    Fenix();
    Fenix(CoordF p);
    ~Fenix();
    void danificar(Jogador* pJog)override;
    void executar()override;
    void update(float dt)override;
    
};

#endif /* Fenix_hpp */
