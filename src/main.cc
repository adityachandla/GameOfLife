#include "Window.h"

int main() {
    Window w{};
    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)  {
                break;
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
                w.flipProcessing();
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x,y;
                SDL_GetMouseState(&x, &y);
                w.handleClick(x, y);
            }
        }
        w.draw();
    }
}
