#pragma once
#include "Alle.h"
#include "Puzzel.h"

class Puzzel21 : public Puzzel {

public:
	
	Puzzel21(float x, float y);
	Puzzel21() {};
	Puzzel21(const Puzzel21 & puzzel);
	Puzzel21(Puzzel21 && puzzel) : Puzzel(std::move(puzzel)) {};
	~Puzzel21() {  };

	void draw();
	bool isclick(Mouse_k mstate_current);
	void MoveFalse();
	void set_structur();
	std::bitset<64> GetStructur();
	bool getIsMove();
	Puzzel21& operator=(const Puzzel & puzzel);

};

