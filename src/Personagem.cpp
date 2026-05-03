#include "../include/Personagem.hpp"
#include "../include/Estilo.hpp"
#include <iostream>

Personagem::Personagem(std::string t_nome, std::string t_classe, int t_forca, int t_reflexos, int t_inteligencia, int t_tecnica, int t_moral, int t_sorte, int t_carisma){

    nome = t_nome;
    classe = t_classe;
    forca = t_forca;
    reflexos = t_reflexos;
    inteligencia = t_inteligencia;
    tecnica = t_tecnica;
    moral = t_moral;
    sorte = t_sorte;
    carisma = t_carisma;

    hpMax = 100 + (forca * 5);
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
    Estilo::impressaoEscrita(Estilo::DESTAQUE + Estilo::AMARELO + "       REGISTRO DE MERCENARIO          " + Estilo::RESET, 10);
    Estilo::impressaoEscrita(Estilo::CIANO + "=======================================" + Estilo::RESET, 10);

    std::cout << Estilo::ROSA << "NOME:   " << Estilo::RESET << nome << "\n";
    std::cout << Estilo::ROSA << "CLASSE: " << Estilo::RESET << classe << "\n";

    std::string corHp = (hpAtual > hpMax * 0.3) ? Estilo::VERDE : Estilo::VERMELHO;
    std::cout << Estilo::MAGENTA << "VIDA:   " << corHp << hpAtual << " / " << hpMax << Estilo::RESET << "\n";

    std::cout << Estilo::CIANO << "=======================================" << Estilo::RESET << "\n";
    std::cout <<  Estilo::AZUL << "FORCA:     " << forca << " (Impacto fisico e resistencia)" << "\n";
    std::cout <<  Estilo::AZUL << "REFLEXOS:     " << reflexos << " (Esquiva e iniciativa de combate)" << "\n";
    std::cout <<  Estilo::AZUL << "INTELIGENCIA:     " << inteligencia << " (Invasao de sistemas corporativos)" << "\n";
    std::cout <<  Estilo::AZUL << "HABILIDADE TECNICA:     " << tecnica << " (Engenharia e tecnologia)" << "\n";
    std::cout <<  Estilo::AZUL << "MORAL:     " << moral << " (Compostura e furtividade)" << "\n";
    std::cout <<  Estilo::AZUL << "SORTE:     " << sorte << " (Criticos e milagres)" << "\n";
    std::cout <<  Estilo::AZUL << "CARISMA:     " << carisma << " (Persuasao e relacionamento)" << "\n";
    std::cout << Estilo::CIANO << "=======================================" << Estilo::RESET << "\n";
}

std::string Personagem::getNome() { return nome; }
int Personagem::getHpAtual() { return hpAtual; }
int Personagem::getForca() { return forca; }
int Personagem::getReflexos() { return reflexos; }
int Personagem::getInteligencia() { return inteligencia; }
int Personagem::getTecnica() { return tecnica; }
int Personagem::getMoral() { return moral; }
int Personagem::getSorte() { return sorte; }
int Personagem::getCarisma() { return carisma; }