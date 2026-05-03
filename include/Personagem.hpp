#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>

class Personagem{
    
    protected:
        
        std::string nome;
        std::string classe;
        
        int hpMax;
        int hpAtual;
        int forca;
        int reflexos;
        int inteligencia;
        int tecnica;
        int moral;
        int sorte;
        int carisma;

    public:

        Personagem(std::string t_nome, std::string t_classe, int t_forca, int t_reflexos, int t_inteligencia, int n_tecnica, int t_moral, int t_sorte, int t_carisma);
        
        void recebeDano(int dano);
        void curarHp(int cura);
        bool vivo();
        void ficha();

        std::string getNome();
        int getHpAtual();
        int getForca();
        int getReflexos();
        int getInteligencia();
        int getTecnica();
        int getMoral();
        int getSorte();
        int getCarisma();
};

#endif