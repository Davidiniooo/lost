#include "lost.h"
#include <unordered_map>
#include <string>

namespace lost::input {

using namespace lost;

void load_key_binds(json j);

extern std::unordered_map<std::string, int> keys;

} // namespace lost::input