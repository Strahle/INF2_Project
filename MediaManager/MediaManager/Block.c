#include "Block.h"

#include <stdio.h>

Node * List;

void init (void)
{
	initList(); //Darf keinen R�ckgabewert mehr haben
	initFileEdit();
}

//Gibt bei Fehler 0 zur�ck
char Media (void)
{
	//Media Men� aufrufen
	if (MediaMenue() == 1)
		{
			return 1;
		}
	switch (askInput())
	{
	case 0: return 1;
	break;
	case 1: setFilePath ("Buecher.txt");
	break;
	case 2: setFilePath ("CD.txt.");
	break;
	case 3: setFilePath ("DVD.txt.");
	break;
	case 'e': exit;
	}
}

//Gibt bei Fehler 0 zur�ck
char Liste (void)
{
	//Listen Men� aufrufen
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

//Gibt bei Fehler 0 zur�ck
char add (void)
{
	Details * Detail;
	Node * Datensatz;

	//Abfrage der Parameter
	if ((Detail = addItemInput()) == NULL) //Kein �bergabeparameter
		{
			return 0;
		}
	//Datensetz in Liste einf�gen
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

//Gibt bei Fehler 0 zur�ck
char savelist (void)
{
	Node * Datensatz;
	Datensatz = getAnkerAnfang(List); //Warum Parameter�bergabe?
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
	while (addItem(loadFromFile()) != NULL)
	{
	}
}

char gotoxy(int xpos, int ypos)
{
    COORD scrn;    
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
	return -1;
} 