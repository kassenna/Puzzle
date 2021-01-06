#pragma once
#include "Alle.h"
#include "Puzzel.h"

class Puzzel22dr : public Puzzel {
public:

	Puzzel22dr(float x, float y);
	Puzzel22dr() {};
	Puzzel22dr(const Puzzel22dr & puzzel);
	Puzzel22dr(Puzzel22dr && puzzel) : Puzzel(std::move(puzzel)) {};
	~Puzzel22dr() { };

	void draw();
	bool isclick(Mouse_k mstate);
	void MoveFalse();
	void set_structur();
	
	Puzzel22dr& operator=(const Puzzel & puzzel);
};

