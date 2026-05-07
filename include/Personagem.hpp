#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "Entidade.hpp"
#include <string>
#include <vector>

enum IdItem{

    ARMA,
    CONSUMIVEL,
    CHAVE
};

struct Item{

    std::string nome;
    std::string descricao;
    IdItem id;
    int valorEfeito; 
    int quantidade;
    bool armaDeFogo;
};
class Personagem : public Entidade{
    
    protected:
        
        std::string classe;
        
        int forca;
        int reflexos;
        int inteligencia;
        int tecnica;
        int moral;
        int sorte;
        int carisma;

        std::vector<Item> inv;
        Item armaEquipada;

    public:

        Personagem(std::string t_nome, std::string t_classe, int t_forca, int t_reflexos, int t_inteligencia, int n_tecnica, int t_moral, int t_sorte, int t_carisma);
        
        void ficha();
        void adcionarItem(Item novoItem);
        void listarInv();
        bool usarItem(int index);
        bool temItem(std::string nomeItem);

        int getForca();
        int getReflexos();
        int getInteligencia();
        int getTecnica();
        int getMoral();
        int getSorte();
        int getCarisma();
        Item getArmaEquipada();
        Item getArmaDeFogo();
};

#endif