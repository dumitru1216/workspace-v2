#pragma once
#include "../../../includes.hpp"
#include "../../framework.hpp"

namespace window {
	class impl {
	public:

	};
	const auto g_window = std::make_unique<impl>( );
}