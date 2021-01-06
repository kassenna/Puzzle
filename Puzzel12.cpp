#pragma once
#include "puzzel12.h"

Puzzel12::Puzzel12(float x, float y)
{
	xy.x = x;
	xy.y = y;
	set_structur();
	P_size.h = 8;
	P_size.w = 7;
};
Puzzel12::Puzzel12(const Puzzel12 &puzzel) : Puzzel(puzzel) {};
void Puzzel12::draw()
{
	al_draw_filled_rectangle(xy.x, xy.y, xy.x + 90, xy.y + 180, al_map_rgb(0, 0, 0));
	al_flip_display();
};
bool Puzzel12::isclick(Mouse_k mstate_current)
{
	if ((mstate_current.x - (int)xy.x) < 95 &&
		(mstate_current.x - (int)xy.x) > -5 &&
		(mstate_current.y - (int)xy.y) < 185 &&
		(mstate_current.y - (int)xy.y) > -5)
	{
		if (isMove == false)
		{
			isMove = true;
			al_draw_rectangle(xy.x, xy.y, xy.x + 90, xy.y + 180, al_map_rgb(0, 200, 0), 3);
			al_flip_display();
			return true;
		}
		MoveFalse();
	}
	return false;
};
void Puzzel12::MoveFalse() {
	isMove = false;
	al_draw_rectangle(xy.x, xy.y, xy.x + 90, xy.y + 180, al_map_rgb(0, 0, 0), 3);
	al_flip_display();
};
void Puzzel12::set_structur()
{
	structur.set(63, 1);
	structur.set(55, 1);
}

Puzzel12& Puzzel12::operator=(const Puzzel & puzzel)
{
	Puzzel::operator=(puzzel);

	return *this;
}