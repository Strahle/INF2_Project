// Hier muss noch der Header rein ToDO

#pragma once
#ifndef FILEEDIT_H_
	#define FILEEDIT_H_

	char saveToFile (char * Pfad, Knoten * List, Details * Detail);
	//Fügt der Datei einen neuen Datensatz hinzu

	Details * loadFromFile (char * Pfad, Knoten * List , char Option)
	//Lädt einen Datensatz aus der Datei

	char printListeToFile (char * Pfad, Knoten * List, char Option);
	//Speichert die aktuelle Liste in einer TXT Datei (Titel / Details)

	char sortFile (char * Pfad, Knoten * List, int Option);
	//Sortiert die akltuelle Liste nach dem Parameter

	Knoten * searchInFile (char * Pfad, Details * Detail);
	//Sucht in der Datei mit den angegebenen Parametern

#endif