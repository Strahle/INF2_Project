// Hier muss noch der Header rein ToDO

#pragma once

#ifndef FILEEDIT_H_
	#define FILEEDIT_H_

	#include "Liste.h"

	//Gibt FilePath zurück
	void setFilePath(char * pfad);

	//Fügt der Datei einen neuen Datensatz hinzu
	char saveToFile (Node * List, Details * nodeDetails);

	//Lädt einen Datensatz aus der Datei
	Details * loadFromFile (Node * List , char Option);

	//Speichert die aktuelle Liste in einer TXT Datei (Titel / Details)
	char printListeToFile (Node * List, char Option);

	//Sortiert die akltuelle Liste nach dem Parameter
	char sortFile (Node * List, int Option);
	
	//Sucht in der Datei mit den angegebenen Parametern
	Node * searchInFile (Details * Detail);
	
#endif