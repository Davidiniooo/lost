#include "chaiscript/chaiscript.hpp"
#include "core/game.h"

chaiscript::ChaiScript chai;

void eval_script_func(const char *f) {
  chai.eval(f);
}

void eval_script_func(std::string s) {
  chai.eval(s);
}

void eval_script_file(const char *f) {
  chai.eval_file(f);
}

void eval_script_file(std::string s) {
  chai.eval_file(s);
}

void use_script_file(const char *f) {
  chai.use(f);
}

void use_script_file(std::string s) {
  chai.use(s);
}

int main(int argc, char **argv) {
  game *g = new game();
  return g->run(960, 540, 60);
}