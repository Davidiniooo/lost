#include "core/game.h"
#include <iostream>
#include <fstream>

json json_from_file(const char *path_from_data) {
  std::ifstream ifs(path_from_data);
  json j;
  ifs >> j;
  ifs.close();
  return j;
}

int main(int argc, char **argv) {
  game *g = new game();
  return g->run(960, 540, 60);
}
