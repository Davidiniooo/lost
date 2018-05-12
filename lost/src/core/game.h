#pragma once

#include "lost.h"

class world;
struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;

class game {
public:
  game();
  ~game();

  int run(uint w, uint h, double fps);
  int clean();

  UPDATE_RENDER

  bool          running;
  SDL_Window *  window;
  SDL_Surface * screen_surface;
  SDL_Renderer *renderer;
  world *       current_world;
};
