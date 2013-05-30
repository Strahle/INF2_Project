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
	#define MAX_SEARCH_RESULT (30*3) //Sollte das Suchergebenis kleiner sein als diese Konstante wird das ergebnis im ram gespeichert
	#define TITLE_LENGTH (50+1)
	#define MAX_TEXT_LENGTH (1024+1)
	#define MAX_VERLAG_LENGTH (50+1)

	#include <stdlib.h>	

	typedef
		struct strNode {
			int pos;
			struct strNode * next;
			struct strNode * prev;
			struct strDetails * nodeDetails;
		} Node;

	typedef
		struct strDetails {
			unsigned int index;
			char titel[TITLE_LENGTH];
			char verlag[MAX_VERLAG_LENGTH];
			double isbn;
			time_t erscheinungsdatum;
			char genre;
			int pos;
			char text[MAX_TEXT_LENGTH];
		} Details;

		
	//Inits list with null
	Node * initList ();

	//F�gt am Ende der Liste ein neues Element hinzu
	//F�gt der Datei den neuen Datensatz hinzu
	Node * addItem (Details * nodeDetails);

	//L�scht den Datensatz in der Datei
	//L�scht das Element aus der Liste
	void deleteItem (Node * List);

	//Fr�gt die zu suchenden Parameter ab
	//Sucht in der Datei nach den Parametern
	//Speichert die Ergebnisse in einer Liste
	Node * searchItem (char * Pfad);

	//Fr�gt das Element ab das ge�ndert weren soll
	//Fr�gt nach dem zu �ndernden Parameter/n
	//�ndert die Werte in der Datei
	void changeItem (Node * nodeToChange, Details * newDetails);


	//switchtes position of the nodes
	void swapNodes(Node * node1 , Node * node2);

	int intSortList(Node * curNode);
	int charSortList(Node * curNode);
	int doubleSortList(Node * curNode);

	int bubbleSortList(Node * startNode);

	//Returns ankerAnfang
	Node * getAnkerAnfang();

#endif