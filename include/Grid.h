#pragma once

#include <vector>

class Grid {
    std::vector<int> bits;
    int rows, columns;
public:
    Grid(int rows, int columns): rows{rows}, columns{columns}, bits((rows*columns + 7)/8){}
    void setBit(int row, int col);
    bool isSet(int row, int col);
    void nextState();
private:
    bool shouldLive(int row, int col);
};
