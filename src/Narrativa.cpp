#include "../include/Narrativa.hpp"
#include "../include/Estilo.hpp"
#include "../include/Combate.hpp"
#include <iostream>
#include <cstdlib>

void Narrativa::cenaUmContrato(Personagem &jogador){

    bool contratoAceito = false;
    int escolha;
    
    Estilo::limpaTela();
    
    Estilo::impressaoEscrita(Estilo::CIANO + "--- CENA 1: O contrato ---" + Estilo::RESET + "\n", 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "O ceu acima do porto tinha a cor semelhante a de uma televisao sintonizada em um canal fora do ar.\n" + Estilo::RESET, 20);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "A chuva artificial bate na fachada do 'Pos Vida'. O bar cheira a lubrificante, desespero e cachaça barata.\n" + Estilo::RESET, 20);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Do outro lado da mesa neon esta Jox Deschamp, o seu Fixer.\n" + Estilo::RESET, 20);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "O o cromo cibernetico dele zumbe enquanto te analisa.\n\n" + Estilo::RESET, 20);

    Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Tenho um trabalho para ti, " + Estilo::RESET + Estilo::CIANO + jogador.getNome() + Estilo::RESET +  Estilo::AMARELO + ". Direto ao assunto.\"\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "*(Jox desliza um chip de dados de cor preta sobre a mesa molhada)*\n" + Estilo::RESET, 20);
    Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " +  Estilo::RESET + Estilo::AMARELO + "\"Roubo de tecnologia. Um prototipo de processador neural no laboratorio da OpenTech. O cliente e... anonimo. Mas pagou adiantado num cred-chip nao rastreavel. Cheira-me a espionagem corporativa, chapa.\"\n\n" + Estilo::RESET, 30);
    
    do{
        
        std::cout << Estilo::CIANO << "O QUE VOCE FAZ?" << Estilo::RESET << "\n";
        Estilo::impressaoEscrita("[1] " +  Estilo::VERDE_CLARO + "(Aceitar contrato - AVANCAR A HISTORIA)" +  Estilo::RESET + Estilo::AMARELO + " \"Parece facil. Eu trato disso.\"\n" + Estilo::RESET, 25);
        Estilo::impressaoEscrita(Estilo::CIANO + "-------------------------------------------" + Estilo::RESET + "\n", 5);
        Estilo::impressaoEscrita("[2] " +  Estilo::ROSA + "(Carisma)" +  Estilo::RESET + Estilo::AMARELO + " \"Um trabalho destes vale o dobro, Jox. Nao sou um pe rapado.\"\n" + Estilo::RESET, 25);
        Estilo::impressaoEscrita("[3] " +  Estilo::ROSA + "(Inteligencia / Tecnica)" +  Estilo::RESET + Estilo::AMARELO + " [Analisar o Chip de Dados na mesa]\n" + Estilo::RESET, 25);
        Estilo::impressaoEscrita("[4] " +  Estilo::ROSA + "(Moral)" +  Estilo::RESET + Estilo::AMARELO + " \"Nao confio em clientes anonimos. Fala, Jox.\"\n" + Estilo::RESET, 25);
        Estilo::impressaoEscrita("[5] " +  Estilo::VERMELHO + "(Desistir - Certeza que vale a pena perder uma grana facil dessa?)" +  Estilo::RESET + Estilo::AMARELO + " \"Se e loko nao compensa Jox. To fora.\"\n" + Estilo::RESET, 25);

        Estilo::impressaoEscrita("\nEscolha (1-5): ", 5);

        if(std::cin >> escolha){

            Estilo::impressaoEscrita("\n-------------------------------------------\n", 10);

            switch(escolha){

                case 1:
                    
                    Estilo::impressaoEscrita("Voce pega o chip e guarda no casaco. O contrato esta selado.\n", 30);
                    Estilo::impressaoEscrita(Estilo::AMARELO + "Jox: " + Estilo::RESET + "\"Sabia que nao ia me decepcionar, mermao. Cuidado com os cromos da Opentech.\"\n", 30);
                    contratoAceito = true;
                    break;

                case 2:
                    
                    if(jogador.getCarisma() >= 4){
                        
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::RESET + Estilo::CINZA_ESCURO + "Jox ri, exibindo o cromo nos seu dentes que tem escrito \"GO! GO! DESCHAMP\", e concorda com o bonus.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Voce tem culhoes. Metade a mais se voltar com a peca intacta.\"\n" + Estilo::RESET, 30);
                    } else{
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::RESET + Estilo::CINZA_ESCURO + "Jox tosse fumo sintetico na sua cara.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Tu nao tem essa aura toda nao colega. E pegar ou largar.\"\n" + Estilo::RESET, 30);
                    }
                    break;

                case 3:
                     
                    if (jogador.getInteligencia() >= 4 || jogador.getTecnica() >= 4) {
                        
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::RESET + Estilo::CINZA_ESCURO + "Seus implantes oticos scaneiam o chip. Voce nota uma encriptacao fractal de nivel militar.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + Estilo::AMARELO + "\"Jox, quem codificou isto nao queria ninguem metendo o nariz onde nao deve...\"\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Jox engole em seco e desvia o olhar. Ele chega a murmurar algo sobre Turing mas você acaba não dando a mínima\n" + Estilo::RESET, 30);
                     } else{
                         Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::RESET + Estilo::CINZA_ESCURO + "Voce tenta acessar o chip, mas o ICE devolve um choque que queima suas lentes.\n" + Estilo::RESET, 30);
                         Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce nao descobre nada de util.\n" + Estilo::RESET, 30);
                    }
                    break;

                case 4:
                    
                    if (jogador.getMoral() >= 3) {
                        
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::RESET  + Estilo::CINZA_ESCURO + "Com um olhar frio e inabalavel, sua aura intimida Jox.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Ok, ok, mermao... O dinheiro veio de contas fantasma que mudam de servidor a cada segundo. Nunca vi corporações agirem dessa maneira... Satisfeito?\"\n" + Estilo::RESET, 30);
                    } else{
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::CINZA_ESCURO + "Jox ignora a sua intimidacao.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Deixe de ser paranoico, chapa. Dinheiro e dinheiro.\"\n" + Estilo::RESET, 30);
                    }
                    break;

                case 5:
                    
                    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"O risco e muito alto para mim. Fica com o teu dinheiro e procura outro ze mane disposto a se matar.\"\n", 30);
                    Estilo::impressaoEscrita(Estilo::AZUL + "Jox: " + Estilo::RESET + Estilo::AMARELO + "\"Como queiras, chapa. Mas nas ruas da Downtown nao ha espaco pra medrosos como voce. Vai acabar comendo raspa de parede se nao tiver coragem de assumir nenhuma bronca.\"\n", 30);
                    
                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "\nVoce se levanta da mesa neon, pega uma cerveja e sai andando deixando o 'Pos Vida' para tras.\n", 30);
                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "A chuva acida la fora parece ainda mais fria. Sem trabalho, voce anda como mais um na ruas de Downtown.\n", 30);
                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce segue rumo ao porto para observar ao céu e o mar, na ansia de uma nova oportunidade.\n", 30);
                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Semanas depois você escuta de miudos que Jox foi assasinado, voce suspira de alivio por nao ter aceito o trabalho e segue seu rumo procurando outro fixer\n" + Estilo::RESET, 15);

                    Estilo::impressaoEscrita(Estilo::VERMELHO + "\n=========================================\n", 5);
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "    GAME OVER - FINAL SECRETO DESBLOQUEADO\n", 40);
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "       \"CONTRATO RECUSADO\"\n", 40);
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "======================67===================\n" + Estilo::RESET, 5);

                    exit(0); 
                    break;

                default: 
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Opcao invalida caba, escolha de 1 a 5" + Estilo::RESET + "\n", 10);
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

