#include "execute_script.h"

#include <lua5.3/lua.hpp>

#include "script_funcs.h"

namespace lost::scripting {

int execute_script(std::string path) {
  lua_State *state = luaL_newstate();

  // Make standard libraries available in the Lua object
  luaL_openlibs(state);

  int result;

  // Load the program; this supports both source code and bytecode files.
  result = luaL_loadfile(state, path.c_str());

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