#include "lost.h"

namespace lost::entities {
class game_entity;
}

namespace lost::worlds::layers {
class tile_layer;
}

namespace lost::math::collision {

using namespace lost;

void entity_tilemap(
    lost::entities::game_entity &e, lost::worlds::layers::tile_layer &t);
} // namespace lost::math::collision