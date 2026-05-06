#include "../include/Entidade.hpp"

Entidade::Entidade(std::string t_nome, int t_hpMax)
    : nome(t_nome), hpMax(t_hpMax), hpAtual(t_hpMax){}

void Entidade::recebeDano(int dano){

    hpAtual -= dano;
    if(hpAtual < 0) hpAtual = 0;
}

void Entidade::curar(int cura){

    hpAtual += cura; 
    if(hpAtual > hpMax) hpAtual = hpMax;
}

bool Entidade::vivo(){

    return hpAtual > 0;
}

std::string Entidade::getNome() { return nome; }
int Entidade::getHpAtual() { return hpAtual; }
int Entidade::getHpMax() { return hpMax; }