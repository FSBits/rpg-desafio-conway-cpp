#include "../include/Combate.hpp"
#include "../include/Estilo.hpp"
#include <iostream>
#include <string>


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
    EstadoCombate estado;

    while(jogador.vivo() && adversario.vivo() && !estado.fugiu){

        bool hackBloqueado = (estado.curtoUsado && estado.sabotagemUsada && estado.sobrecargaUsada);
        exibirHUDCombate(jogador, adversario, hackBloqueado);

        if(std::cin >> escolha){

            std::cout << "\n";

            bool turnoGasto = false;

            switch(escolha){

                case 1: {//atk

                    turnoGasto = ataqueJogador(jogador, adversario);
                    break;
                }
                case 2: { //inv
                
                    turnoGasto = acessarInv(jogador);
                    break;
                }
                case 3: { //hackearam meu email hackearam meu site

                    turnoGasto = executarInvasao(jogador, adversario, estado, gen, d100);
                    break;
                }

                case 4: { //covardia ou genialidade

                    turnoGasto = tryFuga(jogador, estado, gen, d100);
                    break;
                }

                default:
                    
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Voce hesitou! Acao invalida.\n" + Estilo::RESET, 10);
                    break;
            } 

            if(adversario.vivo() && !estado.fugiu && turnoGasto) executarTurnoInimigo(jogador, adversario, estado.inimigoSabotado, gen, d100);

            if(jogador.vivo() && adversario.vivo() && !estado.fugiu){
                
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
    
    if(estado.fugiu){

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

void Combate::exibirHUDCombate(Personagem& jogador, Inimigo& adversario, bool hackBloqueado){
    
    Estilo::limpaTela();
    Estilo::impressaoEscrita(Estilo::AMARELO + ">>> STATUS DE COMBATE <<<\n" + Estilo::RESET, 5);
    Estilo::impressaoEscrita("-----------------------------------------\n", 5);
    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + " [HP: " + Estilo::VERDE_CLARO + std::to_string(jogador.getHpAtual()) + "/" + std::to_string(jogador.getHpMax()) + Estilo::CIANO + "]\n" + Estilo::RESET, 5);
    Estilo::impressaoEscrita(Estilo::ROSA + adversario.getNome() + " [HP: " + Estilo::VERMELHO + std::to_string(adversario.getHpAtual()) + "/" + std::to_string(adversario.getHpMax()) + Estilo::ROSA + "]\n" + Estilo::RESET, 5);
    Estilo::impressaoEscrita("-----------------------------------------\n\n", 5);
    
    Estilo::impressaoEscrita("Sua vez de agir:\n", 5);
    Estilo::impressaoEscrita("[1] " + Estilo::VERMELHO + "Atacar com " + jogador.getArmaEquipada().nome + Estilo::RESET + "\n", 5);
    Estilo::impressaoEscrita("[2] " + Estilo::AMARELO + "Abrir Mochila (Inventario)" + Estilo::RESET + "\n", 5);
        
    if(!hackBloqueado) Estilo::impressaoEscrita("[3] " + Estilo::VERDE_CLARO + "Protocolos de Invasao (Hackear)" + Estilo::RESET + "\n", 5);
    else Estilo::impressaoEscrita("[3] " + Estilo::AZUL + "Protocolos de Invasao (BLOQUEADO PELO ICE)" + Estilo::RESET + "\n", 5);
        
    Estilo::impressaoEscrita("[4] " + Estilo::MAGENTA + "Recuo Tatico / Fugir" + Estilo::RESET + "\n", 5);
        
    Estilo::impressaoEscrita("\nEscolha: ", 5);
}

bool Combate::ataqueJogador(Personagem& jogador, Inimigo& adversario){

    Item arma = jogador.getArmaEquipada();
    int bonusDamage = 0;
    std::string avisoAtributo = "";
                    
    if(arma.armaDeFogo){
        
        bonusDamage = jogador.getMoral() * 2;
        avisoAtributo = " (Bonus de Moral)";
    } else{

        bonusDamage = jogador.getForca() * 2;
        avisoAtributo = " (Bonus de Forca)";
    }
                    
    int danoCausado = arma.valorEfeito + bonusDamage;      
    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + Estilo::RESET + " ataca com " + arma.nome + "!\n", 15);
    adversario.recebeDano(danoCausado);
    Estilo::impressaoEscrita(Estilo::MAGENTA + ">> Causou " + std::to_string(danoCausado) + " de dano!" + avisoAtributo + " <<\n" + Estilo::RESET, 15);
    return true;
}

bool Combate::acessarInv(Personagem &jogador){

    jogador.listarInv();

    Estilo::impressaoEscrita("\nDigite o numero do item que deseja usar (ou qualquer coisa para fechar a mochila): ", 5);

    int index;
    if(std::cin >> index && index >= 0) return jogador.usarItem(index);
    else{

        std::cin.clear();
        std::cin.ignore(999996799999, '\n');
        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce fechou a mochila rapidamente." + Estilo::RESET, 10);
        return false;
    }
}

bool Combate::executarInvasao(Personagem& jogador, Inimigo& adversario, EstadoCombate& estado, std::mt19937& gen, std::uniform_int_distribution<>& d100){
    
    if(estado.curtoUsado && estado.sabotagemUsada && estado.sobrecargaUsada){
        
        Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] ICE adaptativo detectado. Invasao indisponivel." + Estilo::RESET + "\n", 10);
        return false;
    }
    
    Estilo::impressaoEscrita(Estilo::VERDE_CLARO + ">>> PROTOCOLOS DE INVASAO <<<" + Estilo::RESET + "\n", 5);
    
    if(!estado.curtoUsado) Estilo::impressaoEscrita(Estilo::VERMELHO + "[1] Curto-Circuito (Atordoa 1 turno - Low Skill)\n" + Estilo::RESET, 5);
    else Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "[1] Curto-Circuito (BLOQUEADO PELO ICE)\n" + Estilo::RESET, 5);
   
    if(!estado.sabotagemUsada) Estilo::impressaoEscrita(Estilo::VERMELHO + "[2] Sabotagem Optica (Reduz dano inimigo - Medium Skill)\n" + Estilo::RESET, 5);
    else Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "[2] Sabotagem Optica (BLOQUEADO PELO ICE)\n" + Estilo::RESET, 5);
    
    if(!estado.sobrecargaUsada) Estilo::impressaoEscrita(Estilo::VERMELHO + "[3] Sobrecarga Neural (Dano direto massivo - High Skil)\n" + Estilo::RESET, 5);
    else Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "[3] Sobrecarga Neural (BLOQUEADO PELO ICE)\n" + Estilo::RESET, 5);
    
    Estilo::impressaoEscrita("Escolha o protocolo (ou digite qualquer coisa para cancelar): " + Estilo::RESET, 5);

    int hackOption;
    if(std::cin >> hackOption && hackOption >= 1 && hackOption <= 3){
        
        int intel = jogador.getInteligencia();
        int dado = d100(gen);
        int chance = 0;
        bool stunBonus = false;
        bool hackTry = false;
        
        Estilo::impressaoEscrita(Estilo::AMARELO + "\n[SISTEMA] Iniciando quebra de ICE (Inteligencia: " + std::to_string(intel) + ")...\n" + Estilo::RESET, 20);

        switch(hackOption){
            
            case 1: {
                
                if(estado.curtoUsado) Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] O sistema inimigo ja se adaptou a este protocolo." + Estilo::RESET + "\n", 10);
                else{
                    
                    estado.curtoUsado = true; 
                    hackTry = true;
                    chance = 40 + (intel * 10);
                    
                    if(dado <= chance){
                        
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] Curto-circuito aplicado! Sistemas motores travados." + Estilo::RESET + "\n", 10);
                        Estilo::impressaoEscrita(Estilo::CIANO + ">> BRECHA ABERTA: Voce ganhou uma acao extra neste turno! <<\n" + Estilo::RESET, 10);
                        stunBonus = true;
                    } else
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] Acesso negado pelo ICE corporativo." + Estilo::RESET + "\n", 10);
                } 
                break;
            }
            
            case 2: {
                
                if(estado.sabotagemUsada) Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] O sistema inimigo ja se adaptou a este protocolo." + Estilo::RESET + "\n", 10);
                else{
                    
                    chance = 30 + (intel * 10);
                    estado.sabotagemUsada = true;
                    hackTry = true;

                    if(dado <= chance){
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] Modulos oticos corrompidos. Precisao inimiga reduzida drasticamente!" + Estilo::RESET + "\n", 10);
                        estado.inimigoSabotado = true;
                    } else
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] Acesso negado pelo ICE corporativo." + Estilo::RESET + "\n", 10);
                }
                break;
            } 
            
            case 3: {
                if(estado.sobrecargaUsada) Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] O sistema inimigo ja se adaptou a este protocolo." + Estilo::RESET + "\n", 10);
                else {
                    
                    chance = 10 + (intel * 10);
                    estado.sobrecargaUsada = true;
                    hackTry = true;
                    
                    if(dado <= chance){
                        int danoHack = 10 + (intel * 5);
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] Sobrecarga executada! Sinapses fritadas." + Estilo::RESET + "\n", 10);
                        adversario.recebeDano(danoHack);
                        Estilo::impressaoEscrita(Estilo::AZUL + ">> Causou " + std::to_string(danoHack) + " de DANO NEURAL! <<\n" + Estilo::RESET, 15);
                    } else 
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] ICE bloqueou o ataque e revidou a conexao." + Estilo::RESET + "\n", 10);
                }
                break;
            }
        }
    
        if(hackTry && !stunBonus) return true;
        return false;
        
    } else{
        
        std::cin.clear();
        std::cin.ignore(999996799999, '\n');
        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Conexao abortada pelo usuario." + Estilo::RESET, 10);
        return false;
    }
}

