#include "game_entity.h"
#include "SFML/Graphics.hpp"
#include "core/game.h"
#include "gfx/texture_loader.h"
#include "input/input_manager.h"
#include "input/keys.h"
#include "math/collision/entity_tilemap.h"
#include "math/lerp.h"
#include "scripting/execute_script.h"

namespace lost::entities {

game_entity::game_entity(entity *e, math::vec2 p, math::vec2 v, math::vec2 s)
    : m_entity(e), m_position(p), m_velocity(v), m_half_sizes(s) {}

int game_entity::update(double dt) {
  return scripting::execute_script(m_entity->update);
}

int game_entity::render() {
  return scripting::execute_script(m_entity->render);
}

int game_entity::player_update(double dt) {
  int r = g_game->m_input_manager.key_down(input::KEY_RIGHT) ? 1 : 0;
  int l = g_game->m_input_manager.key_down(input::KEY_LEFT) ? 1 : 0;

  m_velocity.m_x = (r - l) * 0.8;

  math::collision::entity_tilemap(*this, g_game->t);

  m_position.m_x += m_velocity.m_x;
  m_position.m_y += m_velocity.m_y;

  return 0;
}

int game_entity::player_render() {
  sf::Sprite s;
  s.setTexture(*gfx::get_texture("1x2.png"));
  s.setOrigin(m_half_sizes.m_x, m_half_sizes.m_y);
  s.setPosition(m_position.m_x, m_position.m_y);
  g_game->m_window.draw(s);
  sf::RectangleShape rect(sf::Vector2f(m_half_sizes.m_x * 2, m_half_sizes.m_y * 2));
  rect.setPosition(
      m_position.m_x - m_half_sizes.m_x, m_position.m_y - m_half_sizes.m_y);
  g_game->m_window.draw(rect);
  return 0;
}

} // namespace lost::entities
