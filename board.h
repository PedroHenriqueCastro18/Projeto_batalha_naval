#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

typedef enum { CELL_WATER, CELL_SHIP, CELL_HIT, CELL_MISS } CellState;

typedef struct {
    CellState state;
    int ship_id;
} Cell;

typedef struct {
    int rows, cols;
    Cell *cells;
} Board;

void criarBoard(Board *b, int rows, int cols);
void liberarBoard(Board *b);
Cell *getCell(Board *b, int r, int c);
void imprimirBoard(Board *b, bool esconderNavios);

#endif
