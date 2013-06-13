#pragma once
#ifndef BLOCK_H_
	#define BLOCK_H_

char cMedia; //Speichervariable für das ausgewählte Medium

#include "Ausgabe.h"
#include "Eingabe.h"
#include "FileEdit.h"
#include "Liste.h"
#include "Menue.h"
#include "Tools.h"

//Initialisiert alle Funktionen
void init (void);

//Speichert die Liste in die Datei
char savelist (void);

//Lädt die Liste aus der Datei
char loadlist (void);

//Sortiert die Liste
char sort (void);

//Löscht ein Element
char del (void);

//Ändert einen Parameter in einem Element
char edit (void);

//Fügt ein Element hinzu
char add (void);

//Sucht nach einem Parameter
char search (void);

//Anzeige der Details + Menü
//Übergabe: Pointer mit den Details
//Bei Fehler: 0
char details (void);

//Frägt den Benutzer nach einem Element
//Bei Fehler: 0
char selectElement (void);

//Anzeige der Liste + Menü
char Liste (void);

//Anzeige der Medien
char Media (void);

//Löscht den Bildschirm
void clrscreen(void);

//Blättert 10 Elemente nach vorne
//Wenn das Ende erreicht ist wird versucht wieder 10 Elemente nach hinten zu Blättern
void vorBlaettern (void);

//Blättert 10 Elemente nach hinten
//Stopt wenn das Ende erreicht ist
void zurueckBlaettern (void);

//Gibt eine Fehlermeldung aus
void printError (char * Error);

#endif