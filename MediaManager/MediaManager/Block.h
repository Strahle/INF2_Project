#pragma once
#ifndef BLOCK_H_
	#define BLOCK_H_

char cMedia; //Speichervariable f�r das ausgew�hlte Medium

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

//L�dt die Liste aus der Datei
char loadlist (void);

//Sortiert die Liste
char sort (void);

//L�scht ein Element
char del (void);

//�ndert einen Parameter in einem Element
char edit (void);

//F�gt ein Element hinzu
char add (void);

//Sucht nach einem Parameter
char search (void);

//Anzeige der Details + Men�
//�bergabe: Pointer mit den Details
//Bei Fehler: 0
char details (void);

//Fr�gt den Benutzer nach einem Element
//Bei Fehler: 0
char selectElement (void);

//Anzeige der Liste + Men�
char Liste (void);

//Anzeige der Medien
char Media (void);

//L�scht den Bildschirm
void clrscreen(void);

//Bl�ttert 10 Elemente nach vorne
//Wenn das Ende erreicht ist wird versucht wieder 10 Elemente nach hinten zu Bl�ttern
void vorBlaettern (void);

//Bl�ttert 10 Elemente nach hinten
//Stopt wenn das Ende erreicht ist
void zurueckBlaettern (void);

//Gibt eine Fehlermeldung aus
void printError (char * Error);

#endif