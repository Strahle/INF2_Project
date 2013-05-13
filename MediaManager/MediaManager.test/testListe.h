/*Header: testListe.h
 
 contains all test functions for List.h
 ----------------------------------------------------------------------------
 -	Autor: Ulf Schmelzer 													-
 -	Bearbeitet: 09.05.2013													-
 -	Änderungen:	siehe Repo.													-
 ----------------------------------------------------------------------------



*/

#pragma once
#ifndef TESTLISTE_H_
#define TESTLISTE_H_

	#include <stdlib.h>
	#include <string.h>
	#include "..\MediaManager\Liste.h"
	#include "Cunit\CUnit.h"
	

	//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
	//Gibt das erste Element der Knoten zurück
	Node * testInitList (Node ** Pfad);

	//Frägt alle Paramenter des neuem Items ab
	//Fügt am Ende der Liste ein neues Element hinzu
	// Hier muss noch der Header rein ToDO
	//Fügt der Datei den neuen Datensatz hinzu
	void testAddItem (char * Pfad, Details * Detail);

	//Löscht den Datensatz in der Datei
	//Löscht das Element aus der Liste
	void testDeleteItem (char * Pfad, Node * List);

	//Frägt die zu suchenden Parameter ab
	//Sucht in der Datei nach den Parametern
	//Speichert die Ergebnisse in einer Liste
	Node * testSearchItem (char * Pfad);

	//Frägt das Element ab das geändert weren soll
	//Frägt nach dem zu ändernden Parameter/n
	//Ändert die Werte in der Datei
	void testChangeItem (char * Pfad, Node * List);


	//switchtes position of the nodes
	void testSwitchNodes();

	int testIntSortList(Node * curNode);
	int testCharSortList(Node * curNode);
	int testDoubleSortList(Node * curNode);

#endif