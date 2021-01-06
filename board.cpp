
#include "board.h"
#define SIZE 90 //size of small rectangle 
void Board::draw() {
	float x_current = (float)x;
	float y_current = (float)y;
	std::bitset<S2> temp(std::string("1000000000000000000000000000000000000000000000000000000000000000")); //table to check to draw
	std::bitset<S2> temp_tab;
	for (int i = 0; i < S; i++)
	{
		x_current = (float)x;
		for (int j = 0; j < S; j++)
		{
			temp_tab = tab;			
			if ((temp_tab&=temp) == temp)
				al_draw_filled_rectangle(x_current, y_current, x_current + SIZE, y_current + SIZE, al_map_rgb(250, 250, 250)); //draw empty rectangle
			else
				al_draw_filled_rectangle(x_current, y_current, x_current + SIZE, y_current +SIZE, al_map_rgb(20, 170, 20)); //draw fully rectangle
			al_draw_rectangle(x_current, y_current, x_current + SIZE, y_current + SIZE, al_map_rgb(255, 255, 255), 3); //draw no-fully rectangle
			x_current += SIZE;
			temp= temp >>= 1;	
		}
		y_current += SIZE;
	}
};

void Board::column0()
{
	column.reset();
};
void Board::row0() {
	row.reset();
};
void Board::check_to_destroy()
{
	std::bitset<S2> temp_row(std::string   ("1111111100000000000000000000000000000000000000000000000000000000"));
	std::bitset<S2> temp_column(std::string("1000000010000000100000001000000010000000100000001000000010000000"));
	std::bitset<S2> temp;					 
	for (int i = 0; i < S; i++)
	{
		temp = tab;
		if ((temp &= temp_row) == temp_row)
			row.set(S - i - 1, 1); //set number of row to destroyed
		temp = tab;
		if ((temp &= temp_column) == temp_column) //check if column is full
			column.set(S - 1 - i, 1); // set number of column to  destroyed
		temp_row >>= 8; // move to next row
		temp_column  >>= 1; // move to next column
	}
};

void Board::destroy() {
	   std::bitset<S2> temp_column(std::string("1000000010000000100000001000000010000000100000001000000010000000")); //table to destroy column
	   std::bitset<S2>    temp_row(std::string("1111111100000000000000000000000000000000000000000000000000000000"));
	   std::bitset<S> tempIf(std::string("10000000")); //table to check to destroy
	   std::bitset<S> temp;
	  
	for (int i = 0; i < S; i++)
	{	
		temp = tempIf;
		if (tempIf==(temp &= row)) //check 
			tab = tab &= (~temp_row); //destroy
		temp = tempIf;
		if (tempIf == (temp &= column)) //check 
			tab = tab &= (~temp_column); //destroy
		tempIf >>= 1;				//move to next checking
		temp_colum >>= 1;	//move to next column
		temp_row >>= 8;			//move to next row
	}
			row0();	column0(); //clear information about fully column/row
};
bool Board::check(Mouse_k mstate, Puzzel *puzzel)
{
		if (puzzel->getIsMove()  && mstate.x > x && mstate.y > y && mstate.x < x + 720 && mstate.y < y + 720) //check coordinate in place board
	{
		std::bitset<S2> zero;
		zero.reset();
		int i = (mstate.x - x) / SIZE; //the number of column to lay 
		int j = (mstate.y - y) / SIZE;	//number of row
			if (i < puzzel->getSize().h && j< puzzel->getSize().w) //check if puzzel is not above 
			{
				std::bitset<S2> temp = puzzel->GetStructur(); 
				temp >>= (8 * j + i); // set puzzel on board
				if (zero==(temp&=tab)) //overlap?
				{	
					temp = puzzel->GetStructur();
					temp >>= (8 * j + i);
					tab |= temp;		//lay
					puzzel->MoveFalse(); //lock
					check_to_destroy();	
					destroy();
					draw();	//refresh board
					al_flip_display();				
					return true;
				}
			}
		}
	return false;
};
