// Hier muss noch der Header rein ToDO

#include "Liste.h"

#pragma once
#ifndef FILEEDIT_H_
	#define FILEEDIT_H_

	char saveToFile (char * Pfad, Node * List, Details * Detail);
	//Fügt der Datei einen neuen Datensatz hinzu

	Details * loadFromFile (char * Pfad, Node * List , char Option);
	//Lädt einen Datensatz aus der Datei

	char printListeToFile (char * Pfad, Node * List, char Option);
	//Speichert die aktuelle Liste in einer TXT Datei (Titel / Details)

	char sortFile (char * Pfad, Node * List, int Option);
	//Sortiert die akltuelle Liste nach dem Parameter

	Node * searchInFile (char * Pfad, Details * Detail);
	//Sucht in der Datei mit den angegebenen Parametern

#endif