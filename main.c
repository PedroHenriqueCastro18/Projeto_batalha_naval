#include <stdio.h>    
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "io.h"

int main() {
    Game game;
    int opcao = 0;

    srand(time(NULL));

    inicializarPadroes();

    while (1) {
        mostrarMenu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            novoJogo(&game);
        } else if (opcao == 2) {
            configurar();
        } else if (opcao == 3) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }

    return 0;
}
