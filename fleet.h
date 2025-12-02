#ifndef FLEET_H
#define FLEET_H

#include "board.h"

typedef enum { ORIENT_H, ORIENT_V } Orientation;

typedef struct {
    char name[20];
    int length;
    int hits;
    int placed;
} Ship;

typedef struct {
    Ship *ships;
    int count;
} Fleet;

void criarFrota(Fleet *f);
int posicionarNavio(Board *b, Fleet *f, int shipId, int row, int col, Orientation o);
int posicionarAutomatico(Board *b, Fleet *f);
void liberarFrota(Fleet *f);

#endif
