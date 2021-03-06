#pragma once

#include "SFML/Graphics.hpp"
#include "lost.h"

namespace lost::gfx {

using namespace lost;

struct texture_item {
  std::string path;
  sf::Texture texture;
};

sf::Texture *get_texture(std::string path);

} // namespace lost::gfx
