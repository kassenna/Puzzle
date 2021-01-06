#pragma once
#pragma once
#include "Alle.h"
//#include "structs.h"
#include "Puzzel.h"

class Puzzel0 : public Puzzel {
public:
	Puzzel0(float x, float y) { x = x; y = y; };
	Puzzel0() {};
	
	Puzzel0(Puzzel0 && puzzel) : Puzzel(std::move(puzzel)) {};
	~Puzzel0() { };

	void draw() {};
	bool isclick(Mouse_k mstate_current) { return false; };
	void MoveFalse() {};
	void set_structur() {};
	

	Puzzel0& operator=(const Puzzel & puzzel) {};
};
