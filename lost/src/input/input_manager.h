#pragma once

#include <list>
#include <unordered_map>

namespace lost::input {

class input_manager {
public:
  input_manager();
  ~input_manager();

  bool key_pressed(int key_code);
  bool key_down(int key_code);
  bool key_released(int key_code);
  bool key_up(int key_code);

  void press_key(int key_code);
  void release_key(int key_code);

  int update();

private:
  std::unordered_map<int, bool> m_keys;
  std::list<int>                m_changed_keys;
};
} // namespace lost::input