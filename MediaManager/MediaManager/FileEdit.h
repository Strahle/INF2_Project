// Hier muss noch der Header rein ToDO

#pragma once

#ifndef FILEEDIT_H_
	#define FILEEDIT_H_

	#include "Liste.h"

	//initialisiert FileEdit (position = 0)
	void initFileEdit (void);

	//setzt filePath + �ffnet File
	void setFilePath (char * pfad);

	//File wird geschlossen (aktueller filePath)
	void closeFile (void);

	//File wird geschlossen, gel�scht + erneut ge�ffnet (aktueller filePath)
	void removeFile (void);

	//F�gt der Datei einen neuen Datensatz hinzu
	char saveToFile (Details * nodeDetails);

	//L�dt einen Datensatz aus der Datei
	Details * loadFromFile (void);

	//Speichert die aktuelle Liste in einer TXT Datei (Details)			medium = 1 -> Buch;	    = 2 -> CD;	  = 3 -> DVD 
	char printListeToFile (Node * List, char medium);
	
#endif