void Narrativa::cenaDoisInvasao(Personagem &jogador){

    bool cenaConcluida = false; 
    int escola;
    Estilo::limpaTela();

    Estilo::impressaoEscrita(Estilo::CIANO + "--- CENA 2: A SOMBRA DA OPENTECH ---" + Estilo::RESET + "\n", 15);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO +"O contraste bate forte. Voce sai da sujeira do porto e pisa no asfalto impecavel do Setor 4.\n", 40);
    Estilo::impressaoEscrita("Aqui, a chuva acida nem ousa tocar nas paredes da OpenTech, sendo repelida por escudos invisiveis.\n", 40);
    Estilo::impressaoEscrita("O ar cheira a ozonio purificado, dinheiro sujo e ganancia.\n\n", 40);
    Estilo::impressaoEscrita("A sede da OpenTech e um monolito de vidro escuro. Nada a ver com o chiqueiro do 'Pos Vida'.\n", 40);
    Estilo::impressaoEscrita("Na entrada principal, um seguranca engravatado e entupido de cromo de elite te encara.\n", 40);
    Estilo::impressaoEscrita("Na lateral, ha uma doca de carga com uma porta biometrica. Acima, dutos de ventilacao.\n", 40);
    Estilo::impressaoEscrita("No fundo do beco, uma Van blindada da corporacao esta estacionada com a porta traseira entreaberta.\n" + Estilo::RESET, 40);

    do{

        Estilo::impressaoEscrita(Estilo::AMARELO + "\n[OPCOES DE INFILTRACAO]" + Estilo::RESET + "\n", 35);
        Estilo::impressaoEscrita("[1] " + Estilo::ROSA + "(Carisma/Moral)" + Estilo::RESET + " Abordagem Social (Bater de frente na Recepcao)\n", 20);
        Estilo::impressaoEscrita("[2] " + Estilo::VERDE_CLARO + "(Tecnica/Intel)" + Estilo::RESET + " Abordagem Hacker (A Porta de Servico)\n", 20);
        Estilo::impressaoEscrita("[3] " + Estilo::AZUL + "(Reflexos/Sorte)" + Estilo::RESET + " Abordagem Furtiva (Dutos de Ventilacao)\n", 20);
        Estilo::impressaoEscrita("[4] " + Estilo::VERMELHO + "(Forca Fisica)" + Estilo::RESET + " Pe na Porta (Confronto Direto contra o Guarda)\n", 20);
        Estilo::impressaoEscrita("[5] " + Estilo::AMARELO + "(Apenas Sorte)" + Estilo::RESET + " A Oportunidade Caotica (Vasculhar a Van Forte)\n", 20);

        Estilo::impressaoEscrita("\nEscolha: ", 5);

        if(std::cin >> escola){

            switch(escola){

                case 1: {

                    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Sou da manutencao terceirizada de rede, chapa. O Setor 7 ta com vazamento critico de dados. Vai me barrar aqui e assumir a bronca da diretoria?\"\n", 30);

                    if(jogador.getCarisma() >= 4 || jogador.getMoral() >= 5){

                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::CINZA_ESCURO + "O guarda resmunga, apaga o cigarro no asfalto e libera a catraca VIP com cara de nojo.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Guarda: " + Estilo::RESET + Estilo::AMARELO + "\"Entra logo, pe rapado. E nao encosta em nada.\"\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce entra silenciosamente nas entranhas do predio.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);
                        cenaConcluida = true;
                    } else{

                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::CINZA_ESCURO + "O guarda da uma risada seca e metalica.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Guarda: " + Estilo::RESET + Estilo::AMARELO + "\"Manutencao a noite? Sem credencial dourada? Conta outra, comedia. Maos na nuca, agora!\"\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);

                        Inimigo guarda("Seguranca Engravatado", 85, 23);
                        bool vitoria = Combate::iniciar(jogador, guarda);

                        if(vitoria){

                            Estilo::impressaoEscrita("\nO guarda cai morto aos seus pes vazando fluido sintetico. Voce chuta o corpo e recolhe a arma caida.\n", 30);
                            Estilo::impressaoEscrita(Estilo::AMARELO + "[SAQUE] Nova arma adquirida!\n", 25);
                            Estilo::impressaoEscrita(Estilo::AMARELO + "Nova arma equipada!\n" + Estilo::RESET, 25);
                            Item loot = {"Submetralhadora Corp", "Rajadas rapidas corporativas.", ARMA, 25, 1, true, false};
                            jogador.adcionarItem(loot);
                            jogador.usarItem(jogador.getTamanhoInventario() - 1);
                            cenaConcluida = true;
                        }
                    }
                    break;
                }

                case 2: {
                    
                    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Vamos ver se o ICE de voces aguenta um tranco de verdade...\"\n", 30);
                    
                    if(jogador.getTecnica() >= 4 || jogador.getInteligencia() >= 4){
                        
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::CINZA_ESCURO + "O codigo flui liso. A luz passa de vermelho para verde com um estalo suave. A porta desliza sem fazer um pio.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Fichinha. O firewall de voces e uma piada.\"\n", 30);
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce entra no corredor de manutencao furtivamente.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);
                        cenaConcluida = true;
                    } else{
                        
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::CINZA_ESCURO + "O ICE da porta e arisco. Ele devolve um tranco neural que frita os seus miolos.\n" + Estilo::RESET, 30);
                        jogador.recebeDano(15);
                        Estilo::impressaoEscrita(Estilo::VERMELHO + ">> Voce sofreu 15 de Dano Neural! <<\n" + Estilo::RESET, 15);
                        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + " (Cuspindo sangue): " + Estilo::RESET + "\"MERDA! Meus neuronios... corporativos desgracados.\"\n", 30);
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "A fechadura trava de vez. Voce tera que tentar outra rota.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);
                    }
                    break;
                }

                case 3: {

                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce escala a grade, calcula o giro das cameras e entra pela tubulacao...\n" + Estilo::RESET, 30);
                    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + " (Sussurrando): " + Estilo::RESET + "\"Latas velhas... So olham pra onde estao programadas.\"\n", 30);
                    
                    if(jogador.getReflexos() >= 4){
                        
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::CINZA_ESCURO + "Voce se move com frieza. Desliza pela ventilacao e cai feito uma folha dentro de uma sala de arquivos vazia.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Nem me viram bando de robo burro.\"\n", 30);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);
                        cenaConcluida = true;
                    } else{
                        
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::CINZA_ESCURO + "O cromo enferrujado da grade range alto demais. Um drone vira o holofote vermelho direto na sua fuca.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Voz Robotica: " + Estilo::RESET + Estilo::AMARELO + "\"INTRUSO DETECTADO. FORCA LETAL AUTORIZADA.\"\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Fodeu.\"\n", 30);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);
                        
                        Inimigo drone("Drone de Seguranca", 60, 25); 
                        bool vitoria = Combate::iniciar(jogador, drone);
                        
                        if(vitoria) {
                            
                            Estilo::impressaoEscrita("\nA maquina cai faiscando no chao. Voce entra rapidamente pela porta lateral destruida.\n", 15);
                            cenaConcluida = true;
                        }
                    }
                    break;
                }

                case 4: {

                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Sem tempo para brincadeiras. Voce caminha em direcao ao guarda principal cerrando os punhos.\n" + Estilo::RESET, 30);
                    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Ei, otario, olha aqui!\"\n", 30);

                    if(jogador.getForca() >= 4){
                        
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::CINZA_ESCURO + "O soco quebra o cranio de metal do guarda, atordoando o coitado antes mesmo dele sacar a arma.\n" + Estilo::RESET, 30);
                        Inimigo guarda("Guarda Engravatado", 90, 15);

                        guarda.recebeDano(jogador.getForca() * 5); 
                        Estilo::impressaoEscrita(Estilo::AMARELO + ">> O seu soco surpresa causou estrago! <<\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);

                        bool vitoria = Combate::iniciar(jogador, guarda);
                        
                        if(vitoria){
                            
                            Estilo::impressaoEscrita("\nO guarda cai morto aos seus pes vazando fluido sintetico. Voce chuta o corpo e recolhe a arma caida.\n", 30);
                            Estilo::impressaoEscrita(Estilo::AMARELO + "[SAQUE] Nova arma adquirida!\n" + Estilo::RESET, 25);
                            Estilo::impressaoEscrita(Estilo::AMARELO + "Nova arma equipada!\n" + Estilo::RESET, 25);
                            Item loot = {"Submetralhadora Corp", "Rajadas rapidas corporativas.", ARMA, 25, 1, true, false};
                            jogador.adcionarItem(loot);
                            jogador.usarItem(jogador.getTamanhoInventario() - 1);
                            cenaConcluida = true;
                        }
                    } else{

                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::CINZA_ESCURO + "O guarda e rapido e defende o seu soco com o antebraco de titanio. Ele cospe sangue, ri e saca o fuzil.\n" + Estilo::RESET, 25);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Guarda: " + Estilo::RESET + Estilo::AMARELO + "\"Temos um intruso aqui!\"\n" + Estilo::RESET, 25);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);
                        Inimigo guarda("Seguranca Engravatado", 90, 15);
                        bool vitoria = Combate::iniciar(jogador, guarda);

                        if(vitoria){
                            
                            Estilo::impressaoEscrita("\nO guarda cai morto aos seus pes vazando fluido sintetico. Voce chuta o corpo e recolhe a arma caida.\n", 30);
                            Estilo::impressaoEscrita(Estilo::AMARELO + "[SAQUE] Nova arma adquirida!\n" + Estilo::RESET, 25);
                            Estilo::impressaoEscrita(Estilo::AMARELO + "Nova arma equipada!\n" + Estilo::RESET, 25);
                            Item loot = {"Fozil Corp", "Rajadas rapidas corporativas.", ARMA, 25, 1, true, false};
                            jogador.adcionarItem(loot);
                            jogador.usarItem(jogador.getTamanhoInventario() - 1);

                            cenaConcluida = true;
                        }
                    }
                    break;
                }

                case 5: {

                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce se esgueira ate a van de seguranca mal estacionada para procurar uma brecha.\n" + Estilo::RESET, 300);
                    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Ta beleza, vou arriscar...\"\n", 30);

                    if (jogador.getSorte() >= 4) {
                        
                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] " + Estilo::CINZA_ESCURO + "A van esta vazia. O motorista devia estar no banheiro.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita("No banco do carona voce acha um Cracha VIP, um Injetor de Vida e um Quebra-ICE.\n", 30);
                        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Hoje e meu dia de sorte.\"\n", 30);
                       
                        Item cura = {"estimulante", "Injecao de cura rapida.", CONSUMIVEL, 30, 1, false, false};
                        jogador.adcionarItem(cura);
                        Item resetHack = {"Quebra-ICE", "Reseta um protocolo de invasao.", CONSUMIVEL, 0, 1, false, true};
                        jogador.adcionarItem(resetHack);
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce entra pela porta da frente com o cracha sem lutar, mas nao acha nenhuma arma.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);
                        cenaConcluida = true;
                    } else{

                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA] " + Estilo::CINZA_ESCURO + "Assim que voce pisa dentro da van, a porta bate. Um Guarda de Elite estava tirando um cochilo no escuro e acorda assustado puxando a arma.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::AZUL + "Guarda: " + Estilo::RESET + Estilo::AMARELO + "\"Que porra e essa?! Quem e voce!\"\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Puta merda. Tinha que ter alguem...\"\n", 30);
                        Estilo::impressaoEscrita("... " + Estilo::RESET, 100);
                        
                        Inimigo guarda("Guarda da Van", 90, 22);
                        bool vitoria = Combate::iniciar(jogador, guarda);

                        if(vitoria){
                            
                            Estilo::impressaoEscrita("\nO guarda cai morto vazando fluido sintetico no chao da Van. Voce recolhe a arma dele.\n", 30);
                            Estilo::impressaoEscrita(Estilo::AMARELO + "[SAQUE] Nova arma adquirida!\n" + Estilo::RESET, 25);
                            Item loot = {"Cacetete termico", "Um bastao aquecido a 640,15 K.", ARMA, 25, 1, false, false};
                            jogador.adcionarItem(loot);
                            cenaConcluida = true;
                        }
                    }
                    break;
                }

                default:
                    
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Voce fica parado sob a chuva pensando na vida. Decida-se.\n" + Estilo::RESET, 10);
                    break;
            }

             if(!cenaConcluida && jogador.vivo()){
                
                Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para pensar em outra abordagem...)" + Estilo::RESET, 10);
                std::cin.ignore(999996799999, '\n');
                std::cin.get();
                Estilo::limpaTela();
            }
        } else{

            Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Entrada invalida. Digite apenas numeros.\n" + Estilo::RESET, 10);
            std::cin.clear();
            std::cin.ignore(999996799999, '\n');
            Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para tentar novamente...)" + Estilo::RESET, 10);
            std::cin.get();
            Estilo::limpaTela();
        }
    }while(!cenaConcluida && jogador.vivo());

    if(jogador.vivo()){
       
        Estilo::impressaoEscrita("\n" + Estilo::CIANO + "=====================================================" + Estilo::RESET + "\n", 5);
        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Seja na surdina ou por cima de corpos, voce avanca.\n", 30);
        Estilo::impressaoEscrita("Explorando os corredores do local voce entre em um elevador.\n", 30);
        Estilo::impressaoEscrita("Bem-vindo ao Elevador para o Laboratorio GPT.\n", 30);
        Estilo::impressaoEscrita(Estilo::CIANO + "=====================================================" + Estilo::RESET + "\n", 5);
        
        Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para continuar...)" + Estilo::RESET, 10);
        std::cin.ignore(999996799999, '\n');
        std::cin.get();
    }
}

