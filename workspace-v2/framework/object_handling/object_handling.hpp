#pragma once
#include "../../includes.hpp"
#include "../framework.hpp"

namespace object_handling {
	class impl {
	public:
		enum handling_t {
			combo,
			multicombo,
			color_selection,
			textbox,
			bind,
			size
		};

		bool m_animate[ 5 ];
		int m_opened[ handling_t::size ];
		bool m_opened_state[ handling_t::size ][ framework::e_maximum ];

		int get_index( );
		bool is_possible( );

		void set_index( const uintptr_t m_last );
	};
	inline const auto g_object_handling = std::make_unique<impl>( );
}