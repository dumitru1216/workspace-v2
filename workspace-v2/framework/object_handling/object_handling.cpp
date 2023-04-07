#include "object_handling.hpp"
#include "../framework.hpp"

int object_handling::impl::get_index( ) {
	return framework::g_framework->e_framework.e_control_index;
}

void object_handling::impl::set_index( const uintptr_t m_last ) {
	framework::g_framework->e_framework.e_control_index = m_last;
}

bool object_handling::impl::is_possible( ) {
	return m_opened[ handling_t::combo ] == -1 && 
		m_opened[ handling_t::multicombo ] == -1 && 
		m_opened[ handling_t::bind ] == -1;
}