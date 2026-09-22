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

    // Quem CRIA e DESTROI esses objetos continua sendo a Fase (e FasePrimeira);
    // aqui a gente so guarda os ponteiros pra poder checar a colisao entre eles
    // num lugar so, sem ficar passando os vetores por parametro toda hora.
    Jogador* pJog;
    std::vector<Inimigo*> vInimigos;
    std::vector<Obstaculo*> vObstaculos;
    std::vector<Plataforma*> vPlataformas;

    // AABB generico: trata posA/posB como o CENTRO do retangulo (mesma
    // convencao de Entidade::renderHitbox(), usada por Jogador, Inimigo,
    // Ataque, Espinho, etc.)
    bool sobrepondo(CoordF posA, CoordF tamA, CoordF posB, CoordF tamB);

public:
    ~GerenciadorColisoes();

    static GerenciadorColisoes* getInstance();

    // ---- registro dos elementos da fase atual ----
    // chame a partir de Fase/FasePrimeira no lugar dos antigos
    // vEntidades.push_back(...) / vPlats.push_back(...) / vObstaculo.push_back(...)
    void setJogador(Jogador* p);
    void adicionarInimigo(Inimigo* p);
    void adicionarObstaculo(Obstaculo* p);
    void adicionarPlataforma(Plataforma* p);

    // a Fase ainda precisa iterar isso pra atualizar/renderizar/destruir,
    // entao devolve por referencia (sem copiar o vetor a cada chamada)
    std::vector<Inimigo*>& getInimigos();
    std::vector<Obstaculo*>& getObstaculos();
    std::vector<Plataforma*>& getPlataformas();

    // Esvazia os vetores de PONTEIROS guardados aqui - NAO deleta os objetos.
    // A memoria continua sendo responsabilidade de quem criou (Fase). Chamar
    // no destrutor da Fase, DEPOIS de deletar os objetos, pra o singleton nao
    // ficar com ponteiros soltos apontando pra uma fase que ja acabou.
    void limpar();

    // Ataque do inimigo (Inimigo::getAtaque()) x posicao/hitbox do jogador.
    void tratarColisoesJogInimigo();

    // Hitbox do jogador x hitbox de cada obstaculo (ex.: Espinho).
    void tratarColisoesJogObstaculo();
    
    // Trata colisão entre o Jogador e todas as plataformas
        void tratarColisoesJogPlataforma();

        // Trata colisão entre todos os Inimigos e todas as plataformas
        void tratarColisoesInimigoPlataforma();

};


}using namespace Gerenciadores;

#endif /* GerenciadorColisoes_hpp */
