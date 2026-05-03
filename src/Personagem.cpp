#include "../include/Personagem.hpp"
#include "../include/Estilo.hpp"
#include <iostream>

Personagem::Personagem(std::string t_nome, std::string t_classe, int t_forca, int t_reflexos, int t_hack){

    nome = t_nome;
    classe = t_classe;
    forca = t_forca;
    reflexos = t_reflexos;
    hack = t_hack;

    hpMax = 50 + (forca * 5);
    hpAtual = hpMax;
}

void Personagem::recebeDano(int dano){

    hpAtual -= dano;
    if(hpAtual < 0){

        hpAtual = 0;
    }
}

void Personagem::curarHp(int cura){

    hpAtual += cura; 
    if(hpAtual > hpMax){

        hpAtual = hpMax;
    }
}

bool Personagem::vivo(){

    return hpAtual > 0;
}

void Personagem::ficha() {
    Estilo::impressaoEscrita(Estilo::CIANO + "=======================================", 10);
    Estilo::impressaoEscrita(Estilo::CIANO + "       REGISTRO DE MERCENARIO          ", 10);
    Estilo::impressaoEscrita(Estilo::CIANO + "=======================================" + Estilo::RESET, 10);

    std::cout << Estilo::MAGENTA << "NOME:   " << Estilo::RESET << nome << "\n";
    std::cout << Estilo::MAGENTA << "CLASSE: " << Estilo::RESET << classe << "\n";

    std::string corHp = (hpAtual > hpMax * 0.3) ? Estilo::VERDE : Estilo::VERMELHO;
    std::cout << Estilo::AMARELO << "VIDA:   " << corHp << hpAtual << " / " << hpMax << Estilo::RESET << "\n";

    std::cout << Estilo::CIANO << "---------------------------------------" << Estilo::RESET << "\n";
    std::cout << "FORCA:    " << forca << " (Impacto fisico e resistencia)" << "\n";
    std::cout << "REFLEXOS: " << reflexos << " (Esquiva e iniciativa de combate)" << "\n";
    std::cout << "HACK:     " << hack << " (Invasao de sistemas corporativos)" << "\n";
    std::cout << Estilo::CIANO << "=======================================" << Estilo::RESET << "\n";
}

std::string Personagem::getNome() { return nome; }
int Personagem::getHpAtual() { return hpAtual; }
int Personagem::getForca() { return forca; }
int Personagem::getReflexos() { return reflexos; }
int Personagem::getHack() { return hack; }