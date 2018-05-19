#pragma once

#include "SFML/Graphics.hpp"
#include "layer.h"

namespace lost::worlds::layers {

class tile_layer : public layer, public sf::Drawable, public sf::Transformable {
public:
  tile_layer();
  ~tile_layer();

  UPDATE_RENDER

  bool load(
      sf::Texture *ts,
      sf::Vector2u tile_size,
      const int *  tiles,
      uint         width,
      uint         height);

private:
  void            draw(sf::RenderTarget &target, sf::RenderStates states) const;
  sf::VertexArray m_vertices;
  sf::Texture *   m_tileset;
};

} // namespace lost::worlds::layers
