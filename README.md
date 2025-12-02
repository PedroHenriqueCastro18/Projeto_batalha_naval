# Projeto_batalha_naval
Esse é um jogo desenvolvido na  linguagem C por alunos do segundo período da Cesar School. O nosso time composto por Pedro Castro, Paulo Thompson e Daniel Procópio desenvolveu um jogo de batalha naval que rode no terminal a fim de colocar em prática os conhecimentos de Structs, Ponteiros, Alocação Dinâmica de Memória (malloc e realloc) e os fluxos básicos de controle adquiridos na disciplina de programação imperativa e funcional. 

![Image](https://github.com/user-attachments/assets/25fd39d1-f017-4337-96e3-421c884b763e)


## Sobre o jogo:
- 2 jogadores humanos
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


O projeto é modularizado, separando lógica de jogo, tabuleiro, frota, entrada do usuário e geração aleatória.

---

# Como rodar o jogo em sua máquina:

### 1. Pré-requisitos

Para compilar o projeto você precisa de:

GCC — Compilador C

Recomendados:

MinGW-w64

ou MSYS2 (mais moderno e mais estável)

Make (opcional, mas facilita muito)

Se você não quiser instalar make, tudo funciona com apenas um comando usando o gcc.

2. Baixe o Projeto

Baixe/clone o repositório:

git clone https://github.com/seu-usuario/batalha-naval-c.git


Ou simplesmente faça download manual da pasta.

🛠️ 3. Compilando o Projeto

Existem duas maneiras de compilar:

✔ Opção 1 — Usando o Makefile (Recomendado)

Abra o terminal na pasta do projeto:

cd caminho/para/Batalha_naval_em_C


E execute:

mingw32-make


ou (dependendo da instalação):

make


Isso gera o arquivo:

batalha.exe

✔ Opção 2 — Sem Makefile (Apenas GCC)

Caso você não tenha o make, basta rodar este comando:

gcc main.c game.c board.c fleet.c io.c rnd.c -o batalha.exe


Isso compila todo o jogo manualmente e cria o executável.

▶️ 4. Executando o Jogo

No Windows PowerShell ou no terminal do VS Code:

.\batalha.exe


⚠️ O PowerShell não executa arquivos da pasta atual sem .\ na frente.
Por isso o comando batalha.exe sozinho não funciona.

❗ 5. Corrigindo Problemas de Acentuação

Se ao rodar o jogo aparecerem caracteres estranhos como:

Configura├º├Áes
Coordenada inv├ílida
├üGUA


Então seu terminal está usando CP850 e não UTF-8.

Antes de rodar o jogo, execute:

chcp 65001


Depois rode:

.\batalha.exe


Agora todos os acentos aparecerão corretamente.

🎉 6. Pronto para jogar!

Depois de compilar e executar:

escolha Novo jogo

informe os apelidos

escolha posicionamento A (automático) ou M (manual)

jogue digitando coordenadas como B5, C10, J3

O jogo valida coordenadas:

❌ inválida → tenta novamente

❌ repetida → tenta novamente

✔ válida → acerto ou água

E termina quando toda a frota de um jogador for afundada.

🧩 7. Problemas Comuns e Soluções

