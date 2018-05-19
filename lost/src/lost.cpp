#include "lost.h"
#include "core/game.h"
#include <fstream>
#include <iostream>

namespace lost {

lost::core::game *g_game;

json json_from_file(std::string path_from_data) {
  std::ifstream ifs(("data/" + path_from_data).c_str());
  json          j;
  ifs >> j;
  ifs.close();
  return j;
}

} // namespace lost

int main(int argc, char *argv[]) {
	lost::g_game = new lost::core::game(1920, 1080);
  return lost::g_game->run(60);
}
