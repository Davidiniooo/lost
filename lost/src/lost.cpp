#include "lost.h"
#include "core/game.h"
#include <iostream>
#include <fstream>

game * global_game;

json json_from_file(std::string path_from_data) {
  std::ifstream ifs(("data/" + path_from_data).c_str());
  json j;
  ifs >> j;
  ifs.close();
  return j;
}

int main(int argc, char **argv) {
  global_game = new game();
  return global_game->run(960, 540, 60);
}
