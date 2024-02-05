#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

bool is_running = false;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

bool initialize_window(void) {

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

    fprintf(stderr, "error initalizing sdl.\n");
    return false;
  }
  // TO DO: create a sdl window
  window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, /*posX */
                            SDL_WINDOWPOS_CENTERED,       /*posY */
                            800,                          /*width*/
                            600,                          /*height*/
                            SDL_WINDOW_BORDERLESS);

  if (!window) {
    fprintf(stderr, "error creating sdl window\n");
    return false;
  }

  // create a sdl renderer
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) {
    fprintf(stderr, "error creating sdl renderer\n");
    return false;
  }

  return true;
}

void setup(void) {
  // TODO
}

void process_input(void) {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  // x button on window
  case SDL_QUIT:
    is_running = false;
    break;

  case SDL_KEYDOWN:
    if (event.key.keysym.sym == SDLK_ESCAPE) {
      is_running = false;
    }
  }
}

void update(void) {
  // TODO
}

void render(void) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);
}

int main(void) {

  is_running = initialize_window();

  setup();

  while (is_running) {
    process_input();
    update();
    render();
  }
  return 0;
}
