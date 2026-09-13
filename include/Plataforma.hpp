//
//  Plataforma.hpp
//  Ninja
//
//  Created by Edison Shiobara on 05/09/26.
//

#ifndef Plataforma_hpp
#define Plataforma_hpp

#include <stdio.h>
#include "Obstaculo.hpp"
#include "SingleFrameAnimation.hpp"

class Plataforma:public Obstaculo{
protected:
    bool ativa;
    SingleFrameAnimation* sprite;
    SingleFrameAnimation* terra;
public:
    Plataforma();
    Plataforma(CoordF p,CoordF t);
    ~Plataforma();
    
    void executar() override;
    void obstruir(Personagem* pJog) override;
    void update(float dt) override;
    
    void render()override;
    
    };

#endif /* Plataforma_hpp */
