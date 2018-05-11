#pragma once

#include "game_object_template.h"
#include "lost.h"

class game_object {
public:
  game_object(game_object_template t);
  ~game_object();
  UPDATE_RENDER
  void                 removed();
  game_object_template tmplt;
  uint                 index;
};

uint get_obj_index();
