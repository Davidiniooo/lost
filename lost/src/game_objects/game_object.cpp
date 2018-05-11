#include "game_object.h"
#include "lost.h"
#include <string>

game_object::game_object(game_object_template t) {
  tmplt = t;
  use_script_file("scripts/" + std::string(tmplt.script_path) + ".chai");
  index = get_obj_index();
  eval_script_func(
      "var obj" + std::to_string(index) + " = " + std::string(tmplt.script_path)
      + "();");
}

game_object::~game_object() {}

int game_object::update(double dt) {
  eval_script_func(
      "obj" + std::to_string(index) + ".update(" + std::to_string(dt) + ");");
  return 0;
}

int game_object::render() {
  return 0;
}

uint             counter        = 0;
std::stack<uint> unused_indices = std::stack<uint>();

void game_object::removed() {
  unused_indices.push(index);
}

uint get_obj_index() {
  if (unused_indices.size() > 0) {
    uint i = unused_indices.top();
    unused_indices.pop();
    return i;
  } else {
    return counter++;
  }
}