#pragma once
#include <allegro5\allegro.h>
#include "structs.h"
#include <bitset>
#include <iostream>
class Puzzel
{
protected:
	std::bitset<64> structur; // shape of puzzel
	Puzzel_size P_size; // numbers puzzel isn't above board
public:
	bool isMove = false;
	Puzzelxy xy; // coordination of puzzel 
	
	Puzzel();
	Puzzel(float x, float y);
	Puzzel(const Puzzel & puzzel);
	
	~Puzzel() {};

	Puzzel_size getSize();
	virtual void draw(); 
	virtual void MoveFalse() { }; //lock the puzzel a
	virtual bool isclick(Mouse_k mstate_current) { return isclick(mstate_current); }; // check puzzel is chosen
	virtual void set_structur() { };
	std::bitset<64> GetStructur() { return structur; };
	bool getIsMove() { return isMove; };
	void setXY(float x, float y);
	Puzzel& operator=(const Puzzel & puzzel);
};