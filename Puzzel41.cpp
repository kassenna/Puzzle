#pragma once
#include "puzzel41.h"


Puzzel41::Puzzel41(float x, float y)
{
	xy.x = x;
	xy.y = y;
	set_structur();
	P_size.h = 5;
	P_size.w = 8;
};
Puzzel41::Puzzel41(const Puzzel41 &puzzel) : Puzzel(puzzel) {};
void Puzzel41::draw()
{
	al_draw_filled_rectangle(xy.x, xy.y, xy.x + 360, xy.y + 90, al_map_rgb(0, 0, 0));
	al_flip_display();
};
bool Puzzel41::isclick(Mouse_k mstate_current)
{
	if ((mstate_current.x - (int)xy.x) < 365 &&
		(mstate_current.x - (int)xy.x) > -5 &&
		(mstate_current.y - (int)xy.y) < 95 &&
		(mstate_current.y - (int)xy.y) > -5)
	{
		if (isMove == false)
		{
			isMove = true;
			al_draw_rectangle(xy.x, xy.y, xy.x + 360, xy.y + 90, al_map_rgb(0, 200, 0), 3);
		al_flip_display();
		return true;
		}
			MoveFalse();
	}
	return false;
};
void Puzzel41::MoveFalse() {
	isMove = false;
	al_draw_rectangle(xy.x, xy.y, xy.x + 360, xy.y + 90, al_map_rgb(0, 0, 0), 3);
	al_flip_display();
};
void Puzzel41::set_structur()
{
	structur.set(63, 1);
	structur.set(62, 1);
	structur.set(61, 1);
	structur.set(60, 1);
}
Puzzel41& Puzzel41::operator=(const Puzzel & puzzel)
{
	Puzzel::operator=(puzzel);
	return *this;
}