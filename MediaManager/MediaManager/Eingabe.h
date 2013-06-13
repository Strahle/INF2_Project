/*Header: Eingabe.h
 Eingabe.h beinhaltet alle Funktionen, die zum Einlesen von Werten ben�tigt werden. 
 ----------------------------------------------------------------------------
 -	Autor Benedikt Schrade													
 -	Bearbeitet: 9.06.2013													
 -	�nderungen:
				- addItemInput hinzugef�gt
				- addoneItemInput hinzugef�gt
				- deleteItemInput hinzugef�gt
				- searchItemInput hinzugef�gt
				- in Liste.h wurde dem struct Betails ein neuer char regisseur, der den Regisseur, den Interpreten oder den Autor enth�lt
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


//Die Funktion changeItem bekommt als �bergabewerte einen pointer auf Node, sowie einen char mit dem Index, einen char mit einem Suchparameter (1-7) und einen char mit dem Medium (1-3)
//Die Funktion �ndert einen Wert in dem ihr vorgegebenen Knot 
//Konten der Liste, Suchparameter, Media, Index
	Node * changeItemDetails (Node *, char, char , int);

//Die Funktion addItemInpt erstellt einen neuen struct Detais, sie ben�tigt als �bergabeparameter einen char mit dem Medium (1-3)
	Details *  addItemInput (char);
	//�bergabe Medium (char (1=Buch, 2=cd, 3=dvd)
	//Fr�gt die Werte f�r das neue Item ab
	//Gibt bei falscher Eingabe Fehlermeldungen zur�ck
	//Bei Abbruch oder kritischem Fehler wird NULL zur�ck gegeben

	//Fr�gt ab welches Element gel�scht werden soll
	//Sicherheitsabfrage ob das Element wirklich gel�scht werden soll
	Node *  deleteItemInput(Node * Knot, char);

	//�bergabe Medium (char (b=Buch, c=cd, d=dvd) und Suchparameter (1-7)
	//Fr�gt den/die Suchparameter ab
	Details *  searchItemInput (char, char);

	//Fr�gt ab welcher Index ausgew�hlt werden soll und gibt diesen zur�ck
	//R�ckgabe: Index
	//Bei Fehler oder keinem Ergenis: 0
	int askIndex (void);

	//Fr�gt einzelne Char Zeichen ab und gibt eine Integer Zahl zur�ck
	//R�ckgabe: Eingabe(Zahlen)
	//e: -1
	//v: -2
	//z: -3
	int askInput (void);
	
#endif