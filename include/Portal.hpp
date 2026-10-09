//
//  Portal.hpp
//  Ninja
//
//  Created by Edison Shiobara on 05/10/26.
//

#ifndef Portal_hpp
#define Portal_hpp

#include <stdio.h>
#include "Obstaculo.hpp"

class Portal:public Obstaculo{
protected:
    bool pronto;
public:
    Portal();
    ~Portal();
    
    void teleportar(Personagem* pJog);
    void obstruir(Personagem* pJog);
    void executar();
    void update(float dt);
    
};

#endif /* Portal_hpp */
