#pragma once

#include "data/data.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

typedef unsigned int  uint;
typedef unsigned char byte;

using json = nlohmann::json;

#define UPDATE_RENDER                                                          \
  int update(double dt);                                                       \
  int render();

#define V_UPDATE_RENDER                                                        \
  virtual int update(double dt) = 0;                                           \
  virtual int render()          = 0;

json json_from_file(std::string path_from_data);

extern class game * global_game;
