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
 - ToDo: - e: exit, 0 abbrechen 
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
//Konten der Liste, Suchparameter, Media, Index
	Node * changeItemDetails (Node *, char, char , int);

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
	Details *  searchItemInput (char, char);

	//Frägt ab welcher Index ausgewählt werden soll und gibt diesen zurück
	//Rückgabe: Index
	//Bei Fehler oder keinem Ergenis: 0
	int askIndex (void);

	//Frägt einzelne Char Zeichen ab und gibt eine Integer Zahl zurück
	//Rückgabe: Eingabe(Zahlen)
	//e: -1
	//v: -2
	//z: -3
	int askInput (void);
	
#endif