local r = key_down("right") and 1 or 0;
local l = key_down("left") and 1 or 0;

local u = key_down("up") and 1 or 0;
local d = key_down("down") and 1 or 0;

set_hsp((r-l) * 0.8);
set_vsp((d-u) * 0.8);

call_script("move_collide");