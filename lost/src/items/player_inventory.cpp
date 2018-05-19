#include "player_inventory.h"

namespace lost::items {

player_inventory::player_inventory() {}

player_inventory::player_inventory(json j) : inventory(j) {
  if (j["head"].is_object())
    head = armor(json_from_file(get_item_path_from_name(j["head"])));
  if (j["arms"].is_object())
    arms = armor(json_from_file(get_item_path_from_name(j["arms"])));
  if (j["chest"].is_object())
    chest = armor(json_from_file(get_item_path_from_name(j["chest"])));
  if (j["legs"].is_object())
    legs = armor(json_from_file(get_item_path_from_name(j["legs"])));

  if (j["primary"].is_object())
    primary = weapon(
        json_from_file(get_item_path_from_name(j["primary"]["name"])),
        j["primary"]["dps"]);
  if (j["secondary"].is_object())
    secondary = weapon(
        json_from_file(get_item_path_from_name(j["secondary"]["name"])),
        j["primary"]["dps"]);
  if (j["ternary"].is_object())
    ternary = weapon(
        json_from_file(get_item_path_from_name(j["ternary"]["name"])),
        j["primary"]["dps"]);
}

player_inventory::~player_inventory() {}

} // namespace lost::items
