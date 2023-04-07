#include "input.hpp"
#include "../framework.hpp"

vec2_t input::impl::get_mouse_pos( ) {
	return framework::g_framework->e_framework.e_mouse_pos;
}

void input::impl::set_mouse_pos( const vec2_t e_pos ) {
	framework::g_framework->e_framework.e_mouse_pos = vec2_t( e_pos.x, e_pos.y );
}

void input::impl::pool_input( ) {
	for ( size_t i{ 0 }; i < 256; i++ ) {
		helpers_input.m_prev_key_state[ i ] = helpers_input.m_key_state[ i ];
		helpers_input.m_key_state[ i ] = GetAsyncKeyState( i );
	}
}

bool input::impl::key_pressed( const uintptr_t m_key ) {
	return helpers_input.m_key_state[ m_key ] && !helpers_input.m_prev_key_state[ m_key ];
}

bool input::impl::mouse_pointer( const vec2_t m_pos, const vec2_t m_size ) {
	std::pair<bool, bool> m_should_return{
		get_mouse_pos( ).x > m_pos.x && get_mouse_pos( ).y > m_pos.y,
		get_mouse_pos( ).x < m_pos.x + m_size.x && get_mouse_pos( ).y < m_pos.y + m_size.y
	};

	return m_should_return.first && m_should_return.second;
}

void input::impl::set_mouse_wheel( const float m_mouse ) {
	framework::g_framework->e_framework.e_next_menu_wheel = m_mouse;
}

float input::impl::get_mouse_wheel( ) {
	return framework::g_framework->e_framework.e_next_menu_wheel;
}