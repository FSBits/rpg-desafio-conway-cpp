#include "../include/Personagem.hpp"
#include "../include/Estilo.hpp"
#include <iostream>

Personagem::Personagem(std::string t_nome, std::string t_classe, int t_forca, int t_reflexos, int t_inteligencia, int t_tecnica, int t_moral, int t_sorte, int t_carisma)
    : nome(t_nome), classe(t_classe), forca(t_forca), reflexos(t_reflexos), inteligencia(t_inteligencia), tecnica(t_tecnica), moral(t_moral), sorte(t_sorte), carisma(t_carisma) {

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

    Estilo::impressaoEscrita(Estilo::ROSA + "NOME:   " + Estilo::RESET + nome + "\n", 10);
    Estilo::impressaoEscrita(Estilo::ROSA + "NOME:   " + Estilo::RESET + classe + "\n", 10);

    std::string corHp = (hpAtual > hpMax * 0.3) ? Estilo::VERDE : Estilo::VERMELHO;
    Estilo::impressaoEscrita(Estilo::MAGENTA + "VIDA:   " + corHp + std::to_string(hpAtual) + " / " + std::to_string(hpMax) + Estilo::RESET + "\n", 10);

    Estilo::impressaoEscrita(Estilo::CIANO+ "=======================================\n" + Estilo::RESET, 5);
    
    Estilo::impressaoEscrita(Estilo::AZUL + "FORCA:        " + Estilo::RESET + std::to_string(forca) + " (Impacto fisico e resistencia)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "REFLEXOS:     " + Estilo::RESET + std::to_string(reflexos) + " (Esquiva e iniciativa)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "INTELIGENCIA: " + Estilo::RESET + std::to_string(inteligencia) + " (Invasao de sistemas)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "TECNICA:      " + Estilo::RESET + std::to_string(tecnica) + " (Engenharia e tecnologia)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "MORAL:        " + Estilo::RESET + std::to_string(moral) + " (Controle e furtividade)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "SORTE:        " + Estilo::RESET + std::to_string(sorte) + " (Criticos e milagres)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "CARISMA:      " + Estilo::RESET + std::to_string(carisma) + " (Relacionamentos e persuasao)", 10);
    
    Estilo::impressaoEscrita(Estilo::CIANO+ "=======================================\n" + Estilo::RESET, 5);
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

