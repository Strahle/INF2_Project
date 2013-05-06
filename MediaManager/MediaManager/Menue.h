#pragma once
#ifndef MENUE_H_
	#define MENUE_H_

	char GenreMenue (void);
	//Men� f�r die Auswahl des Genre
	//1: B�cher
	//2: CD's
	//3: DVD's

	char ListMenue (void);
	//Men� f�r die Optionen der Listenanzeige
	//1: Suchen
	//2: Details
	//3: Hinzuf�gen
	//4: �ndern
	//5: L�schen
	//6: Sortieren
	//7: Genre Auswahl

	char showDetailMenue (void);
	//Men� f�r die Optionen der Detailanzeige
	//1: Auswahl
	//2: �ndern
	//3: L�schen
	//4: Zur�ck zur Liste

	int SortMenue (void);
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

	char ChangeMenue (void);
	//Men� f�r die Optionen zum �ndern
	//1: Titel
	//2: Autor
	//3: Verlag/Studio/Label
	//4: ISBN
	//5: Erscheinungsdatum
	//6: Schauspieler
	//7: Zusammenfassung
	//8: Genre

	char SearchMenue (void);
	//Men� f�r die Optionen der Suche
	//1: Titel
	//2: Autor
	//3: Verlag/Studio/Label
	//4: ISBN
	//5: Erscheinungsdatum
	//6: Schauspieler

	char SearchMenueResult (void);
	//1: Suchen
	//2: Detail
	//3: �ndern
	//4: L�schen
	//5: Sortieren (Nur in der Suchdatei)
	//6: Zur�ck zur Liste (Suchdatei L�schen)

#endif