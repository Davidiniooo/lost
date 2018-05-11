#include "game.h"
#include "entities/npc.h"
#include "items/item.h"
#include "worlds/layers/entity_layer.h"
#include "worlds/world.h"
#include <chrono>
#include <fstream>

game::game() : running(true) {}

game::~game() {}

using namespace std::chrono_literals;

int game::run(uint w, uint h, double fps) {
  window         = NULL;
  screen_surface = NULL;
  renderer       = NULL;

  current_world = new world();
  current_world->layers.push_back(new entity_layer());

  window = SDL_CreateWindow(
      "lost", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, NULL);

  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    clean();
    return -1;
  }
  screen_surface = SDL_GetWindowSurface(window);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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

      update((double)timestep.count() / 1000000.0);
    }

    render();
  }

  return clean();

  return clean();
}

int game::update(double dt) {
  current_world->update(dt);
  return 0;
}

int game::render() {

  return 0;
}

int game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}
