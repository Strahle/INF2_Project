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
	gotoxy(0,21);
	printf("################################################################################");
	printf("1: B\x81""cher\t\t");
	printf("2: CD's\t\t");
	printf("3: DVD's\t\t");
	printf("e: exit\n");
	printf("################################################################################");
	gotoxy(34,7);
	scanf_s("%c", &input);
	return input;
}

char ListMenue (void)
//Men� f�r die Optionen der Listenanzeige
//1: Suchen
//2: Details
//3: Hinzuf�gen
//4: �ndern
//5: L�schen
//6: Sortieren
//7: Genre Auswahl
{

}

char showDetailMenue (void)
//Men� f�r die Optionen der Detailanzeige
//1: Auswahl
//2: �ndern
//3: L�schen
//4: Zur�ck zur Liste
{

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