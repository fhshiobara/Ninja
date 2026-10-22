//
//  GerenciadorColisoes.hpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#ifndef GerenciadorColisoes_hpp
#define GerenciadorColisoes_hpp

#include <stdio.h>
#include <vector>
#include "Entidade.hpp"
#include "Ataque.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Obstaculo.hpp"
#include "Plataforma.hpp"


namespace Gerenciadores{
class GerenciadorColisoes{
private:
    GerenciadorColisoes();
    static Gerenciadores::GerenciadorColisoes* instance;
    GerenciadorGrafico* pGG;
    bool colisaoDebug;

    Jogador* pJog;
    std::vector<Inimigo*> vInimigos;
    std::vector<Obstaculo*> vObstaculos;
    std::vector<Plataforma*> vPlataformas;

    
    bool sobrepondo(CoordF posA, CoordF tamA, CoordF posB, CoordF tamB);

public:
    ~GerenciadorColisoes();

    static GerenciadorColisoes* getInstance();

    void setJogador(Jogador* p);
    void adicionarInimigo(Inimigo* p);
    void adicionarObstaculo(Obstaculo* p);
    void adicionarPlataforma(Plataforma* p);

    
    std::vector<Inimigo*>& getInimigos();
    std::vector<Obstaculo*>& getObstaculos();
    std::vector<Plataforma*>& getPlataformas();
    bool houveColisaoDebug();
    void resetarColisaoDebug();

    
    void limpar();

    
    void tratarColisoesJogInimigo();

    
    void tratarColisoesJogObstaculo();
    
   
    void tratarColisoesJogPlataforma();

    void tratarColisoesInimigoPlataforma();

};


}using namespace Gerenciadores;

#endif /* GerenciadorColisoes_hpp */
