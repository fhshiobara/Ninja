#include <iostream>
#include "Jogador.hpp"
#include "Plataforma.hpp"

int main(){
    Jogador jogador;
    Plataforma plat;

    sf::Clock relogio;

    while(pGraphicM->windowopen()){
        sf::Event evento;
        while(pGraphicM->getWindow()->pollEvent(evento)){

            if(evento.type == sf::Event::Closed){
                pGraphicM->closeWindow();
            }
            else if(evento.type == sf::Event::KeyPressed){
                if(evento.key.code == sf::Keyboard::Right){
                    jogador.setAndandoDireita(true);
                }
                else if(evento.key.code == sf::Keyboard::Left){
                    jogador.setAndandoEsquerda(true);
                }
                else if(evento.key.code == sf::Keyboard::Space){
                    jogador.atacar();
                }
            }
            else if(evento.type == sf::Event::KeyReleased){
                if(evento.key.code == sf::Keyboard::Right){
                    jogador.setAndandoDireita(false);
                }
                else if(evento.key.code == sf::Keyboard::Left){
                    jogador.setAndandoEsquerda(false);
                }
            }
        }

        float dt = relogio.restart().asSeconds();
        jogador.update(dt);
        jogador.executar();
        
        plat.obstruir(&jogador);
        

        pGraphicM->clear();
        plat.render();
        jogador.render();
        pGraphicM->display();
    }

    return 0;
}
