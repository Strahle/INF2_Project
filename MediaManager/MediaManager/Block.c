#include "Block.h"

#include <stdio.h>


Node * List; //Knoten f�r die aktuelle Position der Liste (Erstes Element auf der Seite)

void init (void)
{
	initList(); //Darf keinen R�ckgabewert mehr haben
	initFileEdit();
}

//Gibt bei Fehler 0 zur�ck
char Media (void)
{
	//Bildschirm l�schen
	clrscreen();

	//Media Men� aufrufen
	if (MediaMenue() == 0)
	{
		return 0;
	}
}

//Gibt bei Fehler 0 zur�ck
char Liste (void)
{
	//Bildschirm l�schen
	clrscreen();

	//Listen Men� aufrufen
	if (ListMenue() == 0)
	{
		return 0;
	}
	
	if (List -> next && List -> prev != NULL)
	{
		Footer(0);
	}
	else if (List -> next != NULL)
	{
		Footer(3);
	}
	else if (List -> prev != NULL)
	{
		Footer(1);
	}

	//Liste aufrufen
	showList(List);
}

char details (void)
{
	//Bildschirm l�schen
	clrscreen();

	//Detail Men� Anzeigen
	showDetailMenue();

	//Details des Elements Anzeigen
	showDetail(List -> nodeDetails, cMedia);

	return -1;
}

char selectElement (void)
{
	//Index abfragen und in der Liste nach dem Datensatz suchen
	List = searchForIndex (List, askIndex());
}

int askInput (void)
{
	int Input = 0;
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
	Details * Detail; //Pointer zur �bergabe der Details

	//Bildschirm l�schen
	clrscreen();

	//Abfrage der Parameter
	if ((Detail = addItemInput(cMedia)) == NULL)
	{
		return 0;
	}

	//Datensetz in Liste einf�gen
	if ((List = addItem(Detail)) == NULL)
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
	int Index; //Speichervariable f�r den Index
	char changeselect; //Speichervariable f�r den Parameter welche Eigenschaft ge�ndert werden soll

	//Index f�r das zu �ndernde Element abfragen
	Index = askIndex();

	//Bildschirm l�schen
	clrscreen();

	//Auswahl der zu �ndernden Parameter anzeigen
	ChangeMenue();

	//Eingabeposition
	gotoxy(0,21);

	//Parameter abfragen der ge�ndert werden soll
	if ((changeselect = askInput()) == 'e')
	{
		exit;
	}
	
	//Element �ndern
	List = changeItemDetails(List,cMedia,changeselect,Index);

	//Speichert die aktuallisierte Liste in der Datei
	if (savelist() == 0)
	{
		return 0;
	}
}

char del (void)
{
	Node * Datensatz;

	//Bildschirm l�schen
	clrscreen();

	//Abfrage der Parameter
	if ((Datensatz = deleteItemInput(List,cMedia)) == NULL)
	{
		return 0;
	}

	//Knoten auf das n�chste oder vorige Element setzen
	if ((List = Datensatz -> next) == NULL)
	{
		List = Datensatz -> prev;
	}

	//Datensetz aus Liste l�schen
	deleteItem(Datensatz);

	//Speichert die aktuallisierte Liste in der Datei
	if (savelist() == 0)
	{
		return 0;
	}
}

char sort (void)
{

}

//Gibt bei Fehler 0 zur�ck
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

	return -1;
}

char loadlist (void)
{
	Details * Detail;
	initFileEdit();
	while (1)
	{
		Detail = loadFromFile();
		if (Detail == NULL)
		{
			break;
		}
		List = addItem(Detail);
	}

	List = getAnkerAnfang(List);

	return -1;
}

char clrscreen(char Line, char space)
{
	clrRange(3,30);
	gotoxy(0,0);
	return -1;
}

void vorBlaettern (void)
{
	char i;
	for (i = 0; i < 10; i++)
	{
		if (List -> next == NULL)
		{
			zurueckBlaettern();
			return;
		}
		List = List -> next;
	}
}

void zurueckBlaettern (void)
{
	char i;
	for (i = 0; i < 10; i++)
	{
		if (List -> prev == NULL)
		{
			return;
		}
		List = List -> prev;
	}
}

void printError (char * Error)
{
	setColor(1,12);
	gotoxy (10,10);
	printf ("%s", Error);
	gotoxy (10,11);
}