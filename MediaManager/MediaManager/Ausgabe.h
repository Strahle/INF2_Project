/*Header: Ausgabe.h
 Ausgabe.h beinhaltet die Funktionen showList und showDetail. Die erste Funkrion
 zeigt die Titel der Medien in einer Liste an und die Zweite zeigt die Detail 
 Infos an
  ----------------------------------------------------------------------------
 -	Autor Manuel Strehle													-
 -	Bearbeitet: 06.05.2013													-
 -	Änderungen:	03.06.2013	-- Beschreibungen Header													-
 ----------------------------------------------------------------------------
		showListe
				Diese Funktion bekommt die eine Element der Liste übergeben und stellt
				ab dieser Stelle 18 Titel in dem Platz zwischen Header und Footer
				dar.

		showDetail
				Diese Funktion bekommt die Deatils eines Medium übergeben und stellt
				diese dann auf dem noch verbleibenden Platz zwischen Header und Footer
				dar.


*/
#include "Liste.h"

#pragma once
#ifndef AUSGABE_H_
	#define AUSGABE_H_

	//void showGenere (void); Hier sollte man sich nochmal Gedanken machen ????? ToDO
	//Zeigt eine Liste aller Genre an

	void showList (Node * Knot);
	//Zeigt eine Liste aller Titel an (auf einer Seite Bereich Zeile 3-21)

	void showDetail (Details * List);
	//Zeigt eine Liste mit den Details eines Elementes an (Bereich 3-22)

#endif
