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
    float atraso;        // NOVO: segundos de preparação (sem dano)
    float decorrido;     // NOVO: quanto do golpe já passou
public:
    Ataque(CoordF tamanho, float duracao, float atraso = 0.f);
    ~Ataque();

    void ativar(CoordF posPersonagem, CoordF tamanhoPersonagem, bool olhandoesquerda);
    void desativar();

    void update(float dt) override;
    void executar() override;
    void render() override; // só desenha a hitbox enquanto ativo
    bool acabou()const;
    bool estaAtivo()const;      // agora significa: hitbox VIVA (causa dano)
    bool emPreparacao()const;

};

#endif /* Ataque_hpp */
