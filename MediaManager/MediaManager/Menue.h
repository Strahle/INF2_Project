/*Header: Menue.h
 Menue.h beinhaltet alle Funktionen die zur Menuedarstellung benötigt werden.
 bei allen Funktionen gibt es die Optionen Zurück und Exit.
 Mit der Funktion zurück kommt man in die vorherige Maske und mit exit wird 
 das Programm an dieser Stelle beendet. 
 ----------------------------------------------------------------------------
 -	Autor Manuel Strehle													-
 -	Bearbeitet: 06.05.2013													-
 -	Änderungen:																-
 ----------------------------------------------------------------------------
	folgende Menues gibt es
		MediaMenue
			Dieses Menue wird beim Start des Programms aufgerufen und fragt ab
			welchen Medientyp durchsucht oder bearbeitet werden soll. Und returnt
			dann den Medientyp als char.

		ListMenue
			Dieses Menue wird nach der Auswahl des Medientyps aufgerufen und bietet
			die unterschiedlichen Optionen an die in der Liste möglich sind.
			Und Returnt dann die Option ebenfalls wieder als char.
			
					
*/
			

#pragma once
#ifndef MENUE_H_
	#define MENUE_H_

	char MediaMenue (void);
	//Menü für die Auswahl des Genre
	//1: Bücher
	//2: CD's
	//3: DVD's
	//e: exit

	char ListMenue (void);
	//Menü für die Optionen der Listenanzeige
	//1: Suchen
	//2: Details
	//3: Hinzufügen
	//4: Ändern
	//5: Löschen
	//6: Sortieren
	//7: Genre Auswahl
	//99: zurück
	//e: exit

	char showDetailMenue (void);
	//Menü für die Optionen der Detailanzeige
	//1: Auswahl
	//2: Ändern
	//3: Löschen
	//99: Zurück zur Liste
	//e: exit

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

	//99: zurück
	//e: exit

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
	//99: zurück
	//e: exit

	char SearchMenue (void);
	//Menü für die Optionen der Suche
	//1: Titel
	//2: Autor
	//3: Verlag/Studio/Label
	//4: ISBN
	//5: Erscheinungsdatum
	//6: Schauspieler
	//99: zurück
	//e: exit

	char SearchMenueResult (void);
	//1: Suchen
	//2: Detail
	//3: Ändern
	//4: Löschen
	//5: Sortieren (Nur in der Suchdatei)
	//99: Zurück zur Liste (Suchdatei Löschen)
	//e: exit

#endif