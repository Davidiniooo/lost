-- ~ T I L E S E T   C O L L I S I O N ~

local x = get_x()
local y = get_y()
local hsp = get_hsp()
local vsp = get_vsp()
local right = hitbox_right()
local left = hitbox_left()
local top = hitbox_top()
local bottom = hitbox_bottom()
local width = right - left
local height = bottom - top

local bbox_side_h = nil
local bbox_side_v = nil

local tile_layer = get_tile_layer("collision")
local tile_width = tile_layer_get_tile_width(tile_layer)
local tile_height = tile_layer_get_tile_height(tile_layer)

if hsp ~= 0 then
	if hsp > 0 then 
		bbox_side_h = right
	else 
		bbox_side_h = left
	end
	
	local col = false;
	
	for i = math.floor(top / tile_height), math.floor(bottom / tile_height) do
	 	local c = tile_layer_get_at(
			tile_layer, 
			math.floor((bbox_side_h + hsp) / tile_width), 
			i
		);
		
			if c == 1 then
	  		col = true;
				break
	  	end
	end

	if col then
	 	if hsp > 0 then
	 		set_x(tile_layer_get_cell_x_at_pixel(tile_layer, bbox_side_h + hsp, y) - (width/2))
			x = get_x()
			right = hitbox_right()
			left = hitbox_left()
	 	else
			set_x(tile_layer_get_cell_x_at_pixel(tile_layer, bbox_side_h + hsp, y) + tile_width + (width/2))
			x = get_x()
			right = hitbox_right()
			left = hitbox_left()
    end
		
		set_hsp(0);
		hsp = get_hsp()
  end
end

if vsp ~= 0 then
	if vsp > 0 then 
		bbox_side_v = bottom; 
	else 
		bbox_side_v = top; 
	end
	
	local col = false;
	
 	for i = math.floor(left / tile_height), math.floor(right / tile_height) do
 		local c = tile_layer_get_at(
			tile_layer, 
			i, 
			math.floor((bbox_side_v + vsp) / tile_height)
		);
		
 		if c == 1 then
 			col = true;
		end
	end
	
 	if col then
 		if vsp > 0 then
 			set_y(tile_layer_get_cell_y_at_pixel(tile_layer, x, bbox_side_v + vsp) - (height/2))
 		else
 			set_y(tile_layer_get_cell_y_at_pixel(tilemap, x, bbox_side_v + vsp) + tile_height + (height/2))
		end
 		set_vsp(0)
	end
end

-- if vsp != 0 {
-- 	var vvsp = vsp > 0 ? ceil(vsp) : floor(vsp)
	
-- 	if vsp > 0 bbox_side_v = bbox_bottom; else bbox_side_v = bbox_top;
	
-- 	if (tilemap_get_at_pixel(tilemap, bbox_left, bbox_side_v + vvsp) == 2) or 
-- 		(tilemap_get_at_pixel(tilemap, bbox_right, bbox_side_v + vvsp) == 2) {
			
-- 		if vsp > 0 and 
-- 			tilemap_get_cell_y_at_pixel(tilemap, bbox_left, bbox_side_v + vvsp) >= bbox_bottom {
-- 				draw_rectangle (tilemap_get_cell_x_at_pixel(tilemap, bbox_left, bbox_side_v + vvsp), tilemap_get_cell_y_at_pixel(tilemap, bbox_left, bbox_side_v + vvsp), tilemap_get_cell_x_at_pixel(tilemap, bbox_left, bbox_side_v + vvsp) + 15, tilemap_get_cell_y_at_pixel(tilemap, bbox_left, bbox_side_v + vvsp) + 15, false)
-- 			y = tilemap_get_cell_y_at_pixel(tilemap, bbox_left, bbox_side_v + vvsp) * 16 - sprite_yoffset
		
-- 			vsp = 0;
-- 		}
-- 	}
-- }

-- // ~ O B J E C T   C O L L I S I O N ~

-- if (place_meeting(x+hsp,y,o_collide)) {
-- 	while(!place_meeting(x+sign(hsp),y,o_collide)) {
-- 		x += sign(hsp);
-- 	}
-- 	hsp = 0;
-- }


-- if (place_meeting(x,y+vsp,o_collide)) {
-- 	while(!place_meeting(x,y+sign(vsp),o_collide)) {
-- 		y += sign(vsp);
-- 	}
-- 	vsp = 0;
-- }

set_x(get_x() + get_hsp());
set_y(get_y() + get_vsp());