#include <stdlib.h>
#include "rnd.h"

int rndInt(int min, int max) {
    return min + rand() % (max - min + 1);
}
