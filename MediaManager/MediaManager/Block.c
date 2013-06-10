#include "Block.h"

#include <stdio.h>

Node * List;
char cMedia;

void init (void)
{
	initList(); //Darf keinen Rückgabewert mehr haben
	initFileEdit();
}

//Gibt bei Fehler 0 zurück
char Media (void)
{
	//Media Menü aufrufen
	if (MediaMenue() == 0)
	{
		return 0;
	}

	switch (askInput())
	{
	case 0: cMedia = 0;
			return 0;
	break;
	case 1: setFilePath ("Buecher.bin");
			cMedia = 'b';
	break;
	case 2: setFilePath ("CD.bin");
			cMedia = 2;
	break;
	case 3: setFilePath ("DVD.bin");
			cMedia = 3;
	break;
	case 'e': exit;
	}

	if (loadlist() == 0)
	{
		return 0;
	}

	clrscreen();
}

//Gibt bei Fehler 0 zurück
char Liste (void)
{
	//Listen Menü aufrufen
	if (ListMenue() == 0)
	{
		return 0;
	}
	
	//Liste aufrufen
	showList(List);

	switch (askInput())
	{
	case 0: return 0;
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
	case 7: if (0 == 0)
			{
				return 0;
			}
	break;
	case 88: 
		if (Media() == 0)
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

	clrscreen();

}

char details (void)
{

}

char askInput (void)
{
	int Input = 0;
	gotoxy(0,0);
	gotoxy(0,23);
	setColor(0,15);
	scanf_s("%i", &Input); fflush(stdin);
	return Input;
}

char search (void)
{

}

//Gibt bei Fehler 0 zurück
char add (void)
{
	Details * Detail;
	Node * Datensatz;

	//Abfrage der Parameter
	if ((Detail = addItemInput(cMedia)) == NULL)
	{
		return 0;
	}

	//Datensetz in Liste einfügen
	if ((Datensatz = addItem(Detail)) == NULL) //Return notwendig?
	{
		return 0;
	}

	//Speichert die aktuallisierte Liste in der Datei
	if (savelist() == 0)
	{
		return 0;
	}
}

char edit (void)
{
	Details * Detail;
	Node * Datensatz;

	//Abfrage der Parameter
	if ((Detail = addItemInput(cMedia)) == NULL)
	{
		return 0;
	}

	//Datensetz in Liste einfügen
	if ((Datensatz = addItem(Detail)) == NULL)
	{
		return 0;
	}

	//Speichert die aktuallisierte Liste in der Datei
	if (savelist() == 0)
	{
		return 0;
	}
}

char del (void)
{

}

char sort (void)
{

}

//Gibt bei Fehler 0 zurück
char savelist (void)
{
	Node * Datensatz;
	if (removeFile () == 0)
	{
		return 0;
	}

	Datensatz = getAnkerAnfang(List);
	while (Datensatz != NULL)
	{
		if (saveToFile (Datensatz -> nodeDetails ) == 0)
		{
			return 0;
		}
		Datensatz = Datensatz -> next;
	}
}

char loadlist (void)
{
	initFileEdit();
	while (addItem(loadFromFile()) != NULL)
	{
	}
}

char clrscreen(char Line, char space)
{
	int i;
	gotoxy(0,4);
	for (i = 1; i <= 25; i++)
	{
		printf("                                                                                ");
	}
	gotoxy(0,0);
	return -1;
}

void vorBlaettern (void)
{
	char i;
	for (i = 0; i < 10; i++)
	{
		List = List -> next;
	}
}

void zurueckBlaettern (void)
{
	char i;
	for (i = 0; i < 10; i++)
	{
		List = List -> prev;
	}
}