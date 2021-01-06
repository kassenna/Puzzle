#pragma once
#include "Alle.h"
#include "Puzzel.h"

class Puzzel22 : public Puzzel {

public:

	Puzzel22(float x, float y);
	Puzzel22() {};
	Puzzel22(const Puzzel22 & puzzel);
	Puzzel22(Puzzel22 && puzzel) : Puzzel(std::move(puzzel)) {};
	~Puzzel22() {  };

	void draw();
	bool isclick(Mouse_k mstate_current);
	void MoveFalse();
	void set_structur();
	
	Puzzel22& operator=(const Puzzel & puzzel);

};

