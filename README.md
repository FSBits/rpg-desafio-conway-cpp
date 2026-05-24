# CPP-2067 — RPG de Terminal Cyberpunk

> *"Dawn City mastigou suas ambições e cuspiu a carcaça."*

Um RPG narrativo de texto ambientado em um futuro distópico, jogado inteiramente no terminal. Desenvolvido em C++17 como desafio final da trilha **Sapphiron** da FSBits.

---

## Sobre o Projeto

**CPP-2067** é um jogo de aventura narrativa por texto onde o jogador cria um mercenário e enfrenta três cenas de ação em Dawn City — uma metrópole cyberpunk implacável. As escolhas de classe e a distribuição de atributos influenciam diretamente os combates e os desfechos da história.

---

## Funcionalidades

- Criação de personagem com **5 classes** jogáveis (Solo, Netrunner, Techie, Nomad, Corpo)
- **7 atributos** distribuíveis, cada um com impacto direto no gameplay:
  - **Força** — aumenta o dano de armas corpo a corpo e a vida máxima
  - **Reflexos** — eleva a chance de esquivar ataques inimigos e de fuga bem-sucedida
  - **Inteligência** — determina a chance de sucesso dos hacks e a eficácia da Sabotagem Óptica (redução de dano recebido)
  - **Técnica** — atributo de especialização, influencia o perfil técnico do personagem
  - **Moral** — aumenta o dano de armas de fogo e a compostura
  - **Sorte** — contribui para esquiva e para a chance de fuga em combate
  - **Carisma** — atributo de influência social, impacta escolhas e desfechos narrativos
- Sistema de **inventário e itens** (armas, consumíveis, chaves) (acabei não usando as chaves ;-;)
- **3 cenas narrativas** com combates e escolhas
- Efeito de impressão estilizada e cores no terminal via ANSI escape codes
- Tela de **Game Over** e **créditos finais**

---

## Estrutura do Projeto

```
rpg-desafio-conway-cpp/
├── include/
│   ├── Combate.hpp       # Lógica de combate
│   ├── Entidade.hpp      # Classe base para personagens e inimigos
│   ├── Estilo.hpp        # Cores e utilitários de terminal
│   ├── Inimigo.hpp       # Classe de inimigos
│   ├── Narrativa.hpp     # Cenas e narrativa do jogo
│   └── Personagem.hpp    # Classe do jogador e sistema de itens
├── src/
│   ├── Combate.cpp
│   ├── Entidade.cpp
│   ├── Estilo.cpp
│   ├── Inimigo.cpp
│   ├── Narrativa.cpp
│   ├── Personagem.cpp
│   └── main.cpp          # Ponto de entrada do jogo
└── Makefile
```

---

## Pré-requisitos

- **g++** com suporte a C++17 (GCC 7+ recomendado)
- **make**
- Terminal com suporte a cores ANSI (Linux, macOS ou WSL no Windows)

Para verificar se o compilador está instalado:

```bash
g++ --version
make --version
```

Para instalar no Ubuntu/Debian:

```bash
sudo apt update && sudo apt install g++ make
```

---

## Compilação e Execução

**Clone o repositório:**

```bash
git clone https://github.com/FSBits/rpg-desafio-conway-cpp.git
cd rpg-desafio-conway-cpp
```

**Compile com o Makefile:**

```bash
make
```

Isso irá compilar todos os arquivos `.cpp` em `src/` e gerar o executável `cyberpunk_rpg`.

**Execute o jogo:**

```bash
./cyberpunk_rpg
```

**Para limpar os arquivos gerados:**

```bash
make clean
```

> **Windows (sem WSL):** O projeto utiliza ANSI escape codes para cores e limpeza de tela. Recomenda-se rodar via WSL, Git Bash ou um terminal moderno com suporte a ANSI.

---

## Classes Disponíveis

| Classe      | Descrição                         | Pontos Fortes                        |
|-------------|-----------------------------------|--------------------------------------|
| Solo        | Especialista em combate           | Força e Reflexos elevados            |
| Netrunner   | Mestre da rede e invasão          | Inteligência e Técnica elevadas      |
| Techie      | Engenheiro e tecnólogo            | Técnica alta e atributos equilibrados|
| Nomad       | Sobrevivente dos ermos            | Atributos equilibrados e Sorte       |
| Corpo       | Estrategista corporativo          | Carisma e Sorte elevados             |

---

## Créditos

Desenvolvido por **FSBits** para o desafio final da trilha Sapphiron.

---

## Disclaimer

Este README foi gerado com o auxílio do **Claude** (Anthropic) e revisado pelo autor do projeto.
