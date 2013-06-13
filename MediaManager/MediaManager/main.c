#include "Block.h"

//Auswertung der Auswahl in Details
void evaluateDetail (void);

//Auswertung der Auswahl in Liste
void evaluateListe (void);

//Setzt den Dateipfad für das ausgewählte Medium
//Lädt die Liste für das ausgewählte Medium
char evaluateMedia (void);

//Auswertung der Auswalh im Suchergebnis
void evaluateSearch (void);

//Lädt die aktuelle Liste neu
void reloadList (void);


void main(void)
{
	while (1)
	{
		//Funktionen Initialisieren
		init();

		//Medien Anzeigen
		Media();
		//Listen laden
		

		if (evaluateMedia() != 0)
		{
			//Liste anzeigen
			Liste();

			//Auswahl auswerten
			evaluateListe();

			//Datei schließen
			closeFile();
		}
	}
}

char evaluateMedia (void)
{
	//Eingabeposition
	gotoxy(0,23);

	switch (askInput())
	{
	case 1: setFilePath ("Buecher.bin");
		cMedia = 1;
		break;
	case 2: setFilePath ("CD.bin");
		cMedia = 2;
		break;
	case 3: setFilePath ("DVD.bin");
		cMedia = 3;
		break;
	case -1: exit(0);
	default: return 0;
	}

	if (loadlist() == 0)
	{
		printError ("Es ist ein Fehler beim laden der Liste aufgetreten");
		return 0;
	}

	return -1;
}

void evaluateListe (void)
{
	while (1)
	{
		//Eingabeposition
		gotoxy(0,22);

		switch (askInput())
		{
		case 0: return;
		case 1: if (search() == 0)
				{
					printError ("Es ist ein Fehler beim suchen des Elements aufgetreten");
				}
				evaluateSearch();
				break;
		case 2: selectElement();
				if (details() == 0)
				{
					printError ("Es ist ein Fehler beim anzeigen der Details aufgetreten");
				}
				evaluateDetail();
				break;
		case 3: if (add() == 0)
				{
					printError("Es ist ein Fehler beim hinzufuegen des Elements aufgetreten");
				}
				break;
		case 4: selectElement();
				if (edit() == 0)
				{
					printError ("Es ist ein Fehler beim \204""ndern des Elements aufgetreten");
				}
				break;
		case 5: if (del() == 0)
				{
					printError ("Es ist ein Fehler beim loeschen des Elements aufgetreten");
				}
				break;
		case 6: if (sort() == 0)
				{
					printError ("Es ist ein Fehler beim sortieren aufgetreten");
				}
				break;
		case -2: vorBlaettern();
			break;
		case -3: zurueckBlaettern();
			break;
		case -1: exit(0);
		}
		Liste();
	}
}

void evaluateDetail (void)
{
	while (1)
	{
		//Eingabeposition
		gotoxy(0,22);

		switch (askInput())
		{
		case 0: return;
		case 1: selectElement();
			break;
		case 2: edit();
			break;
		case 3: del();
			break;
		case -1: exit(0);
		}
		details();
	}
}

void evaluateSearch (void)
{
	while (1)
	{
		//Liste anzeigen
		Liste();

		//Suchergebnis-Menü anzeigen
		SearchMenueResult();

		//Eingabeposition
		gotoxy(0,22);

		switch (askInput())
		{
		case 0:
			reloadList();
			return;
		case 1: if (search() == 0)
				{
					printError ("Es ist ein Fehler beim suchen des Elements aufgetreten");
				}
				break;
		case 2: selectElement();
				if (details() == 0)
				{
					printError ("Es ist ein Fehler beim anzeigen der Details aufgetreten");
				}
				evaluateDetail();
				break;
		case 3: reloadList();
				selectElement();
				if (edit() == 0)
				{
					printError ("Es ist ein Fehler beim aendern des Elements aufgetreten");
				}
				break;
		case 4: reloadList();
				if (del() == 0)
				{
					printError ("Es ist ein Fehler beim loeschen des Elements aufgetreten");
				}
				break;
		case 5: if (sort() == 0)
				{
					printError ("Es ist ein Fehler beim sortieren aufgetreten");
				}
				break;
		case -2: vorBlaettern();
			break;
		case -3: zurueckBlaettern();
			break;
		case -1: exit(0);
		}
	}


}

void reloadList (void)
{
	//Datei schließen
	closeFile();

	//Funktionen Initialisieren
	init();

	//Abfrage welches Medium ausgewählt ist
	switch (cMedia)
	{
	case 1: setFilePath ("Buecher.bin");
		break;
	case 2: setFilePath ("CD.bin");
		break;
	case 3: setFilePath ("DVD.bin");
		break;
	case -1: exit(0);
	}

	//Liste laden
	if (loadlist() == 0)
	{
		printError ("Es ist ein Fehler beim laden der Liste aufgetreten");
		return;
	}
}