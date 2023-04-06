#include "render.hpp"

void render::impl::initialize_fonts( ) {
	/* here we are going to initialize our fonts */
}

void render::impl::add_rect_filled( int x, int y, int w, int h, color color, int rounding ) {
	draw_list->AddRectFilled( im_vec_2( x, y ), im_vec_2( x + w, y + h ), color.to_d3d( ), rounding );
}