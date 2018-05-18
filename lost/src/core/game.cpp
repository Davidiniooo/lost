#include "game.h"
#include "entities/npc.h"
#include "entities/player.h"
#include "items/item.h"
#include "worlds/layers/entity_layer.h"
#include "worlds/world.h"
#include <chrono>
#include <fstream>
#include <unordered_map>
#include <list>

game::game()
    : running(true), window(sf::VideoMode(1920, 1080), "lost"),
      current_world(new world()) {}

game::~game() {}

player p;

using namespace std::chrono_literals;

int game::run(uint w, uint h, double fps) {
  current_world->layers.push_back(new entity_layer());

  std::unordered_map<int, bool> keys;
  std::list<int> changed_keys;

  // T E S T I N G   A R E A

  p = player(json_from_file("player/player.json"));
  std::cout << p.name << std::endl
            << p.race << std::endl
            << p.gender << std::endl
            << p.inv.items.size() << std::endl
            << p.inv.items[0].i.name << p.inv.items[0].count << std::endl
            << p.inv.primary.name << std::endl;

  std::flush(std::cout);

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
      case sf::Event::EventType::Closed:
        running = false;
        break;
      case sf::Event::EventType::KeyPressed:
        if (keys.count(e.key.code) == 0) {
          keys[e.key.code] = true;
          changed_keys.push_back(e.key.code);
        }
        break;
      case sf::Event::EventType::KeyReleased:
        if (keys.count(e.key.code) == 1) {
          keys.erase(e.key.code);
          changed_keys.push_back(e.key.code);
        }
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
