#include "Block.h"

#include <stdio.h>


Node * List; //Knoten f�r die aktuelle Position der Liste (Erstes Element auf der Seite)

void init (void)
{
	List = initList(); //Initialisiert eine neue Liste
	initFileEdit(); //Reinitialisiert FileEdit
}

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

char Liste (void)
{
	//Pointer f�r die Abfrage Vor/Zur�ck
	Node * Listvor;
	//Z�hervariable
	char i;

	//Bildschirm l�schen
	clrscreen();

	//Listen Men� aufrufen
	if (ListMenue(cMedia) == 0)
	{
		return 0;
	}

	//Abfrage ob Vor, Zur�ck oder beides angezeigt werden muss
	if (List != NULL)
	{
		Listvor = List;
		for (i = 0; i < 17; i++)
		{
			if (Listvor -> next == NULL)
			{
				break;
			}
			Listvor = Listvor -> next;
		}


		if (Listvor -> next != NULL && List -> prev != NULL)
		{
			Footer(0);
		}
		else if (Listvor -> next != NULL)
		{
			Footer(3);
		}
		else if (List -> prev != NULL)
		{
			Footer(1);
		}
		else
		{
			Footer(2);
		}
	}
	else
	{
		Footer(2);
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
	int Data = 0;
	char Input = 0;
	setColor(0,14);
	fflush(stdin);
	while (1)
	{
		scanf_s("%c", &Input);
		switch (Input)
		{
		case 'e': return -1;
		case 'v': return -2;
		case 'z': return -3;
		case '\n': return Data;
		}
		Data = Data * 10 + Input - 48;
	}
	return 0;
}

char search (void)
{
	int searchParameter;
	char titel[50];

	setColor(0,15);

	//Men� l�schen
	if (clrRange(22, 3) == 0)
	{
		return 0;
	}

	//Footer anzeigen
	Footer(4);

	gotoxy(0,23);
	printf("Bitte geben Sie einen Titel ein (max 50 Zeichen): ");
	fgets(titel, (TITLE_LENGTH), stdin);

	//Abbruchbedingungen anzeigen
	switch (titel[0])
	{
	case 'e': exit(0);
	case '0': return -1;
	}

	//Sucht in der Liste nach dem Titel und �bergibt eine neue Liste mit den Ergebnissen
	List = searchItem(List,titel);

	return -1;
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
	char changeselect; //Speichervariable f�r den Parameter welche Eigenschaft ge�ndert werden soll

	//Bildschirm l�schen
	clrscreen();

	//Auswahl der zu �ndernden Parameter anzeigen
	ChangeMenue();

	//Eingabeposition
	gotoxy(0,21);

	//Parameter abfragen der ge�ndert werden soll
	switch (changeselect = askInput())
	{
	case -1: exit(0);
	case 0: return -1;
	}

	//Element �ndern
	List = changeItemDetails(List, cMedia,changeselect, List -> nodeDetails -> index);

	//Speichert die aktuallisierte Liste in der Datei
	if (savelist() == 0)
	{
		return 0;
	}
}

char del (void)
{
	Node * Datensatz; //Pointer auf den Datensatz der  gel�scht werden soll

	//Index abfragen und Datensatz suchen
	Datensatz = searchForIndex(List, askIndex());

	//Bildschirm l�schen
	clrscreen();

	//Knoten auf das n�chste oder vorige Element setzen
	if (Datensatz != NULL)
	{
		if ((List = Datensatz -> next) == NULL)
		{
			List = Datensatz -> prev;
		}
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
	int sortParameter;

	//Bildschirm l�schen
	clrscreen();

	//Optionen nach denen sortiert werden kann anzeigen
	SortMenue();

	gotoxy(0,18);
	switch (askInput())
	{
	case 0: return -1;
	case -1: exit(0);
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	}

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
	setColor(0,15);
	clrRange(3,30);
	gotoxy(0,0);
	return -1;
}

void vorBlaettern (void)
{
	if (List != NULL)
	{
		char i;
		for (i = 0; i < 17; i++)
		{
			if (List -> next == NULL)
			{
				zurueckBlaettern();
				return;
			}
			List = List -> next;
		}
	}
}

void zurueckBlaettern (void)
{
	if (List != NULL)
	{
		char i;
		for (i = 0; i < 17; i++)
		{
			if (List -> prev == NULL)
			{
				return;
			}
			List = List -> prev;
		}
	}
}

void printError (char * Error)
{
	setColor(1,12);
	gotoxy (10,63);
	gotoxy (10,50);
	printf ("%s", Error);
	gotoxy (26,51);
	printf("f: Fortfahren		e: Exit");
	gotoxy (39,52);
	if (askInput() == 'e')
	{
		exit(0);
	}
	clrRange(50,3);
	gotoxy (0,0);
}