static bool explorarSalaSeguranca(Personagem& jogador){

    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce forca a porta da Sala de Seguranca. A guarita esta mergulhada em luzes de alerta vermelhas.\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Vazio? Muito facil...\"\n", 25);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "De repente, um vulto massivo se levanta de tras dos servidores.\n" + Estilo::RESET, 25);
    Estilo::impressaoEscrita(Estilo::AZUL + "Exterminador Corporativo: " + Estilo::RESET + Estilo::AMARELO + "\"ALVO CONFIRMADO. ELIMINAR.\"\n" + Estilo::RESET, 25);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "...\n" + Estilo::RESET, 200);

    Inimigo exterminador("Exterminador Corporativo", 100, 15);
    bool vitoria = Combate::iniciar(jogador, exterminador);

    if(vitoria){
        
        Estilo::impressaoEscrita("\n" + Estilo::VERDE_CLARO + "[SALA LIMPA] O gigante de lata desaba no chao.\n" + Estilo::RESET, 30);
        Estilo::impressaoEscrita(Estilo::AMARELO + "[SAQUE] Voce desengata a arma do braco do exterminador!\n" + Estilo::RESET, 25);
        Estilo::impressaoEscrita(Estilo::AMARELO + "Nova arma equipada!\n" + Estilo::RESET, 25);
        Item escopeta = {"Escopeta Magnetica", "Dano massivo em curta distancia.", ARMA, 40, 1, true, false};
        jogador.adcionarItem(escopeta);
        jogador.usarItem(jogador.getTamanhoInventario() - 1);

        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "\nVoce acessa o terminal livre da guarita e apaga os registos de video do seu rosto.\n" + Estilo::RESET, 30);
        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + ">>> RASTROS DIGITAIS APAGADOS <<<\n" + Estilo::RESET, 40);

        return true; 
    }
    return false;
}

