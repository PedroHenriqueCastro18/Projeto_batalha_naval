# Projeto_batalha_naval
Esse é um jogo desenvolvido na  linguagem C por alunos do segundo período da Cesar School. O nosso time composto por **Pedro Castro**, **Paulo Thompson** e **Daniel Procópio** desenvolveu um jogo de batalha naval que rode no terminal a fim de colocar em prática os conhecimentos de Structs, Ponteiros, Alocação Dinâmica de Memória (malloc e realloc) e os fluxos básicos de controle adquiridos na disciplina de programação imperativa e funcional. 

![Image](https://github.com/user-attachments/assets/25fd39d1-f017-4337-96e3-421c884b763e)


## Sobre o jogo:
- 2 jogadores 
- Posicionamento manual ou automático das frotas
- Sistema de tiros com acertos e afundamentos
- Exibição do tabuleiro e mapa de tiros
- Tela de vitória

## Estrutura de pastas e arquivos

Batalha_naval_em_C/
main.c
game.c
game.h
board.c
board.h
fleet.c
fleet.h
io.c
io.h
rnd.c
rnd.h
Makefile


O projeto é modularizado, separando lógica de jogo, tabuleiro, navios, entrada do usuário e geração aleatória.

---

# Pré-requisitos

Para compilar e rodar o jogo no Windows, você precisa de:

### GCC (compilador C)  
Recomendado:  
- MinGW  
ou  
- MSYS2 (mais moderno)

### Make (opcional, mas recomendado)

Se não quiser instalar o make, também é possível compilar usando apenas o gcc.

---

# Como Compilar

## Opção 1 — Usando o Makefile

No terminal, navegue até a pasta do projeto:

cd caminho/para/Batalha_naval_em_C

Execute:

mingw32-make

ou:

make

Isso vai gerar o executável:

batalha.exe


---

## Opção 2 — Compilar manualmente com GCC

Se você não tiver make instalado, use:

gcc main.c game.c board.c fleet.c io.c rnd.c -o batalha.exe


---

# Como executar

No PowerShell ou terminal do VS Code escreva:

.\batalha.exe


**Importante:** o PowerShell exige usar `.\` para executar programas da pasta atual.

---

# Problema de acentuação no Windows

Se ao rodar o programa aparecerem caracteres estranhos (Ã, ┤, ▒, etc) digite isso no terminal:

chcp 65001


Agora rode o jogo novamente.

---

# Como Jogar

1. Escolha “Novo jogo”
2. Digite os apelidos dos jogadores
3. Escolha o tipo de posicionamento:
   - A → Automático
   - M → Manual
4. Ataque digitando coordenadas como:
   - B5
   - C10
   - J3
5. O jogo valida entradas:
   - Inválida → repete a jogada
   - Coordenada já usada → repete a jogada
   - Acertou → marca o navio
   - Afundou → indica o navio destruído
6. O jogo termina quando todos os navios de um jogador forem afundados.

---

# Frota Utilizada

| Navio         | Tamanho |
|---------------|----------|
| Porta-aviões  | 5        |
| Encouraçado   | 4        |
| Cruzador      | 3        |
| Cruzador      | 3        |
| Destroyer     | 2        |
| Destroyer     | 2        |

---

# Equipe

Desenvolvido por **Pedro Henrique Araújo de Castro**, **Paulo Henrique Thompson** e **Daniel Procópio**  






