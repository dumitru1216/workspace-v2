#include "render.hpp"

void render::impl::initialize_fonts( ) {
	/* here we are going to initialize our fonts */
}

void render::impl::add_rect_filled( int x, int y, int w, int h, color c, int rounding ) {
	draw_list->AddRectFilled( im_vec_2( x, y ), im_vec_2( x + w, y + h ), c.to_d3d( ), rounding );
}

void render::impl::add_rect( int x, int y, int w, int h, color c, int rounding ) {
	draw_list->AddRect( im_vec_2( x, y ), im_vec_2( x + w, y + h ), c.to_d3d( ), rounding );
}

void render::impl::add_gradient_horizontal( int x, int y, int w, int h, color c1, color c2 ) {
	draw_list->AddRectFilledMultiColor( im_vec_2( x, y ), im_vec_2( x + w, y + h ), c1.to_d3d( ), c2.to_d3d( ), c2.to_d3d( ), c1.to_d3d( ) );
}

void render::impl::add_gradient_horizontal( int x, int y, int w, int h, color c1, color c2 ) {
	draw_list->AddRectFilledMultiColor( im_vec_2( x, y ), im_vec_2( x + w, y + h ), c1.to_d3d( ), c1.to_d3d( ), c2.to_d3d( ), c2.to_d3d( ) );
}