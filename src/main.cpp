#include <iostream>
#include <string>
#include "../include/Estilo.hpp" 
#include "../include/Personagem.hpp"
#include "../include/Narrativa.hpp"
#include "../include/Inimigo.hpp"
#include "../include/Combate.hpp"

int lerAtributos(std::string nomeAtributo, int& pontosRestantes);
Personagem criarPersonagem();
void menuInicial();
void gameOver();
void creditosFinais();


//bem longe da versao final e nao ta escrito o quanto que eu mudei essa main para testar kkkkkkkkkkkk
int main(){

    Estilo::limpaTela();
    menuInicial();
    Personagem jogador = criarPersonagem();
    Estilo::limpaTela();
    
    Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para plugar o cabo neural em Dawn City...)" + Estilo::RESET, 10);
    std::cin.ignore(999996799999, '\n');
    std::cin.get();

    Narrativa::cenaUmContrato(jogador);

    Narrativa::cenaDoisInvasao(jogador);
    
    if(!jogador.vivo()){
        
        gameOver();
        return 0; 
    }

    Narrativa::cenaTresLaboratorioFinal(jogador);
    
    if(!jogador.vivo()){
        
        gameOver();
        return 0; 
    }

    creditosFinais();

    return 0;
}

void menuInicial(){
    
    Estilo::impressaoEscrita(Estilo::VERMELHO + "=====================================================\n", 2);
    Estilo::impressaoEscrita("                   CPP-2067           \n", 10);
    Estilo::impressaoEscrita("=====================================================\n" + Estilo::RESET, 2);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "       [Pressione ENTER para Iniciar a JORNADA]      \n\n" + Estilo::RESET, 5);
    std::cin.get();
}

int lerAtributos(std::string nomeAtributo, int& pontosRestantes, int base){

    int v;
    while(true){
        //trocar impressao para a estilizada
        std::cout << Estilo::AMARELO << "Pontos restantes: " << pontosRestantes << Estilo::RESET << "\n";
        std::cout << Estilo::AMARELO << "Sua base em " << Estilo::AZUL << nomeAtributo << Estilo::RESET << " e " << base << ". Quantos pontos alocar? (0 a " << pontosRestantes << "): ";

        if(std::cin >> v){

            if(v >= 0 && v <= pontosRestantes){

                pontosRestantes -= v;
                return base + v;
            }
            //trocar impressao para a estilizada
            std::cout << Estilo::VERMELHO << "[ERRO] Valor invalido. Digite um numero entre 0 e " << pontosRestantes << ".\n" << Estilo::RESET;
            continue;
        }
        //trocar impressao para a estilizada
        std::cout << Estilo::VERMELHO << "[ERRO] Entrada invalida. Digite apenas numeros.\n" << Estilo::RESET;
        std::cin.clear();
        std::cin.ignore(999996799999, '\n');
    }
}

