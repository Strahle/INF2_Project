/*Header: testListe.h
 
 contains all test functions for List.h
 ----------------------------------------------------------------------------
 -	Autor: Ulf Schmelzer 													-
 -	Bearbeitet: 09.05.2013													-
 -	�nderungen:	siehe Repo.													-
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
	//Gibt das erste Element der Knoten zur�ck
	Node * testInitList (Node ** Pfad);

	//Fr�gt alle Paramenter des neuem Items ab
	//F�gt am Ende der Liste ein neues Element hinzu
	// Hier muss noch der Header rein ToDO
	//F�gt der Datei den neuen Datensatz hinzu
	void testAddItem (char * Pfad, Details * Detail);

	//L�scht den Datensatz in der Datei
	//L�scht das Element aus der Liste
	void testDeleteItem (char * Pfad, Node * List);

	//Fr�gt die zu suchenden Parameter ab
	//Sucht in der Datei nach den Parametern
	//Speichert die Ergebnisse in einer Liste
	Node * testSearchItem (char * Pfad);

	//Fr�gt das Element ab das ge�ndert weren soll
	//Fr�gt nach dem zu �ndernden Parameter/n
	//�ndert die Werte in der Datei
	void testChangeItem (char * Pfad, Node * List);


	//switchtes position of the nodes
	void testSwitchNodes();

	int testIntSortList(Node * curNode);
	int testCharSortList(Node * curNode);
	int testDoubleSortList(Node * curNode);

#endif