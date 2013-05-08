#include <stdio.h>
#include "Ausgabe.h"
#include "Eingabe.h"
#include "FileEdit.h"
#include "Liste.h"
#include "Menue.h"


int main()
{
	char input;
	 input = ListMenue (MediaMenue ());
	 switch(input)
	 {
	 case '2':
			showDetailMenue ();
			break;
	 default:
		 break;
	 }


	//printf("Hall Git");

	//printf("Added another line");
	//printf("New line added");
	//printf("Hallo strahlemann");
	//printf("Strahles erste Gehversuche");

	getchar();
	return 1;
}