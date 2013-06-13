/*Header: Menue.h
 Menue.h beinhaltet alle Funktionen die zur Menuedarstellung ben�tigt werden.
 bei allen Funktionen gibt es die Optionen Zur�ck und Exit.
 Mit der Funktion zur�ck kommt man in die vorherige Maske und mit exit wird 
 das Programm an dieser Stelle beendet. 
 ----------------------------------------------------------------------------
 -	Autor Manuel Strehle													-
 -	Bearbeitet: 06.05.2013													-
 -	�nderungen:	03.06.2013	-- Beschreibungen Header													-
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

	//Men� f�r die Auswahl des Genre
	//1: B�cher
	//2: CD's
	//3: DVD's
	//e: Exit
	char MediaMenue (void);
	
	//Men� f�r die Optionen der Listenanzeige
	//0: Zur�ck zur Medienauswahl
	//1: Suchen
	//2: Details
	//3: Hinzuf�gen
	//4: �ndern
	//5: L�schen
	//6: Sortieren
	//v: vor
	//z: zur�ck
	//e: exit
	char ListMenue (char Medium);

	//Men� f�r die Optionen der Detailanzeige
	//0: Zur�ck zur Liste
	//1: Auswahl
	//2: �ndern
	//3: L�schen
	//e: exit
	char showDetailMenue (void );

	//Men� f�r die Optionen der Sortierfunktion // Ich muss als B�cherliste aussehen
	//0: Zur�ck zur Liste
	//
	//1: Titel abw�rts
	//2: Autor abw�rts
	//3: Verlag/Studio/Label abw�rts
	//4: ISBN abw�rts
	//5: Erscheinungsdatum abw�rts
	//6: Schauspieler abw�rts
	//
	//11: Titel aufw�rts
	//12: Autor aufw�rts
	//13: Verlag/Studio/Label aufw�rts
	//14: ISBN aufw�rts
	//15: Erscheinungsdatum aufw�rts
	//16: Schauspieler aufw�rts
	//
	//e: exit
	int SortMenue (char );

	//Men� f�r die Optionen zum �ndern
	//0: Zur�ck zur Liste
	//1: Titel
	//2: Autor
	//3: Verlag/Studio/Label
	//4: ISBN
	//5: Erscheinungsdatum
	//6: Schauspieler
	//7: Zusammenfassung
	//8: Genre
	//e: exit
	char ChangeMenue (void);

	//Men� f�r die Optionen der Suche
	//0: Zur�ck zur Liste
	//1: Titel
	//2: Autor
	//3: Verlag/Studio/Label
	//4: ISBN
	//5: Erscheinungsdatum
	//6: Schauspieler
	//e: exit
	char SearchMenue (void);
	
	//0: Zur�ck zur Liste
	//1: Suchen
	//2: Detail
	//3: �ndern
	//4: L�schen
	//5: Sortieren
	//v: vor
	//z: zur�ck
	//e: exit
	char SearchMenueResult (void);
	
#endif