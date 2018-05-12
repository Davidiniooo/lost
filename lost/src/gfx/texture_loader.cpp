#include "texture_loader.h"
#include "SDL2/SDL_image.h"

std::vector<texture_item> loaded_textures = std::vector<texture_item>();

bool texture_exists(std::string path, int * i) {
  for (int _i = 0; _i < loaded_textures.size(); ++_i) {
    if ((*(loaded_textures.begin() + _i)).path.compare(path) == 0) {
      *i = _i;
      return true;
    }
  }
  return false;
}

SDL_Texture *get_texture(std::string path, SDL_Renderer *r) {
  int i;
  if (texture_exists(path, &i)) {
    return loaded_textures[i].texture;
  } else {
    SDL_Surface *tmp_surface = IMG_Load(("textures/" + path).c_str());
    SDL_Texture *tmp_texture = SDL_CreateTextureFromSurface(r, tmp_surface);
    SDL_FreeSurface(tmp_surface);
    loaded_textures.push_back({path, tmp_texture});
    return tmp_texture;
  }
}
