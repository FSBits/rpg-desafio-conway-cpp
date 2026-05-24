#include "../include/Inimigo.hpp"
#include "../include/Estilo.hpp"
#include <iostream>
#include <string>

Inimigo::Inimigo(std::string n_nome, int n_vidaMax, int n_danoBase)
    : Entidade(n_nome, n_vidaMax), danoBase(n_danoBase){}

int Inimigo::getDanoBase() { return danoBase; }
