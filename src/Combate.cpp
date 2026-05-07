#include "../include/Combate.hpp"
#include "../include/Estilo.hpp"
#include <iostream>
#include <string>
#include <random>

bool Combate::iniciar(Personagem& jogador, Inimigo& adversario){

    Estilo::limpaTela();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> d100(1, 100);

    Estilo::impressaoEscrita(Estilo::VERMELHO + "=========================================" + Estilo::RESET, 2);
    Estilo::impressaoEscrita(Estilo::VERMELHO + "!!! ALERTA DE AMEACA DETECTADA !!!" + Estilo::RESET, 15);
    Estilo::impressaoEscrita(Estilo::VERMELHO + "=========================================" + Estilo::RESET, 2);

    Estilo::impressaoEscrita("\nUm " + Estilo::AZUL + adversario.getNome() + Estilo::RESET + " bloqueia o seu caminho!", 15);
    std::cout << "\n" << Estilo::CINZA_ESCURO << "(Pressione ENTER para entrar em modo de combate...)" << Estilo::RESET;
    std::cin.ignore(999996799999, '\n');
    std::cin.get();

    int escolha;
    bool fugiu = false;

    while(jogador.vivo() && adversario.vivo() && !fugiu){

        Estilo::limpaTela();
        Estilo::impressaoEscrita(Estilo::AMARELO + ">>> STATUS DE COMBATE <<<\n" + Estilo::RESET, 5);
        Estilo::impressaoEscrita("-----------------------------------------\n", 5);
        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + " [HP: " + Estilo::VERDE_CLARO + std::to_string(jogador.getHpAtual()) + "/" + std::to_string(jogador.getHpMax()) + Estilo::CIANO + "]\n" + Estilo::RESET, 5);
        Estilo::impressaoEscrita(Estilo::ROSA + adversario.getNome() + " [HP: " + Estilo::VERMELHO + std::to_string(adversario.getHpAtual()) + "/" + std::to_string(adversario.getHpMax()) + Estilo::ROSA + "]\n" + Estilo::RESET, 5);
        Estilo::impressaoEscrita("-----------------------------------------\n\n", 5);

        Estilo::impressaoEscrita("Sua vez de agir:\n", 5);
        Estilo::impressaoEscrita("[1] " + Estilo::VERMELHO + "Atacar com " + jogador.getArmaEquipada().nome + Estilo::RESET + "\n", 5);
        Estilo::impressaoEscrita("[2] " + Estilo::AMARELO + "Abrir Mochila (Inventario)" + Estilo::RESET + "\n", 5);
        Estilo::impressaoEscrita("[3] " + Estilo::CINZA_ESCURO + "Recuo Tatico / Fugir" + Estilo::RESET + "\n", 5);
        Estilo::impressaoEscrita("\nEscolha: ", 5);


        if(std::cin >> escolha){

            Estilo::impressaoEscrita("\n", 5);

            bool turnoGasto = false;

            switch(escolha){

                case 1: {//atk
                    Item arma = jogador.getArmaEquipada();
                    int bonusDamage = 0;
                    std::string avisoAtributo = "";
                    if(arma.armaDeFogo){
                        bonusDamage = jogador.getTecnica() * 2;
                        avisoAtributo = " (Bonus de Tecnica)";
                    } else{

                        bonusDamage = jogador.getForca() * 2;
                        avisoAtributo = " (Bonus de Forca)";
                    }
                    int danoCausado = arma.valorEfeito + bonusDamage;
                    
                    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + Estilo::RESET + " ataca com " + arma.nome + "!\n", 15);
                    adversario.recebeDano(danoCausado);
                    Estilo::impressaoEscrita(Estilo::MAGENTA + ">> Causou " + std::to_string(danoCausado) + " de dano!" + avisoAtributo + " <<\n" + Estilo::RESET, 15);
                    turnoGasto = true;
                    break;
                }
                case 2: { //inv
                
                    jogador.listarInv();
                    Estilo::impressaoEscrita("\nDigite o numero do item que deseja usar (ou -1 para cancelar): ", 5);
                    int index;
                    if(std::cin >> index && index >= 0){
                        if(jogador.usarItem(index)) turnoGasto = true;
                    } else{

                        std::cin.clear();
                        std::cin.ignore(999996799999, '\n');
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce fechou a mochila rapidamente." + Estilo::RESET, 10);
                    }
                    break;
                }
                case 3: { //covardia ou genialidade

                    int chanceFuga = 40 + (jogador.getReflexos() * 5) + (jogador.getSorte() * 5);
                    int dado = d100(gen);

                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce tenta correr para as sombras...\n" + Estilo::RESET, 15);

                    if(dado < chanceFuga){
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "Voce despistou o inimigo com sucesso!" + Estilo::RESET, 15);
                        fugiu = true;
                    } else{

                        Estilo::impressaoEscrita(Estilo::VERMELHO + "O inimigo bloqueou a sua rota de fuga!" + Estilo::RESET, 15);
                    }
                    turnoGasto = true; 
                    break;
                }

                default:
                Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Voce hesitou! Acao invalida.\n" + Estilo::RESET, 10);
                break;
            } 

            if(adversario.vivo() && !fugiu && turnoGasto){

                Estilo::impressaoEscrita("\n-----------------------------------------\n", 5);
                Estilo::impressaoEscrita(Estilo::ROSA + adversario.getNome() + Estilo::RESET + " contra-ataca!\n", 15);

                int chanceEsquiva = (jogador.getReflexos() * 4) + (jogador.getSorte() * 2);
                int dadoEsquiva = d100(gen);

                if(dadoEsquiva <= chanceEsquiva){
                    Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "* SWOOSH * Os seus reflexos salvaram a sua vida! Voce desviou do ataque!" + Estilo::RESET, 10);
                } else{

                    int danoRecebido = adversario.getDanoBase();
                    jogador.recebeDano(danoRecebido); 
                    Estilo::impressaoEscrita(Estilo::VERMELHO + ">> Voce sofreu " + std::to_string(danoRecebido) + " de dano! <<" + Estilo::RESET, 10);
                }
            }

            if(jogador.vivo() && adversario.vivo() && !fugiu){
                Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para continuar...)" + Estilo::RESET, 10);
                std::cin.ignore(999996799999, '\n');
                std::cin.get();
            }
        } else{
            Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Entrada invalida.\n" + Estilo::RESET, 10);
            std::cin.clear();
            std::cin.ignore(999996799999, '\n');
            Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para tentar de novo...)" + Estilo::RESET, 10);
            std::cin.get();
        }
    }

    Estilo::limpaTela();
    if(fugiu){

        Estilo::impressaoEscrita(Estilo::AMARELO + "FUGA BEM SUCEDIDA. Mas a que custo...?" + Estilo::RESET, 15);
        return false;
    } else if(jogador.vivo()){

        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + ">>> AMEACA ELIMINADA <<<" + Estilo::RESET, 15);
        Estilo::impressaoEscrita("O " + adversario.getNome() + " cai sem vida no chao.\n", 15);
        return true; 
    }
    Estilo::impressaoEscrita(Estilo::VERMELHO + "=========================================", 5);
    Estilo::impressaoEscrita("SINAIS VITAIS CRITICOS... FALHA NO SISTEMA.", 15);
    Estilo::impressaoEscrita("VOCE MORREU.", 25);
    Estilo::impressaoEscrita("=========================================" + Estilo::RESET, 5);
    return false;
}