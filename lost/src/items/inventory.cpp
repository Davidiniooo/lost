#include "inventory.h"

namespace lost::items {

inventory::inventory() {
  items = std::vector<inventory_item>();
}

inventory::inventory(json j) {
  json json_items = j["items"];
  items                 = std::vector<inventory_item>();

  for (json _j : json_items) {
    inventory_item i = inventory_item(
        item(json_from_file(get_item_path_from_name(_j["name"]))), _j["count"]);

    items.push_back(i);
  }
}

inventory::~inventory() {}

} // namespace lost::items
