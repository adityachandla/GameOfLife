#pragma once

#include "Grid.h"
#include <SDL.h>
#include <tuple>

const int HEIGHT = 600;
const int WIDTH = 600;

const int NUM_ROWS = 20;
const int NUM_COLS = 20;

const int SQAURE_SIDE = 20;
const int PADDING = 10;

class Window {
    Grid grid{NUM_ROWS, NUM_COLS};
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    bool processing = false;
public:
    Window();
    void draw();
    void handleClick();
    void flipProcessing();
private:
    void drawGrid();
    std::tuple<int,int> getSquareXY(int,int);
};
