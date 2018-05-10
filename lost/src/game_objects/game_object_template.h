#pragma once

#include "lost.h"

struct game_object_template {
public:
	char * script_path;
};

#define OBJ_TMPLT_PLAYER                                                       \
  { "player.chai" }
