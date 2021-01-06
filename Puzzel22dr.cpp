#pragma once
#include "puzzel22dr.h"

Puzzel22dr::Puzzel22dr(float x, float y)
{
	xy.x = x;
	xy.y = y;
	set_structur();
	P_size.h = 6;
	P_size.w = 7;
};
Puzzel22dr::Puzzel22dr(const Puzzel22dr &puzzel) : Puzzel(puzzel) {};
void Puzzel22dr::draw()
{
	al_draw_filled_rectangle(xy.x, xy.y, xy.x + 180, xy.y + 90, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(xy.x+90, xy.y+90, xy.x + 270, xy.y + 180, al_map_rgb(0, 0, 0));
	al_flip_display();
};
bool Puzzel22dr::isclick(Mouse_k mstate_current)
{
	if ((mstate_current.x - (int)xy.x) < 305 &&
		(mstate_current.x - (int)xy.x) > -5 &&
		(mstate_current.y - (int)xy.y) < 205 &&
		(mstate_current.y - (int)xy.y) > -5)
	{
		if (isMove == false)
		{
			isMove = true;
			al_draw_line(xy.x, xy.y, xy.x + 180, xy.y, al_map_rgb(0, 200, 0), 3);
			al_draw_line(xy.x, xy.y + 90, xy.x + 90, xy.y + 90, al_map_rgb(0, 200, 0), 3);
			al_draw_line(xy.x + 180, xy.y + 90, xy.x + 270, xy.y + 90, al_map_rgb(0, 200, 0), 3);
			al_draw_line(xy.x + 90, xy.y + 180, xy.x + 270, xy.y + 180, al_map_rgb(0, 200, 0), 3);

			al_draw_line(xy.x, xy.y, xy.x, xy.y + 90, al_map_rgb(0, 200, 0), 3);
			al_draw_line(xy.x + 90, xy.y + 90, xy.x + 90, xy.y + 180, al_map_rgb(0, 200, 0), 3);
			al_draw_line(xy.x + 180, xy.y, xy.x + 180, xy.y + 90, al_map_rgb(0, 200, 0), 3);
			al_draw_line(xy.x + 270, xy.y + 90, xy.x + 270, xy.y + 180, al_map_rgb(0, 200, 0), 3);
		al_flip_display();
		return true;
		}
			MoveFalse();
	}
	return false;
};
void Puzzel22dr::MoveFalse() {
	isMove = false;
	al_draw_line(xy.x, xy.y, xy.x + 180, xy.y, al_map_rgb(0, 0, 0), 3);
	al_draw_line(xy.x, xy.y+90, xy.x + 90, xy.y+90, al_map_rgb(0, 0, 0), 3);
	al_draw_line(xy.x+180, xy.y+90, xy.x + 270, xy.y+90, al_map_rgb(0, 0, 0), 3);
	al_draw_line(xy.x+90, xy.y+180, xy.x + 270, xy.y+180, al_map_rgb(0, 0, 0), 3);

	al_draw_line(xy.x, xy.y, xy.x, xy.y+90, al_map_rgb(0, 0, 0), 3);
	al_draw_line(xy.x+90, xy.y+90, xy.x + 90, xy.y+180, al_map_rgb(0, 0, 0), 3);
	al_draw_line(xy.x+180, xy.y, xy.x + 180, xy.y+90, al_map_rgb(0, 0, 0), 3);
	al_draw_line(xy.x+270, xy.y+90, xy.x + 270, xy.y + 180, al_map_rgb(0, 0, 0), 3);
	al_flip_display();
};
void Puzzel22dr::set_structur()
{
	structur.set(63, 1);
	structur.set(62, 1);
	structur.set(54, 1);
	structur.set(53, 1);

}

Puzzel22dr& Puzzel22dr::operator=(const Puzzel & puzzel)
{
	Puzzel::operator=(puzzel);
	return *this;
}