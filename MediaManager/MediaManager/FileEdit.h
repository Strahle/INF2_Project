// Hier muss noch der Header rein ToDO

#pragma once

#ifndef FILEEDIT_H_
	#define FILEEDIT_H_

	#include "Liste.h"

	//initialisiert FileEdit (position = 0)
	void initFileEdit ();

	//setzt filePath + öffnet File
	void setFilePath (char * pfad);

	//File wird geschlossen (aktueller filePath)
	void closeFile ();

	//File wird geschlossen, gelöscht + erneut geöffnet (aktueller filePath)
	void removeFile ();

	//Fügt der Datei einen neuen Datensatz hinzu
	char saveToFile (Details * nodeDetails);

	//Lädt einen Datensatz aus der Datei
	Details * loadFromFile ();

	//Speichert die aktuelle Liste in einer TXT Datei (Details)			medium = 1 -> Buch;	    = 2 -> CD;	  = 3 -> DVD 
	char printListeToFile (Node * List, char medium);
	
#endif