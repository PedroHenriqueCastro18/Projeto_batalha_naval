#include <stdio.h>
#include <stdlib.h>   
#include <ctype.h>
#include "io.h"

int boardSize = 10;
char modoPosicionamento = 'A';

void mostrarMenu() {
    printf("\n=== BATALHA NAVAL ===\n");
    printf("1) Novo jogo\n");
    printf("2) Configurações\n");
    printf("3) Sair\n> ");
}

void inicializarPadroes() {
    boardSize = 10;
    modoPosicionamento = 'A';
}

void configurar() {
    printf("Tamanho do tabuleiro (6-26): ");
    scanf("%d", &boardSize);

    if (boardSize < 6) boardSize = 6;
    if (boardSize > 26) boardSize = 26;

    printf("Posicionamento Manual (M) ou Automático (A): ");
    scanf(" %c", &modoPosicionamento);
    modoPosicionamento = toupper(modoPosicionamento);
}

void lerCoordenada(char *col, int *row) {
    char input[5];
    scanf("%s", input);

    *col = toupper(input[0]);
    *row = atoi(&input[1]) - 1;
}

