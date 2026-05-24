#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Entidade.hpp"
#include <string>

class Inimigo : public Entidade {

    protected:
        
        int danoBase;

    public:

        Inimigo(std::string n_nome, int n_vidaMax, int n_danoBase);

        int getDanoBase();
};

#endif