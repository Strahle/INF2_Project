// Hier muss noch der Header rein ToDO

#include "Liste.h"

#pragma once
#ifndef AUSGABE_H_
	#define AUSGABE_H_

	//void showGenere (void); Hier sollte man sich nochmal Gedanken machen ????? ToDO
	//Zeigt eine Liste aller Genre an

	void showList (Node * Knot);
	//Zeigt eine Liste aller Titel an (auf einer Seite)

	void showDetail (char * Pfad , Node * List);
	//Zeigt eine Liste mit den Details eines Elementes an

#endif
