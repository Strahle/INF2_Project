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
	#include <time.h>
	#include "..\MediaManager\Liste.h"
	#include "Cunit\CUnit.h"
	

	//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
	//Gibt das erste Element der Knoten zur�ck
	void testInitList (void);

	//Fr�gt alle Paramenter des neuem Items ab
	//F�gt am Ende der Liste ein neues Element hinzu
	// Hier muss noch der Header rein ToDO
	//F�gt der Datei den neuen Datensatz hinzu
	void testAddItem (void);

	//L�scht den Datensatz in der Datei
	//L�scht das Element aus der Liste
	void testDeleteItem (void);

	//Fr�gt die zu suchenden Parameter ab
	//Sucht in der Datei nach den Parametern
	//Speichert die Ergebnisse in einer Liste
	void testSearchItem (void);

	//Fr�gt das Element ab das ge�ndert weren soll
	//Fr�gt nach dem zu �ndernden Parameter/n
	//�ndert die Werte in der Datei
	void testChangeItem (void);


	//switchtes position of the nodes
	void testSwitchNodes();

	void testIntSortList(void);
	void testCharSortList(void);
	void testDoubleSortList(void);

#endif