// Hier muss noch der Header rein ToDO

#pragma once

#ifndef FILEEDIT_H_
	#define FILEEDIT_H_

	#include "Liste.h"

	//initialisiert FileEdit (position = 0)
	char initFileEdit (void);

	//setzt filePath + �ffnet File
	char setFilePath (char * pfad);

	//schlie�t File
	char closeFile (void);

	//schlie�t, l�scht und �ffnet file anschlie�end
	char removeFile (void);

	//F�gt der Datei einen neuen Datensatz hinzu
	char saveToFile (Details * nodeDetails);

	//L�dt einen Datensatz aus der Datei
	//gibt NULL zur�ck, wenn kein Element mehr vorhanden ist
	Details * loadFromFile ();

	//Speichert die aktuelle Liste in einer TXT Datei (Details)				medium: 1 = Buch;	2 = CD;	  3 = DVD 
	char printListeToFile (Node * List, char medium);
	
#endif