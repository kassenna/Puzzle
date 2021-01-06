#pragma once
//#include "Alle.h"
#include "structs.h"
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
class Button
{
	int x, y;
	int xe, ye;
	char button_click = 0;
	ALLEGRO_FONT * font;
	const char* text = nullptr;
	Color color;
public:
	Button(int, int);
	Button(int, int, const char *);
	Button(int, int, int, int, const char*, unsigned char, unsigned char, unsigned char);
	Button(Button & b);
	
	bool button_down(Mouse_k mouse); 
	void draw();
};



