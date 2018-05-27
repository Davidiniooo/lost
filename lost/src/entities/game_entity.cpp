#include "game_entity.h"
#include "SFML/Graphics.hpp"
#include "core/game.h"
#include "gfx/texture_loader.h"
#include "input/input_manager.h"
#include "input/keys.h"
#include "math/lerp.h"
#include "scripting/execute_script.h"

namespace lost::entities {

game_entity::game_entity(entity *e, math::vec2 p, math::vec2 v, math::vec2 s)
    : m_entity(e), m_position(p), m_velocity(v), m_size(s) {}

int game_entity::update(double dt) {
  return scripting::execute_script(m_entity->update, this);
}

int game_entity::render() {
  return scripting::execute_script(m_entity->render, this);
}

int game_entity::player_update(double dt) {
  int r = g_game->m_input_manager.key_down(input::keys["right"]) ? 1 : 0;
  int l = g_game->m_input_manager.key_down(input::keys["left"]) ? 1 : 0;

  m_velocity.x = (r - l) * 0.8;

  m_position.x += m_velocity.x;
  m_position.y += m_velocity.y;

  return 0;
}

int game_entity::player_render() {
  sf::Sprite s;
  s.setTexture(*gfx::get_texture("1x2.png"));
  s.setPosition(m_position.x, m_position.y);
  g_game->m_window.draw(s);
  return 0;
}

} // namespace lost::entities
