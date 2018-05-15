#include "game.h"
#include "entities/npc.h"
#include "items/item.h"
#include "worlds/layers/entity_layer.h"
#include "worlds/world.h"
#include <chrono>
#include <fstream>
#include "entities/player.h"

game::game() : running(true), window(sf::VideoMode(1920, 1080), "lost"), current_world(new world()) {}

game::~game() {}

player p;

using namespace std::chrono_literals;

int game::run(uint w, uint h, double fps) {
  current_world->layers.push_back(new entity_layer());

  // T E S T I N G   A R E A

  p = player(json_from_file("player/player.json"));

  // T E S T I N G   A R E A

  using clock = std::chrono::high_resolution_clock;

  std::chrono::nanoseconds lag(0ns);
  std::chrono::nanoseconds timestep((long long)((1 / fps) * 1000000ll));

  auto time_start = clock::now();

  while (running) {
    auto dt    = clock::now() - time_start;
    time_start = clock::now();
    lag += std::chrono::duration_cast<std::chrono::nanoseconds>(dt);

    sf::Event e;

    while (window.pollEvent(e)) {
      switch (e.type) {
      case sf::Event::Closed:
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
}

int game::update(double dt) {
  current_world->update(dt);
  return 0;
}

int game::render() {
  window.clear();
  
  window.display();

  return 0;
}

int game::clean() {
  window.close();
  return 0;
}
