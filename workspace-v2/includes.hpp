#pragma once
#pragma warning ( disable : 4005 )
#define WINDOWS_IGNORE_PACKING_MISMATCH
#define WIN32_LEAN_AND_MEAN      // Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include <memory>
#include <sstream>
#include <iostream>
#include <functional>
#include <WinUser.h>

/* main includes */
#include "math/vec2_t.hpp"
#include "math/color_t.hpp"

/* imgui */
#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_internal.h"