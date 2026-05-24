#include "../include/Personagem.hpp"
#include "../include/Estilo.hpp"
#include <iostream>

Personagem::Personagem(std::string t_nome, std::string t_classe, int t_forca, int t_reflexos, int t_inteligencia, int t_tecnica, int t_moral, int t_sorte, int t_carisma)
    : Entidade(t_nome, 100 + (t_forca * 5)), 
      classe(t_classe), forca(t_forca), reflexos(t_reflexos), inteligencia(t_inteligencia), 
      tecnica(t_tecnica), moral(t_moral), sorte(t_sorte), carisma(t_carisma) {

        Item pistola = {"3 OITAO", "Arma de fogo basica.", ARMA, 5, 1, true, false};
        Item katata = {"Katana cega", "Katana cega retratil.", ARMA, 8, 1, true, false};
        Item estimulante = {"estimulante", "Injecao de cura rapida.", CONSUMIVEL, 30, 3, false, false};
        Item resetHack = {"Quebra-ICE", "Reseta um protocolo de invasao.", CONSUMIVEL, 0, 1, false, true};

        armaEquipada = pistola;
        adcionarItem(katata);
        adcionarItem(pistola);
        adcionarItem(estimulante);
        adcionarItem(resetHack);
}


void Personagem::adcionarItem(Item novoItem){

    int i;
    for(i = 0; i < inv.size(); i++){

        if(inv[i].nome == novoItem.nome){
            
            inv[i].quantidade += novoItem.quantidade;
            //diminuir o delay entre os chars
            Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SISTEMA] + " + std::to_string(novoItem.quantidade) + "x " + novoItem.nome + " (Total: " + std::to_string(inv[i].quantidade) + ")" + Estilo::RESET + "\n", 20);
            return;
        }
    }
    
    inv.push_back(novoItem);
    Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[SISTEMA] Novo item obtido: " + novoItem.nome + Estilo::RESET + "\n", 30);
}

void Personagem::listarInv(){

    Estilo::impressaoEscrita("\n" + Estilo::AMARELO + ">>> MOCHILA DE EQUIPAMENTOS <<<" + Estilo::RESET + "\n", 30);

    int i;
    for(i = 0; i < inv.size(); i++){

        if(inv[i].quantidade > 0){

            Estilo::impressaoEscrita("[" + std::to_string(i) + "] " + std::to_string(inv[i].quantidade) + "x " + Estilo::CIANO + inv[i].nome + Estilo::RESET, 10);
            //poderia ter feito um switch não?
            if(inv[i].id == ARMA) Estilo::impressaoEscrita(Estilo::MAGENTA + " (Dano: " + std::to_string(inv[i].valorEfeito) + ")\n" + Estilo::RESET, 10);
            else if(inv[i].id == CONSUMIVEL) Estilo::impressaoEscrita(Estilo::MAGENTA + " (Cura: " + std::to_string(inv[i].valorEfeito) + " HP)\n" + Estilo::RESET, 10);
            else
                Estilo::impressaoEscrita(Estilo::MAGENTA + " (Item Chave)\n" + Estilo::RESET, 10);
            Estilo::impressaoEscrita("  > " + Estilo::CINZA_ESCURO + inv[i].descricao + Estilo::RESET + "\n", 15);
        }
    }
}

