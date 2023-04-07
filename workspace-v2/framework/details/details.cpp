#include "details.hpp"
#include "../framework.hpp"

bool detail::impl::get_menu_state( ) {
	return framework::g_framework->e_framework.e_show;
}

void detail::impl::set_menu_state( const bool m_state ) {
	framework::g_framework->e_framework.e_show = m_state;
}