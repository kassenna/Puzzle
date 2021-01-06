#include "puzzel.h"
#include "Alle.h"
Puzzel::Puzzel() {};
Puzzel::Puzzel(float x, float y) {
	xy.x = x;
	xy.y = y;
};
Puzzel::Puzzel(const Puzzel & puzzel) {
	structur = puzzel.structur;
	P_size.h = puzzel.P_size.h;
	P_size.w = puzzel.P_size.w;
	xy.x = puzzel.xy.x;
	xy.y = puzzel.xy.y;
	isMove = false;

};
Puzzel& Puzzel::operator=(const Puzzel & puzzel)
{
	isMove = puzzel.isMove;
	xy.x = puzzel.xy.x;
	xy.y = puzzel.xy.y;
	structur = puzzel.structur;
	P_size.h = puzzel.P_size.h;
	P_size.w = puzzel.P_size.w;

	return *this;
};
void Puzzel::setXY(float x, float y) {
	xy.x = x;
	xy.y = y;

};
void Puzzel::draw() { al_draw_filled_rectangle(1000, 100, 1300, 120, al_map_rgb(200, 150, 120)); al_flip_display(); };
Puzzel_size Puzzel::getSize() 
{
	return P_size;
};