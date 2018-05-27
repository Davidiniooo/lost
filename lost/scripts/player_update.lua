local r = key_down("right") and 1 or 0;
local l = key_down("left") and 1 or 0;

local u = key_down("up") and 1 or 0;
local d = key_down("down") and 1 or 0;

set_hsp((r-l) * 0.8);
set_vsp(get_vsp() + 0.1);

if key_pressed("jump") and on_floor() then
  set_vsp(get_vsp() - 1.5)
end

move_collide()