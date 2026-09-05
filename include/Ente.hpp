//
//  Ente.hpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#ifndef Ente_hpp
#define Ente_hpp

#include <stdio.h>
#include "GerenciadorGrafico.hpp"
#include "VectorTL.hpp"

class Ente{
protected:
    Gerenciadores::GerenciadorGrafico* pGG;
    int id;
    sf::RectangleShape* hitbox;
    CoordF tam;
public:
    Ente();
    ~Ente();
    
    void setPGG(Gerenciadores::GerenciadorGrafico* p);
    //void setID(); nao vou precisar pois usei o pretected
    void desenhar();
    virtual void executar()=0;
    void criarHitbox();
    CoordF getTam();
    void setTam(CoordF t);
};

#endif /* Ente_hpp */
