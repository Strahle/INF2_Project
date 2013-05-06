#pragma once
#ifndef MENUE_H_
	#define MENUE_H_

	char GenreMenue (void);
	//Menü für die Auswahl des Genre
	//1: Bücher
	//2: CD's
	//3: DVD's

	char ListMenue (void);
	//Menü für die Optionen der Listenanzeige
	//1: Suchen
	//2: Details
	//3: Hinzufügen
	//4: Ändern
	//5: Löschen
	//6: Sortieren
	//7: Genre Auswahl

	char showDetailMenue (void);
	//Menü für die Optionen der Detailanzeige
	//1: Auswahl
	//2: Ändern
	//3: Löschen
	//4: Zurück zur Liste

	int SortMenue (void);
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

	char ChangeMenue (void);
	//Menü für die Optionen zum ändern
	//1: Titel
	//2: Autor
	//3: Verlag/Studio/Label
	//4: ISBN
	//5: Erscheinungsdatum
	//6: Schauspieler
	//7: Zusammenfassung
	//8: Genre

	char SearchMenue (void);
	//Menü für die Optionen der Suche
	//1: Titel
	//2: Autor
	//3: Verlag/Studio/Label
	//4: ISBN
	//5: Erscheinungsdatum
	//6: Schauspieler

	char SearchMenueResult (void);
	//1: Suchen
	//2: Detail
	//3: Ändern
	//4: Löschen
	//5: Sortieren (Nur in der Suchdatei)
	//6: Zurück zur Liste (Suchdatei Löschen)

#endif