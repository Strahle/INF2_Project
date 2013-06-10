// Hier muss noch der Header rein ToDO

#pragma once

#ifndef FILEEDIT_H_
	#define FILEEDIT_H_

	#include "Liste.h"

	//initialisiert FileEdit (position = 0)
	char initFileEdit (void);

	//setzt filePath + öffnet File
	char setFilePath (char * pfad);

	//schließt File
	char closeFile (void);

	//schließt, löscht und öffnet file anschließend
	char removeFile (void);

	//Fügt der Datei einen neuen Datensatz hinzu
	char saveToFile (Details * nodeDetails);

	//Lädt einen Datensatz aus der Datei
	//gibt NULL zurück, wenn kein Element mehr vorhanden ist
	Details * loadFromFile ();

	//Speichert die aktuelle Liste in einer TXT Datei (Details)				medium: 1 = Buch;	2 = CD;	  3 = DVD 
	char printListeToFile (Node * List, char medium);
	
#endif