//
//  Ataque.hpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#ifndef Ataque_hpp
#define Ataque_hpp

#include <stdio.h>
#include "Entidade.hpp"

class Ataque:public Entidade{
protected:
    float tempo;
    float duracaoBase;
    bool ativo;
public:
    Ataque(CoordF tamanho, float duracao);
    ~Ataque();

    void ativar(CoordF posPersonagem, CoordF tamanhoPersonagem, bool olhandoesquerda);
    void desativar();
    bool estaAtivo()const;

    void update(float dt) override;
    void executar() override;
    void render() override; // só desenha a hitbox enquanto ativo
    bool acabou()const;


};

#endif /* Ataque_hpp */
