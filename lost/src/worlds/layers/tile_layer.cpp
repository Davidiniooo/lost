#include "tile_layer.h"
#include "SFML/Graphics.hpp"
#include "core/game.h"

namespace lost::worlds::layers {

tile_layer::tile_layer(std::string n) : layer(n), m_visible(true) {}

tile_layer::~tile_layer() {}

int tile_layer::update(double dt) {
  return 0;
}

int tile_layer::render() {
  if (m_visible) {
    g_game->m_window.draw(*this);
  }
  return 0;
}

bool tile_layer::load(
    sf::Texture *ts,
    sf::Vector2u tile_size,
    const int *  tiles,
    uint         width,
    uint         height) {

  m_raw_tiles = tiles;

  m_width  = width;
  m_height = height;

  m_tile_size = tile_size;

  m_tileset = ts;

  m_vertices.setPrimitiveType(sf::Quads);
  m_vertices.resize(width * height * 4);

  for (unsigned int i = 0; i < width; ++i) {
    for (unsigned int j = 0; j < height; ++j) {
      // get the current tile number
      int tileNumber = tiles[i + j * width];

      // find its position in the tileset texture
      int tu = tileNumber % (m_tileset->getSize().x / tile_size.x);
      int tv = tileNumber / (m_tileset->getSize().x / tile_size.x);

      // get a pointer to the current tile's quad
      sf::Vertex *quad = &m_vertices[(i + j * width) * 4];

      // define its 4 corners
      quad[0].position =
          sf::Vector2f((float)(i * tile_size.x), (float)(j * tile_size.y));
      quad[1].position = sf::Vector2f(
          (float)((i + 1) * tile_size.x), (float)(j * tile_size.y));
      quad[2].position = sf::Vector2f(
          (float)((i + 1) * tile_size.x), (float)((j + 1) * tile_size.y));
      quad[3].position = sf::Vector2f(
          (float)(i * tile_size.x), (float)((j + 1) * tile_size.y));

      // define its 4 texture coordinates
      quad[0].texCoords =
          sf::Vector2f((float)(tu * tile_size.x), (float)(tv * tile_size.y));
      quad[1].texCoords = sf::Vector2f(
          (float)((tu + 1) * tile_size.x), (float)(tv * tile_size.y));
      quad[2].texCoords = sf::Vector2f(
          (float)((tu + 1) * tile_size.x), (float)((tv + 1) * tile_size.y));
      quad[3].texCoords = sf::Vector2f(
          (float)(tu * tile_size.x), (float)((tv + 1) * tile_size.y));
    }
  }
  return true;
}

int tile_layer::get_at(int x, int y) {
  if (x * y < 0 || x * y >= m_width * m_height)
    return 0;
  
  return m_raw_tiles[y * m_width + x];
}

int tile_layer::get_at_coord(double x, double y) {
  if (x * y < 0 || x * y >= m_width * m_height)
    return 0;

  return m_raw_tiles[(int)floor(y / (double)m_tile_size.y) * m_width
         + (int)floor(x / (double)m_tile_size.x)];
}

int tile_layer::x_coord_to_index(double x) {
  return (int)floor(x / m_tile_size.x);
}

int tile_layer::y_coord_to_index(double y) {
  return (int)floor(y / m_tile_size.y);
}

void tile_layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  // apply the transform
  states.transform *= getTransform();

  // apply the tileset texture
  states.texture = m_tileset;

  // draw the vertex array
  target.draw(m_vertices, states);
}

} // namespace lost::worlds::layers
