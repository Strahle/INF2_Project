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
 - ToDo: 
				-addouneItemInput zu changeItem �ndern
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


//Die Funktion changeItem bekommt als �bergabewerte einen pointer auf Node, sowie einen char mit dem Index, einen char mit einem Suchparameter (1-7) und einen char mit dem Medium (1-3)
//Die Funktion �ndert einen Wert in dem ihr vorgegebenen Knot 
	Details * changeItem (Node *, char, char , char );

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
	Details *  searchItemInput (char);


#endif