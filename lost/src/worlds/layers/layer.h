#pragma once

class layer {
public:
  layer() {}
  ~layer() {}

  virtual int update(double dt) = 0;
  virtual int draw()            = 0;
};