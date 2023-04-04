#include "entry_point.hpp"

int main( HINSTANCE h_instance, HINSTANCE h_prev_instance, 
		  LPWSTR lp_cmd_line, int n_cmd_show ) {
	/* main function so we can build and we also here call everything so yeah... */
}

/* reset device function, we use that to reset or result d3d window */
void entry::impl::reset_device( ) {
	HRESULT result{}; /* this is main result var, we use {} to initialize it */

	/* we want our code look shiny so im gonna do that retarded shit
		oxygen and whoever sees that code please forgive me 
	*/
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

/* this function creates a directx_d3d device with a swapchain for rendering on a window, 
	it sets up the presentation parameters for the device, if the device is created successfully, 
	the function returns true, otherwise it returns false. 
	The function uses global variables g_pd3d and g_device, which are assumed to be initialized elsewhere.
*/
vs_bool entry::impl::create_device( HWND hwnd ) {
	/* lets create it */
	if ( ( g_pd3d = direct_3d_create( D3D_SDK_VERSION ) ) == NULL )
		return vs_false; /* classic, dinosaur epoca */

	/* create the device */
	/* initialize presentation parameters to zero */
	zero_memory( &g_d3d9pp, sizeof( g_d3d9pp ) );

	/* set windowed mode */
	d3d_windowed = vs_true;

	/* set swap effect */
	d3d_swap_effect = d3d_swap_effect_discard;

	/* set back buffer format */
	d3d_back_buffer_format = d3d_fmt_unknown;

	/* enable auto depth stencil */
	d3d_enable_depth_stencil = vs_true;

	/* set depth stencil buffer format */
	d3d_auto_depth_stencil_format = d3d_fmt_16;

	/* set presentation interval to one (present with vsync) */
	d3d_presentation_interval = D3DPRESENT_INTERVAL_ONE;

	/* we want our code look shiny so im gonna do that retarded shit
		oxygen and whoever sees that code please forgive me, i fucking love snake_case 
	*/
	auto create_device = [ ]( HWND hwnd ) -> vs_bool {
		/* ok i know i said i love snake_case but im not fucking that retarded so i redefine everything snake_case */
		if ( g_pd3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3d9pp, &g_device ) < 0 )
			return vs_false;
	}; /* now we must create it (call it) */
	create_device( hwnd ); /* this now will create our device */

	/* now lets return true */
	return vs_true;
}