bool Combate::tryFuga(Personagem& jogador, EstadoCombate& estado, std::mt19937& gen, std::uniform_int_distribution<>& d100){

    int chance = 30 + (jogador.getReflexos() * 5) + (jogador.getSorte() * 5);
    int dado = d100(gen);

    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce tenta correr para as sombras...\n" + Estilo::RESET, 15);

    if(dado <= chance){
        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "Voce despistou o inimigo com sucesso!" + Estilo::RESET, 15);
        estado.fugiu = true;
    } else
        Estilo::impressaoEscrita(Estilo::VERMELHO + "O inimigo bloqueou a sua rota de fuga!" + Estilo::RESET, 15);
    
    return true;
}
                    
void Combate::executarTurnoInimigo(Personagem& jogador, Inimigo& adversario, bool inimigoSabotado, std::mt19937& gen, std::uniform_int_distribution<>& d100){
                    
    Estilo::impressaoEscrita("\n-----------------------------------------\n", 5);
    Estilo::impressaoEscrita(Estilo::ROSA + adversario.getNome() + Estilo::RESET + " contra-ataca!\n", 15);
                        
    int chanceEsquiva = (jogador.getReflexos() * 4) + (jogador.getSorte() * 2);
    int dadoEsquiva = d100(gen);
                        
    if(dadoEsquiva <= chanceEsquiva) Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "* SWOOSH * Os seus reflexos salvaram a sua vida! Voce desviou do ataque!" + Estilo::RESET, 10);
     else{
                        
        int danoRecebido = adversario.getDanoBase();
                    
        if(inimigoSabotado){
                    
            int reducao = 10 + (jogador.getInteligencia() * 2);
            if(reducao > 60) reducao = 60;
                
            int danoReduzido = (danoRecebido * reducao) / 100;
            danoRecebido -= danoReduzido;
            if(danoRecebido < 1) danoRecebido = 1;
            Estilo::impressaoEscrita(Estilo::CIANO + "[Sabotagem Optica] O dano inimigo foi reduzido em " + std::to_string(reducao) + "%!\n" + Estilo::RESET, 10);
        }
                                            
        jogador.recebeDano(danoRecebido); 
        Estilo::impressaoEscrita(Estilo::VERMELHO + ">> Voce sofreu " + std::to_string(danoRecebido) + " de dano! <<" + Estilo::RESET, 10);
    }
}