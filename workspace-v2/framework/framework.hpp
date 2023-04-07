#pragma once
#include "../includes.hpp"

namespace framework {
	/* maximum handling */
	inline constexpr int e_maximum = 1000;

	class impl {
	public:
		struct framework_t {
			/* we might want to store e_maximum after 
				im going to think about that
			*/
			bool e_show{}, e_colorpicker_open{};
			int e_detail_index{}, e_control_index{};
			float e_next_mouse_pos{}, e_next_menu_wheel{};
			vec2_t e_mouse_pos{};
		};

		/* in the struct up im gonna store everything i need because
			it makes it cleaner
		*/
		framework_t e_framework;

		/* initialize framework */
		void initialize( );
	};
	inline const auto g_framework = std::make_unique<impl>( );
}