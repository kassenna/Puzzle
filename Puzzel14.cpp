#pragma once
#include "puzzel14.h"


Puzzel14::Puzzel14(float x, float y)
{
	xy.x = x;
	xy.y = y;
	set_structur();
	P_size.h = 8;
	P_size.w = 5;
};
Puzzel14::Puzzel14(const Puzzel14 &puzzel) : Puzzel(puzzel) {};
void Puzzel14::draw()
{
	al_draw_filled_rectangle(xy.x, xy.y, xy.x + 90, xy.y + 360, al_map_rgb(0, 0, 0));
	al_flip_display();
};
bool  Puzzel14::isclick(Mouse_k mstate_current)
{
	if ((mstate_current.x - (int)xy.x) < 95 &&
		(mstate_current.x - (int)xy.x) > -5 &&
		(mstate_current.y - (int)xy.y) < 365 &&
		(mstate_current.y - (int)xy.y) > -5)
	{
		if (isMove == false)
		{
			isMove = true;
			al_draw_rectangle(xy.x, xy.y, xy.x + 90, xy.y + 360, al_map_rgb(0, 200, 0), 3);
		al_flip_display();
		return true;
		}
		MoveFalse();
	}
	return false;

};
void Puzzel14::MoveFalse() {
	isMove = false;
	al_draw_rectangle(xy.x, xy.y, xy.x + 90, xy.y + 360, al_map_rgb(0, 0, 0), 3);
	al_flip_display();
};
void Puzzel14::set_structur()
{
	structur.set(63, 1);
	structur.set(55, 1);
	structur.set(47, 1);
	structur.set(39, 1);


}
Puzzel14& Puzzel14::operator=(const Puzzel & puzzel)
{
	Puzzel::operator=(puzzel);

	return *this;
}