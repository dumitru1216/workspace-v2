#pragma once
#include "../../includes.hpp"

namespace externals {
	/* the structs for externals */
	struct e_draw_rect {
		e_draw_rect( float pos_x, float pos_y, float m_width, float m_height, color c ) {
			this->pos_x = pos_x;
			this->pos_y = pos_y;
			this->m_width = m_width;
			this->m_height = m_height;
			this->c = c;
		}

		int pos_x;
		int pos_y;
		int m_width;
		int m_height;
		color c;
	};

	struct e_draw_text {
		e_draw_text( float pos_x, float pos_y, std::string m_text, color c ) {
			this->pos_x = pos_x;
			this->pos_y = pos_y;
			this->m_text = m_text;
			this->c = c;
		}

		float pos_x;
		float pos_y;
		std::string m_text;
		color c;
	};


	struct e_draw_gradient {
		e_draw_gradient( float pos_x, float pos_y, float m_width, float m_height, color c, color c1 ) {
			this->pos_x = pos_x;
			this->pos_y = pos_y;
			this->m_width = m_width;
			this->m_height = m_height;
			this->c = c;
			this->c1 = c1;
		}

		int pos_x;
		int pos_y;
		int m_width;
		int m_height;
		color c;
		color c1;
	};

	/* the class for externals */
	class impl {
	public:
		/* we are going to do a struct for externals */
		struct externals_t {
			// outline and text
			std::vector< e_draw_text > text_draw;
			std::vector< e_draw_rect > outline_draw;

			// rect
			std::vector< e_draw_rect > rect_draw;
			std::vector< e_draw_rect > rect_draw2;

			// gradient
			std::vector< e_draw_gradient > gradient_v_draw;
			std::vector< e_draw_gradient > gradient_h_draw;
		};
		externals_t e_drawing;

		void initialize( );
	};
	inline const auto g_externals = std::make_unique<impl>( );
}