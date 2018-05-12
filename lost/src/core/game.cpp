#include "game.h"
#include "entities/npc.h"
#include "items/item.h"
#include "worlds/layers/entity_layer.h"
#include "worlds/world.h"
#include <chrono>
#include <fstream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

game::game() : running(true) {}

game::~game() {}

using namespace std::chrono_literals;

int game::run(uint w, uint h, double fps) {
  window         = nullptr;
  screen_surface = nullptr;
  renderer       = nullptr;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
    clean();
    return -1;
  }

  IMG_Init(IMG_INIT_PNG);

  current_world = new world();
  current_world->layers.push_back(new entity_layer());

  window = SDL_CreateWindow(
      "lost", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, NULL);

  if (window == nullptr) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    clean();
    return -1;
  }
  screen_surface = SDL_GetWindowSurface(window);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // T E S T I N G   A R E A

  item apple = item(json_from_file("items/apple.json"));

  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

  SDL_RenderClear(renderer);

  SDL_Rect dst = {0, 0, 64, 64};
  SDL_RenderCopy(renderer, apple.texture, NULL, &dst);

  SDL_RenderPresent(renderer);

  // T E S T I N G   A R E A

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
