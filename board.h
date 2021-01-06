#include "Alle.h"
#include "structs.h"
#include <bitset>
#define S 8
#define S2 64
class Board { 

public:
		
	std::bitset<S2> tab; // contain structur array
	std::bitset<8> column; // contain information about column which will destroyed
	std::bitset<8> row;
	int x = 50; 
	int y = 50; // begining drawing
	Board() { tab.reset(); }; //
	void draw(); 
	void column0(); //reset column after destroyed
	void row0();
	void check_to_destroy(); //check if column/row is full
	void destroy(); 
	bool check(Mouse_k mstate, Puzzel *puzzel); //check if may lay puzzle; if YES do it
	
};

