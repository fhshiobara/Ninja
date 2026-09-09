//
//  GerenciadorColisoes.hpp
//  Ninja
//
//  Created by Edison Shiobara on 09/09/26.
//

#ifndef GerenciadorColisoes_hpp
#define GerenciadorColisoes_hpp

#include <stdio.h>
#include "Entidade.hpp"
#include <vector>

namespace Gerenciadores{
class GerenciadorColisoes{
private:
    GerenciadorColisoes();
    static Gerenciadores::GerenciadorColisoes* instance;
    std::vector<Entidade*> vEnts;
public:
    ~GerenciadorColisoes();
    
    bool tratarColisaoMago();
    bool tratarColisaoPlataforma();
    
};


}using namespace Gerenciadores;

#endif /* GerenciadorColisoes_hpp */
