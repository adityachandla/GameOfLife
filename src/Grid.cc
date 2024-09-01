#include "Grid.h"
#include <cstdio>

void Grid::setBit(int row, int col) {
    int pos = row * columns + col;
    bits[pos / 8] |= (1 << (pos % 8));
}

void Grid::flipBit(int row, int col) {
    int pos = row * columns + col;
    bits[pos / 8] ^= (1 << (pos % 8));
}

bool Grid::isSet(int row, int col) {
    int pos = row * columns + col;
    return (bits[pos / 8] >> (pos % 8)) & 0x1;
}

void Grid::nextState() {
    std::vector<int> next(bits.size());
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            int idx = (r * columns + c) / 8;
            int bit = (r * columns + c) % 8;
            next[idx] |= (shouldLive(r, c) << bit);
        }
    }
    bits = std::move(next);
}

bool Grid::shouldLive(int row, int col) {
    bool currState = isSet(row, col);

    int numLiveNeighbours = 0;
    for (int i = -1; i <= 1; i++) {
        if (row+i < 0 || row+i >= rows) continue;

        for (int j = -1; j <= 1; j++) {
            if (col+j < 0 || col+i >= columns) continue;

            int pos = (row + i) * columns + (col + j);
            numLiveNeighbours += (bits[pos / 8] >>  (pos % 8)) & 0x1;
        }
    }
    return numLiveNeighbours == 3 || (currState && numLiveNeighbours == 4);
}
