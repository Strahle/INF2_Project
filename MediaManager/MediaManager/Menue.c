#include <stdlib.h>
#include <stdio.h>
#include "Menue.h"
#include <windows.h>


char gotoxy(int xpos, int ypos)
// Diese Funktion ermöglicht es durch übergabe der x und y Postion den Cursor frei zu setzen
{
    COORD scrn;    
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
	return -1;
} 


char clrRange(char Line, char space)
// Diese Funktion löscht die Anzahl Zeilen(Space) von der übergebenen Zeile(Line) an
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
// Diese Funktion löscht die Anzahl Zeichen(Space) von der übergebenen Zeile(Line) und Position an
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
// Abfrage nach einlesen ob es ein erlaubter Wert für die Menue Listen ist
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
//Menü für die Auswahl des Genre
//1: Bücher
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
//Menü für die Optionen der Listenanzeige
//1: Suchen
//2: Details
//3: Hinzufügen
//4: Ändern
//5: Löschen
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
//Menü für die Optionen der Detailanzeige
//1: Auswahl
//2: Ändern
//3: Löschen
//99: Zurück zur Liste
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
//Menü für die Optionen der Sortierfunktion
//1: Titel abwärts
//2: Autor abwärts
//3: Verlag/Studio/Label abwärts
//4: ISBN abwärts
//5: Erscheinungsdatum abwärts
//6: Schauspieler abwärts

//-1: Titel aufwärts
//-2: Autor aufwärts
//-3: Verlag/Studio/Label aufwärts
//-4: ISBN aufwärts
//-5: Erscheinungsdatum aufwärts
//-6: Schauspieler aufwärts
{

}

char ChangeMenue (void)
//Menü für die Optionen zum ändern
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
//Menü für die Optionen der Suche
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
//3: Ändern
//4: Löschen
//5: Sortieren (Nur in der Suchdatei)
//6: Zurück zur Liste (Suchdatei Löschen)
{

}