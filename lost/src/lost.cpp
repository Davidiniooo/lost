#include "chaiscript/chaiscript.hpp"
#include "core/game.h"

chaiscript::ChaiScript chai;

void eval_script_func(const char *f) {
  chai.eval(f);
}

void eval_script_file(const char *f) {
  chai.eval_file(f);
}

void use_script_file(const char *f) {
  chai.use(f);
}

int main(int argc, char **argv) {
  game *g = new game();
  return g->run(960, 540, 60);
}