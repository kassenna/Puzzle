#pragma once
#pragma once
#include "Alle.h"
#include "Puzzel.h"

class Puzzel41 : public Puzzel {

public:

	Puzzel41(float x, float y);
	Puzzel41() {};
	Puzzel41(const Puzzel41 & puzzel);
	~Puzzel41() {};

	void draw();
	bool isclick(Mouse_k mstate_current);
	void MoveFalse();
	void set_structur();
	
	Puzzel41& operator=(const Puzzel & puzzel);

};

