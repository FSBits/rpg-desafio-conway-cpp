#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP

#include <string>

class Entidade {

    protected:
        
        std::string nome;
        int hpMax;
        int hpAtual;

    public:

        Entidade(std::string t_nome, int t_hpMax);

        virtual void recebeDano(int dano);
        virtual void curar(int quantidade);
        bool vivo();

        std::string getNome();
        int getHpAtual();
        int getHpMax();
};

#endif