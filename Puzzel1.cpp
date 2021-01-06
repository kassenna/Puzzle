#pragma once
#include "puzzel1.h"


Puzzel1::Puzzel1( float x, float y)
{
	xy.x = x;
	xy.y = y;
	set_structur();
	P_size.h =	8;
	P_size.w = 8;
};
Puzzel1::Puzzel1(const Puzzel1 &puzzel) : Puzzel(puzzel) {};
void Puzzel1::draw()
{	
	al_draw_filled_rectangle(xy.x, xy.y, xy.x + 90, xy.y + 90, al_map_rgb(0, 0, 0));
	al_flip_display();
};
bool Puzzel1::isclick(Mouse_k mstate_current)
{
	if ((mstate_current.x - (int)xy.x) < 95 &&
		(mstate_current.x - (int)xy.x) > -5 &&
		(mstate_current.y - (int)xy.y) < 95 &&
		(mstate_current.y - (int)xy.y) > -5) //check coordinate is in puzzel
	{
		if (isMove == false)
		{
			isMove = true;
			al_draw_rectangle(xy.x, xy.y, xy.x + 90, xy.y + 90, al_map_rgb(0, 200, 0), 3); //draw green no-fully square (can move)
			al_flip_display();
			return true;
		}
		MoveFalse();
	}	
	return false;
};
void Puzzel1::MoveFalse() {
	isMove = false;
	al_draw_rectangle(xy.x, xy.y, xy.x + 90, xy.y + 90, al_map_rgb(0, 0, 0), 3); //draw black rectangle (can't move)
	al_flip_display();
};
void Puzzel1::set_structur()
{
	structur.set(63, 1);
}

Puzzel1& Puzzel1::operator=(const Puzzel & puzzel)
{
	Puzzel::operator=(puzzel);

	return *this;
}