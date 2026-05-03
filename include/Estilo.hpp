#ifndef ESTILO_HPP
#define ESTILO_HPP

#include <string>

namespace Estilo{

    const std::string DESTAQUE = "\033[7m";
    const std::string RESET = "\033[0m";
    const std::string CIANO = "\033[36m";   
    const std::string MAGENTA = "\033[35m";   
    const std::string AMARELO = "\033[33m";   
    const std::string VERMELHO = "\033[31m";   
    const std::string VERDE = "\033[32m";
    const std::string AZUL = "\033[94m";
    const std::string ROSA = "\033[95m";
    const std::string VERDE_CLARO = "\033[92m";
    const std::string CINZA_ESCURO = "\033[90m";   

    void impressaoEscrita(const std::string& texto, int delayMs = 30);
    void limpaTela();
}

#endif