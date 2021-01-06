#pragma once
#include "Alle.h"
#include "Puzzel.h"

class Puzzel14 : public Puzzel {

public:
	
	Puzzel14(float x, float y);
	Puzzel14() {};
	Puzzel14(const Puzzel14 & puzzel);
	~Puzzel14() {};

	void draw();
	bool isclick(Mouse_k mstate_current);
	void MoveFalse();
	void set_structur();

	Puzzel14& operator=(const Puzzel & puzzel);

};

