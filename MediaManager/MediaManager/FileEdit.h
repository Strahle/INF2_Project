// Hier muss noch der Header rein ToDO

#pragma once

#ifndef FILEEDIT_H_
	#define FILEEDIT_H_

	#include "Liste.h"

	//Fügt der Datei einen neuen Datensatz hinzu
	char saveToFile (char * Pfad, Node * List, Details * Detail);

	//Lädt einen Datensatz aus der Datei
	Details * loadFromFile (char * Pfad, Node * List , char Option);

	//Speichert die aktuelle Liste in einer TXT Datei (Titel / Details)
	char printListeToFile (char * Pfad, Node * List, char Option);

	//Sortiert die akltuelle Liste nach dem Parameter
	char sortFile (char * Pfad, Node * List, int Option);
	
	//Sucht in der Datei mit den angegebenen Parametern
	Node * searchInFile (char * Pfad, Details * Detail);
	
#endif