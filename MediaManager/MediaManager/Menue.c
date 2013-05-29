#include <stdlib.h>
#include <stdio.h>
#include "Menue.h"
#include <windows.h>

	//SearchMenueResult ();
	//ChangeMenue ();
	//SearchMenue ();
	//SortMenue();
	//MediaMenue ();
	//ListMenue ();
	//showDetailMenue ();


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
int correctInput(int min, int max, char posX, char posY, boolean back)
{
	int input;
	gotoxy(0,0);
	gotoxy(posX,posY + 1);
	setColor(0,15);
	scanf_s("%i", &input); fflush(stdin);
	
	while((input > max || (char)input < min) && (input !=99 || !back)) //
	{
		if(input == -1 ) 
		{
			exit(0);
		}
		else
		{
			clrRange(posY,1);
			gotoxy(posX,posY);
			setColor(0,12);
			printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben.\n");
			setColor(0,15);
			scanf_s("%i", &input); fflush(stdin);
		}
	}
	return input;
}

//Hier wird die Kopfzeile und zurück und exit erzeugt
char Footer(boolean back)
{
	setColor(7,9);
	if(back)
	{
		gotoxy(55,24);
		printf("99: Zur\x81""ck\t");
	}
	else
	{
		gotoxy(72,24);
	}
	printf("-1: exit\n");

	setColor(0,15);
	return;
}

//Hier wird die Kopfzeile und zurück und exit erzeugt
char Head(char Number, boolean back)
{
	static int actPos = -10;

	if (back)
	{
		actPos -= 10;
		clrPosition(2,actPos, 8);
	}
	else
	{
		setColor(7,1);
		gotoxy(actPos,2);

		switch (Number)
		{
		case 0:
				setColor(7,9);
				gotoxy(0,0);
				printf("\t\t\t\n");// tab sind 8 Leerzeichen
				printf("     Media Manager\t\n");
				printf("\t\t\t");
				break;

		case 1:
				printf("B\x81""cher/   ");
				break;
		case 2:
				printf("CD's/     ");
				break;
		case 3:
				printf("DVD's/    ");
				break;
		case 4:
				printf("Details/  ");
				break;
		case 5:
				printf("Suchen/   ");
				break;
		case 6:
				printf("Sortieren/");
				break;
		case 7:
				printf("Ergebnis/ ");
				break;
		case 8:
				printf("\x8E""ndern/   ");
				break;
		default:
			break;
		}
				actPos += 10;
	}

	setColor(0,15);
	return;
}

//Menü für die Auswahl des Genre
//1: Bücher
//2: CD's
//3: DVD's
char MediaMenue (void)
{
	int result;

	Head(0, 0);

	setColor(0,15);
	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Medien Auswahl");

	clrPosition(4,20,80);	
	gotoxy(20,4);
	printf("In Welchem Medientyp wollen sie suchen?");


	gotoxy(0,24);
	setColor(7,1);
	printf("1: B\x81""cher\t");
	printf("2: CD's\t\t");
	printf("3: DVD's\t\t\t\t");

	Footer(0);
	result = correctInput( 1, 3, 0, 22, 0);
	clrRange(22,3);

	clrPosition(4,20,80);	
	Head((char)result, 0);

	return result;
}

//Menü für die Optionen der Listenanzeige
//1: Suchen
//2: Details
//3: Hinzufügen
//4: Ändern
//5: Löschen
//6: Sortieren
//7: Genre Auswahl
char ListMenue (void)
{
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Listenanzeige");	

	gotoxy(0,23);
	setColor(7,1);
	printf("1: Suchen\t");
	printf("2: Details\t");
	printf("3: Hinzuf\x81""gen\t\t");
	printf("4: \x8E""ndern\t\t");
	printf("5: L\x94""schen\t");
	printf("6: Sortieren\t\t\t\t");

	Footer(1);
	result = correctInput( 1, 6, 0, 21, 1);
	clrRange(21,4);

	return result;
}

//Menü für die Optionen der Detailanzeige
//1: Auswahl
//2: Ändern
//3: Löschen
//99: Zurück zur Liste
//e: exit
char showDetailMenue (void)
{
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Detail Men\x81");

	gotoxy(0,24);
	setColor(7,1);
	printf("1: Auswahl\t");
	printf("2: \x8E""ndern\t");
	printf("3: L\x94""schen\t\t\t");

	Footer(1);
	result = correctInput(1, 3, 0, 22, 1);
	clrRange(22,3);

	Head(4, 0);

	return result;
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
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Sortier Men\x81");

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
	printf("16: Schauspieler\t\t\t");

	Footer(1);
	result = correctInput(1, 16, 0, 17, 1);
	clrRange(17,8);

	Head(6, 0);
	return result;
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
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Eintrag \x8E""ndern");

	gotoxy(0,22);
	setColor(7,1);
	printf("1: Titel\t\t");
	printf("2: Autor\t");
	printf("3: Verlag/Studio/Label\t");
	printf("4: ISBN\t\t");
	printf("5: Erscheinungsdatum\t");
	printf("6: Schauspieler\t");
	printf("7: Zusammenfassung\t");
	printf("8: Genre\t\t\t\t\t\t\t\t");

	Footer(1);
	result = correctInput(1, 8, 0, 20, 1);
	clrRange(20,5);
	Head(8, 0);
	return result;
}

//Menü für die Optionen der Suche
//1: Titel
//2: Autor
//3: Verlag/Studio/Label
//4: ISBN
//5: Erscheinungsdatum
//6: Schauspieler
char SearchMenue (void)
{
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Suchen");

	gotoxy(0,23);
	setColor(7,1);
	printf("1: Titel\t\t");
	printf("2: Autor\t");
	printf("3: Verlag/Studio/Label\t");
	printf("4: ISBN\t\t");
	printf("5: Erscheinungsdatum\t");
	printf("6: Schauspieler\t\t\t");

	Footer(1);
	result = correctInput(1, 6, 0, 21, 1);
	clrRange(21,4);

	Head(5, 0);
	return result;
}

//1: Suchen
//2: Detail
//3: Ändern
//4: Löschen
//5: Sortieren (Nur in der Suchdatei)
//6: Zurück zur Liste (Suchdatei Löschen)
char SearchMenueResult (void)
{
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Ergebnis");

	gotoxy(0,22);
	setColor(7,1);
	printf("1: Suchen\t");
	printf("2: Detail\t");
	printf("3: \x8E""ndern\t");
	printf("4: L\x94""schen\t\t\t");
	printf("5: Sortieren (in der Suchdatei)\t\t");
	printf("6: Zur\x81""ck zur Liste (Suchdatei L\x94""schen)\t\t\t\t\t\t\t\t");

	Footer(1);
	result = correctInput(1, 6, 0, 20, 1);
	clrRange(20,5);

	Head(7, 0);
	return result;
}