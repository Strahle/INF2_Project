/*Header: Liste.h
 Hier sind alle Funktionen zum erzeugen der Listen Definiert.
 Beim erstellen der Liste wird nur der Titel geladen und nicht alle Informationen
 ----------------------------------------------------------------------------
 -	Autor: Ulf Schmelzer 													-
 -	Bearbeitet: 05.05.2013													-
 -	�nderungen:	siehe Repo.													-
 ----------------------------------------------------------------------------



*/
#pragma once

#ifndef LISTE_H_
	#define LISTE_H_
	#define NUM_ELEMENTS_TO_LOAD (30*3) //sollte ersetzt werden durch die Variable der Elemente pro Seite
	#define TITLE_LENGTH (50+1)

	#include <stdlib.h>
	//#include "FileEdit.h"
	typedef
		struct strNode {
			char Titel [TITLE_LENGTH];
			int Pos;
			struct strNode * next;
			struct strNode * prev;
		} Node;

	typedef
		struct strDetails {
			char Titel [TITLE_LENGTH];
			int Pos;
		} Details ;

	Node * initList (char * Pfad);
	//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
	//Gibt das erste Element der Knoten zur�ck

	void addItem (char * Pfad, Details * Detail);
	//Fr�gt alle Paramenter des neuem Items ab
	//F�gt am Ende der Liste ein neues Element hinzu
	// Hier muss noch der Header rein ToDO
	//F�gt der Datei den neuen Datensatz hinzu

	void deleteItem (char * Pfad, Node * List);
	//L�scht den Datensatz in der Datei
	//L�scht das Element aus der Liste

	Node * searchItem (char * Pfad);
	//Fr�gt die zu suchenden Parameter ab
	//Sucht in der Datei nach den Parametern
	//Speichert die Ergebnisse in einer Liste

	void changeItem (char * Pfad, Node * List);
	//Fr�gt das Element ab das ge�ndert weren soll
	//Fr�gt nach dem zu �ndernden Parameter/n
	//�ndert die Werte in der Datei

	void sortList (char * Pfad);
	//Fr�gt den Wert nach dem Sortiert werden soll
	//Sortiert die Datei nach den Kriterien

#endif