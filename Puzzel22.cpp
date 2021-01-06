#pragma once
#include "puzzel22.h"


Puzzel22::Puzzel22(float x, float y)
{
	xy.x = x;
	xy.y = y;
	set_structur();
	P_size.h = 7;
	P_size.w = 7;
};
Puzzel22::Puzzel22(const Puzzel22 &puzzel) : Puzzel(puzzel) {};
void Puzzel22::draw()
{
	al_draw_filled_rectangle(xy.x, xy.y, xy.x + 180, xy.y + 180, al_map_rgb(0, 0, 0));
	al_flip_display();
};
bool Puzzel22::isclick(Mouse_k mstate_current)
{
	if ((mstate_current.x - (int)xy.x) < 185 &&
		(mstate_current.x - (int)xy.x) > -5 &&
		(mstate_current.y - (int)xy.y) < 185 &&
		(mstate_current.y - (int)xy.y) > -5)
	{
		if (isMove == false)
		{
			isMove = true;
			al_draw_rectangle(xy.x, xy.y, xy.x + 180, xy.y + 180, al_map_rgb(0, 200, 0), 3);
			al_flip_display();
			return true;
		}
		MoveFalse();
	}
		return false;
};
void Puzzel22::MoveFalse() {
	isMove = false;
	al_draw_rectangle(xy.x, xy.y, xy.x + 180, xy.y + 180, al_map_rgb(0, 0, 0), 3);
	al_flip_display();
};
void Puzzel22::set_structur()
{
	structur.set(63, 1);
	structur.set(55, 1);
	structur.set(62, 1);
	structur.set(54, 1);

}

Puzzel22& Puzzel22::operator=(const Puzzel & puzzel)
{
	Puzzel::operator=(puzzel);

	return *this;
}