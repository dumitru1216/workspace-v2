#include "entry_point.hpp"

int main( HINSTANCE h_instance, HINSTANCE h_prev_instance, 
		  LPWSTR lp_cmd_line, int n_cmd_show ) {
	/* main function so we can build and we also here call everything so yeah... 
		console alocation 
	*/
	alloc_console( );

	/* lzp class initialization */
	LPCTSTR lpz_class{};
	lpz_class = "workspace v2";
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

/* this function initialize all render states */
void entry::impl::setup_render_states( std::function< void( ) > func ) {
	/* backup dx state */
	IDirect3DStateBlock9* d3d9_state_block{}; /* retarded */

	/* store this to null */
	d3d9_state_block = vs_null;

	/* create state block */
	if ( create_state_block( D3DSBT_ALL, &d3d9_state_block ) < 0 )
		return;

	/* get display size */
	vs_rect screen_rect{};
	get_client_rect( g_window, &screen_rect ); /* get the client rect and port it to screen-rect */

	/* grab display size */
	vec2_t display_size{};
	display_size = vec2_t( ( float )( screen_rect.right - screen_rect.left ), ( float )( screen_rect.bottom - screen_rect.top ) );

	set_pixel_shader( vs_null );
	set_vertex_shader( vs_null );

	/* im not that retarded so yeah... */
	/* set render state */
	set_render_state( D3DRS_CULLMODE, D3DCULL_NONE );
	set_render_state( D3DRS_LIGHTING, false );
	set_render_state( D3DRS_ZENABLE, false );
	set_render_state( D3DRS_ALPHABLENDENABLE, true );
	set_render_state( D3DRS_ALPHATESTENABLE, false );
	set_render_state( D3DRS_BLENDOP, D3DBLENDOP_ADD );
	set_render_state( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );
	set_render_state( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	set_render_state( D3DRS_SCISSORTESTENABLE, true );

	/* set texture stage state */
	set_texture_stage_state( 0, D3DTSS_COLOROP, D3DTOP_MODULATE );
	set_texture_stage_state( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
	set_texture_stage_state( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
	set_texture_stage_state( 0, D3DTSS_ALPHAOP, D3DTOP_MODULATE );
	set_texture_stage_state( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );
	set_texture_stage_state( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );

	/* sampler state */
	set_sampler_state( 0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
	set_sampler_state( 0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );

	/* setup viewport | oh we had to initialize a pointer */
	auto setup_view_port = [ ]( vec2_t size ) -> void {
		/* clean setup yeah, sorry for that */
		D3DVIEWPORT9 vp;
		vp.X = vp.Y = 0;
		vp.Width = ( DWORD )size.x;
		vp.Height = ( DWORD )size.y;
		vp.MinZ = 0.0f;
		vp.MaxZ = 1.0f;

		/* set it */
		set_viewport( &vp );
	}; /* we also have to call it to initialize it */
	setup_view_port( display_size );

	/* ortographic matrix pos, 1 year ago i was doing it with {} now lets do it with lambada */
	auto setup_ortographic_matrix = [ ]( vec2_t size ) -> void {
		const float L = 0.5f, R = size.x + 0.5f, T = 0.5f, B = size.y + 0.5f;
		D3DMATRIX mat_identity = { { 1.0f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  0.0f, 0.0f, 1.0f, 0.0f,  0.0f, 0.0f, 0.0f, 1.0f } };
		D3DMATRIX mat_projection =
		{
			2.0f / ( R - L ),   0.0f,         0.0f,  0.0f,
			0.0f,         2.0f / ( T - B ),   0.0f,  0.0f,
			0.0f,         0.0f,         0.5f,  0.0f,
			( L + R ) / ( L - R ),  ( T + B ) / ( B - T ),  0.5f,  1.0f,
		};

		/* set transformation */
		set_transform( D3DTS_WORLD, &mat_identity );
		set_transform( D3DTS_VIEW, &mat_identity );
		set_transform( D3DTS_PROJECTION, &mat_projection );
	};

	/* run function */
	func( );

	/* restore dx state */
	d3d9_state_block->Apply( );
	d3d9_state_block->Release( );
}

/* window process pointer */
LRESULT CALLBACK wnd_processing( HWND, UINT, WPARAM, LPARAM );

/* register class */
vs_atom entry::impl::register_window_class( HINSTANCE instance, LPCTSTR class_name ) {
	WNDCLASSEX wcex{}; /* initialize class */

	/* initialize client */
	auto initialzize_client = [ ]( WNDCLASSEX wcex, HINSTANCE instance, LPCTSTR class_name ) -> vs_atom {
		wcex.cbSize = sizeof( WNDCLASSEX );
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = wnd_processing;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = instance;
		wcex.hIcon = LoadIcon( instance, MAKEINTRESOURCE( IDI_GUITEST ) );
		wcex.hCursor = LoadCursor( nullptr, IDC_ARROW );
		wcex.hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 );
		wcex.lpszMenuName = MAKEINTRESOURCE( IDC_GUITEST );
		wcex.lpszClassName = class_name;
		wcex.hIconSm = LoadIcon( wcex.hInstance, MAKEINTRESOURCE( IDI_SMALL ) );

		/* register the class */
		return RegisterClassEx( &wcex );
	}; /* we also have to call it */
	initialzize_client( wcex, instance, class_name );
}

/* window initialization */
vs_bool entry::impl::initialize_window( HINSTANCE instance, LPCTSTR class_name, LPCTSTR title ) {
	/* get position on screen, i just dint wanted to make it snake_case full this, it keps getting boring*/
	vs_rect screen_rect{};
	GetWindowRect( GetDesktopWindow( ), &screen_rect );

	/* on the whole screen */
	g_window = CreateWindowEx( WS_EX_APPWINDOW, class_name, title, WS_POPUP,
							   screen_rect.left, screen_rect.top, screen_rect.right /* width */,
							   screen_rect.bottom /* height */, NULL, NULL, instance, NULL );

	if ( !g_window ) { return vs_false; }
	return vs_true;
}

/* window process */
LRESULT CALLBACK wnd_processing( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp ) {
	return DefWindowProcA( hwnd, msg, wp, lp );
}

/* call for window processing */
LRESULT CALLBACK entry::impl::wnd_proc( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp ) {
	/* lets call wnd_process */
	wnd_processing( hwnd, msg, wp, lp );
}