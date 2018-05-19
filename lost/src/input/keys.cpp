#include "keys.h"

namespace lost::input {
void load_key_binds(json j) {
  KEY_RIGHT = j["right"];
  KEY_LEFT  = j["left"];
  KEY_JUMP  = j["jump"];
}
} // namespace lost::input