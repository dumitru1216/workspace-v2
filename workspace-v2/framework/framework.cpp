#include "framework.hpp"
#include "externals/externals.hpp"
#include "input/input.hpp"
#include "object_handling/object_handling.hpp"
#include "details/details.hpp"

void framework::impl::initialize( ) {
	auto initialize_menu_handling = [ ]( ) -> void {
		input::g_input->pool_input( );
		object_handling::g_object_handling->set_index( 0 );

		/* menu key setup */
		if ( input::g_input->key_pressed( VK_INSERT ) )
			detail::g_detail->set_menu_state( !detail::g_detail->get_menu_state( ) );

		/* state handling */
		object_handling::g_object_handling->m_opened[ object_handling::impl::handling_t::combo ] = -1;
		object_handling::g_object_handling->m_opened[ object_handling::impl::handling_t::multicombo ] = -1;
		object_handling::g_object_handling->m_opened[ object_handling::impl::handling_t::bind ] = -1;
	};

	/* lets initialize it */
	initialize_menu_handling( );

	/* we have to initialize externals at the end of framework*/
	externals::g_externals->initialize( );
}