#include "keys.h"

namespace lost::input {

std::unordered_map<std::string, int> keys;

void load_key_binds(json j) {
  keys = std::unordered_map<std::string, int>();

  for (json::iterator it = j.begin(); it != j.end(); ++it) {
    keys[it.key()] = it.value();
  }
}
} // namespace lost::input