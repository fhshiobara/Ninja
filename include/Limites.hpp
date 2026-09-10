//
//  Limites.hpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#ifndef Limites_hpp
#define Limites_hpp

#include <stdio.h>
#include "Plataforma.hpp"
#include <vector>

class Limites:public Plataforma{
protected:
    CoordF tamMapa;
    std::vector<Plataforma*> lims;
    std::vector<Plataforma*>::iterator it;
    
public:
    Limites();
    ~Limites();
    void executar(Personagem* pJog);
    void criarLimitesMapa();
};

#endif /* Limites_hpp */
