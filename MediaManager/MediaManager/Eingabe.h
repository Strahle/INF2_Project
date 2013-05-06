// Hier muss noch der Header rein ToDO

#include "Liste.h"

#pragma once
#ifndef EINGABE_H_
	#define EINGABE_H_

	Details *  addItemInput (void);
	//Frägt die Werte für das neue Item ab
	//Gibt bei falscher Eingabe Fehlermeldungen zurück
	//Bei Abbruch oder krotischem Fehler wird NULL zurück gegeben

	Node *  deleteItemInput(Node * Knot);
	//Frägt ab welches Element gelöscht werden soll
	//Sicherheitsabfrage ob das Element wirklich gelöscht werden soll

	Details *  searchItemInput (void);
	//Frägt den/die Suchparameter ab

#endif