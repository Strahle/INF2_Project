#include <stdlib.h>
#include <stdio.h>
#include "Menue.h"
#include <windows.h>


char gotoxy(int xpos, int ypos)
// Diese Funktion erm�glicht es durch �bergabe der x und y Postion den Cursor frei zu setzen
{
    COORD scrn;    
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
	return -1;
} 


char clrRange(char Line, char space)
// Diese Funktion l�scht die Anzahl Zeilen(Space) von der �bergebenen Zeile(Line) an
{
	int i;
	gotoxy(0,Line);
	for (i = 1; i <= space; i++)
	{
		printf("                                                                                ");
	}
	return -1;
}

char clrPosition(char Line, char position ,char space)
// Diese Funktion l�scht die Anzahl Zeichen(Space) von der �bergebenen Zeile(Line) und Position an
{
	int i;
	gotoxy(position,Line);
	for (i = 1; i <= space; i++)
	{
		printf(" ");
	}
	return -1;
}
   
char correctInput(char input, char min, char max, char posX, char posY)
// Abfrage nach einlesen ob es ein erlaubter Wert f�r die Menue Listen ist
{
	while((input > max || (char)input < min) && input !='99') //
	{
		if(input == 'e' || input == 'E') 
		{
			exit(0);
		}
		else
		{
			clrRange(posY,1);
			gotoxy(posX,posY);
			printf("Nicht erlaubte eingabe. Bitte nochmal eingeben.\n");
			scanf_s("%c", &input); fflush(stdin);
		}
	}
}

char MediaMenue (void)
//Men� f�r die Auswahl des Genre
//1: B�cher
//2: CD's
//3: DVD's
{
	char input;
	printf("##########################\n");
	printf("###\tMedia Manager\t##\t\tMedien Auswahl\n");
	printf("##########################\n\n\n");
	printf("\t\tIn Welchem Medientyp wollen sie suchen?\n\n");
	gotoxy(0,22);
	printf("################################################################################");
	printf("1: B\x81""cher\t");
	printf("2: CD's\t\t");
	printf("3: DVD's\t\t\t\t");
	printf("e: exit\n");
	printf("################################################################################");
//	gotoxy(34,7);
	gotoxy(0,0);
	gotoxy(0,21);
	scanf_s("%c", &input); fflush(stdin);
	

	while(input > '3' || input < '1') 
	{
		if(input == 'e' || input == 'E') 
		{
			exit(0);
		}
		else
		{
			gotoxy(0,20);
			printf("Nicht erlaubte eingabe. Bitte nochmal eingeben.\n");
			scanf_s("%c", &input); fflush(stdin);
		}
	}
	return input;
}

char ListMenue (char media)
//Men� f�r die Optionen der Listenanzeige
//1: Suchen
//2: Details
//3: Hinzuf�gen
//4: �ndern
//5: L�schen
//6: Sortieren
//7: Genre Auswahl
{
	char input;
	clrPosition(1,40,39);
	gotoxy(40,1);
	switch(media)
	{
	case '1':
			printf("B\x81""cher");
		break;
	case '2':
			printf("CD");
		break;
	case '3':
			printf("DVD");
		break;
	default:
		break;
	}
	clrRange(20,3);
	gotoxy(0,20);
	printf("################################################################################");
	printf("1: Suchen\t");
	printf("2: Details\t\t");
	printf("3: Hinzuf\x81""gen\t\t");
	printf("4: \x8E""ndern\n");
	printf("5: L\x94""schen\t");
	printf("6: Sortieren");
	gotoxy(50,22);
	printf("99: Zur\x81""ck\t\t");
	printf("e: exit\n");
	
	gotoxy(0,19);
	scanf_s("%c", &input); fflush(stdin);

	return correctInput(input, '1', '6', 0, 18);
}

char showDetailMenue (void)
//Men� f�r die Optionen der Detailanzeige
//1: Auswahl
//2: �ndern
//3: L�schen
//99: Zur�ck zur Liste
//e: exit
{
	char input;
	clrPosition(1,40,39);
	gotoxy(40,1);
	printf("Details");

	clrRange(20,3);
	gotoxy(0,20);
	printf("################################################################################");
	printf("1: Auswahl\t");
	printf("2: \x8E""ndern\t\t");
	printf("3: L\x94""schen\n");
	gotoxy(50,22);
	printf("99: Zur\x81""ck\t\t");
	printf("e: exit\n");

	gotoxy(0,19);
	scanf_s("%c", &input); fflush(stdin);

	return correctInput(input, 1, 3, 0, 18);
}

int SortMenue (void)
//Men� f�r die Optionen der Sortierfunktion
//1: Titel abw�rts
//2: Autor abw�rts
//3: Verlag/Studio/Label abw�rts
//4: ISBN abw�rts
//5: Erscheinungsdatum abw�rts
//6: Schauspieler abw�rts

//-1: Titel aufw�rts
//-2: Autor aufw�rts
//-3: Verlag/Studio/Label aufw�rts
//-4: ISBN aufw�rts
//-5: Erscheinungsdatum aufw�rts
//-6: Schauspieler aufw�rts
{

}

char ChangeMenue (void)
//Men� f�r die Optionen zum �ndern
//1: Titel
//2: Autor
//3: Verlag/Studio/Label
//4: ISBN
//5: Erscheinungsdatum
//6: Schauspieler
//7: Zusammenfassung
//8: Genre
{

}

char SearchMenue (void)
//Men� f�r die Optionen der Suche
//1: Titel
//2: Autor
//3: Verlag/Studio/Label
//4: ISBN
//5: Erscheinungsdatum
//6: Schauspieler
{

}

char SearchMenueResult (void)
//1: Suchen
//2: Detail
//3: �ndern
//4: L�schen
//5: Sortieren (Nur in der Suchdatei)
//6: Zur�ck zur Liste (Suchdatei L�schen)
{

}