#include "game.h"

int main(int argc, char ** argv) {
  game *g = new game();
  return g->run(640, 360, 60);
}