// Hier muss noch der Header rein ToDO

#pragma once
#ifndef AUSGABE_H_
	#define AUSGABE_H_

	void showGenere (void);
	//Zeigt eine Liste aller Genere an

	void showList (Knoten * Knot);
	//Zeigt eine Liste aller Titel an (auf einer Seite)

	void showDetail (char * Pfad , Knoten * List);
	//Zeigt eine Liste mit den Details eines Elementes an

#endif