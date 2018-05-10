#include "core/game.h"

int main(int argc, char **argv) {
  game *g = new game();
  return g->run(960, 540, 60);
}