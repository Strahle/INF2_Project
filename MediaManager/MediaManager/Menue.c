#include <stdlib.h>
#include <stdio.h>
#include "Menue.h"
#include <windows.h>


// Diese Funktion ermöglicht es durch übergabe der x und y Postion den Cursor frei zu setzen
char gotoxy(int xpos, int ypos)
{
    COORD scrn;    
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
	return -1;
} 

// Diese Funktion löscht die Anzahl Zeilen(Space) von der übergebenen Zeile(Line) an
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

// Diese Funktion legt die Hintergrund- und die Schriftfarbe fest
//0 : Schwarz
//1 : Dunkelblau (Blau)
//2 : Dunkelgrün (Grün)
//3 : Dunkeltürkis
//4 : Dunkelrot (Rot)
//5 : Dunkelviolett (DarkPink)
//6 : Dunkelgelb
//7 : Hellgrau
//8 : Dunkelgrau
//9 : Hellblau
//10: Hellgrün
//11: Türkis
//12: Hellrot (Fehler-Rot ;) )
//13: Violett (Pink)
//14: Hellgelb
//15: Weiss
char setColor(char backColor, char fondColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),	backColor * 16 + fondColor);
	return -1;
}

// Diese Funktion löscht die Anzahl Zeichen(Space) von der übergebenen Zeile(Line) und Position an
char clrPosition(char Line, char position ,char space)
{
	int i;
	gotoxy(position,Line);
	for (i = 1; i <= space; i++)
	{
		printf(" ");
	}
	return -1;
}
   
// Abfrage nach einlesen ob es ein erlaubter Wert für die Menue Listen ist
char correctInput(char input, char min, char max, char posX, char posY)
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
			setColor(0,12);
			printf("Nicht erlaubte eingabe. Bitte nochmal eingeben.\n");
			setColor(0,15);
			scanf_s("%c", &input); fflush(stdin);
		}
	}
}

//Menü für die Auswahl des Genre
//1: Bücher
//2: CD's
//3: DVD's
char MediaMenue (void)
{
	char input;
	setColor(7,1);
	printf("\t\t\t\n");// tab sind 8 Leerzeichen
	printf("     Media Manager\t\n");
	printf("\t\t\t");

	setColor(0,15);
	gotoxy(35,1);
	printf("Medien Auswahl\n");
	printf("\n\n\n\n");
	
	printf("\t\tIn Welchem Medientyp wollen sie suchen?\n\n");
	gotoxy(0,24);
	setColor(7,1);
	printf("1: B\x81""cher\t");
	printf("2: CD's\t\t");
	printf("3: DVD's\t\t\t\t");
	printf("e: exit \n");
	gotoxy(0,0);
	gotoxy(0,23);
	setColor(0,15);
	scanf_s("%c", &input); fflush(stdin);
	

	while(input > '3' || input < '1') 
	{
		if(input == 'e' || input == 'E') 
		{
			exit(0);
		}
		else
		{
			gotoxy(0,22);
			setColor(0,12);
			printf("Nicht erlaubte eingabe. Bitte nochmal eingeben.\n");
			setColor(0,15);
			scanf_s("%c", &input); fflush(stdin);
			clrRange(22,1);
		}
	}
	clrRange(0,25);
	return input;
}

//Menü für die Optionen der Listenanzeige
//1: Suchen
//2: Details
//3: Hinzufügen
//4: Ändern
//5: Löschen
//6: Sortieren
//7: Genre Auswahl
char ListMenue (char media)
{
	char input;
	gotoxy(0,0);
	setColor(7,1);
	printf("\t\t\t\n");// tab sind 8 Leerzeichen
	printf("     Media Manager\t\n");
	setColor(7,9);
	printf("   Medien Auswahl\t\n");
	setColor(0,15);
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
	clrRange(22,3);
	gotoxy(0,23);
	setColor(7,1);
	printf("1: Suchen\t");
	printf("2: Details\t");
	printf("3: Hinzuf\x81""gen\t\t");
	printf("4: \x8E""ndern\t\t");
	printf("5: L\x94""schen\t");
	printf("6: Sortieren\t\t\t\t\t\t");
	gotoxy(55,24);
	printf("99: Zur\x81""ck\t");
	printf("e: exit \n");
	setColor(0,15);
	gotoxy(0,0);
	gotoxy(0,22);
	scanf_s("%c", &input); fflush(stdin);

	return correctInput(input, '1', '6', 0, 20);

}

