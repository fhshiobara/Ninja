//
//  Efeitos.hpp
//  Ninja
//
//  Created by Edison Shiobara on 28/09/26.
//

#ifndef Efeitos_hpp
#define Efeitos_hpp

#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "Entidade.hpp"
#include "Animation.hpp"
class Efeitos:public Entidade{
protected:
    float duracao;
    float tempoDecorrido;
    bool ativo;
public:
    Efeitos();
    ~Efeitos();
    void executar();
    void update(float dt);
    void setAtivo(bool a);
    void ativar();
  
};

#endif /* Efeitos_hpp */
