#include <iostream>
#include "Jogador.hpp"
#include "Plataforma.hpp"
#include "Mago.hpp"

int main(){
    srand(time(NULL));
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
                else if(evento.key.code == sf::Keyboard::Space){
                    jogador.defender();
                }
            }
            else if(evento.type == sf::Event::KeyReleased){
                if(evento.key.code == sf::Keyboard::Right){
                    jogador.setAndandoDireita(false);
                }
                else if(evento.key.code == sf::Keyboard::Left){
                    jogador.setAndandoEsquerda(false);
                }
                else if(evento.key.code==sf::Keyboard::Space){
                    jogador.setDefendendo(false);
                }
            }
        }

        float dt = relogio.restart().asSeconds();
        jogador.update(dt);
        jogador.executar();
        mago.olhar(&jogador);
        mago.danificar(&jogador);
        mago.update(dt);
        
        
        
        plat.obstruir(&jogador);
        plat.obstruir(&mago);
        mago.executar();
        
        
        
        
        pGraphicM->clear();
        pGraphicM->seguirCamera(jogador.getPos(), CoordF(4000, 1080));
        // ... desenha jogador, mago, plataformas, ataques ...
        plat.render();
        jogador.renderHitbox();
        jogador.render();
        mago.renderHitbox();
        mago.render();
        pGraphicM->usarViewPadrao();
        //aqui da o render no que é parado
        pGraphicM->display();
    }

    return 0;
}
