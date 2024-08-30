#include "Grid.h"

void Grid::setBit(int row, int col) {
    int idx = (row*col)/8;
    int bit = (row*col)%8;
    bits[idx] |= (1<<bit);
}

bool Grid::isSet(int row, int col) {
    int idx = (row*col)/8;
    int bit = (row*col)%8;
    return bits[idx]&(1<<bit);
}
