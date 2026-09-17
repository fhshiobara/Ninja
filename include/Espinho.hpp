//
//  Espinho.hpp
//  Ninja
//
//  Created by Edison Shiobara on 17/09/26.
//

#ifndef Espinho_hpp
#define Espinho_hpp

#include <stdio.h>
#include "Obstaculo.hpp"


class Espinho:public Obstaculo{
protected:
    int afiado;
    
public:
    Espinho();
    Espinho(CoordF p);
    ~Espinho();
    void obstruir(Personagem* pJog);
    void executar();
    void update(float dt);
    
    
};

#endif /* Espinho_hpp */
