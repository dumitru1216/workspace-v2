#include "entry_point.hpp"

int main( HINSTANCE h_instance, HINSTANCE h_prev_instance, 
		  LPWSTR lp_cmd_line, int n_cmd_show ) {
	/* main function so we can build and we also here call everything so yeah... */
}

/* reset device function, we use that to reset or result d3d window */
void entry::impl::reset_device( ) {
	HRESULT result{}; /* this is main result var, we use {} to initialize it */

	/* we want our code look shiny so im gonna do that retarded shit
		oxygen and whoever sees that code please forgive me */
	auto reset_d3d_revice = [ ]( D3DPRESENT_PARAMETERS reset_parrameter ) -> HRESULT {
		/* this shit might crash or might work, im not sure yet we will see once we run it :) */
		g_device->Reset( &reset_parrameter );
	};

	/* store stuff to our result */
	result = reset_d3d_revice( g_d3d9pp );

	/* function */
	if ( result != D3DERR_INVALIDCALL ) { }
}

/* clean device function, we use that to clean our stuff always
	this helps much to avoid memory leaks, we check if the pointer is null, if its not null we set it to
	null after we release our device into main function
*/
void entry::impl::clean_device( ) {
	/* if our device is avaible release it to our main function */
	if ( g_device ) {
		g_device->Release( );

		/* after we released our device we also want to set it to null/nullptr */
		g_device = NULL;
	}

	/* if our d3d pointer is avaible release it to our main function */
	if ( g_pd3d ) {
		g_pd3d->Release( );

		/* after we released our d3d pointer we also want to set it to null/nullptr */
		g_pd3d = NULL;
	}
}