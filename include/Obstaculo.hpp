//
//  Obstaculo.hpp
//  Ninja
//
//  Created by Edison Shiobara on 05/09/26.
//

#ifndef Obstaculo_hpp
#define Obstaculo_hpp

#include <stdio.h>
#include "Entidade.hpp"
#include "Personagem.hpp"

class Obstaculo:public Entidade{
protected:
    bool danoso;
public:
    Obstaculo();
    ~Obstaculo();
    
    virtual void obstruir(Personagem* pJog)=0;
    virtual void executar()=0;
    
    bool getDanoso();
};

#endif /* Obstaculo_hpp */
