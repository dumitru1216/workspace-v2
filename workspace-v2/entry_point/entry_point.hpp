#pragma once

/* directx includes */
#include <d3d9.h>
#include <d3dx9.h>

/* libs for directx */
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

/* include all vs needs */
#include "../includes.hpp"

/* those are main vars, i dont really want to bother to add them in the class
	you can do that if you want tho
*/
static LPDIRECT3D9 g_pd3d = NULL;
static LPDIRECT3DDEVICE9 g_device = NULL;
static D3DPRESENT_PARAMETERS g_d3d9pp = {};
static HWND g_window;

/* do some defines */
/* you dont realise how much i hate those BOOL stuff in big case so we gonna make them small case */
/* fuck you visual studio */
#define vs_bool BOOL
#define vs_true TRUE
#define vs_false FALSE
#define direct_3d_create Direct3DCreate9
#define zero_memory ZeroMemory

/* d3d defines, i know this seems so fucking retarded but i love lowercase and snake_case */
#define d3d_windowed g_d3d9pp.Windowed
#define d3d_swap_effect g_d3d9pp.SwapEffect
#define d3d_back_buffer_format g_d3d9pp.BackBufferFormat
#define d3d_enable_depth_stencil g_d3d9pp.EnableAutoDepthStencil
#define d3d_auto_depth_stencil_format g_d3d9pp.AutoDepthStencilFormat
#define d3d_presentation_interval g_d3d9pp.PresentationInterval
#define d3d_swap_effect_discard D3DSWAPEFFECT_DISCARD
#define d3d_fmt_unknown D3DFMT_UNKNOWN
#define d3d_fmt_16 D3DFMT_D16

/* entry_point namespace */
namespace entry {
	class impl {
		void reset_device( );
		void clean_device( );
		vs_bool create_device( HWND hwnd );
	};
	inline const auto g_entry = std::make_unique<impl>( );
}