#include "game.h"
#include <chrono>

game::game() : running(true) {}

game::~game() {}

using namespace std::chrono_literals;

int game::run(uint w, uint h, double fps) {
  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow(
      "lost", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, NULL);
  screen_surface = SDL_GetWindowSurface(window);

  using clock = std::chrono::high_resolution_clock;

  std::chrono::nanoseconds lag(0ns);
  std::chrono::nanoseconds timestep((long long)((1 / fps) * 1000000ll));

  auto time_start = clock::now();

  while (running) {
    auto dt    = clock::now() - time_start;
    time_start = clock::now();
    lag += std::chrono::duration_cast<std::chrono::nanoseconds>(dt);

    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {
      case SDL_QUIT:
        running = false;
        break;
      }
    }

    while (lag >= timestep) {
      lag -= timestep;

      // update();
    }

    // render();
  }

  return clean();
}

int game::clean() {
  SDL_DestroyWindow(window);

  SDL_Quit();
  return 0;
}