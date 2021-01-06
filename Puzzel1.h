#pragma once
#include "Alle.h"
//#include "structs.h"
#include "Puzzel.h"

class Puzzel1 : public Puzzel{
public:
	Puzzel1(float x, float y);
	Puzzel1() {};
	Puzzel1(const Puzzel1 & puzzel);
	Puzzel1(Puzzel1 && puzzel) : Puzzel(std::move(puzzel)) {};
	~Puzzel1() { };
	
	void draw();
	bool isclick(Mouse_k mstate_current);
	void MoveFalse();
	void set_structur();

	
	Puzzel1& operator=(const Puzzel & puzzel);
};
