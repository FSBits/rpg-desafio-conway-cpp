#ifndef COMBATE_HPP
#define COMBATE_HPP

#include "../include/Inimigo.hpp"
#include "../include/Personagem.hpp"
#include <random>

namespace Combate{
    
    struct EstadoCombate {
        bool fugiu = false;
        bool curtoUsado = false;
        bool sabotagemUsada = false;
        bool sobrecargaUsada = false;
        bool inimigoSabotado = false;
    };

    bool iniciar(Personagem& jogador, Inimigo& adversario);
    void executarTurnoInimigo(Personagem& jogador, Inimigo& adversario, bool inimigoSabotado, std::mt19937& gen, std::uniform_int_distribution<>& d100);
    void exibirHUDCombate(Personagem& jogador, Inimigo& adversario, bool hackBloqueado);
    bool acessarInv(Personagem& jogador);
    bool ataqueJogador(Personagem& jogador, Inimigo& adversario);
    bool executarInvasao(Personagem& jogador, Inimigo& adversario, EstadoCombate& estado, std::mt19937& gen, std::uniform_int_distribution<>& d100);
    bool tryFuga(Personagem& jogador, EstadoCombate& estado, std::mt19937& gen, std::uniform_int_distribution<>& d100);
}

#endif