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

// Efeito temporario "preso" a um alvo (hoje: estrelinhas de STUN).
// Segue a mesma ideia do Ataque: e alocado UMA vez, ligado por ponteiro
// ao dono e so ativado/desativado quando necessario.
class Efeitos:public Entidade{
protected:
    float duracao;        // quanto tempo o efeito dura (segundos)
    float tempoRestante;  // quanto ainda falta
    bool ativo;
    float offsetY;        // distancia extra acima da cabeca do alvo
public:
    Efeitos(float duracao = 6 * 0.15f);
    ~Efeitos();

    // liga o efeito no alvo (nao reinicia se ja estiver ativo)
    void ativar(CoordF posAlvo, CoordF tamAlvo);
    void desativar();

    // reposiciona o efeito acima da cabeca do alvo (chamar todo frame)
    void seguir(CoordF posAlvo, CoordF tamAlvo);

    void update(float dt) override;
    void executar() override;
    void render() override;   // so desenha enquanto ativo

    bool estaAtivo() const;
    void setDuracao(float d);
};

#endif /* Efeitos_hpp */
