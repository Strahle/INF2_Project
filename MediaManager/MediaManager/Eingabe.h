/*Header: Eingabe.h
 Eingabe.h beinhaltet alle Funktionen, die zum Einlesen von Werten benötigt werden. 
 ----------------------------------------------------------------------------
 -	Autor Benedikt Schrade													
 -	Bearbeitet: 9.06.2013													
 -	Änderungen:
				- addItemInput hinzugefügt
				- addoneItemInput hinzugefügt
				- deleteItemInput hinzugefügt
				- searchItemInput hinzugefügt
				- in Liste.h wurde dem struct Betails ein neuer char regisseur, der den Regisseur, den Interpreten oder den Autor enthält
 - ToDo: 
				- Verknüpfung exit und back müssen noch an den vorgegebenen Stellen eingefügt werden
				- deleteItemInput muss richtig eingebunden werden
				- Kopf muss noch eingefügt werden

 ----------------------------------------------------------------------------
*/			
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "Liste.h"
#include "Menue.h"

#pragma once
#ifndef EINGABE_H_
	#define EINGABE_H_

	Details * addoneItemInput (char , char );

	Details *  addItemInput (char);
	//Frägt die Werte für das neue Item ab
	//Gibt bei falscher Eingabe Fehlermeldungen zurück
	//Bei Abbruch oder kritischem Fehler wird NULL zurück gegeben

	Node *  deleteItemInput(Node * Knot, char);
	//Frägt ab welches Element gelöscht werden soll
	//Sicherheitsabfrage ob das Element wirklich gelöscht werden soll

	Details *  searchItemInput (char);
	//Frägt den/die Suchparameter ab

#endif