#include "game_object.h"

game_object::game_object(game_object_template t) {
	tmplt = t;
  use_script_file(tmplt.script_path);
}

game_object::~game_object() {}

int game_object::update(double dt) {
	return 0;
}