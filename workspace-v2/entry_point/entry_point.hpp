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

	};
	inline const auto g_entry = std::make_unique<impl>( );
}