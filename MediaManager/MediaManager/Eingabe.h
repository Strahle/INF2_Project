// Hier muss noch der Header rein ToDO

#pragma once
#ifndef EINGABE_H_
	#define EINGABE_H_

	Details * Detail addItemInput (void);
	//Frägt die Werte für das neue Item ab
	//Gibt bei falscher Eingabe Fehlermeldungen zurück
	//Bei Abbruch oder krotischem Fehler wird NULL zurück gegeben

	Knoten * Knot deleteItemInput (Knoten * Knot);
	//Frägt ab welches Element gelöscht werden soll
	//Sicherheitsabfrage ob das Element wirklich gelöscht werden soll

	Details * Detail searchItem Input (void);
	//Frägt den/die Suchparameter ab

#endif