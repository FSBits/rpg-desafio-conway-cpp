#include "../include/Inimigo.hpp"
#include "../include/Estilo.hpp"
#include <iostream>
#include <string>

Inimigo::Inimigo(std::string n_nome, int n_atk, int n_hp, int n_hpMax)
    : nome(n_nome), atkBase(n_atk), hpAtual(n_hp), hpMax(n_hpMax){

        hpAtual = hpMax;
    }   

void Inimigo::recebeDano(int danoSofrido){

    hpAtual = hpAtual - danoSofrido;

    if(hpAtual < danoSofrido) hpAtual = 0;
    Estilo::impressaoEscrita(Estilo::VERMELHO + "O " + nome + " sofreu " + std::to_string(danoSofrido) +" de dano!" + Estilo::RESET, 5);
}

bool Inimigo::bivo(){

    if(hpAtual > 0) return true;
    return false;
}

std::string Inimigo::getNome() { return nome;}
int Inimigo::getAtk() { return atkBase; }
int Inimigo::getHpAtual() { return hpAtual; }
int Inimigo::getHpMax() { return hpMax; }