#include <stdlib.h>
#include <stdio.h>
#include "Menue.h"
#include <windows.h>


// Diese Funktion erm�glicht es durch �bergabe der x und y Postion den Cursor 
// auf eine beliebeige Stelle der Console zu setzen
char gotoxy(int xpos, int ypos)
{
    COORD scrn;    
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
	return -1;
} 

// Diese Funktion l�scht die �bergene Anzahl an Zeilen inklusive der �bergeben
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
//2 : Dunkelgr�n (Gr�n)
//3 : Dunkelt�rkis
//4 : Dunkelrot (Rot)
//5 : Dunkelviolett (DarkPink)
//6 : Dunkelgelb
//7 : Hellgrau
//8 : Dunkelgrau
//9 : Hellblau
//10: Hellgr�n
//11: T�rkis
//12: Hellrot (Fehler-Rot ;) )
//13: Violett (Pink)
//14: Hellgelb
//15: Weiss
char setColor(char backColor, char fondColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),	backColor * 16 + fondColor);
	return -1;
}

// Diese Funktion l�scht die Anzahl Zeichen(Space) von der �bergebenen Zeile(Line) und Position an
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
   
//Die Funktion pr�ft nach Plausibilit�t dazu werden die Grenzen �bergeben und
//zus�tzlich noch die Possition an der die Fehlermeldung erscheinen soll
// Desweiteren ob bei der Funktion eine Zur�ck erlaubt ist.
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
			setColor(fehlerBackground,fehlerFond);
			printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben.\n");
			setColor(standBackground,standFond);
			scanf_s("%i", &input); fflush(stdin);
		}
	}
	return input;
}

//Hier werden die Sonderfunktion Zur�ck, Exit und Vor erzeugt und an die linke
//untere Ecke Positioniert 
char Footer(boolean back)
{
	setColor(sonderBackground,sonderFond);
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

	setColor(standBackground,standFond);
	return;
}

//Hier wird die Baumstruktur erezugt
// Dazu muss entsprechdnde Nummer des Menues �bergeben werden
//	0: Header Media Manger
//	1: B�cher
//	2: CD
//	3: DVD
//	4: Details
//	5: suchen
//	6: sortieren
//	7: ergebnis
//	8: �nder
//	9: eine Struktur zur�ck

char Head(char Number)
{
	static int actPos = -10;

	setColor(menueBackground,menueFond);
	gotoxy(actPos,2);

	switch (Number)
	{
	case 0:
		setColor(sonderBackground,sonderFond);
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
	case 9:
			actPos -= 20;
			clrPosition(2,actPos, 8);
			break;
	default:
		break;
	}
			actPos += 10;

	setColor(standBackground,standFond);
	return;
}

//Men� f�r die Auswahl des Genre
//1: B�cher
//2: CD's
//3: DVD's
char MediaMenue (void)
{
	int result;

	Head(0);

	setColor(standBackground,standFond);
	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Medien Auswahl");

	clrPosition(4,20,80);	
	gotoxy(20,4);
	printf("In Welchem Medientyp wollen sie suchen?");


	gotoxy(0,24);
	setColor(menueBackground,menueFond);
	printf("1: B\x81""cher\t");
	printf("2: CD's\t\t");
	printf("3: DVD's\t\t\t\t");

	Footer(0);
	result = correctInput( 1, 3, 0, 22, 0);
	clrRange(22,3);

	clrPosition(4,20,80);	
	Head((char)result);

	return result;
}

//Men� f�r die Optionen der Listenanzeige
//1: Suchen
//2: Details
//3: Hinzuf�gen
//4: �ndern
//5: L�schen
//6: Sortieren
//7: Genre Auswahl
char ListMenue (void)
{
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Listenanzeige");	

	gotoxy(0,23);
	setColor(menueBackground,menueFond);
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

//Men� f�r die Optionen der Detailanzeige
//1: Auswahl
//2: �ndern
//3: L�schen
//99: Zur�ck zur Liste
//e: exit
char showDetailMenue (void)
{
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Detail Men\x81");

	gotoxy(0,24);
	setColor(menueBackground,menueFond);
	printf("1: Auswahl\t");
	printf("2: \x8E""ndern\t");
	printf("3: L\x94""schen\t\t\t");

	Footer(1);
	result = correctInput(1, 3, 0, 22, 1);
	clrRange(22,3);

	Head(4);

	return result;
}

//Men� f�r die Optionen der Sortierfunktion
//1: Titel abw�rts
//2: Autor abw�rts
//3: Verlag/Studio/Label abw�rts
//4: ISBN abw�rts
//5: Erscheinungsdatum abw�rts
//6: Schauspieler abw�rts

//11: Titel aufw�rts
//12: Autor aufw�rts
//13: Verlag/Studio/Label aufw�rts
//14: ISBN aufw�rts
//15: Erscheinungsdatum aufw�rts
//16: Schauspieler aufw�rts
int SortMenue (void)
{
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Sortier Men\x81");

	gotoxy(0,19);
	setColor(sonderBackground,sonderFond);
	printf("abw\x84""rts Sortieren\t\t\t\t\t\t\t\t");
	setColor(menueBackground,menueFond);
	printf("1: Titel\t\t");
	printf("2: Autor\t");
	printf("3: Verlag/Studio/Label\t");
	printf("4: ISBN\t\t");
	printf("5: Erscheinungsdatum\t");
	printf("6: Schauspieler\t\t\t\t\t\t");

	setColor(sonderBackground,sonderFond);
	printf("aufw\x84""rts Sortieren\t\t\t\t\t\t\t\t");
	setColor(menueBackground,menueFond);	setColor(7,1);
	printf("11: Titel\t\t");
	printf("12: Autor\t");
	printf("13: Verlag/Studio/Label\t");
	printf("14: ISBN\t");
	printf("15: Erscheinungsdatum\t");
	printf("16: Schauspieler\t\t\t");

	Footer(1);
	result = correctInput(1, 16, 0, 17, 1);
	clrRange(17,8);

	Head(6);
	return result;
}

//Men� f�r die Optionen zum �ndern
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
	setColor(menueBackground,menueFond);
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
	Head(8);
	return result;
}

//Men� f�r die Optionen der Suche
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
	setColor(menueBackground,menueFond);
	printf("1: Titel\t\t");
	printf("2: Autor\t");
	printf("3: Verlag/Studio/Label\t");
	printf("4: ISBN\t\t");
	printf("5: Erscheinungsdatum\t");
	printf("6: Schauspieler\t\t\t");

	Footer(1);
	result = correctInput(1, 6, 0, 21, 1);
	clrRange(21,4);

	Head(5);
	return result;
}

//1: Suchen
//2: Detail
//3: �ndern
//4: L�schen
//5: Sortieren (Nur in der Suchdatei)
//6: Zur�ck zur Liste (Suchdatei L�schen)
char SearchMenueResult (void)
{
	int result;

	clrPosition(1,35,45);
	gotoxy(35,1);
	printf("Ergebnis");

	gotoxy(0,22);
	setColor(menueBackground,menueFond);
	printf("1: Suchen\t");
	printf("2: Detail\t");
	printf("3: \x8E""ndern\t");
	printf("4: L\x94""schen\t\t\t");
	printf("5: Sortieren (in der Suchdatei)\t\t");
	printf("6: Zur\x81""ck zur Liste (Suchdatei L\x94""schen)\t\t\t\t\t\t\t\t");

	Footer(1);
	result = correctInput(1, 6, 0, 20, 1);
	clrRange(20,5);

	Head(7);
	return result;
}