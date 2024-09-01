#pragma once

#include "Grid.h"
#include <SDL.h>
#include <optional>
#include <tuple>

const int HEIGHT = 1000;
const int WIDTH = 1500;

const int NUM_ROWS = 100;
const int NUM_COLS = 150;

const int SQUARE_SIDE = 10;

class Window {
    Grid grid{NUM_ROWS, NUM_COLS};
    int processCount{0};
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    bool processing = false;
public:
    Window();
    void draw();
    void handleClick(int x, int y);
    void flipProcessing();
private:
    void drawGrid();
    std::optional<int> search(int, int);
    std::tuple<int,int> getSquareXY(int,int);
};
