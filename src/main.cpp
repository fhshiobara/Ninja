#include <iostream>
#include "Jogador.hpp"
#include "Plataforma.hpp"
#include "Mago.hpp"
#include "Limites.hpp"
#include "SingleFrameAnimation.hpp"

int main(){
    srand(0);
    Jogador jogador;
    Plataforma plat;
    Plataforma plat2(CoordF(760.f,700),CoordF(800,200));
    Mago mago;
    Limites lim;
    SingleFrameAnimation* fundo;
    int i =0;
    fundo = new SingleFrameAnimation("../assets/Telas/fase1.png",CoordF(0.f,0.f),CoordF(4000.f,1080.f),1.0);
    
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
        plat2.obstruir(&jogador);
        plat2.obstruir(&mago);
        mago.executar();
        lim.executar(&jogador);
        
        
        
        
        pGraphicM->clear();
        pGraphicM->seguirCamera(jogador.getPos(), CoordF(4000, 1080));
        // ... desenha jogador, mago, plataformas, ataques ...
        fundo->render();
        plat.render();
        plat2.render();
        jogador.renderHitbox();
        jogador.render();
        if(jogador.getAtaque()!=NULL){ jogador.getAtaque()->render(); }
        mago.renderHitbox();
        mago.render();
        if(mago.getAtaque()!=NULL){ mago.getAtaque()->render(); }
        pGraphicM->usarViewPadrao();
        //aqui da o render no que é parado
        pGraphicM->display();
    }
    delete fundo;

    return 0;
}
