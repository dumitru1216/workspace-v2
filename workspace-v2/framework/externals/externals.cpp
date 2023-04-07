#include "externals.hpp"
#include "../../render/render.hpp"

void externals::impl::initialize( ) {
	for ( size_t i{ 0 }; i < e_drawing.rect_draw.size( ); i++ )
		render::g_render->add_rect( e_drawing.rect_draw[ i ].pos_x, e_drawing.rect_draw[ i ].pos_y, 
								e_drawing.rect_draw[ i ].m_width, e_drawing.rect_draw[ i ].m_height, e_drawing.rect_draw[ i ].c );

	/* we are going to initialize more stuff soon */
	/* clear everything */
	e_drawing.rect_draw.clear( );
	e_drawing.outline_draw.clear( );
	e_drawing.gradient_h_draw.clear( );
	e_drawing.gradient_v_draw.clear( );
	e_drawing.rect_draw2.clear( );
	e_drawing.text_draw.clear( );
}