#pragma once

#include "lost.h"

class game {
public:
  game();
  ~game();

  int run(uint w, uint h, double fps);
  int clean();

  bool         running;
  SDL_Window * window;
  SDL_Surface *screen_surface;
};
