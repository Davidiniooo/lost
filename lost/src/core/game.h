#pragma once

#include "lost.h"

class game {
public:
  game();
  ~game();

  int run(uint w, uint h, double fps);
  int clean();
  int update(double dt);
  int render();

  bool          running;
  SDL_Window *  window;
  SDL_Surface * screen_surface;
  SDL_Renderer *renderer;
};
