#include "Block.h"

//Auswertung der Auswahl in Details
void evaluateDetail (void);

//Auswertung der Auswahl in Liste
void evaluateListe (void);

//Setzt den Dateipfad für das ausgewählte Medium
//Lädt die Liste für das ausgewählte Medium
void evaluateMedia (void);


void main(void)
{
	//Funktionen Initialisieren
	init();

	while (1)
	{
		//Funktionen Initialisieren
		init();

		//Medien Anzeigen
		Media();
		//Listen laden
		evaluateMedia();

		//Liste anzeigen
		Liste();
		//Auswahl auswerten
		evaluateListe();

		//Datei schließen
		closeFile();
	}
}

void evaluateMedia (void)
{
	//Eingabeposition
	gotoxy(0,23);

	switch (askInput())
	{
	case 1: setFilePath ("Buecher.txt");
		cMedia = 1;
		break;
	case 2: setFilePath ("CD.txt.");
		cMedia = 2;
		break;
	case 3: setFilePath ("DVD.txt.");
		cMedia = 3;
		break;
	case 'e': exit;
	}

	if (loadlist() == 0)
	{
		printError ("Es ist ein Fehler beim laden der Liste aufgetreten");
		return;
	}
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
					return;
				}
				break;
		case 2: selectElement();
				if (details() == 0)
				{
					printError ("Es ist ein Fehler beim anzeigen der Details aufgetreten");
					return;
				}
				evaluateDetail();
			break;
		case 3: if (add() == 0)
				{
					printError("Es ist ein Fehler beim hinzufuegen des Elements aufgetreten");
					return;
				}
				Liste();
				break;
		case 4: if (edit() == 0)
				{
					printError ("Es ist ein Fehler beim aendern des Elements aufgetreten");
					return;
				}
				break;
		case 5: if (del() == 0)
				{
					printError ("Es ist ein Fehler beim loeschen des Elements aufgetreten");
					return;
				}
				break;
		case 6: if (sort() == 0)
				{
					printError ("Es ist ein Fehler beim sortieren aufgetreten");
					return;
				}
				break;
		case 7: if (1 == 0)
				{
					return;
				}
				break;
		case 88: vorBlaettern();
			break;
		case 99: zurueckBlaettern();
			break;
		case 'e': exit;
		}
		Liste();
	}
}

void evaluateDetail (void)
{
	while (1)
	{
		//Eingabeposition
		gotoxy(0,23);

		switch (askInput())
		{
		case 0: return;
		case 1: selectElement();
			break;
		case 2: edit();
			break;
		case 3: del();
			break;
		case 'e': exit;
		}
		details();
	}
}