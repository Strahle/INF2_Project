// Hier muss noch der Header rein ToDO

#include "Liste.h"

#pragma once
#ifndef AUSGABE_H_
	#define AUSGABE_H_

	void showGenere (void);
	//Zeigt eine Liste aller Genere an

	void showList (Node * Knot);
	//Zeigt eine Liste aller Titel an (auf einer Seite)

	void showDetail (char * Pfad , Node * List);
	//Zeigt eine Liste mit den Details eines Elementes an

#endif