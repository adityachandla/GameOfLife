#pragma once

#include <vector>

class Grid {
    std::vector<int> bits;
public:
    Grid(int rows, int columns): bits((rows*columns + 7)/8){}
    void setBit(int row, int col);
    bool isSet(int row, int col);
};
