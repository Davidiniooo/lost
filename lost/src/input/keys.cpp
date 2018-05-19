#include "keys.h"

namespace lost::input {

int KEY_RIGHT;
int KEY_LEFT;
int KEY_JUMP;

void load_key_binds(json j) {
  KEY_RIGHT = j["right"];
  KEY_LEFT  = j["left"];
  KEY_JUMP  = j["jump"];
}
} // namespace lost::input