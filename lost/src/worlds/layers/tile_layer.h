#pragma once

#include "SFML/Graphics.hpp"
#include "layer.h"

namespace lost::worlds::layers {

class tile_layer : public layer, public sf::Drawable, public sf::Transformable {
public:
  tile_layer(std::string n);
  ~tile_layer();

  UPDATE_RENDER

  bool m_visible;

  bool load(
      sf::Texture *ts,
      sf::Vector2u tile_size,
      const int *  tiles,
      uint         width,
      uint         height);

  sf::Vector2u m_tile_size;

  int get_at(int x, int y);
  int get_at_coord(double x, double y);
  int x_coord_to_index(double x);
  int y_coord_to_index(double y);

  const int * m_raw_tiles;

private:
  void            draw(sf::RenderTarget &target, sf::RenderStates states) const;
  sf::VertexArray m_vertices;
  sf::Texture *   m_tileset;
  uint            m_width;
  uint            m_height;
};

} // namespace lost::worlds::layers
