#include "Menue.h"

//Hier wird die Baumstruktur erezugt
// Dazu muss entsprechdnde Nummer des Menues übergeben werden
//	0: Header Media Manger
//	1: Bücher
//	2: CD
//	3: DVD
//	4: Details
//	5: suchen
//	6: sortieren
//	7: ergebnis
//	8: änder
//	9: eine Struktur zurück

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

//Menü für die Auswahl des Genre
//1: Bücher
//2: CD's
//3: DVD's
char MediaMenue (void)
{
	clrRange(0,30);

	Head(0);

	setColor(standBackground,standFond);
	clrRange(3,30);
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

	Footer(2);

	return 1;
}

//Menü für die Optionen der Listenanzeige
//1: Suchen
//2: Details
//3: Hinzufügen
//4: Ändern
//5: Löschen
//6: Sortieren
//7: Genre Auswahl
char ListMenue (char Medium)
{
	clrPosition(1,35,15);
	gotoxy(35,1);
	printf("Listenanzeige");


	setColor(sonderBackground,sonderFond);
	gotoxy(60,0);
	printf("\t\t\t");// tab sind 8 Leerzeichen
	
	gotoxy(60,1);
	switch (Medium)
	{
	case 1: printf("        B\x81""cher       ");
		break;
	case 2: printf("         CD's             ");
		break;
	case 3: printf("        DVD's             ");
		break;
	}

	gotoxy(60,2);
	printf("\t\t\t");

	gotoxy(0,23);
	setColor(menueBackground,menueFond);
	printf("1: Suchen\t");
	printf("2: Details\t");
	printf("3: Hinzuf\x81""gen\t    ");
	printf("0: Zur\x81""ck zur Medienauswahl ");
	printf("4: \x8E""ndern\t");
	printf("5: L\x94""schen\t");
	printf("6: Sortieren\t\t\t\t");

	return 1;
}

//Menü für die Optionen der Detailanzeige
//1: Auswahl
//2: Ändern
//3: Löschen
//99: Zurück zur Liste
//e: exit
char showDetailMenue (void)
{

	clrPosition(1,35,15);
	gotoxy(35,1);
	printf("Detail Men\x81");

	gotoxy(0,23);
	setColor(menueBackground,menueFond);
	printf("1: Auswahl\t");
	printf("2: \x8E""ndern\t");
	printf("3: L\x94""schen\t\t    ");
	printf("0: Zur\x81""ck zur Liste ");

	clrRange(24,1);
	Footer(2);

	return 1;
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
int SortMenue (char medium)
{

	clrPosition(1,35,15);
	gotoxy(35,1);
	printf("Sortier Men\x81");

	gotoxy(0,19);
	setColor(sonderBackground,sonderFond);
	printf("abw\x84""rts Sortieren\t\t\t\t\t\t\t\t");
	setColor(menueBackground,menueFond);
	printf("1: Titel\t\t");
	switch (medium)
	{
		case 1 :
			printf("2: Autor\t\t");
			printf("3: Verlag\t\t");
			break;
		case 2 :
			printf("2: Interpret\t\t");
			printf("3: Label\t\t");
			break;
		case 3 :
			printf("2: Regisseur\t\t");
			printf("3: Studio\t\t");
			break;
	}
	printf("4: ISBN\t");
	printf("5: Erscheinungsdatum\t\t\t\t\t\t\t\t");

	setColor(sonderBackground,sonderFond);
	printf("aufw\x84""rts Sortieren\t\t\t\t\t\t\t\t");
	setColor(menueBackground,menueFond);	setColor(7,1);
	printf("11: Titel\t\t");
	switch (medium)
	{
		case 1 :
			printf("12: Autor\t\t");
			printf("13: Verlag\t\t");
			break;
		case 2 :
			printf("12: Interpret\t\t");
			printf("13: Label\t\t");
			break;
		case 3 :
			printf("12: Regisseur\t\t");
			printf("13: Studio\t\t");
			break;
	}
	printf("14: ISBN");
	printf("15: Erscheinungsdatum\t\t\t\t");

	Footer(4);

	return 1;
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

	clrPosition(1,35,15);
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

	Footer(4);

	return 1;
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

	clrPosition(1,35,15);
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

	return 1;
}

//1: Suchen
//2: Detail
//3: Ändern
//4: Löschen
//5: Sortieren (Nur in der Suchdatei)
//6: Zurück zur Liste (Suchdatei Löschen)
char SearchMenueResult (void)
{

	clrPosition(1,35,15);
	gotoxy(35,1);
	printf("Ergebnis");

	gotoxy(0,23);
	setColor(menueBackground,menueFond);
	printf("1: Suchen\t");
	printf("2: Detail\t");
	printf("3: \x8E""ndern\t\t    ");
	printf("0: Zur\x81""ck zur Liste ");
	printf("4: L\x94""schen\t");
	printf("5: Sortieren (in der Suche)\t\t");



	return 1;
}