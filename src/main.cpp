#include <iostream>
#include "Jogador.hpp"
#include "Plataforma.hpp"
#include "Mago.hpp"

int main(){
    Jogador jogador;
    Plataforma plat;
    Mago mago;
    int i =0;
    
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
                else if(evento.key.code == sf::Keyboard::Z){
                    jogador.pular();
                }
                else if(evento.key.code == sf::Keyboard::X){
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
        mago.update(dt);
        mago.executar();
        mago.danificar(&jogador);
        
        plat.obstruir(&jogador);
        plat.obstruir(&mago);
        

        pGraphicM->clear();
        plat.render();
        jogador.renderHitbox();
        jogador.render();
        mago.renderHitbox();
        mago.render();
        pGraphicM->display();
    }

    return 0;
}
