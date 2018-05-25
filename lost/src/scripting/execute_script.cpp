#include "execute_script.h"

#include <lua5.3/lua.hpp>

#include "obj_script_funcs.h"
#include "script_funcs.h"

#include "entities/game_entity.h"

namespace lost::scripting {

void register_funcs(lua_State *state) {
  luaL_openlibs(state);

  lua_register(state, "get_tile_layer", funcs::get_tile_layer);
  lua_register(state, "tile_layer_get_at", funcs::tile_layer_get_at);
  lua_register(
      state, "tile_layer_get_at_pixel", funcs::tile_layer_get_at_pixel);
  lua_register(
      state,
      "tile_layer_get_cell_x_at_pixel",
      funcs::tile_layer_get_cell_x_at_pixel);
  lua_register(
      state,
      "tile_layer_get_cell_x_at_pixel",
      funcs::tile_layer_get_cell_x_at_pixel);
  lua_register(state, "tile_layer_get_tile_width", funcs::tile_layer_get_tile_width);
  lua_register(state, "tile_layer_get_tile_height", funcs::tile_layer_get_tile_height);
  lua_register(state, "call_script", funcs::call_script);
  lua_register(state, "key_down", funcs::key_down);
  lua_register(state, "key_pressed", funcs::key_pressed);
  lua_register(state, "key_up", funcs::key_up);
  lua_register(state, "key_released", funcs::key_released);
}

int execute_script(std::string path) {
  lua_State *state = luaL_newstate();

  register_funcs(state);

  int result;

  // Load the program; this supports both source code and bytecode files.
  result = luaL_loadfile(state, ("scripts/" + path + ".lua").c_str());

  if (result != LUA_OK) {
    return -1;
  }

  // Finally, execute the program by calling into it.
  // Change the arguments if you're not running vanilla Lua code.

  result = lua_pcall(state, 0, LUA_MULTRET, 0);

  lua_pop(state, 1);

  return 0;
}

void register_obj_funcs(lua_State *state) {
  lua_register(state, "get_x", funcs::get_x);
  lua_register(state, "set_x", funcs::set_x);
  lua_register(state, "get_y", funcs::get_y);
  lua_register(state, "set_y", funcs::set_y);
  lua_register(state, "get_hsp", funcs::get_hsp);
  lua_register(state, "set_hsp", funcs::set_hsp);
  lua_register(state, "get_vsp", funcs::get_vsp);
  lua_register(state, "set_vsp", funcs::set_vsp);
  lua_register(state, "hitbox_right", funcs::hitbox_right);
  lua_register(state, "hitbox_left", funcs::hitbox_left);
  lua_register(state, "hitbox_top", funcs::hitbox_top);
  lua_register(state, "hitbox_bottom", funcs::hitbox_bottom);
}

int execute_script(std::string path, lost::entities::game_entity *e) {
  lua_State *state = luaL_newstate();

  register_funcs(state);

  lua_pushlightuserdata(state, e);
  lua_setglobal(state, "this");

  register_obj_funcs(state);

  int result;

  // Load the program; this supports both source code and bytecode files.
  result = luaL_loadfile(state, ("scripts/" + path + ".lua").c_str());

  if (result != LUA_OK) {
    return -1;
  }

  // Finally, execute the program by calling into it.
  // Change the arguments if you're not running vanilla Lua code.

  result = lua_pcall(state, 0, LUA_MULTRET, 0);

  lua_pop(state, 1);

  return 0;
}

} // namespace lost::scripting