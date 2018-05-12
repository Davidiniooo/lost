#pragma once

#include "SDL2/SDL.h"
#include "lost.h"

struct texture_item {
  std::string path;
  SDL_Texture *texture;
};

SDL_Texture *get_texture(std::string path, SDL_Renderer *r);
