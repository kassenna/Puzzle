#pragma once
#include "buttons.h"
	Button::Button(int x, int y) : x(x), y(y)
	{
		font = al_load_font("print_bold_tt.ttf", 48, 0);
		xe = x + 100;
		ye = y + 100;
	};
	Button::Button(int x, int y, const char * text) : x(x), y(y), text(text) {
		xe = x + 100;
		ye = y + 100;
		font = al_load_font("print_bold_tt.ttf", 48, 0);
	}
	Button::Button(int x, int y, int xe, int ye, const char* text, unsigned char R, unsigned char G, unsigned char B)
		: x(x), y(y), xe(xe), ye(ye), text(text) {
		color.R = R;
		color.G = G;
		color.B = B;
		font = al_load_font("print_bold_tt.ttf", 48, 0);
	};
	Button::Button(Button & b) {
		x = b.x;
		y = b.y;
		xe = b.xe;
		ye = b.ye;
	};
	bool Button::button_down(Mouse_k mouse)
	{
		if (mouse.x > x && mouse.x <xe && mouse.y >y && mouse.y < ye)
			return true;
		return false;
	}
	void Button::draw()
	{
		al_draw_text(font, al_map_rgb(color.R, color.G, color.B), x, y, 0, text);
		text = nullptr;
		al_destroy_font(font);
	};



