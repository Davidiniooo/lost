#include "lost.h"
#include "core/game.h"
#include <fstream>
#include <iostream>

namespace lost {

game *g_game;

json json_from_file(std::string path_from_data) {
  std::ifstream ifs(("data/" + path_from_data).c_str());
  json          j;
  ifs >> j;
  ifs.close();
  return j;
}

int main(int argc, char **argv) {
  g_game = new game();
  return g_game->run(960, 540, 60);
}

} // namespace lost
