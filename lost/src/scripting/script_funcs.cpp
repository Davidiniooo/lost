#include "scripting/script_funcs.h"
#include "scripting/execute_script.h"

namespace lost::scripting::funcs {
int get_tile_layer(lua_State *L) {
  std::string name = lua_tostring(L, 1);

  for (uint i = 0; i < g_game->m_current_world->m_layers.size(); ++i) {
    if (g_game->m_current_world->m_layers[i]->name.compare(name) == 0) {
      lua_pushlightuserdata(
          L,
          (worlds::layers::tile_layer *)(g_game->m_current_world->m_layers[i]));
      return 1;
    }
  }

  return 0;
}

int tile_layer_get_at(lua_State *L) {
  worlds::layers::tile_layer *tl =
      (worlds::layers::tile_layer *)lua_touserdata(L, 1);

  int x = lua_tointeger(L, 2);
  int y = lua_tointeger(L, 3);

  lua_pushnumber(L, tl->get_at(x, y));

  return 1;
}

int tile_layer_get_at_pixel(lua_State *L) {
  worlds::layers::tile_layer *tl =
      (worlds::layers::tile_layer *)lua_touserdata(L, 1);

  int x = lua_tointeger(L, 2);
  int y = lua_tointeger(L, 3);

  lua_pushnumber(L, tl->get_at_coord(x, y));

  return 1;
}

int tile_layer_get_cell_x_at_pixel(lua_State *L) {
  worlds::layers::tile_layer *tl =
      (worlds::layers::tile_layer *)lua_touserdata(L, 1);

  double x = lua_tonumber(L, 2);

  lua_pushnumber(L, tl->x_coord_to_index(x) * tl->m_tile_sizes.x);

  return 1;
}

int tile_layer_get_cell_y_at_pixel(lua_State *L) {
  worlds::layers::tile_layer *tl =
      (worlds::layers::tile_layer *)lua_touserdata(L, 1);

  double y = lua_tonumber(L, 2);

  lua_pushnumber(L, tl->y_coord_to_index(y) * tl->m_tile_sizes.y);

  return 1;
}

int call_script(lua_State *L) {
  int result;

  std::string s = lua_tostring(L, 1);

  int top = lua_gettop(L);

  for (int i = 1; i <= top; ++i) {
    lua_pushvalue(L, i);
    lua_setglobal(L, ("argument" + i));
  }

  result = luaL_dofile(L, ("scripts/" + s + ".script").c_str());

  if (result != LUA_OK) {
    return -1;
  }

  return result;
}
} // namespace lost::scripting::funcs