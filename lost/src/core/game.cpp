#include "game.h"
#include "entities/entity.h"
#include "entities/game_entity.h"
#include "entities/npc.h"
#include "entities/player.h"
#include "gfx/texture_loader.h"
// #include "imgui/imgui-SFML.h"
// #include "imgui/imgui.h"
#include "input/input_manager.h"
#include "input/keys.h"
#include "items/item.h"
#include "worlds/layers/entity_layer.h"
#include "worlds/layers/tile_layer.h"
#include "worlds/world.h"
#include <fstream>
#include <list>
#include <unordered_map>

namespace lost::core {

game::game(uint w, uint h)
    : m_running(true), m_window(sf::VideoMode(w, h), "lost"),
      m_current_world(new worlds::world()) {
  //ImGui::SFML::Init(m_window);
}

game::~game() {}

entities::player      p;
entities::game_entity ge;

void gui() {
  // ImGui::Begin("blablabla");
  // ImGui::Button("Look at this pretty button");
  // ImGui::End();
}

int game::run(double fps) {
  m_current_world->m_layers.push_back(new worlds::layers::entity_layer());

  input::load_key_binds(json_from_file("../key_binds.json"));

  // T E S T I N G   A R E A

  p = entities::player(json_from_file("player/player.json"));
  std::cout << p.name << std::endl
            << p.race << std::endl
            << p.gender << std::endl
            << p.inv.items.size() << std::endl
            << p.inv.items[0].i.name << std::endl
            << p.inv.items[0].count << std::endl
            << p.inv.primary.name << std::endl;

  ge = entities::game_entity(
      &p, math::vec2(24, 24), math::vec2(), math::vec2(8, 16));

  const int tiles[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0,
                       0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1};

  t.load(
      gfx::get_texture("tilesets/dirt.png"), sf::Vector2u(16, 16), tiles, 5, 5);

  // T E S T I N G   A R E A

  sf::Clock clock;
  sf::Time  accumulator = sf::Time::Zero;
  sf::Time  ups         = sf::seconds(1.f / fps);
  while (m_running) {
    sf::Event e;

    while (m_window.pollEvent(e)) {
      // ImGui::SFML::ProcessEvent(e);
      switch (e.type) {
      case sf::Event::EventType::Closed:
        m_running = false;
        break;
      case sf::Event::EventType::KeyPressed:
        m_input_manager.press_key(e.key.code);
        break;
      case sf::Event::EventType::KeyReleased:
        m_input_manager.release_key(e.key.code);
        break;
      default:
        break;
      }
    }

    //ImGui::SFML::Update(m_window, clock.getElapsedTime());

    while (accumulator >= ups) {
      accumulator -= ups;
      update(1.0 / fps);
    }

    // gui();

    render();

    accumulator += clock.restart();
  }

  return clean();
}

int game::update(double dt) {
  m_current_world->update(dt);
  ge.player_update(dt);

  return 0;
}

int game::render() {
  m_window.clear();
  m_window.draw(t);
  ge.player_render();
  // ImGui::SFML::Render(m_window);
  m_window.display();

  return 0;
}

int game::clean() {
  m_window.close();
  //ImGui::SFML::Shutdown();
  return 0;
}

} // namespace lost::core
