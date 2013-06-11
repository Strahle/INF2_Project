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
				-addouneItemInput zu changeItem ändern
				-Details * changeItem (Node * Knot, char, char, char)
				-Listenknoten, Index, Suchparameter, Medium
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


//Die Funktion changeItem bekommt als Übergabewerte einen pointer auf Node, sowie einen char mit dem Index, einen char mit einem Suchparameter (1-7) und einen char mit dem Medium (1-3)
//Die Funktion ändert einen Wert in dem ihr vorgegebenen Knot 
	Details * changeItem (Node *, char, char , char );

//Die Funktion addItemInpt erstellt einen neuen struct Detais, sie benötigt als Übergabeparameter einen char mit dem Medium (1-3)
	Details *  addItemInput (char);
	//Übergabe Medium (char (1=Buch, 2=cd, 3=dvd)
	//Frägt die Werte für das neue Item ab
	//Gibt bei falscher Eingabe Fehlermeldungen zurück
	//Bei Abbruch oder kritischem Fehler wird NULL zurück gegeben

	//Frägt ab welches Element gelöscht werden soll
	//Sicherheitsabfrage ob das Element wirklich gelöscht werden soll
	Node *  deleteItemInput(Node * Knot, char);

	//Übergabe Medium (char (b=Buch, c=cd, d=dvd) und Suchparameter (1-7)
	//Frägt den/die Suchparameter ab
	Details *  searchItemInput (char);


#endif