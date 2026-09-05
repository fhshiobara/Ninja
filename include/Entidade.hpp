//
//  Entidade.hpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#ifndef Entidade_hpp
#define Entidade_hpp

#include <stdio.h>
#include "Animation.hpp"
#include "Ente.hpp"


class Entidade:public Ente{
protected:
    CoordF pos;
    CoordF vel;
    Animation animacao;
    bool olhandoesquerda;
public:
    Entidade();
    virtual ~Entidade();
    
    void mover();
    void sincronizar();
    
    virtual void update(float dt)=0;
    virtual void render();
    
    CoordF getPos();
    void setPos(CoordF p);
    
    void frearHorizontal();
    void frearVertical();
    void frear();
};

#endif /* Entidade_hpp */
