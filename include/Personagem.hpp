//
//  Personagem.hpp
//  Ninja
//
//  Created by Edison Shiobara on 03/09/26.
//

#ifndef Personagem_hpp
#define Personagem_hpp

#include <stdio.h>
#include "Entidade.hpp"

class Personagem:public Entidade{
protected:
    int hp;
    bool vivo;
    bool nochao;
    bool subindo;
    float tempoSubida;
    
    bool atacando;
    bool andandoDireita;
    bool andandoEsquerda;
    float tempoAtaque;
public:
    Personagem();
    ~Personagem();
    
    void tomarDano();
    
    virtual void executar()=0;
    
    void gravidade();
    
    void aterrissar();
    
    void iniciarSubida(float tempo,float velocidade);
    void atualizarSubida(float dt);
    bool getSubindo();
    
    //daqui pra frente vai ser o que eu subi de jogador
    
    bool estaAndando();
    bool estaAtacando();
    void setAndandoDireita(bool valor);
    void setAndandoEsquerda(bool valor);
    void atacar();
    void pular();
    
    

    
};

#endif /* Personagem_hpp */