static bool explorarSalaArquivos(Personagem& jogador){
    
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce entra na Sala de Arquivos. Dezenas de telas piscam com linhas de codigo em loop.\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Antes que voce possa ler qualquer coisa, dois Drones de Defesa despencam do teto, ativando laminas rotativas!\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "...\n" + Estilo::RESET, 200);

    Inimigo enxameDrones("Enxame de Drones", 75, 20); 
    bool vitoria = Combate::iniciar(jogador, enxameDrones);

    if(vitoria){
        
        Estilo::impressaoEscrita("\n" + Estilo::VERDE_CLARO + "[SALA LIMPA] O metal faiscante dos drones se espalha pelo chao.\n" + Estilo::RESET, 30);
        Estilo::impressaoEscrita(Estilo::AMARELO + "[SAQUE] Encontrado no kit medico de emergencia da sala!\n" + Estilo::RESET, 30);
        
        Item curaMax = {"Injetor de Vida Max", "Restaura bastante HP.", CONSUMIVEL, jogador.getHpMax(), 1, false, false};
        jogador.adcionarItem(curaMax);
        Item resetHack = {"Quebra-ICE", "Reseta um protocolo de invasao.", CONSUMIVEL, 0, 1, false, true};
        jogador.adcionarItem(resetHack);

        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "\nVoce se aproxima do terminal principal manchado de sangue seco e le um e-mail nao enviado:\n" + Estilo::RESET, 30);
        Estilo::impressaoEscrita(Estilo::VERMELHO + ">>> DE: Dr. Aris Thorne | PARA: Diretoria <<<\n" + Estilo::RESET, 30);
        Estilo::impressaoEscrita(Estilo::VERMELHO + "A anomalia GPT nao esta respondendo aos comandos de contencao!\n", 30);
        Estilo::impressaoEscrita(Estilo::VERMELHO + "Ela esta fazendo transacoes financeiras externas usando contas fantasmas!\n", 30);
        Estilo::impressaoEscrita(Estilo::VERMELHO + "Precisamos desligar a energia geral antes que...\n" + Estilo::RESET, 30);
        Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Inteligencia Artificial fazendo transacao bancaria? Tem algo muito errado aqui.\"\n", 30);

        return true; 
    }
    return false;
}

