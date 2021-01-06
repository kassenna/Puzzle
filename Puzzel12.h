#pragma once
#include "Alle.h"
#include "Puzzel.h"

class Puzzel12 : public Puzzel {
	
public:
	Puzzel12(float x, float y);
	Puzzel12() {};
	Puzzel12(const Puzzel12 & puzzel);
	Puzzel12(Puzzel12 && puzzel) : Puzzel(std::move(puzzel)) {};
	~Puzzel12() {};

	void draw();
	bool isclick(Mouse_k mstate_current);
	void MoveFalse();
	void set_structur();
	
	
	Puzzel12& operator=(const Puzzel & puzzel);
};
