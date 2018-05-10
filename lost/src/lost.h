#pragma once

#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

typedef unsigned int  uint;
typedef unsigned char byte;

#define UPDATE_RENDER                                                          \
  int update(double dt);                                                       \
  int render();

#define V_UPDATE_RENDER                                                        \
  virtual int update(double dt) = 0;                                           \
  virtual int render()          = 0;

void eval_script_func(const char *f);
void eval_script_file(const char *p);
void use_script_file(const char *f);
