#include <iostream>
#include <string>
#include "../include/Estilo.hpp" 
#include "../include/Personagem.hpp"

int lerAtributos(std::string nomeAtributo, int& pontosRestantes);
Personagem criarPersonagem();

int main(){

    Personagem jogador = criarPersonagem();

    Estilo::limpaTela();
    jogador.ficha();
    
    return 0;
}

int lerAtributos(std::string nomeAtributo, int& pontosRestantes){

    int v;
    while(true){

        std::cout << Estilo::AMARELO << "Pontos restantes: " << pontosRestantes << Estilo::RESET << "\n";
        std::cout << Estilo::AMARELO << "Quantos pontos colocar em " << Estilo::AZUL << nomeAtributo << Estilo::RESET << "? (0 a " << pontosRestantes << "): ";

        
        if(std::cin >> v){

            if(v >= 0 && v <= pontosRestantes){

                pontosRestantes -= v;
                return v + 1;
            }

            std::cout << Estilo::VERMELHO << "[ERRO] Valor invalido. Digite um numero entre 0 e " << pontosRestantes << ".\n" << Estilo::RESET;
            continue;
        }

        std::cout << Estilo::VERMELHO << "[ERRO] Entrada invalida. Digite apenas numeros.\n" << Estilo::RESET;
        std::cin.clear();
        std::cin.ignore(999996799999, '\n');
    }
}

Personagem criarPersonagem(){

    std::string nome;
    int opcaoClasse;
    std::string classe;

    Estilo::limpaTela();
    Estilo::impressaoEscrita(Estilo::DESTAQUE + Estilo::AMARELO + "TERMINAL DE CRIACAO DE MERCENARIO" + Estilo::RESET, 10);
    std::cout << "\n";

    std::cout << Estilo::VERDE_CLARO << "Digite seu nome ou apelido : " << Estilo::RESET << "\n";
    std::getline(std::cin, nome);

    bool classeValida = false;
    while(!classeValida){

        std::cout << Estilo::CIANO << "Escolha sua Especializacao (Classe):" << Estilo::RESET << "\n";
        std::cout << Estilo::AZUL << "[1] Solo      (Especialista em Combate)" << "\n";
        std::cout << Estilo::AZUL << "[2] Netrunner (Mestre da Rede e Invasao)" << "\n";
        std::cout << Estilo::AZUL << "[3] Techie    (Engenheiro de Implantes)" << "\n";
        std::cout << Estilo::AZUL << "[4] Nomad     (Sobrevivente dos Ermos)" << "\n";
        std::cout << Estilo::AZUL << "[5] Corpo     (Estrategista Corporativo)" << "\n" << Estilo::RESET << "\n";
        std::cout << Estilo::CIANO << "Escolha de 1 a 5: ";

        if(std::cin >> opcaoClasse){

            switch(opcaoClasse){

                case 1:
                    classe = "Solo";
                    classeValida = true;
                    break;
                case 2:
                    classe = "Netrunner";
                    classeValida = true;
                    break;
                case 3:
                    classe = "Techie";
                    classeValida = true;
                    break;
                case 4:
                    classe = "Nomad";
                    classeValida = true;
                    break;
                case 5:
                    classe = "Corpo";
                    classeValida = true;
                    break;
                default:
                    std::cout << Estilo::VERMELHO << "[ERRO] Opcao invalida. Escolha um numero entre 1 e 5." << Estilo::RESET << "\n";
                    break;    
            }
        } else{
            
            std::cout << Estilo::VERMELHO << "[ERRO] Entrada invalida. Digite apenas numeros." << Estilo::RESET << "\n";
            std::cin.clear();
            std::cin.ignore(999996799999, '\n');
        }        
    }

    int pontos = 28;
    int forca, reflexos, inteligencia, tecnica, moral, sorte, carisma;
    
    Estilo::limpaTela();
    std::cout << Estilo::ROSA << ">>> ALOCACAO DE ATRIBUTOS <<<" << Estilo::RESET << "\n";
    std::cout << "Voce tem " << Estilo::AMARELO << pontos << " pontos" << Estilo::RESET << " para distribuir.\n";

    forca = lerAtributos("FORCA", pontos);
    reflexos = lerAtributos("REFLEXOS", pontos);
    inteligencia = lerAtributos("INTELIGENCIA", pontos);
    tecnica = lerAtributos("TECNICA", pontos);
    moral = lerAtributos("MORAL", pontos);
    sorte = lerAtributos("SORTE", pontos);
    carisma = lerAtributos("CARISMA", pontos);

    std::cout << "\n" << Estilo::AMARELO << "[SISTEMA] Perfil bio-digital salvo com sucesso." << Estilo::RESET << "\n";

    Estilo::impressaoEscrita("...", 1000);

    return Personagem(nome, classe, forca, reflexos, inteligencia, tecnica, moral, sorte, carisma);
}