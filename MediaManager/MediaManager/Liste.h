/*Header: Liste.h
 Hier sind alle Funktionen zum erzeugen der Listen Definiert.
 Beim erstellen der Liste wird nur der Titel geladen und nicht alle Informationen
 ----------------------------------------------------------------------------
 -	Autor: Ulf Schmelzer 													-
 -	Bearbeitet: 05.05.2013													-
 -	Änderungen:	siehe Repo.													-
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
	#include <string.h>

	//Node Struct for List
	typedef
		struct strNode {
			//int pos;
			struct strNode * next;
			struct strNode * prev;
			struct strDetails * nodeDetails;
		} Node;

	//Details Struct for List Elements
	typedef
		struct strDetails {
			unsigned int index;
			char titel[TITLE_LENGTH];
			char regisseur[TITLE_LENGTH];
			char verlag[MAX_VERLAG_LENGTH];
			double isbn;
			time_t erscheinungsdatum;
			char genre;
			int pos;
			char text[MAX_TEXT_LENGTH];
		} Details;

	//Inits list with null
	Node * initList ();

	//Sucht in der Liste nach einem Element mit dem entsprechenden Index
	//Übergabe: Knoten der Liste, suchender Index
	//Rückgabe: Gesuchter Knoten
	//Bei Fehler oder keinem Ergenis: NULL
	Node * searchForIndex (Node * Knot, int Index);
	
	//Returns ankerAnfang
	Node * getAnkerAnfang(Node * myNode);

	//Return ankerEnde
	Node * getAnkerEnde(Node * myNode);

	//Fügt am Ende der Liste ein neues Element hinzu
	Node * addItem (Details * nodeDetails);

	//Löscht das Element aus der Liste
	void deleteItem (Node * List);

	//Sucht in der Liste mit der Übergebenen Node nach 
	//Speichert die Ergebnisse in einer Liste
	Node * searchItem (Node * nNode, char * searchStr);

	//Frägt das Element ab das geändert weren soll
	//Frägt nach dem zu ändernden Parameter/n
	void changeItem (Node * nodeToChange, Details * newDetails);

	//switchtes position of the nodes
	void swapNodes(Node * node1 , Node * node2);

	//Bubblesort for List
	//Input: CompareFunction with Atribute Details and Return 
	//0	The element pointed by p1 goes before the element pointed by p2
	//>0	The element pointed by p1 goes after the element pointed by p2
	void bubbleSortList(int (*compareFunction) (Details *,Details *));

	//CompareFunctions for BubbleSortList

	//Sortieren nach Index aufsteigend
	int sortIndexAsc (Details * a, Details * b);
	//Sortieren nach Index absteigend
	int sortIndexDesc (Details * a, Details * b);
	//Sortieren nach Titel aufsteigend
	int sortTitelAsc (Details * a, Details * b);
	//Sortieren nach Titel absteigend
	int sortTitelDesc (Details * a, Details * b);
	//Sortieren nach Verlag aufsteigend
	int sortVerlagAsc (Details * a, Details * b);
	//Sortieren nach Verlag absteigend
	int sortVerlagDesc (Details * a, Details * b);
	//Sortieren nach Isbn aufsteigend
	int sortIsbnAsc (Details * a, Details * b);
	//Sortieren nach Isbn absteigend
	int sortIsbnDesc (Details * a, Details * b);
	//Sortieren nach Erscheinungsdatum aufsteigend
	int sortErscheinungsdatumAsc (Details * a, Details * b);
	//Sortieren nach Erscheinungsdatum absteigend
	int sortErscheinungsdatumDesc (Details * a, Details * b);
	//Sortieren nach Genere aufsteigend
	int sortGenereAsc (Details * a, Details * b);
	//Sortieren nach Genere absteigend
	int sortGenereDesc (Details * a, Details * b);
	//Sortieren nach Text aufsteigend
	int sortTextAsc (Details * a, Details * b);
	//Sortieren nach Text absteigend
	int sortTextDesc (Details * a, Details * b);
#endif