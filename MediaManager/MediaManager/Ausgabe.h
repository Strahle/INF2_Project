/*Header: Ausgabe.h
 Ausgabe.h beinhaltet die Funktionen showList und showDetail. Die erste Funkrion
 zeigt die Titel der Medien in einer Liste an und die Zweite zeigt die Detail 
 Infos an
  ----------------------------------------------------------------------------
 -	Autor Manuel Strehle													-
 -	Bearbeitet: 06.05.2013													-
 -	�nderungen:	03.06.2013	-- Beschreibungen Header													-
 ----------------------------------------------------------------------------
		showListe
				Diese Funktion bekommt die eine Element der Liste �bergeben und stellt
				ab dieser Stelle 18 Titel in dem Platz zwischen Header und Footer
				dar.

		showDetail
				Diese Funktion bekommt die Deatils eines Medium �bergeben und stellt
				diese dann auf dem noch verbleibenden Platz zwischen Header und Footer
				dar.


*/
#include "Liste.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Tools.h"



#pragma once
#ifndef AUSGABE_H_
	#define AUSGABE_H_

	char showList (Node * Knot);
	//Zeigt eine Liste aller Titel an (auf einer Seite Bereich Zeile 3-21)

	char showDetail (Details * List, char medium);
	//Zeigt eine Liste mit den Details eines Elementes an (Bereich 3-22)

#endif
