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
#include "Jogador.hpp"
#include "Efeitos.hpp"




class Inimigo:public Personagem{
protected:
    int maldade;
    bool ativo;
    CoordF posAnt;

    // Stun: Efeitos alocado uma vez (como o Ataque) e so ligado/desligado
    Efeitos* stun;
    bool stunado;
public:
    Inimigo();
    ~Inimigo();
    
    virtual void danificar(Jogador* pJog)=0;
    void olhar(Jogador* pJog);

    // deixa o inimigo imovel e sem atacar pela duracao do Efeitos (stun)
    void stunnar();
    void atualizarStun(float dt);
    bool estaStunado() const;
    Efeitos* getStun();
    
};
#endif /* Inimigo_hpp */
