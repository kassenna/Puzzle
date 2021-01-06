#include <stdio.h>
#include <allegro5/allegro.h>
#include "Puzzel.h"
#include "Puzzel0.h"
#include "Puzzel12.h"
#include "Puzzel14.h"
#include "Puzzel21.h"
#include "Puzzel22dr.h"
#include "Puzzel1.h"
#include "Puzzel22.h"
#include "Alle.h"
#include "Puzzel41.h"

int main(int argc, char * argv[])
{
srand(time(NULL));


Alle alleg;

if (alleg.allinit())
{
	
	Puzzel0 p0(10, 10);
	Puzzel1 p1(10, 10);
	Puzzel12 p12(10, 10);
	Puzzel14 p14(10, 10);
	Puzzel21 p21(10, 10);
	Puzzel22 p22(10, 10);
	Puzzel22dr p22dr(10, 10);
	Puzzel41 p41(10, 10);

	alleg.PuzzelAdd(p0);
	alleg.PuzzelAdd(p1);
	alleg.PuzzelAdd(p12);
	alleg.PuzzelAdd(p14);
	alleg.PuzzelAdd(p21);
	alleg.PuzzelAdd(p22);
	alleg.PuzzelAdd(p22dr);
	alleg.PuzzelAdd(p41);
	int chosen = 0;
	do {
		chosen = alleg.action_and_chosen();
		if (chosen == 1 && alleg.action_mode1())
			break;
		if (chosen == 2 && alleg.action_mode2())
			break;
	} while (chosen>0);
}
alleg.aluinit();

return 0;
}