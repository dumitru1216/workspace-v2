#pragma once

/* directx includes */
#include <d3d9.h>
#include <d3dx9.h>

/* libs for directx */
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

/* include all vs needs */
#include "../includes.hpp"

/* entry_point namespace */
namespace entry {
	class impl {
		void reset_device( );
	};
	inline const auto g_entry = std::make_unique<impl>( );
}

/* those are main vars, i dont really want to bother to add them in the class
	you can do that if you want tho
*/
static LPDIRECT3D9 g_pd3d = NULL;
static LPDIRECT3DDEVICE9 g_device = NULL;
static D3DPRESENT_PARAMETERS g_d3d9pp = {};
static HWND g_window;