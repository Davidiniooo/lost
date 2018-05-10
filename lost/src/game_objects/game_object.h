#pragma once

#include "game_object_template.h"
#include "lost.h"

class game_object {
public:
  game_object(game_object_template t);
  ~game_object();
  UPDATE_RENDER
	game_object_template tmplt;
};