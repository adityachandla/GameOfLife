#include "Window.h"

Window::Window() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Trial", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Could not initialize renderer %s\n", SDL_GetError());
    }
}

void Window::draw() {
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
    drawGrid();
    SDL_RenderPresent(renderer);
}

void Window::drawGrid() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            auto pos = getSquareXY(i, j);
            SDL_Rect filledRect = SDL_Rect{std::get<0>(pos), std::get<1>(pos),
                                           SQUARE_SIDE, SQUARE_SIDE};
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
            if (grid.isSet(i, j)) {
                SDL_RenderFillRect(renderer, &filledRect);
            } else {
                SDL_RenderDrawRect(renderer, &filledRect);
            }
        }
    }
    if (processing) {
        grid.nextState();
    }
}

void Window::handleClick(int x, int y) {
    if (processing) {
        printf("Clicks not allowed while processing\n");
        return;
    }
    auto rowOpt = search(x, NUM_COLS);
    auto colOpt = search(y, NUM_ROWS);
    if (colOpt.has_value() && rowOpt.has_value()) {
        grid.setBit(rowOpt.value(), colOpt.value());
    }
}

void Window::flipProcessing() {
    processing = !processing;
}

std::optional<int> Window::search(int val, int high) {
    int low = 0;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (val >= mid * SQUARE_SIDE && val <= (mid + 1) * SQUARE_SIDE) {
            return mid;
        } else if (val < mid * SQUARE_SIDE) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return {};
}

std::tuple<int, int> Window::getSquareXY(int i, int j) {
    int pos_x = i * SQUARE_SIDE;
    int pos_y = j * SQUARE_SIDE;
    return std::tuple<int, int>{pos_x, pos_y};
}
