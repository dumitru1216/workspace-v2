#pragma once
#include "../../includes.hpp"

namespace input {
	class impl {
	public:
		void pool_input( );
		void set_mouse_pos( const vec2_t e_pos );
		void set_mouse_wheel( const float e_mouse );

		bool key_pressed( const uintptr_t e_key );
		bool mouse_pointer( const vec2_t e_pos, const vec2_t e_size );

		float get_mouse_wheel( );
		vec2_t get_mouse_pos( );

		/* struct */
		struct helpers_t {
			bool m_key_state[ 256 ]{};
			bool m_prev_key_state[ 256 ]{};
		};
		helpers_t helpers_input;
	};
	inline const auto g_input = std::make_unique<impl>( );
}