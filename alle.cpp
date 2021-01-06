#pragma once

#include "Alle.h"
#include "board.h"
#include "Puzzel.h"
#include "buttons.h"
Alle::Alle() {};

bool Alle::allinit() {
	if (!al_init())
	{
		fprintf(stderr, "Failed to initialize allegro!\n");
		return 0;
	}
	al_init_primitives_addon();
	queue = al_create_event_queue();
	al_init_font_addon();
	al_init_ttf_addon();
	if (queue == NULL)
	{
		fprintf(stderr, "Failed to create event queue!\n");
		return 0;
	}
	display = al_create_display(W, H);
	al_install_mouse();
	al_clear_to_color(al_map_rgb(45, 90, 23)); //create background
	al_flip_display(); // refresh screen
	return 1;
};
int Alle::action_and_chosen()
{
	
	al_register_event_source(queue, al_get_display_event_source(display)); //add screen to event
	al_register_event_source(queue, al_get_mouse_event_source()); // add  mouse to event
	bool chosen = false;
	al_clear_to_color(al_map_rgb(45, 90, 23)); // 
	Button Menu(800, 50, 801, 51, "MENU", 200, 200, 0);
	Menu.draw();
	Button b1(800, 100, "TRYB 1");
	Button b2(800, 200, "TRYB 2");
	Button b3(800, 500, "WYJSCIE");
	b1.draw();
	b2.draw();
	b3.draw();
	al_flip_display();
			
	while (!al_key_down(&keyboard, ALLEGRO_KEY_ESCAPE ) && chosen == false)
	{
		al_get_mouse_state(&mstate);
		SetMState();
		if(mstate.buttons & 1)
			 if (b1.button_down(mstate_current)) return 1;
		else if (b2.button_down(mstate_current)) return 2;
		else if (b3.button_down(mstate_current)) return 0;
		if (ev1.type == ALLEGRO_EVENT_DISPLAY_CLOSE)	return 0;
		al_wait_for_event(queue, &ev1);
	}
	return 0;
}
bool Alle::action_mode1()
{

	al_clear_to_color(al_map_rgb(45, 90, 23));
	Add(0);	Add(1);	Add(2); //add puzzle to screen 
	Board board; 
	board.draw(); 
	Button Be(100, 800, 1050, 850, "wyjscie", 200, 200, 20);
	Be.draw();
	al_flip_display();
	while (!al_key_down(&keyboard, ALLEGRO_KEY_ESCAPE))
	{
		if (ev1.type == ALLEGRO_EVENT_DISPLAY_CLOSE)	return  true;
		al_wait_for_event(queue, &ev1);
		al_get_mouse_state(&mstate);
		if (mstate.buttons & 1)
		{
			SetMState();
			if (puzzelCurrent[0]->isclick(mstate_current))
			{
				puzzelCurrent[1]->MoveFalse();
				puzzelCurrent[2]->MoveFalse();
				//lock puzzle when you chose other
				al_flip_display();

			}
			else if (puzzelCurrent[1]->isclick(mstate_current))
			{
				puzzelCurrent[0]->MoveFalse();
				puzzelCurrent[2]->MoveFalse();
				al_flip_display();

			}
			else if (puzzelCurrent[2]->isclick(mstate_current))
			{
				puzzelCurrent[1]->MoveFalse();
				puzzelCurrent[0]->MoveFalse();
				al_flip_display();
			}
			if (board.check(mstate_current, puzzelCurrent[0])) 				Add(0); 
			else if (board.check(mstate_current, puzzelCurrent[1]))			Add(1);
			else if (board.check(mstate_current, puzzelCurrent[2]))			Add(2);
			al_flip_display();
			if (Be.button_down(mstate_current))				return false; // button exit 
		}
	}
	return false;
};

