//
//  Fase.hpp
//  Ninja
//
//  Created by Edison Shiobara on 11/09/26.
//

#ifndef Fase_hpp
#define Fase_hpp

#include <stdio.h>
#include <vector>
#include "Entidade.hpp"
#include "GerenciadorColisoes.hpp"
#include "SingleFrameAnimation.hpp"
#include "Plataforma.hpp"

class Fase{
protected:
    std::vector<Entidade*> vEntidades;
    std::vector<Entidade*>::iterator it;
    Gerenciadores::GerenciadorColisoes* pGC;
    SingleFrameAnimation* fundo;
    std::vector<Plataforma*> vPlats;
    std::vector<Plataforma*>::iterator itP;
    
    
public:
    Fase();
    ~Fase();
    virtual void executar()=0;
    void criarInimigos();
    void criarPlataformas();
    virtual void criarCenario();
    
    float gridmap(int aux);
    
};

#endif /* Fase_hpp */
