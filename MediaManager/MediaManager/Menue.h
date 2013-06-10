/*Header: Menue.h
 Menue.h beinhaltet alle Funktionen die zur Menuedarstellung benötigt werden.
 bei allen Funktionen gibt es die Optionen Zurück und Exit.
 Mit der Funktion zurück kommt man in die vorherige Maske und mit exit wird 
 das Programm an dieser Stelle beendet. 
 ----------------------------------------------------------------------------
 -	Autor Manuel Strehle													-
 -	Bearbeitet: 06.05.2013													-
 -	Änderungen:	03.06.2013	-- Beschreibungen Header													-
 ----------------------------------------------------------------------------
		MediaMenue
			Diese Funktion erzeugt Links oben den Programm Namen und am unteren 
			Rand die passenden Auswahloptionen und erzeugt den Abfrage Text.
			Sie ruft desweiteren die Funktion Footer auf um die Sonderfunktionen 
			zu erhalten.

		ListMenue
			Diese Funktion erzeugt in der 2. Zeile mittig den Menuenamen und am 
			unteren Rand Rand die passenden Auswahloptionen. 
			Sie ruft desweiteren die Funktion Footer auf um die 
			Sonderfunktionen zu erhalten. 
			
		showDetailMenue
			Diese Funktion erzeugt in der 2. Zeile mittig den Menuenamen und am 
			unteren Rand Rand die passenden Auswahloptionen. 
			Sie ruft desweiteren die Funktion Footer auf um die Sonderfunktionen 
			zu erhalten. 

		sortMenue
			Diese Funktion erzeugt in der 2. Zeile mittig den Menuenamen und am 
			unteren Rand Rand die passenden Auswahloptionen. 
			Sie ruft desweiteren die Funktion Footer auf um die Sonderfunktionen 
			zu erhalten.

		changeMenue
			Diese Funktion erzeugt in der 2. Zeile mittig den Menuenamen und am 
			unteren Rand Rand die passenden Auswahloptionen. 
			Sie ruft desweiteren die Funktion Footer auf um die Sonderfunktionen 
			zu erhalten. 

		SearchMenue
			Diese Funktion erzeugt in der 2. Zeile mittig den Menuenamen und am 
			unteren Rand Rand die passenden Auswahloptionen. 
			Sie ruft desweiteren die Funktion Footer auf um die Sonderfunktionen 
			zu erhalten. 

		SearchMenueResult
			Diese Funktion erzeugt in der 2. Zeile mittig den Menuenamen und am 
			unteren Rand Rand die passenden Auswahloptionen. 
			Sie ruft desweiteren die Funktion Footer auf um die 
			Sonderfunktionen zu erhalten.

*/
	
#include <stdlib.h>
#include <stdio.h>
#include "Tools.h"


#pragma once
#ifndef MENUE_H_
	#define MENUE_H_
	
	#define standBackground (0)
	#define menueBackground (7) 
	#define fehlerBackground (0) 
	#define sonderBackground (7) 
	#define standFond (15) 
	#define menueFond (1) 
	#define fehlerFond (12) 
	#define sonderFond (9) 

	char MediaMenue (void);
	//Menü für die Auswahl des Genre
	//1: Bücher
	//2: CD's
	//3: DVD's

	char ListMenue (void );
	//Menü für die Optionen der Listenanzeige
	//1: Suchen
	//2: Details
	//3: Hinzufügen
	//4: Ändern
	//5: Löschen
	//6: Sortieren
	//7: Media Auswahl
	//88: vor
	//99: zurück
	//e: exit

	char showDetailMenue (void );
	//Menü für die Optionen der Detailanzeige
	//1: Auswahl
	//2: Ändern
	//3: Löschen
	//99: Zurück zur Liste
	//e: exit

	int SortMenue (void);
	//Menü für die Optionen der Sortierfunktion // Ich muss als Bücherliste aussehen
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
	//88: vor
	//99: Zurück zur Liste (Suchdatei Löschen)
	//e: exit

#endif