#include <iostream>
#include "Jogador.hpp"

int main(){
    Jogador jogador;

    sf::Clock relogio;

    while(pGraphicM->windowopen()){
        sf::Event evento;
        while(pGraphicM->getWindow()->pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                pGraphicM->closeWindow();
            }
        }

        float dt = relogio.restart().asSeconds();
        jogador.update(dt);

        pGraphicM->clear();
        jogador.render();
        pGraphicM->display();
    }

    return 0;
}
