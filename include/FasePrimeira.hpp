//
//  FasePrimeira.hpp
//  Ninja
//
//  Created by Edison Shiobara on 14/09/26.
//

#ifndef FasePrimeira_hpp
#define FasePrimeira_hpp

#include <stdio.h>
#include "Fase.hpp"
#include "Mago.hpp"


class FasePrimeira:public Fase{
protected:
    int numMagos;
public:
    FasePrimeira();
    ~FasePrimeira();
    
    void executar();
    void criarInimigos();
};
#endif /* FasePrimeira_hpp */
