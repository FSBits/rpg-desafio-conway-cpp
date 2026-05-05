#include "../include/Narrativa.hpp"
#include "../include/Estilo.hpp"
#include <iostream>

void Narrativa::cenaUmContrato(Personagem &jogador){

    bool contratoAceito = false;
    int escolha;
    
    Estilo::limpaTela();
    
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "O ceu acima do porto tinha a cor semelhante a de uma televisao sintonizada em um canal fora do ar.\n" + Estilo::RESET, 5);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "A chuva acida bate na janela rachada do 'Pos Vida'. O bar cheira a oleo de motor e desespero.\n" + Estilo::RESET, 5);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Do outro lado da mesa pegajosa esta Jox Deschamp, o seu Fixer.\n" + Estilo::RESET, 5);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "O olho cibernetico dele zumbe enquanto te analisa.\n\n" + Estilo::RESET, 5);

    Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Tenho um trabalho para ti, " + Estilo::RESET + Estilo::CIANO + jogador.getNome() + Estilo::RESET +  Estilo::AMARELO + ". Direto ao assunto.\"\n" + Estilo::RESET, 10);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "*(Jox desliza um chip de dados de cor preta sobre a mesa molhada)*\n" + Estilo::RESET, 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " +  Estilo::RESET + Estilo::AMARELO + "\"Roubo de tecnologia. Um prototipo de processador neural no laboratorio da OpemTech. O cliente e... anonimo. Mas pagou adiantado num cred-chip nao rastreavel. Cheira-me a espionagem corporativa, chapa.\"\n\n" + Estilo::RESET, 10);
    
    do{
        
        std::cout << Estilo::CIANO << "O QUE VOCE FAZ?" << Estilo::RESET << "\n";
        Estilo::impressaoEscrita("[1] " +  Estilo::VERDE_CLARO + "(Aceitar contrato - AVANCAR A HISTORIA)" +  Estilo::RESET + Estilo::AMARELO + " \"Parece facil. Eu trato disso.\"\n" + Estilo::RESET, 5);
        Estilo::impressaoEscrita(Estilo::CIANO + "-------------------------------------------" + Estilo::RESET + "\n", 5);
        Estilo::impressaoEscrita("[2] " +  Estilo::ROSA + "(Carisma)" +  Estilo::RESET + Estilo::AMARELO + " \"Um trabalho destes vale o dobro, Jox. Nao sou um pe rapado.\"\n" + Estilo::RESET, 5);
        Estilo::impressaoEscrita("[3] " +  Estilo::ROSA + "(Inteligencia / Tecnica)" +  Estilo::RESET + Estilo::AMARELO + " [Analisar o Chip de Dados na mesa]\n" + Estilo::RESET, 5);
        Estilo::impressaoEscrita("[4] " +  Estilo::ROSA + "(Moral)" +  Estilo::RESET + Estilo::AMARELO + " \"Nao confio em clientes anonimos. Fala, Jox.\"\n" + Estilo::RESET, 5);

        Estilo::impressaoEscrita("\nEscolha (1-4): ", 5);

        if(std::cin >> escolha){

            Estilo::impressaoEscrita("\n-------------------------------------------\n", 10);

            switch(escolha){

                case 1:
                    Estilo::impressaoEscrita("Voce pega o chip e guarda no casaco. O contrato esta selado.\n", 10);
                    Estilo::impressaoEscrita(Estilo::AMARELO + "Jox: " + Estilo::RESET + "\"Sabia que nao ia me decepcionar, mermao. Cuidado com os cromos da Kuroyama.\"\n", 10);
                    contratoAceito = true;
                    break;

                case 2:
                    if(jogador.getCarisma() >= 4){
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::RESET + Estilo::CINZA_ESCURO + "Jox ri, exibindo o cromo nos seu dentes que tem escrito \"GO! GO! DESCHAMP\", e concorda com o bonus.\n" + Estilo::RESET, 10);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Voce tem culhoes. Metade a mais se voltar com a peca intacta.\"\n" + Estilo::RESET, 10);
                    }
                    else{

                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::RESET + Estilo::CINZA_ESCURO + "Jox tosse fumo sintetico na sua cara.\n" + Estilo::RESET, 10);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Tu nao tem essa aura toda nao colega. E pegar ou largar.\"\n" + Estilo::RESET, 10);
                    }
                    break;

                case 3:
                     if (jogador.getInteligencia() >= 4 || jogador.getTecnica() >= 4) {
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::RESET + Estilo::CINZA_ESCURO + "Seus implantes oticos scaneiam o chip. Voce nota uma encriptacao fractal de nivel militar.\n" + Estilo::RESET, 10);
                        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + Estilo::AMARELO + "\"Jox, quem codificou isto nao queria ninguem metendo o nariz onde nao deve...\"\n" + Estilo::RESET, 10);
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Jox engole em seco e desvia o olhar.\n" + Estilo::RESET, 10);
                     }
                     else{

                         Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::RESET + Estilo::CINZA_ESCURO + "Voce tenta acessar o chip, mas o ICE devolve um choque que queima suas lentes.\n" + Estilo::RESET, 10);
                         Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce nao descobre nada de util.\n" + Estilo::RESET, 10);
                        }
                        break;

                case 4:
                    if (jogador.getMoral() >= 3) {
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::RESET  + Estilo::CINZA_ESCURO + "Com um olhar frio e inabalavel, sua aura intimida Jox.\n" + Estilo::RESET, 10);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Ok, ok, mermao... O dinheiro veio de contas fantasma que mudam de servidor a cada segundo. Satisfeito?\"\n" + Estilo::RESET, 10);
                    }
                    else{

                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::CINZA_ESCURO + "Jox ignora a sua intimidacao.\n" + Estilo::RESET, 10);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Deixe de ser paranoico, chapa. Dinheiro e dinheiro.\"\n" + Estilo::RESET, 10);
                    }
                    break;

                default: 
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Opcao invalida tchum, escolha de 1 a 4" + Estilo::RESET + "\n", 10);
                    break;
            }
   
            std::cout << "\n" << Estilo::CINZA_ESCURO << "(Pressione ENTER para continuar...)" << Estilo::RESET;
            std::cin.ignore(999996799999, '\n');
            std::cin.get();
            std::cout << "\n";
        } else{

            Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Entrada invalida. Digite apenas numeros." + Estilo::RESET + "\n", 20);
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            
            Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para continuar...)" + Estilo::RESET, 10);
            std::cin.get();
            std::cout << "\n";
        }

    }while(!contratoAceito);
}