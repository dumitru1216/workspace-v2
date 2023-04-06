#pragma once
#include "../includes.hpp"

/* a little define to grab drawlist */
#define draw_list ImGui::GetBackgroundDrawList()
#define im_vec_2 ImVec2

namespace render {
	class impl {
		struct font_t {
			
		}; /* main define for font_t */
		font_t fonts;

		/* initialize part */
		void add_rect_filled( int x, int y, int w, int h, color c, int rounding = 0.f );
		void add_rect( int x, int y, int w, int h, color c, int rounding = 0.f );
		void add_gradient_vertical( int x, int y, int w, int h, color c, color c1 );
		void add_gradient_horizontal( int x, int y, int w, int h, color c, color c1 );

		void initialize_fonts( );
	};
	const auto g_render = std::make_unique<impl>( );
}