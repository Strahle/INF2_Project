// Hier muss noch der Header rein ToDO

#include "Liste.h"

#pragma once
#ifndef EINGABE_H_
	#define EINGABE_H_

	Details *  addItemInput (void);
	//Fr�gt die Werte f�r das neue Item ab
	//Gibt bei falscher Eingabe Fehlermeldungen zur�ck
	//Bei Abbruch oder krotischem Fehler wird NULL zur�ck gegeben

	Node *  deleteItemInput(Node * Knot);
	//Fr�gt ab welches Element gel�scht werden soll
	//Sicherheitsabfrage ob das Element wirklich gel�scht werden soll

	Details *  searchItemInput (void);
	//Fr�gt den/die Suchparameter ab

#endif