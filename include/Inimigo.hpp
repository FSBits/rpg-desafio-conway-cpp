#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include <string>

class Inimigo{

    protected:
        
        std::string nome;
        int atkBase;
        int hpAtual;
        int hpMax;

    public:

        Inimigo(std::string n_nome, int n_atk, int n_hp, int n_hpMax);

        void recebeDano(int danoSofrido);
        bool bivo();

        std::string getNome();
        int getAtk();
        int getHpAtual();
        int getHpMax();
};

#endif