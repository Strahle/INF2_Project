#include "Block.h"

#include <stdio.h>

Node * List;

void init (void)
{
	initList(); //Darf keinen Rückgabewert mehr haben
	//initFileEdit();
}

//Gibt bei Fehler 0 zurück
char Media (void)
{
	//Media Menü aufrufen
	if (MediaMenue() == 1)
		{
			return 1;
		}
	switch (askInput())
	{
	case 0: return 1;
	break;
	case 1:
	break;
	case 2:
	break;
	}
}

//Gbit bei Fehler 0 zurück
char Liste (void)
{
	//Listen Menü aufrufen
	if (ListMenue() == 1)
	{
		return 1;
	}
	
	//Liste aufrufen
	showList(List);

	switch (askInput())
	{
	case 0: return 1;
	break;
	case 1: if (search() == 0)
			{
				return 0;
			}
	break;
	case 2: if (details() == 0)
			{
				return 0;
			}
	break;
	case 3: if (add() == 0)
			{
				return 0;
			}
	break;
	case 4: if (edit() == 0)
			{
				return 0;
			}
	break;
	case 5: if (del() == 0)
			{
				return 0;
			}
	break;
	case 6: if (sort() == 0)
			{
				return 0;
			}
	break;
	case 7: if (back() == 0)
			{
				return 0;
			}
	break;
	case 99: if (Media() == 0)
			{
				return 0;
			}
	break;
	case 'e': exit;
	}
}

char details (void)
{

}

char askInput (void)
{
	char Input = 0;
	gotoxy(0,0);
	gotoxy(0,23);
	setColor(0,15);
	scanf_s("%i", &Input); fflush(stdin);
	return Input;
}

char search (void)
{

}

char add (void)
{

}

char edit (void)
{

}

char del (void)
{

}

char sort (void)
{

}

char back (void)
{

}