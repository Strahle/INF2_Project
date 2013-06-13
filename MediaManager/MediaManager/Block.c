#include "Block.h"

#include <stdio.h>


Node * List; //Knoten für die aktuelle Position der Liste (Erstes Element auf der Seite)

void init (void)
{
	List = initList(); //Initialisiert eine neue Liste
	initFileEdit(); //Reinitialisiert FileEdit
}

char Media (void)
{
	//Bildschirm löschen
	clrscreen();

	//Media Menü aufrufen
	if (MediaMenue() == 0)
	{
		return 0;
	}
}

char Liste (void)
{
	//Pointer für die Abfrage Vor/Zurück
	Node * Listvor;
	//Zähervariable
	char i;

	//Bildschirm löschen
	clrscreen();

	//Listen Menü aufrufen
	if (ListMenue(cMedia) == 0)
	{
		return 0;
	}

	//Abfrage ob Vor, Zurück oder beides angezeigt werden muss
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

	return -1;
}

char details (void)
{
	//Bildschirm löschen
	clrscreen();

	//Detail Menü Anzeigen
	showDetailMenue();

	//Details des Elements Anzeigen
	showDetail(List -> nodeDetails, cMedia);

	return -1;
}

char selectElement (void)
{
	Node * Datensatz = NULL; //Pointer auf das ausgewählte Element

	//Menü löschen
	if (clrRange(22, 3) == 0)
	{
		return 0;
	}

	while (1)
	{
		//Index abfragen und in der Liste nach dem Datensatz suchen
		Datensatz = searchForIndex (List, askIndex());
		if (Datensatz != NULL)
		{
			break;
		}
		gotoxy(0,23);
		printf_s("Der von Ihnen gew\204""hlte Index ist nicht g\x81""ltig");
	}

	List = Datensatz;

	return -1;
}

char search (void)
{
	char titel[50]; //Zwischenspeicher für den Suchwert
	int i; //Zählvariable

	setColor(0,15);

	//Menü löschen
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

	//"\n" entfernen
	for (i = 0; i < 50; i ++)
	{
		if (titel[i] == '\n')
		{
			titel[i] = '\0';
			break;
		}
	}

	//Sucht in der Liste nach dem Titel und übergibt eine neue Liste mit den Ergebnissen
	List = searchItem(List,titel);

	return -1;
}

//Gibt bei Fehler 0 zurück
char add (void)
{
	Details * Detail; //Pointer zur übergabe der Details
	
	//Bildschirm löschen
	clrscreen();

	//Abfrage der Parameter
	if ((Detail = addItemInput(cMedia)) == NULL)
	{
		return 0;
	}

	//Datensetz in Liste einfügen
	if ((List = addItem(Detail)) == NULL)
	{
		return 0;
	}

	//Speichert die aktuallisierte Liste in der Datei
	if (savelist() == 0)
	{
		return 0;
	}

	return -1;
}

char edit (void)
{
	char changeselect; //Speichervariable für den Parameter welche Eigenschaft geändert werden soll

	//Bildschirm löschen
	clrscreen();

	//Auswahl der zu ändernden Parameter anzeigen
	ChangeMenue();

	//Eingabeposition
	gotoxy(0,21);

	//Parameter abfragen der geändert werden soll
	switch (changeselect = askInput())
	{
	case -1: exit(0);
	case 0: return -1;
	}

	//Element ändern
	List = changeItemDetails(List, cMedia,changeselect, List -> nodeDetails -> index);

	//Speichert die aktuallisierte Liste in der Datei
	if (savelist() == 0)
	{
		return 0;
	}

	return -1;
}

char del (void)
{
	Node * Datensatz; //Pointer auf den Datensatz der  gelöscht werden soll

	//Index abfragen und Datensatz suchen
	Datensatz = searchForIndex(List, askIndex());

	//Bildschirm löschen
	clrscreen();

	//Knoten auf das nächste oder vorige Element setzen
	if (Datensatz != NULL)
	{
		if ((List = Datensatz -> next) == NULL)
		{
			List = Datensatz -> prev;
		}
	}

	//Datensetz aus Liste löschen
	deleteItem(Datensatz);

	//Speichert die aktuallisierte Liste in der Datei
	if (savelist() == 0)
	{
		return 0;
	}

	return -1;
}

char sort (void)
{
	int sortParameter;

	//Bildschirm löschen
	clrscreen();

	//Optionen nach denen sortiert werden kann anzeigen
	SortMenue(cMedia);

	gotoxy(0,18);
	switch (askInput())
	{
	case 0: return -1;
	case -1: exit(0);
	case 1: bubbleSortList(sortTitelDesc);
		break;
	case 2: //bubbleSortList(sortAutorDesc);
		break;
	case 3: bubbleSortList(sortVerlagDesc);
		break;
	case 4: bubbleSortList(sortIsbnDesc);
		break;
	case 5: bubbleSortList(sortErscheinungsdatumDesc);
		break;
	case 6: //bubbleSortList(sortTextDesc);
		break;
	case 11: bubbleSortList(sortTitelAsc);
		break;
	case 12: //bubbleSortList(sortAutorAsc);
		break;
	case 13: bubbleSortList(sortVerlagAsc);
		break;
	case 14: bubbleSortList(sortIsbnAsc);
		break;
	case 15: bubbleSortList(sortErscheinungsdatumAsc);
		break;
	case 16: //bubbleSortList(sortTextAsc);
		break;
	}

	return -1;
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