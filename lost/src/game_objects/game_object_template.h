#pragma once

#include "lost.h"

struct game_object_template {
public:
	const char * script_path;
};

constexpr game_object_template OBJ_TMPLT_PLAYER = {"player"};
