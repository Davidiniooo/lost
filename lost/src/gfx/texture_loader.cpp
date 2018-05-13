#include "texture_loader.h"

std::vector<texture_item> loaded_textures = std::vector<texture_item>();

bool texture_exists(std::string path, int *i) {
  for (int _i = 0; _i < loaded_textures.size(); ++_i) {
    if ((*(loaded_textures.begin() + _i)).path.compare(path) == 0) {
      *i = _i;
      return true;
    }
  }
  return false;
}

sf::Texture *get_texture(std::string path) {
  int i;
  if (texture_exists(path, &i)) {
    return &(loaded_textures[i].texture);
  } else {
    sf::Texture texture;
    texture.loadFromFile("textures/" + path);
    texture.setSmooth(false);
    texture_item i = {path, texture};
    loaded_textures.push_back(i);
    return &((*(loaded_textures.end() - 1)).texture);
  }
}
