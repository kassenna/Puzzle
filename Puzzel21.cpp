#pragma once
#include "puzzel21.h"


Puzzel21::Puzzel21(float x, float y)
{
	xy.x = x;
	xy.y = y;
	set_structur();
	P_size.h = 7;
	P_size.w = 8;
};
Puzzel21::Puzzel21(const Puzzel21 &puzzel) : Puzzel(puzzel) {};
void Puzzel21::draw()
{
	al_draw_filled_rectangle(xy.x, xy.y, xy.x + 180, xy.y+90, al_map_rgb(0, 0, 0));
	al_flip_display();
};
bool Puzzel21::isclick(Mouse_k mstate_current)
{
	if ((mstate_current.x - (int)xy.x) < 185 &&
		(mstate_current.x - (int)xy.x) > -5 &&
		(mstate_current.y - (int)xy.y) < 95 &&
		(mstate_current.y - (int)xy.y) > -5)
	{
		if (isMove == false)
		{
			isMove = true;
			al_draw_rectangle(xy.x, xy.y, xy.x + 180, xy.y + 90, al_map_rgb(0, 200, 0), 3);
		al_flip_display();
		return true;
		}
		MoveFalse();
	}
	return false;
};
void Puzzel21::MoveFalse() {
	isMove = false;
	al_draw_rectangle(xy.x, xy.y, xy.x + 180, xy.y + 90, al_map_rgb(0, 0, 0), 3);
	al_flip_display();
};
void Puzzel21::set_structur()
{
	structur.set(63, 1);
	structur.set(62, 1);
}
Puzzel21& Puzzel21::operator=(const Puzzel & puzzel)
{
	Puzzel::operator=(puzzel);

	return *this;
}