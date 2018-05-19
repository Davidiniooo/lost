#include "input/input_manager.h"
#include <algorithm>

namespace lost::input {
input_manager::input_manager() {}

input_manager::~input_manager() {}

int input_manager::update() {
  m_changed_keys.clear();
  return 0;
}

bool input_manager::key_pressed(int key_code) {
  return key_down(key_code)
         && (std::find(m_changed_keys.begin(), m_changed_keys.end(), key_code)
             != m_changed_keys.end());
}

bool input_manager::key_down(int key_code) {
  return m_keys.count(key_code) == 1 && m_keys[key_code];
}

bool input_manager::key_released(int key_code) {
  return key_up(key_code)
         && (std::find(m_changed_keys.begin(), m_changed_keys.end(), key_code)
             != m_changed_keys.end());
}

bool input_manager::key_up(int key_code) {
  return m_keys.count(key_code) == 0;
}

void input_manager::press_key(int key_code) {
  if (m_keys.count(key_code) == 0) {
    m_keys[key_code] = true;
    m_changed_keys.push_back(key_code);
  }
}

void input_manager::release_key(int key_code) {
  if (m_keys.count(key_code) == 1) {
    m_keys.erase(key_code);
    m_changed_keys.push_back(key_code);
  }
}

} // namespace lost::input