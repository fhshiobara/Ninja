//
//  Inimigo.hpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#ifndef Inimigo_hpp
#define Inimigo_hpp

#include <stdio.h>
#include "Personagem.hpp"




class Inimigo:public Personagem{
protected:
    int maldade;
public:
    Inimigo();
    ~Inimigo();
    
    virtual void danificar()=0;
};
#endif /* Inimigo_hpp */
