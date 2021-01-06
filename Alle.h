#pragma once
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>
#include "Puzzel.h"
#include "structs.h"
#define NUMBER 8 //number of object "puzzle"
#define W 1900 //width of screen
#define H 1000 //height of screen
class Alle {
	
	ALLEGRO_DISPLAY * display = NULL; 
	ALLEGRO_EVENT_QUEUE * queue = NULL;
	ALLEGRO_MOUSE_STATE mstate; // date of mouse
	ALLEGRO_EVENT ev1 ;
	ALLEGRO_KEYBOARD_STATE keyboard;
public:
	Alle();
	Puzzel* puzzelCurrent[3]; // array of puzzle uses in game
	Puzzel* PuzzelTab[NUMBER]; // array of all puzzle
	Mouse_k mstate_current; // struct coordinate x, y

	int nmbr = 0;
	char tab[3];
	
	void PuzzelAdd( Puzzel & puzzel);
	void Add(int i);
	void SetMState(); // copy mouse's coordinate
	bool allinit(); // init screen and other graphic function
	bool action_mode1();
	bool action_mode2();
	int action_and_chosen(); // 
	bool aluinit();
};