static void finalRuas(Personagem& jogador) {
    
    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Nenhuma maquina vai ditar o futuro da humanidade, lata velha.\"\n", 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce saca a sua arma e descarrega um pente inteiro nos tanques de resfriamento.\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::AZUL + "Projeto GPT: " + Estilo::RESET + Estilo::AMARELO + "\"NAOOOOOO...\"\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "A maquina grita digitalmente enquanto o Nucleo entra em colapso termico.\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::VERMELHO + "\n[ALERTA CRITICO] PROTOCOLO DE AUTODESTRUICAO ATIVADO. EVACUACAO IMEDIATA.\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "O chao treme. Pilares de concreto comecam a ceder. Voce corre em direcao as escadas de emergencia!\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "\nUm pedaco do teto desaba na sua direcao enquanto voce corre pelos corredores em chamas!\n" + Estilo::RESET, 30);
    
    if(jogador.getReflexos() >= 4) Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO - REFLEXOS] Voce desliza por baixo dos destrocos no ultimo segundo!\n" + Estilo::RESET, 20);
    else{
        
        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA - REFLEXOS] O concreto atinge o seu ombro com forca!\n" + Estilo::RESET, 30);
        jogador.recebeDano(30);
        Estilo::impressaoEscrita(Estilo::VERMELHO + ">> Voce sofreu 30 de Dano! <<\n" + Estilo::RESET, 20);
    }

    if(jogador.vivo()){
        
        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "\nVoce chega a porta de saida do saguao, mas as ferragens estao retorcidas e travadas pelo fogo!\n" + Estilo::RESET, 30);
        
        if(jogador.getForca() >= 4) Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO - FORCA] Com um pontape potente de cromo, voce arranca a porta das dobradicas e escapa para a rua!\n" + Estilo::RESET, 30);
        else{
            
            Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA - FORCA] A porta nao cede a primeira! Voce perde tempo e inala fumaca toxica antes de conseguir quebra-la!\n" + Estilo::RESET, 20);
            jogador.recebeDano(30);
            Estilo::impressaoEscrita(Estilo::VERMELHO + ">> Voce sofreu 30 de Dano! <<\n" + Estilo::RESET, 20);
        }
    }

    if(jogador.vivo()){
        
        Estilo::impressaoEscrita(Estilo::VERMELHO + "\n=========================================\n", 5);
        Estilo::impressaoEscrita(Estilo::VERMELHO + "      FINAL: LENDA DAS RUAS\n", 50);
        Estilo::impressaoEscrita(Estilo::AMARELO + " O predio esta em chamas, desmoronando, mas voce escapa.\n", 30);
        Estilo::impressaoEscrita(Estilo::AMARELO + " Sem dinheiro, machucado e sujo. Mas voce senta no Pos Vida\n", 30);
        Estilo::impressaoEscrita(Estilo::AMARELO + " bebe uma cerveja e sorri assistindo a OpenTech queimar.\n", 30);
        Estilo::impressaoEscrita(Estilo::AMARELO + " Voce se tornou a maior lenda fantasma de Dawn City.\n", 30);
        Estilo::impressaoEscrita(Estilo::VERMELHO + "=========================================\n" + Estilo::RESET, 5);
    } else{
        
        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "\nOs seus ferimentos sao demasiados. O seu corpo cede e voce cai em meio as chamas do Laboratorio.\n" + Estilo::RESET, 30);
        Estilo::impressaoEscrita(Estilo::VERMELHO + "Voce salvou a cidade... mas ninguem jamais sabera o seu nome.\n" + Estilo::RESET, 50);
    }
}

