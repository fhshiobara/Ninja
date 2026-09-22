//
//  GerenciadorColisoes.cpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#include "GerenciadorColisoes.hpp"
#include <cmath> // Necessário para a função std::abs()



namespace Gerenciadores {

// Inicializa a instância estática do Singleton como nula
GerenciadorColisoes* GerenciadorColisoes::instance = nullptr;

// Construtor Privado
GerenciadorColisoes::GerenciadorColisoes() : pJog(nullptr) {
}

// Destrutor
GerenciadorColisoes::~GerenciadorColisoes() {
    limpar();
}

// Método Singleton para recuperar a única instância
GerenciadorColisoes* GerenciadorColisoes::getInstance() {
    if (instance == nullptr) {
        instance = new GerenciadorColisoes();
    }
    return instance;
}

// Lógica de intersecção AABB (Axis-Aligned Bounding Box) assumindo que as posições são os CENTROS
bool GerenciadorColisoes::sobrepondo(CoordF posA, CoordF tamA, CoordF posB, CoordF tamB) {
    // Calcula as bordas (Assumindo que getPos() retorna o CENTRO)
    float EsqA = posA.x - (tamA.x / 2.0f);
    float DirA = posA.x + (tamA.x / 2.0f);
    float TopA = posA.y - (tamA.y / 2.0f);
    float FunA = posA.y + (tamA.y / 2.0f);

    float EsqB = posB.x - (tamB.x / 2.0f);
    float DirB = posB.x + (tamB.x / 2.0f);
    float TopB = posB.y - (tamB.y / 2.0f);
    float FunB = posB.y + (tamB.y / 2.0f);

    // Condição clássica de intersecção:
    // Se a borda direita de A ultrapassa a esquerda de B E
    // a borda esquerda de A é menor que a direita de B E
    // a borda inferior de A ultrapassa o topo de B E
    // a borda superior de A é menor que o fundo de B... estão colidindo!
    if (DirA > EsqB && EsqA < DirB && FunA > TopB && TopA < FunB) {
        return true;
    }
    
    return false;
}

// ---- Setters / Adições ----
void GerenciadorColisoes::setJogador(Jogador* p) {
    pJog = p;
}
void GerenciadorColisoes::adicionarInimigo(Inimigo* p) {
    if (p) vInimigos.push_back(p);
}
void GerenciadorColisoes::adicionarObstaculo(Obstaculo* p) {
    if (p) vObstaculos.push_back(p);
}
void GerenciadorColisoes::adicionarPlataforma(Plataforma* p) {
    if (p) vPlataformas.push_back(p);
}

// ---- Getters ----
std::vector<Inimigo*>& GerenciadorColisoes::getInimigos() {
    return vInimigos;
}
std::vector<Obstaculo*>& GerenciadorColisoes::getObstaculos() {
    return vObstaculos;
}
std::vector<Plataforma*>& GerenciadorColisoes::getPlataformas() {
    return vPlataformas;
}

// ---- Limpeza ----
void GerenciadorColisoes::limpar() {
    pJog = nullptr;
    vInimigos.clear();
    vObstaculos.clear();
    vPlataformas.clear();
}

// ---- Tratamento de Colisões ----

void GerenciadorColisoes::tratarColisoesJogInimigo() {
    // Retorna imediatamente se o ponteiro do jogador for nulo
    if (!pJog) return;
    
    // Obtém as coordenadas e o tamanho do jogador a partir das classes base Entidade e Ente
    CoordF posJog = pJog->getPos();
    CoordF tamJog = pJog->getTam();

    // Itera pelo vetor de ponteiros de Inimigos
    for (size_t i = 0; i < vInimigos.size(); i++) {
        Inimigo* pIni = vInimigos[i];
        
        if (pIni) {
            // Recupera o ponteiro do ataque pertencente ao inimigo
            Ataque* atk = pIni->getAtaque();
            
            // Verifica se o ataque existe e se está ativo neste frame
            if (atk && atk->estaAtivo()) {
                
                CoordF posAtk = atk->getPos();
                CoordF tamAtk = atk->getTam();
                
                // Checa a sobreposição dos centros usando a sua função AABB
                if (sobrepondo(posJog, tamJog, posAtk, tamAtk)) {
                    // Aplica o dano ao jogador
                    pJog->tomarDano();
                    std::cout<<"colidiu com ataque"<<std::endl;
                }
            }
        }
    }
}

void GerenciadorColisoes::tratarColisoesJogObstaculo() {
    if (!pJog) return;
    
    CoordF posJog = pJog->getPos();
    CoordF tamJog = pJog->getTam();

    for (size_t i = 0; i < vObstaculos.size(); i++) {
        Obstaculo* pObs = vObstaculos[i];
        
        if (pObs) {
            CoordF posObs = pObs->getPos();
            CoordF tamObs = pObs->getTam();
            
            // Checa a sobreposição do jogador com a hitbox do obstáculo
            if (sobrepondo(posJog, tamJog,CoordF(posObs.x+80,posObs.y), CoordF(tamObs.x-90,tamObs.y))) {
                // Como Obstaculo implementa obstruir(Personagem*), basta passar o jogador.
                // O próprio obstáculo cuida se é espinho (dano) ou parede (impedir movimento).
                pObs->obstruir(pJog);
                std::cout<<"colidiu com espinho"<<std::endl;
                
            }
        }
    }
}
void GerenciadorColisoes::tratarColisoesJogPlataforma() {
    if (!pJog) return;
    
    // Deixa a própria plataforma decidir se bateu e ajustar o jogador
    for (size_t i = 0; i < vPlataformas.size(); i++) {
        if (vPlataformas[i]) {
            vPlataformas[i]->obstruir(pJog);
        }
    }
}

void GerenciadorColisoes::tratarColisoesInimigoPlataforma() {
    for (size_t i = 0; i < vInimigos.size(); i++) {
        if (vInimigos[i]) {
            for (size_t j = 0; j < vPlataformas.size(); j++) {
                if (vPlataformas[j]) {
                    // Manda a plataforma obstruir o Inimigo direto
                    vPlataformas[j]->obstruir(vInimigos[i]);
                }
            }
        }
    }
}

} // Fim namespace Gerenciadores
