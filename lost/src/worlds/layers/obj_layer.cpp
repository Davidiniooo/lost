#include "obj_layer.h"

#include "game_objects/game_object.h"

obj_layer::obj_layer() {
  objs = std::vector<game_object *>();
}

obj_layer::~obj_layer() {}

int obj_layer::update(double dt) {

  return 0;
}

int obj_layer::render() {

  return 0;
}

void obj_layer::add_obj(game_object *obj) {
  objs.push_back(obj);
}

void obj_layer::remove_first_obj(game_object *obj) {
	int i = 0;
  for (game_object *o : objs) {
    if (o == obj) {
      objs.erase(objs.begin() + i);
			return;
    }
		++i;
  }
}