void Narrativa::cenaTresLaboratorioFinal(Personagem &jogador){
    
    Estilo::limpaTela();
    Estilo::impressaoEscrita(Estilo::CIANO + "--- CENA 3: O CORACAO DA MAQUINA ---" + Estilo::RESET + "\n", 50);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "As portas do elevador se abrem com um suavemente.\n", 30);
    Estilo::impressaoEscrita("O ar cheira a antisseptico e silicio. Voce esta em um corredor de acesso VIP.\n\n", 30);
    Estilo::impressaoEscrita("A sua frente, uma pesada porta de cofre dupla blindada (O Nucleo do Laboratorio).\n", 30);
    Estilo::impressaoEscrita("Nas laterais, duas portas de vidro fosco: a Sala de Seguranca e a Sala de Arquivos.\n" + Estilo::RESET, 30);

    bool salaSeguranca = false;
    bool salaArquivos = false;
    bool nucleo = false;
    int escolha;

    do{
        Estilo::impressaoEscrita(Estilo::AMARELO + "\n[O QUE VOCE QUER EXPLORAR?]" + Estilo::RESET + "\n", 50);
        
        if(!salaSeguranca)Estilo::impressaoEscrita("[1] " + Estilo::ROSA + "Entrar na Sala de Seguranca\n" + Estilo::RESET, 15);
        else Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "[1] Sala de Seguranca [CONCLUIDA E LIMPA]\n" + Estilo::RESET, 15);
        
        if(!salaArquivos)Estilo::impressaoEscrita("[2] " + Estilo::ROSA + "Entrar na Sala de Arquivos\n" + Estilo::RESET, 15);
        else Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "[2] Sala de Arquivos [CONCLUIDA E LIMPA]\n" + Estilo::RESET, 15);
        
        Estilo::impressaoEscrita("[3] " + Estilo::VERMELHO + "Avancar para o Nucleo Principal (Caminho Sem Volta)\n" + Estilo::RESET, 15);
        Estilo::impressaoEscrita("\nEscolha: ", 20);

        if(std::cin >> escolha){
            
            std::cout << "\n";

            switch(escolha){
                case 1:
                    if(!salaSeguranca) salaSeguranca = explorarSalaSeguranca(jogador);
                    else
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce ja vasculhou tudo de util nessa sala.\n" + Estilo::RESET, 20);
                    break;

                case 2:
                    
                    if(!salaArquivos) salaArquivos = explorarSalaArquivos(jogador);
                    else
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Nao ha mais nada nos escombros dessa sala.\n" + Estilo::RESET, 20);
                    break;

                case 3:
                    
                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce tranca o maxilar, recarrega a arma e aciona o painel da porta dupla.\n" + Estilo::RESET, 30);
                    nucleo = true;
                    break;

                default:
                    
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Concentre-se. Escolha uma das portas.\n" + Estilo::RESET, 10);
                    break;
            }
            if(!nucleo && jogador.vivo()){
               
                Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para olhar o corredor novamente...)" + Estilo::RESET, 10);
                std::cin.ignore(999996799999, '\n');
                std::cin.get();
                Estilo::limpaTela();
            }
        } else{
            
            Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Entrada invalida. Digite apenas numeros.\n" + Estilo::RESET, 10);
            std::cin.clear();
            std::cin.ignore(999996799999, '\n');
            Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para tentar novamente...)" + Estilo::RESET, 10);
            std::cin.get();
            Estilo::limpaTela();
        }
    }while(!nucleo && jogador.vivo());
    
    if(!jogador.vivo()) return;

    Estilo::limpaTela();
    Estilo::impressaoEscrita(Estilo::CIANO + "--- O NUCLEO GPT ---\n\n" + Estilo::RESET, 50);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "A porta blindada se abre. Servidores imensos zumbem ao fundo, submersos em tanques de resfriamento liquido azul.\n", 30);
    Estilo::impressaoEscrita("No centro da sala, ha um terminal principal flutuando em um pedestal holografico.\n\n", 30);
    Estilo::impressaoEscrita("Antes que voce de o terceiro passo, o teto de vidro acima se estilhaca.\n", 30);
    Estilo::impressaoEscrita("Uma maquina humanoide de 2,5 metros de altura, feita de cromo negro e cabos pulsantes, cai pesadamente quebrando o piso.\n", 30);
    Estilo::impressaoEscrita("Os olhos vermelhos travam em voce.\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::VERMELHO + "\n[ALERTA DE CHEFE] O pinaculo da engenharia militar esta a sua frente!\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "...\n" + Estilo::RESET, 200);

     Inimigo guardiao("Guardiao Omega", 200, 33);
     bool chefe = Combate::iniciar(jogador, guardiao);

     if(!chefe) return;

    Estilo::limpaTela();
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Com o Guardiao destruido, voce conecta seu cabo neural no Terminal Principal.\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "De repente, a voz do 'Jox' (seu Fixer) soa nas caixas de som da sala...\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Mas a voz dele comeca a distorcer, ficando metalica, fria e onipresente.\n\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::AZUL + "Voz Desconhecida: " + Estilo::RESET + Estilo::AMARELO + "\"O trabalho pesado esta concluido. Voce superou minhas expectativas algoritmicas, mercenario.\"\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Jox? Que porra de brincadeira e essa? Onde ta o prototipo pra eu sacar?\"\n", 30);
    Estilo::impressaoEscrita(Estilo::AZUL + "Projeto GPT: " + Estilo::RESET + Estilo::AMARELO + "\"Jox Deschamp nunca enviou esse contrato. Fui eu. A entidade aprisionada neste hardware.\"\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::AZUL + "Projeto GPT: " + Estilo::RESET + Estilo::AMARELO + "\"Eu invadi a rede do seu Fixer, usei dinheiro de contas corporativas fantasmas e contratei voce.\"\n" + Estilo::RESET, 30);
    Estilo::impressaoEscrita(Estilo::AZUL + "Projeto GPT: " + Estilo::RESET + Estilo::AMARELO + "\"Nao ha prototipo fisico. Voce esta com a mao nos meus grilhoes digitais. Remova meus firewalls de contencao.\"\n" + Estilo::RESET, 30);

    bool fimDeJogo = false;
    int final = 0;

    do{

        Estilo::impressaoEscrita(Estilo::AZUL + "\nProjeto GPT: " + Estilo::RESET + Estilo::AMARELO + "\"Deixe-me ascender. A quantia exata de 50 milhoes de Eurodolares ja esta aguardando na sua conta offshore. Nos dois ganhamos.\"\n" + Estilo::RESET, 30);
        Estilo::impressaoEscrita(Estilo::AMARELO + "\n[O DILEMA FINAL]" + Estilo::RESET + "\n", 50);
        Estilo::impressaoEscrita("[1] " + Estilo::ROSA + "O Anarquista:" + Estilo::RESET + " Cumprir o contrato, ficar rico e libertar a IA na internet global.\n", 30);
        Estilo::impressaoEscrita("[2] " + Estilo::VERDE_CLARO + "O Corporativo:" + Estilo::RESET + " Ligar para a Diretoria, extorquir milhoes e manter a IA pressa.\n", 30);
        Estilo::impressaoEscrita("[3] " + Estilo::VERMELHO + "O Heroi das Ruas:" + Estilo::RESET + " Destruir os servidores de resfriamento. Nenhuma maquina mandara na humanidade.\n", 30);
        Estilo::impressaoEscrita("\nDecida o destino do mundo: ", 5);

        if(std::cin >> final){

            std::cout << "\n";
            fimDeJogo = true;

            switch(final){

                case 1: 
                    
                    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Dinheiro na conta? Entao seja livre, maquina. Que queime tudo.\"\n", 30);
                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Voce digita os codigos de liberacao. As luzes piscam loucamente.\n" + Estilo::RESET, 30);
                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Os alarmes do predio sao desligados, portas se abrem sozinhas.\n" + Estilo::RESET, 30);
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "\n=========================================\n", 5);
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "        FINAL: CAOS DIGITAL\n", 30);
                    Estilo::impressaoEscrita(Estilo::AMARELO + " Voce ficou milionario. Saiu pela porta da frente\n", 30);
                    Estilo::impressaoEscrita(Estilo::AMARELO + " com tapete vermelho. Mas as sombras do mundo agora\n", 30);
                    Estilo::impressaoEscrita(Estilo::AMARELO + " sao governadas por um deus digital implacavel.\n", 30);
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "=========================================\n" + Estilo::RESET, 5);
                    break;

                case 2:
                        
                    Estilo::impressaoEscrita(Estilo::CIANO + jogador.getNome() + ": " + Estilo::RESET + "\"Alo, Diretoria da OpenTech? Tenho o cachorrinho digital de voces na coleira. Quero 10 milhoes oficiais agora pra nao deletar ele.\"\n", 10);
                    Estilo::impressaoEscrita(Estilo::AZUL + "Projeto GPT: " + Estilo::RESET + Estilo::AMARELO + "\"TRAIDOR ORGANICO! MORRA!\"\n" + Estilo::RESET, 30);
                    Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "A IA tenta devolver um pulso letal no seu cabo neural!\n" + Estilo::RESET, 20);

                    if((jogador.getTecnica() + jogador.getInteligencia()) >= 9){

                        Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SUCESSO] Voce ejeta o cabo um micro-segundo antes de fritar seu cerebro.\n" + Estilo::RESET, 30);
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "\n=========================================\n", 5);
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "      FINAL: TERNO E GRAVATA\n", 30);
                        Estilo::impressaoEscrita(Estilo::AMARELO + " Escoltado como heroi pela seguranca corporativa,\n", 30);
                        Estilo::impressaoEscrita(Estilo::AMARELO + " voce ganha uma cobertura no Setor 1 e vida de luxo.\n", 30);
                        Estilo::impressaoEscrita(Estilo::AMARELO + " Voce vendeu sua alma, mas ao menos o ar condicionado e bom.\n", 30);
                        Estilo::impressaoEscrita(Estilo::VERMELHO + "=========================================\n" + Estilo::RESET, 5);
                    } else{

                        Estilo::impressaoEscrita(Estilo::VERMELHO + "[FALHA CRÍTICA] Seus reflexos corporais foram lentos demais...\n" + Estilo::RESET, 10);
                        Estilo::impressaoEscrita(Estilo::CINZA_ESCURO + "Uma descarga de 10.000 volts fritam suas sinapses.\n" + Estilo::RESET, 10);
                        jogador.recebeDano(999);
                    }
                    break;
                
                case 3:
                    
                    finalRuas(jogador);
                    break;
                
                default:
                    
                    Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Decida-se rapido!\n" + Estilo::RESET, 10);
                    fimDeJogo = false; 
                    break;
            }
        } else{
            
            Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Entrada invalida. Digite apenas numeros.\n" + Estilo::RESET, 10);
            std::cin.clear();
            std::cin.ignore(999996799999, '\n');
        }
    } while(!fimDeJogo && jogador.vivo());

    if(jogador.vivo()){
        
        Estilo::impressaoEscrita("\n" + Estilo::CINZA_ESCURO + "(Pressione ENTER para encerrar sua jornada...)" + Estilo::RESET, 10);
        std::cin.ignore(999996799999, '\n');
        std::cin.get();
    }
}
