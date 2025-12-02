#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "game.h"
#include "io.h"
#include "rnd.h"

static void inicializarJogador(Player *p) {
    criarBoard(&p->board, boardSize, boardSize);
    criarBoard(&p->shots, boardSize, boardSize);
    criarFrota(&p->fleet);
}

static void posicionarManual(Board *b, Fleet *f) {
    for (int i = 0; i < f->count; i++) {
        Ship *s = &f->ships[i];
        int colocado = 0;

        while (!colocado) {
            char colChar;
            int row;
            char orientChar;

            printf("Posicione %s (tamanho %d). Ex: B5 H\n", s->name, s->length);
            printf("Coordenada inicial: ");
            lerCoordenada(&colChar, &row);

            printf("Orientação (H/V): ");
            scanf(" %c", &orientChar);
            orientChar = toupper(orientChar);

            int c = colChar - 'A';

            if (row < 0 || row >= boardSize || c < 0 || c >= boardSize) {
                printf("Coordenada inválida.\n");
                continue;
            }

            Orientation o = (orientChar == 'V') ? ORIENT_V : ORIENT_H;

            if (!posicionarNavio(b, f, i, row, c, o))
                printf("Não foi possível posicionar aí. Tente novamente.\n");
            else {
                colocado = 1;
                printf("%s posicionado!\n", s->name);
            }
        }
    }
}

static void posicionarJogador(Player *p) {
    if (modoPosicionamento == 'A')
        posicionarAutomatico(&p->board, &p->fleet);
    else {
        imprimirBoard(&p->board, false);
        posicionarManual(&p->board, &p->fleet);
    }
}


static int processarTiro(Player *atacante, Player *alvo) {

    while (1) { 
        char col;
        int row;

        printf("Digite coordenada (ex: B5): ");
        lerCoordenada(&col, &row);

        int c = col - 'A';

        
        if (row < 0 || row >= boardSize || c < 0 || c >= boardSize) {
            printf("Coordenada inválida! Digite novamente.\n");
            continue;
        }

        Cell *cell = getCell(&alvo->board, row, c);
        Cell *shotCell = getCell(&atacante->shots, row, c);

        
        if (shotCell->state == CELL_HIT || shotCell->state == CELL_MISS) {
            printf("Você já atirou aqui! Digite outra coordenada.\n");
            continue;
        }

        
        if (cell->state == CELL_SHIP) {
            cell->state = CELL_HIT;
            shotCell->state = CELL_HIT;

            Ship *s = &alvo->fleet.ships[cell->ship_id];
            s->hits++;

            if (s->hits == s->length)
                printf("AFUNDOU %s!\n", s->name);
            else
                printf("ACERTOU!\n");

            return 1; 
        }

       
        cell->state = CELL_MISS;
        shotCell->state = CELL_MISS;

        printf("ÁGUA.\n");
        return 0; 
    }
}

static int jogadorDerrotado(Player *p) {
    for (int i = 0; i < p->fleet.count; i++) {
        if (p->fleet.ships[i].hits < p->fleet.ships[i].length)
            return 0;
    }
    return 1;
}

void liberarPlayer(Player *p) {
    liberarBoard(&p->board);
    liberarBoard(&p->shots);
    liberarFrota(&p->fleet);
}

void novoJogo(Game *g) {
    g->current_player = 0;
    g->game_over = 0;

    printf("Apelido jogador 1: ");
    scanf("%31s", g->p1.nickname);

    printf("Apelido jogador 2: ");
    scanf("%31s", g->p2.nickname);

    inicializarJogador(&g->p1);
    inicializarJogador(&g->p2);

    printf("Posicionando frota de %s...\n", g->p1.nickname);
    posicionarJogador(&g->p1);

    printf("Posicionando frota de %s...\n", g->p2.nickname);
    posicionarJogador(&g->p2);

    while (!g->game_over) {
        Player *atacante = g->current_player == 0 ? &g->p1 : &g->p2;
        Player *alvo = g->current_player == 0 ? &g->p2 : &g->p1;

        printf("\n-- Turno de %s --\n", atacante->nickname);

        processarTiro(atacante, alvo);

        if (jogadorDerrotado(alvo)) {
            printf("\n*** FIM DE JOGO ***\n");
            printf("Vencedor: %s\n", atacante->nickname);

            printf("\nTabuleiro final do vencedor:\n");
            imprimirBoard(&atacante->board, false);

            printf("\nMapa de tiros do vencedor:\n");
            imprimirBoard(&atacante->shots, true);

            g->game_over = 1;
            break;
        }

        g->current_player = 1 - g->current_player;
    }

    liberarPlayer(&g->p1);
    liberarPlayer(&g->p2);
}
