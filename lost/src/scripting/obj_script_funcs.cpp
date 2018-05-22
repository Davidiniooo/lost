#include "obj_script_funcs.h"
#include "entities/game_entity.h"
#include "execute_script.h"

namespace lost::scripting::funcs {

int get_x(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e = (lost::entities::game_entity*)lua_topointer(L, lua_gettop(L));

  lua_pushnumber(L, e->m_position.x);

  return 1;
}

int set_x(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e = (lost::entities::game_entity*)lua_topointer(L, lua_gettop(L));

  e->m_position.x = lua_tonumber(L, 1);

  return 0;
}

int get_y(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e = (lost::entities::game_entity*)lua_topointer(L, lua_gettop(L));

  lua_pushnumber(L, e->m_position.y);

  return 1;
}

int set_y(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e = (lost::entities::game_entity*)lua_topointer(L, lua_gettop(L));

  e->m_position.y = lua_tonumber(L, 1);

  return 0;
}

int get_hsp(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e = (lost::entities::game_entity*)lua_topointer(L, lua_gettop(L));

  lua_pushnumber(L, e->m_velocity.x);

  return 1;
}

int set_hsp(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e = (lost::entities::game_entity*)lua_topointer(L, lua_gettop(L));

  e->m_velocity.x = lua_tonumber(L, 1);

  return 0;
}

int get_vsp(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e = (lost::entities::game_entity*)lua_topointer(L, lua_gettop(L));

  lua_pushnumber(L, e->m_velocity.y);

  return 1;
}

int set_vsp(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e = (lost::entities::game_entity*)lua_topointer(L, lua_gettop(L));

  e->m_velocity.y = lua_tonumber(L, 1);

  return 0;
}

} // namespace lost::scripting::funcs