//Menü für die Optionen der Detailanzeige
//1: Auswahl
//2: Ändern
//3: Löschen
//99: Zurück zur Liste
//e: exit
char showDetailMenue (char media)
{
	char input;
	clrRange(3,22);
	setColor(7,9);
	gotoxy(17,2);
	switch(media)
	{
	case '1':
			printf("/B\x81""cher");
		break;
	case '2':
			printf("/CD");
		break;
	case '3':
			printf("/DVD");
		break;
	default:
		break;
	}

	setColor(0,15);
	clrPosition(1,40,39);
	gotoxy(40,1);
	printf("Details");

	gotoxy(0,24);
	setColor(7,1);
	printf("1: Auswahl\t");
	printf("2: \x8E""ndern\t");
	printf("3: L\x94""schen\t\t\t");
	gotoxy(55,24);
	printf("99: Zur\x81""ck\t");
	printf("e: exit \n");
	gotoxy(0,0);
	gotoxy(0,23);
	setColor(0,15);
	scanf_s("%c", &input); fflush(stdin);

	return correctInput(input, '1', '3', 0, 22);
}

//Menü für die Optionen der Sortierfunktion
//1: Titel abwärts
//2: Autor abwärts
//3: Verlag/Studio/Label abwärts
//4: ISBN abwärts
//5: Erscheinungsdatum abwärts
//6: Schauspieler abwärts

//11: Titel aufwärts
//12: Autor aufwärts
//13: Verlag/Studio/Label aufwärts
//14: ISBN aufwärts
//15: Erscheinungsdatum aufwärts
//16: Schauspieler aufwärts
int SortMenue (void)
{
//	Menü für die Optionen der Sortierfunktion

	char input;
	
	gotoxy(0,19);
	setColor(7,9);
	printf("abw\x84""rts Sortieren\t\t\t\t\t\t\t\t");
	setColor(7,1);
	printf("1: Titel\t\t");
	printf("2: Autor\t");
	printf("3: Verlag/Studio/Label\t");
	printf("4: ISBN\t\t");
	printf("5: Erscheinungsdatum\t");
	printf("6: Schauspieler\t\t\t\t\t\t");

	setColor(7,9);
	printf("aufw\x84""rts Sortieren\t\t\t\t\t\t\t\t");
	setColor(7,1);
	printf("11: Titel\t\t");
	printf("12: Autor\t");
	printf("13: Verlag/Studio/Label\t");
	printf("14: ISBN\t");
	printf("15: Erscheinungsdatum\t");
	printf("16: Schauspieler\t\t\t\t\t\t");

	gotoxy(55,24);
	printf("99: Zur\x81""ck\t");
	printf("e: exit \n");
	gotoxy(0,0);
	gotoxy(0,18);
	setColor(0,15);
	scanf_s("%c", &input); fflush(stdin);

	return correctInput(input,'1', '16', 0, 17);

}

//Menü für die Optionen zum ändern
//1: Titel
//2: Autor
//3: Verlag/Studio/Label
//4: ISBN
//5: Erscheinungsdatum
//6: Schauspieler
//7: Zusammenfassung
//8: Genre
char ChangeMenue (void)
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

//1: Suchen
//2: Detail
//3: Ändern
//4: Löschen
//5: Sortieren (Nur in der Suchdatei)
//6: Zurück zur Liste (Suchdatei Löschen)
char SearchMenueResult (void)
{

}