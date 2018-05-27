#pragma once

#include <lua5.3/lua.hpp>

namespace lost::scripting::funcs {
  using namespace lost;

  #define get_set(x) int get_##x(lua_State* L); int set_##x(lua_State* L);

  get_set(x)
  get_set(y)
  get_set(hsp)
  get_set(vsp)
  
  int hitbox_right(lua_State* L);
  int hitbox_left(lua_State* L);
  int hitbox_top(lua_State* L);
  int hitbox_bottom(lua_State* L);
}