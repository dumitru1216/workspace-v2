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

/* resources */
#define IDS_APP_TITLE 103
#define IDR_MAINFRAME 128
#define IDD_GUITEST_DIALOG 102
#define IDD_ABOUTBOX 103
#define IDM_ABOUT 104
#define IDM_EXIT 105
#define IDI_GUITEST 107
#define IDI_SMALL 108
#define IDC_GUITEST 109
#define IDC_MYICON 2
#ifndef IDC_STATIC
#define IDC_STATIC -1
#endif

/* do some defines */
/* you dont realise how much i hate those BOOL stuff in big case so we gonna make them small case */
/* fuck you visual studio */
#define vs_bool BOOL
#define vs_true TRUE
#define vs_false FALSE
#define vs_null NULL
#define vs_rect RECT
#define vs_atom ATOM
#define zero_memory ZeroMemory
#define get_client_rect GetClientRect
#define vs_lresult LRESULT
#define alloc_console AllocConsole

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
#define direct_3d_create Direct3DCreate9
#define create_state_block g_device->CreateStateBlock
#define set_vertex_shader g_device->SetVertexShader
#define set_pixel_shader g_device->SetPixelShader
#define set_render_state g_device->SetRenderState
#define set_texture_stage_state g_device->SetTextureStageState
#define set_sampler_state g_device->SetSamplerState
#define set_transform g_device->SetTransform
#define set_viewport g_device->SetViewport

/* entry_point namespace */
namespace entry {
	class impl {
	public:
		void reset_device( );
		void clean_device( );
		vs_bool create_device( HWND hwnd );
		void setup_render_states( std::function< void( ) > func );
		vs_atom register_window_class( HINSTANCE, LPCTSTR );
		vs_bool initialize_window( HINSTANCE instance, LPCTSTR class_name, LPCTSTR title );
		LRESULT CALLBACK wnd_proc( HWND, UINT, WPARAM, LPARAM );
	};
	inline const auto g_entry = std::make_unique<impl>( );
}