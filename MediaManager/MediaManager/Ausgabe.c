//test
#include "Ausgabe.h"

// Diese Funktion ermöglicht es durch übergabe der x und y Postion den Cursor 
// auf eine beliebeige Stelle der Console zu setzen
char gotoxy(int xpos, int ypos)
{
    COORD scrn;    
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
	return -1;
} 

// Diese Funktion löscht die übergene Anzahl an Zeilen inklusive der übergeben
char clrRange(char Line, char space)
{
	int i;
	gotoxy(0,Line);
	for (i = 1; i <= space; i++)
	{
		printf("                                                                                ");
	}
	return -1;
}



//Zeigt eine Liste aller Genere an
void showGenere (void)
{
	
	/*Details * myDetails=NULL;
	struct tm * nun = NULL;

		nun = (struct tm *) calloc(1,sizeof(struct tm));
		myDetails = (Details *) calloc(1,sizeof(Details));

		nun->tm_mon = 10;
		nun->tm_year = 113; 

		strcpy_s(myDetails->titel,sizeof(myDetails->titel),"Ich bin ein test um zu gucken ob es geht.23456789");
		strcpy_s(myDetails->text,sizeof(myDetails->text),"So jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir");
		strcpy_s(myDetails->text,sizeof(myDetails->text),"So jetzt schreibe ich mal ein paar zeichen und guck wann wir");
		strcpy_s(myDetails->verlag,sizeof(myDetails->verlag),"Ich bin der Werner Heissenberg Verlag und Kokse be");
		myDetails->isbn = 1234567890123;
		myDetails->genre = '1';
		myDetails->erscheinungsdatum = mktime(nun);

		showDetail(myDetails);*/

}

//Zeigt eine Liste aller Titel an (auf einer Seite)
void showList (Node * Knot , char prev)
{
	int i;
	gotoxy(0,4);
	clrRange(4,18);
	for (i = 0 ; i <=18; i ++)
	{
		if (Knot != NULL)
		{
			printf("%i: %s\n",Knot->nodeDetails->index, Knot->nodeDetails->titel);
			if (prev == 1)
			{
			Knot = Knot->prev;
			}
			else
			{
				Knot = Knot->next;
			}
		}
	}

}

//Zeigt eine Liste mit den Details eines Elementes an
void showDetail (Details * Detail, int medium)
{
	int i=0, j,k = 0, start = 0, Test;
	double  ISBN;
	struct tm * nun;
	nun = (struct tm *) calloc(1,sizeof(struct tm));

	gotoxy(0,4);
	clrRange(4,18);

	localtime_s(nun, &Detail->erscheinungsdatum);

	printf("Titel:\t%s\n",Detail->titel);

	//enum genre_film{aktion = 1, thriller = 2, komoedie = 3, drama = 4, science_fiction = 5, doku = 6, horror = 7, abenteuer = 8};
	//enum genre_musik{rock = 1, pop = 2, jazz = 3, house = 4, klassik = 5, dance = 6, metal = 7, hip_hop = 8};
	//enum genre_buch{abenteuer = 1, thriller = 2, sachbuch = 3, biographie = 4, comic = 5, kinderbuch = 6, maerchen = 7, gedicht = 8};
	switch (medium)
	{
	case 1 :
		switch (Detail->genre)
		{
		case 1 :
			printf("Genre:\tAbenteuer\n");
			break;
		case 2 :
			printf("Genre:\tThriller\n");
			break;
		case 3 :
			printf("Genre:\tSachbuch\n");
			break;
		case 4 :
			printf("Genre:\tBiographie\n");
			break;
		case 5 :
			printf("Genre:\tComic\n");
			break;
		case 6 :
			printf("Genre:\tKinderbuch\n");
			break;
		case 7:
			printf("Genre:\tMaerchen\n");
			break;
		case 8 :
			printf("Genre:\tGedicht\n");
			break;
		}
		break;

	case 2 :
		switch (Detail->genre)
		{
		case 1 :
			printf("Genre:\tRock\n");
			break;
		case 2 :
			printf("Genre:\tPop\n");
			break;
		case 3 :
			printf("Genre:\tJazz\n");
			break;
		case 4 :
			printf("Genre:\tHouse\n");
			break;
		case 5 :
			printf("Genre:\tKlassik\n");
			break;
		case 6 :
			printf("Genre:\tDance\n");
			break;
		case 7:
			printf("Genre:\tMetal\n");
			break;
		case 8 :
			printf("Genre:\tHip-Hop\n");
			break;
		}
		break;

	case 3 :
		switch (Detail->genre)
		{
		case 1 :
			printf("Genre:\tAction\n");
			break;
		case 2 :
			printf("Genre:\tThriller\n");
			break;
		case 3 :
			printf("Genre:\tKomoedie\n");
			break;
		case 4 :
			printf("Genre:\tDrama\n");
			break;
		case 5 :
			printf("Genre:\tScience-Fiction\n");
			break;
		case 6 :
			printf("Genre:\tDokumentation\n");
			break;
		case 7:
			printf("Genre:\tHorror\n");
			break;
		case 8 :
			printf("Genre:\tAbenteuer\n");
			break;
		}
		break;
	}
	printf("Verlag:\t%s\n",Detail->verlag);
	printf("Erscheinungsdatum:  %i.%i.%i\t",nun->tm_mday, nun->tm_mon + 1, nun->tm_year + 1900);
	// Formatierung der ISBN durch ganzahliges Teilen mit abs(Absolut)
	// und den Angezeigten Anteil subtrahieren
	ISBN = Detail->isbn;
	printf("%i-", abs(ISBN/10000000000));
	ISBN = ISBN - (double)(abs(ISBN/10000000000))*10000000000;
	printf("%i-", abs(ISBN/1000000000));
	ISBN = ISBN - (double)(abs(ISBN/1000000000))*1000000000;
	printf("%i-",abs(ISBN/10000000));
	ISBN = ISBN -  (double)(abs(ISBN/10000000))*10000000;
	printf("%i-",abs(ISBN/10));
	ISBN = ISBN -  (double)(abs(ISBN/10))*10;
	printf("%i\n",abs(ISBN));

	//Formatierung der Detail Text Ausgabe. So das Wörter Sauber getrennt 
	// werden können und Text nicht ageschnitten wird
	printf("Details:\n");
	while(k <= 13 && start <=1023 && Detail->text[start + i] != 0 )
	{ // vom Letzen Zeichen an an nach Leerzeichen suchen
		for (i = 80; i >= 0; i--)
		{ //Wenn Leerzeichen oder Ende Zeile erreicht
			if (Detail->text[start + i] == ' ' || Detail->text[start + i] == 0 )
			{//Zeile Printen
				for (j = start; j< (start + i); j ++)
				{
					if (Detail->text[j] > 0)
					{
						printf("%c",Detail->text[j]);
					}
				}
				if (i < 80)
				{//new Line Wenn keine 80 Zeichen geprintet werden
					printf("\n");
				}
				if (Detail->text[start + i] == 0)
				{//wenn kein Text vorhanden ist
					k = 14;
				}
				else
				{// Anzahl ausgebenen Zeilen
				k += 1;
				}
				start += (i+1);
				break;
			}
			else if (i == 0)
			{
				for (j = start; j< (start + 80); j ++)
				{// Rest Text ausgeben
					printf("%c",Detail->text[j]);
				}
				k += 1;
				start += (79);
				break;
			}
		}
	}
}