int Personagem::usarItem(int index){

    if(index >= 0 && index < inv.size() && inv[index].quantidade > 0){

        Item& itemEscolhido = inv[index];

        switch(itemEscolhido.id){

            case ARMA:
                
                armaEquipada = itemEscolhido;
                Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[Sistema] " + itemEscolhido.nome + " equipado.\n" + Estilo::RESET, 10);
                return 1;
            
            case CONSUMIVEL:

                if(itemEscolhido.quebraIce){
                    
                    itemEscolhido.quantidade--;
                    Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[Sistema] " + itemEscolhido.nome + " ativado no deck neural.\n" + Estilo::RESET, 10);
                    return 2;
                }
                curar(itemEscolhido.valorEfeito);
                itemEscolhido.quantidade--;
                Estilo::impressaoEscrita(Estilo::VERDE_CLARO + "[Sistema] Voce usou " + itemEscolhido.nome + ". (+ " + std::to_string(itemEscolhido.valorEfeito) + " HP)\n" + Estilo::RESET, 10);
                return 1;
            
            case CHAVE:
                
                Estilo::impressaoEscrita(Estilo::VERMELHO + "[Sistema] Nao ha onde usar " + itemEscolhido.nome + " aqui. Tente usar no cenario correto.\n" + Estilo::RESET, 10);
                return 0;
            
            default:
                
                Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Entrada invalida. " + Estilo::RESET, 10);
                return 0;
        }
    }

    Estilo::impressaoEscrita(Estilo::VERMELHO + "[ERRO] Item invalido ou esgotado.\n" + Estilo::RESET, 10);
    return 0;
}

bool Personagem::temItem(std::string nomeItem){

    int i;
    for(i = 0; i < inv.size(); i++){

        if(inv[i].nome == nomeItem && inv[i].quantidade > 0) return true;
    }
    return false;
}

void Personagem::ficha(){
    
    Estilo::impressaoEscrita(Estilo::CIANO + "=======================================", 10);
    Estilo::impressaoEscrita(Estilo::DESTAQUE + Estilo::AMARELO + "       REGISTRO DE MERCENARIO          " + Estilo::RESET, 10);
    Estilo::impressaoEscrita(Estilo::CIANO + "=======================================" + Estilo::RESET, 10);

    Estilo::impressaoEscrita(Estilo::ROSA + "NOME:   " + Estilo::RESET + nome + "\n", 10);
    Estilo::impressaoEscrita(Estilo::ROSA + "CLASSE:   " + Estilo::RESET + classe + "\n", 10);

    std::string corHp = (hpAtual > hpMax * 0.3) ? Estilo::VERDE : Estilo::VERMELHO;
    Estilo::impressaoEscrita(Estilo::MAGENTA + "VIDA:   " + corHp + std::to_string(hpAtual) + " / " + std::to_string(hpMax) + Estilo::RESET + "\n", 10);

    Estilo::impressaoEscrita(Estilo::CIANO+ "=======================================\n" + Estilo::RESET, 5);
    
    Estilo::impressaoEscrita(Estilo::AZUL + "FORCA:        " + Estilo::RESET + std::to_string(forca) + " (Combate fisico e resistencia)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "REFLEXOS:     " + Estilo::RESET + std::to_string(reflexos) + " (Esquiva e iniciativa)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "INTELIGENCIA: " + Estilo::RESET + std::to_string(inteligencia) + " (Invasao de sistemas)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "TECNICA:      " + Estilo::RESET + std::to_string(tecnica) + " (Engenharia e tecnologia)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "MORAL:        " + Estilo::RESET + std::to_string(moral) + " (Controle e compostura)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "SORTE:        " + Estilo::RESET + std::to_string(sorte) + " (Criticos e milagres)", 10);
    Estilo::impressaoEscrita(Estilo::AZUL + "CARISMA:      " + Estilo::RESET + std::to_string(carisma) + " (Relacionamentos e persuasao)", 10);
    
    Estilo::impressaoEscrita(Estilo::CIANO+ "=======================================\n" + Estilo::RESET, 5);
}


int Personagem::getForca() { return forca; }
int Personagem::getReflexos() { return reflexos; }
int Personagem::getInteligencia() { return inteligencia; }
int Personagem::getTecnica() { return tecnica; }
int Personagem::getMoral() { return moral; }
int Personagem::getSorte() { return sorte; }
int Personagem::getCarisma() { return carisma; }
Item Personagem::getArmaEquipada() { return armaEquipada; }

