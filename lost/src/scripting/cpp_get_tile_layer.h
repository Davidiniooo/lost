#include "lost.h"
#include "worlds/world.h"
#include "worlds/layers/tile_layer.h"
#include "core/game.h"
#include "lua5.3/lua.hpp"

namespace lost::scripting::funcs {
lost::worlds::layers::tile_layer *cpp_get_tile_layer(std::string name);
} // namespace lost::scripting::funcs