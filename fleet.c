#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fleet.h"
#include "rnd.h"

void criarFrota(Fleet *f) {
    f->count = 6;

    Ship *tmp = malloc(sizeof(Ship) * 10);
    if (!tmp) exit(1);

    f->ships = tmp;

    strcpy(f->ships[0].name, "Porta-aviões"); f->ships[0].length = 5;
    strcpy(f->ships[1].name, "Encouraçado");   f->ships[1].length = 4;
    strcpy(f->ships[2].name, "Cruzador");      f->ships[2].length = 3;
    strcpy(f->ships[3].name, "Cruzador");      f->ships[3].length = 3;
    strcpy(f->ships[4].name, "Destroyer");     f->ships[4].length = 2;
    strcpy(f->ships[5].name, "Destroyer");     f->ships[5].length = 2;

    for (int i = 0; i < f->count; i++) {
        f->ships[i].hits = 0;
        f->ships[i].placed = 0;
    }

    Ship *shrunk = realloc(f->ships, sizeof(Ship) * f->count);
    if (shrunk != NULL)
        f->ships = shrunk;
}

int posicionarNavio(Board *b, Fleet *f, int shipId, int row, int col, Orientation o) {
    Ship *s = &f->ships[shipId];

    if (o == ORIENT_H && col + s->length > b->cols) return 0;
    if (o == ORIENT_V && row + s->length > b->rows) return 0;

    for (int i = 0; i < s->length; i++) {
        int r = row + (o == ORIENT_V ? i : 0);
        int c = col + (o == ORIENT_H ? i : 0);
        if (getCell(b, r, c)->state != CELL_WATER) return 0;
    }

    for (int i = 0; i < s->length; i++) {
        int r = row + (o == ORIENT_V ? i : 0);
        int c = col + (o == ORIENT_H ? i : 0);
        Cell *cell = getCell(b, r, c);
        cell->state = CELL_SHIP;
        cell->ship_id = shipId;
    }

    s->placed = 1;
    return 1;
}

int posicionarAutomatico(Board *b, Fleet *f) {
    for (int i = 0; i < f->count; i++) {
        int ok = 0;
        while (!ok) {
            int row = rndInt(0, b->rows - 1);
            int col = rndInt(0, b->cols - 1);
            int o = rndInt(0, 1);
            ok = posicionarNavio(b, f, i, row, col, o);
        }
    }
    return 1;
}

void liberarFrota(Fleet *f) {
    free(f->ships);
    f->ships = NULL;
}
