//
//  Personagem.hpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#ifndef Personagem_hpp
#define Personagem_hpp

#include <stdio.h>
#include "Entidade.hpp"

class Personagem:public Entidade{
protected:
    int hp;
    bool vivo;
    bool nochao;
public:
    Personagem();
    ~Personagem();
    
    void tomarDano();
    
    virtual void executar()=0;
    
    

    
};

#endif /* Personagem_hpp */
