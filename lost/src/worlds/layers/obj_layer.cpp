#include "obj_layer.h"

#include "game_objects/game_object.h"

obj_layer::obj_layer() {
  objs = std::vector<game_object>();
}

obj_layer::~obj_layer() {}

int obj_layer::update(double dt) {
  for (game_object o : objs) {
    o.update(dt);
	}
  return 0;
}

int obj_layer::render() {

  return 0;
}

void obj_layer::add_obj(game_object_template t) {
  objs.push_back(game_object(t));
}

void obj_layer::remove_first_obj(uint index) {
  int i = 0;
  for (game_object o : objs) {
    if (o.index == index) {
      game_object _o = (*(objs.begin() + i));
      _o.removed();
      objs.erase(objs.begin() + i);
      return;
    }
    ++i;
  }
}