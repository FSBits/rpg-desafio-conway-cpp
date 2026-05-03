#include <iostream>
#include "../include/Estilo.hpp" 
#include "../include/Personagem.hpp"

int main() {
    
    Estilo::limpaTela();

    Estilo::impressaoEscrita(Estilo::MAGENTA + "[SISTEMA] Inicializando simulador neural..." + Estilo::RESET, 30);
    std::cout << std::endl;

    Personagem jogador("V", "Solo", 8, 7, 3);

    Estilo::impressaoEscrita(Estilo::CIANO + "[SISTEMA] Carregando perfil do mercenario:" + Estilo::RESET, 30);
    jogador.ficha();
    std::cout << std::endl;

    Estilo::impressaoEscrita(Estilo::VERMELHO + ">> ALERTA: O jogador foi atingido por um tiro de escopeta corporativa! (-50 de Vida)" + Estilo::RESET, 40);
    jogador.recebeDano(70);
    
    jogador.ficha(); 
    std::cout << std::endl;

    Estilo::impressaoEscrita(Estilo::VERDE + ">> INJETANDO STIMPACK: Regenerando tecidos feridos... (+30 de Vida)" + Estilo::RESET, 40);
    jogador.curarHp(30);
    
    jogador.ficha();

    return 0;
}