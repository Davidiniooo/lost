#include "player_inventory.h"

player_inventory::player_inventory() {}

player_inventory::player_inventory(json j) : inventory(j) {
  head  = armor(json_from_file(get_item_path_from_name(j["head"])));
  arms  = armor(json_from_file(get_item_path_from_name(j["arms"])));
  chest = armor(json_from_file(get_item_path_from_name(j["chest"])));
  legs  = armor(json_from_file(get_item_path_from_name(j["legs"])));

  primary   = weapon(json_from_file(get_item_path_from_name(j["primary"])));
  secondary = weapon(json_from_file(get_item_path_from_name(j["secondary"])));
  ternary   = weapon(json_from_file(get_item_path_from_name(j["ternary"])));
}

player_inventory::~player_inventory() {}