bool Alle::action_mode2()
{
	int temp = 0;
	al_clear_to_color(al_map_rgb(45, 90, 23));
	Board board;		board.draw();
	Button Exit(100, 800, "wyjscie");		Exit.draw();
	al_flip_display();
	while (!al_key_down(&keyboard, ALLEGRO_KEY_ESCAPE))
	{
	if (ev1.type == ALLEGRO_EVENT_DISPLAY_CLOSE)		return true; //button X (close) in window
	if (temp == 0){ Add(0);	Add(1);	Add(2);	temp = 3;}
		al_get_mouse_state(&mstate);
		if (mstate.buttons & 1)
		{
			SetMState();
			if (Exit.button_down(mstate_current))	return false;
			if (puzzelCurrent[0]->isclick(mstate_current))
			{
				puzzelCurrent[1]->MoveFalse();
				puzzelCurrent[2]->MoveFalse();
				al_rest(0.1);
				al_flip_display();
			}
			if (puzzelCurrent[1]->isclick(mstate_current))
			{
				puzzelCurrent[0]->MoveFalse();
				puzzelCurrent[2]->MoveFalse();
				al_rest(0.1);
				al_flip_display();
			}
			if (puzzelCurrent[2]->isclick(mstate_current))
			{
				puzzelCurrent[1]->MoveFalse();
				puzzelCurrent[0]->MoveFalse();
				al_rest(0.1);
			al_flip_display();
			}
				if (board.check(mstate_current, puzzelCurrent[0]))
				{
					al_draw_filled_rectangle(898, 9, 1262, 372, al_map_rgb(45, 90, 23)); //clear place when puzzel was
					puzzelCurrent[0]->MoveFalse();
					puzzelCurrent[0] = PuzzelTab[0];									// *puzzelTab[0] ->puzzel without parametres
					temp--;																// decrement number of avaiable puzzel
				}
				if (board.check(mstate_current, puzzelCurrent[1]))
				{
					al_draw_filled_rectangle(1498, 298, 2162, 662, al_map_rgb(45, 90, 23));
					puzzelCurrent[1]->MoveFalse();
					puzzelCurrent[1] = PuzzelTab[0];
					temp--; 
				}
				if (board.check(mstate_current, puzzelCurrent[2]))
				{
					al_draw_filled_rectangle(898, 598, 1262, 962, al_map_rgb(45, 90, 23));
					puzzelCurrent[2]->MoveFalse();
					puzzelCurrent[2] = PuzzelTab[0];
					temp--;
				}
			al_wait_for_event(queue, &ev1);
		}
	}
};

bool Alle::aluinit()
{
	al_destroy_display(display);
	al_destroy_event_queue(queue);
	return 1;
};
void Alle::SetMState()
{
	mstate_current.x = mstate.x;
	mstate_current.y = mstate.y;
	al_rest(0.1);
};
void Alle::PuzzelAdd( Puzzel & puzzel)
{
	PuzzelTab[nmbr] = &puzzel;
	nmbr++;
}; 


void Alle::Add(int i)
{
	int nmbr;
	bool repeted = false;
	do{
		repeted = false;
		nmbr = rand() %( NUMBER -1)+1;
		for (int j = 0; j < 3; j++)
		{
			if (tab[j] == nmbr) repeted = true;
		}
	} while (repeted == true);
	puzzelCurrent[i] = PuzzelTab[nmbr];
	tab[i] = nmbr;
	switch (i)
	{
	case 0:
	{
		al_draw_filled_rectangle(898, 8, 1262, 412, al_map_rgb(45, 90, 23));
		puzzelCurrent[i]->setXY(900, 10);
		break;
	}
	case 1:
	{
		al_draw_filled_rectangle(1498, 298, 1862, 902, al_map_rgb(45, 90, 23));
		puzzelCurrent[i]->setXY(1500, 300);
		break;
	}
	case 2:
	{
		al_draw_filled_rectangle(898, 598, 1262, 1002, al_map_rgb(45, 90, 23));
		puzzelCurrent[i]->setXY(900, 600);
		break;
	}
	default:
		break;
	}
	al_flip_display();
	puzzelCurrent[i]->draw();
	al_flip_display();
	puzzelCurrent[i]->MoveFalse();
};
