#include "Window.h"

int main() {
    Window w{};
    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e) && e.type == SDL_QUIT) {
            break;
        }
        w.draw();
    }
}