Personagem criarPersonagem(){

    std::string nome;
    int opcaoClasse;
    std::string classe;
    int bForca = 1, bReflexos = 1, bInteligencia = 1, bTecnica = 1, bMoral = 1, bCarisma = 1, bSorte = 1;

    Estilo::limpaTela();
    Estilo::impressaoEscrita(Estilo::DESTAQUE + Estilo::AMARELO + "TERMINAL DE CRIACAO DE MERCENARIO" + Estilo::RESET, 10);
    std::cout << "\n";
    //trocar impressao para a estilizada
    std::cout << Estilo::VERDE_CLARO << "Digite seu nome ou apelido : " << Estilo::RESET << "\n";
    std::getline(std::cin, nome);

    bool classeValida = false;
    while(!classeValida){
        //trocar impressao para a estilizada
        std::cout << Estilo::CIANO << "Escolha sua Especializacao (Classe):" << Estilo::RESET << "\n";
        std::cout << Estilo::AZUL << "[1] Solo      (Especialista em Combate)" << "\n";
        std::cout << Estilo::AZUL << "[2] Netrunner (Mestre da Rede e Invasao)" << "\n";
        std::cout << Estilo::AZUL << "[3] Techie    (Engenheiro e tecnologo)" << "\n";
        std::cout << Estilo::AZUL << "[4] Nomad     (Sobrevivente dos Ermos)" << "\n";
        std::cout << Estilo::AZUL << "[5] Corpo     (Estrategista Corporativo)" << "\n" << Estilo::RESET << "\n";
        std::cout << Estilo::CIANO << "Escolha de 1 a 5: ";

        if(std::cin >> opcaoClasse){

            switch(opcaoClasse){

                case 1:
                    classe = "Solo";
                    bForca = 6; bReflexos = 6; bInteligencia = 1; bTecnica = 2; bMoral = 3; bCarisma = 1; bSorte = 2;
                    classeValida = true;
                    break;
                case 2:
                    classe = "Netrunner";
                    bForca = 1; bReflexos = 3; bInteligencia = 7; bTecnica = 4; bMoral = 2; bCarisma = 1; bSorte = 3;
                    classeValida = true;
                    break;
                case 3:
                    classe = "Techie";
                    bForca = 3; bReflexos = 3; bInteligencia = 3; bTecnica = 6; bMoral = 2; bCarisma = 2; bSorte = 2;
                    classeValida = true;
                    break;
                case 4:
                    classe = "Nomad";
                    bForca = 4; bReflexos = 4; bInteligencia = 1; bTecnica = 3; bMoral = 3; bCarisma = 3; bSorte = 3;
                    classeValida = true;
                    break;
                case 5:
                    classe = "Corpo";
                    bForca = 2; bReflexos = 2; bInteligencia = 2; bTecnica = 1; bMoral = 3; bCarisma = 6; bSorte = 5;
                    classeValida = true;
                    break;
                default:
                    //trocar impressao para a estilizada
                    std::cout << Estilo::VERMELHO << "[ERRO] Opcao invalida. Escolha um numero entre 1 e 5." << Estilo::RESET << "\n";
                    break;    
            }
        } else{
            //trocar impressao para a estilizada
            std::cout << Estilo::VERMELHO << "[ERRO] Entrada invalida. Digite apenas numeros." << Estilo::RESET << "\n";
            std::cin.clear();
            std::cin.ignore(999996799999, '\n');
        }        
    }

    int pontos = 11;
    int pontosLivres;
    int forca, reflexos, inteligencia, tecnica, moral, sorte, carisma;
    do{

        pontosLivres = pontos;

        Estilo::limpaTela();
        //trocar impressao para a estilizada ou nao porque vai ser chato e é culpa sua ter se esquecido da funcao que voce mesmo criou.
        std::cout << Estilo::ROSA << ">>> ALOCACAO DE ATRIBUTOS NEUROBIOLOGICOS <<<" << Estilo::RESET << "\n";
        std::cout << "Voce tem " << Estilo::AMARELO << pontosLivres << " pontos livres" << Estilo::RESET << " para distribuir.\n";
    
        forca = lerAtributos("FORCA", pontosLivres, bForca);
        reflexos = lerAtributos("REFLEXOS", pontosLivres, bReflexos);
        inteligencia = lerAtributos("INTELIGENCIA", pontosLivres, bInteligencia);
        tecnica = lerAtributos("TECNICA", pontosLivres, bTecnica);
        moral = lerAtributos("MORAL", pontosLivres, bMoral);
        sorte = lerAtributos("SORTE", pontosLivres, bSorte);
        carisma = lerAtributos("CARISMA", pontosLivres, bCarisma);

        if(pontosLivres > 0){
            //trocar impressao para a estilizada ou nao porque vai ser chato e é culpa sua ter se esquecido da funcao que voce mesmo criou.
            std::cout << "\n" << Estilo::VERMELHO << "[SISTEMA] Alerta: Voce nao gastou todos os seus pontos (" << pontosLivres << " sobrando)." << Estilo::RESET << "\n";
            std::cout << Estilo::CINZA_ESCURO << "Reiniciando calibracao neural. Aloque TODOS os pontos para prosseguir.\n";
            std::cout << "(Pressione ENTER para tentar novamente...)" << Estilo::RESET;
            std::cin.ignore(999996799999, '\n');
            std::cin.get();
        }
    }while(pontosLivres > 0);
    //trocar impressao para a estilizada ou nao porque vai ser chato e é culpa sua ter se esquecido da funcao que voce mesmo criou.
    std::cout << "\n" << Estilo::AMARELO << ">>>[SISTEMA] Perfil bio-digital salvo com sucesso.<<<" << Estilo::RESET << "\n";
    Estilo::impressaoEscrita("...", 1000);

    return Personagem(nome, classe, forca, reflexos, inteligencia, tecnica, moral, sorte, carisma);
}

void gameOver(){
    
    Estilo::limpaTela();
    std::cout << "\n\n";
    Estilo::impressaoEscrita(Estilo::VERMELHO + "=====================================================\n", 1);
    Estilo::impressaoEscrita("                     GAME OVER                       \n", 25);
    Estilo::impressaoEscrita("=====================================================\n" + Estilo::RESET, 1);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + " O seu sinal vital fraco foi detectado pela SAMU TEAM.\n", 15);
    Estilo::impressaoEscrita(" Dawn City mastigou suas ambicoes e cuspiu a carcaca.\n\n" + Estilo::RESET, 15);
    Estilo::impressaoEscrita(Estilo::VERMELHO + "[CONEXAO NEURAL ENCERRADA]\n\n" + Estilo::RESET, 10);
}

void creditosFinais(){
    
    Estilo::limpaTela();
    std::cout << "\n\n";
    Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "=====================================================\n", 2);
    Estilo::impressaoEscrita("                OBRIGADO POR JOGAR                   \n", 15);
    Estilo::impressaoEscrita("                Feito por: MIM                   \n", 70);
    Estilo::impressaoEscrita("                Brincadeira...                   \n", 70);
    Estilo::impressaoEscrita("                Feito por: >> fsbits <<                   \n", 70);
    Estilo::impressaoEscrita("=====================================================\n" + Estilo::RESET, 2);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + " Desenvolvido para o desafio final da trilha Sapphiron.\n", 10);
}

//no fim acho que nem vou trocar a impressao aqui muita preguica