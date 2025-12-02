#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void criarBoard(Board *b, int rows, int cols) {
    b->rows = rows;
    b->cols = cols;
    b->cells = (Cell *) malloc(rows * cols * sizeof(Cell));

    for (int i = 0; i < rows * cols; i++) {
        b->cells[i].state = CELL_WATER;
        b->cells[i].ship_id = -1;
    }
}

void liberarBoard(Board *b) {
    free(b->cells);
    b->cells = NULL;
}

Cell *getCell(Board *b, int r, int c) {
    return &b->cells[r * b->cols + c];
}

void imprimirBoard(Board *b, bool esconderNavios) {
    printf("  ");
    for (int c = 0; c < b->cols; c++) printf("%c ", 'A' + c);
    printf("\n");

    for (int r = 0; r < b->rows; r++) {
        printf("%02d ", r+1);

        for (int c = 0; c < b->cols; c++) {
            Cell *cell = getCell(b, r, c);

            if (cell->state == CELL_WATER)
                printf("~ ");
            else if (cell->state == CELL_SHIP)
                printf(esconderNavios ? "~ " : "S ");
            else if (cell->state == CELL_HIT)
                printf("X ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

