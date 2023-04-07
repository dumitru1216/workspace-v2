#pragma once
#include "../../includes.hpp"

namespace detail {
	class impl {
	public:
		/* lets build the class -> bob the constructor */
		~impl( void ) = default;

		/* main functions */
		bool get_menu_state( );
		void set_menu_state( const bool menu_state );

		/* color classes */
		struct detail_color {
			/* colors */
			color backround = color( 20, 20, 20 );
			color accent = color( 255, 0, 0 );
		};
		detail_color detail_theme;
	};
	const auto g_detail = std::make_unique<impl>( );
}