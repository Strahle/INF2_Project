#pragma once
#ifndef BLOCK_H_
	#define BLOCK_H_

#include "Ausgabe.h"
#include "Eingabe.h"
#include "FileEdit.h"
#include "Liste.h"
#include "Menue.h"

//Initialisiert alle Funktionen
void init (void);

// Diese Funktion ermöglicht es durch übergabe der x und y Postion den Cursor 
// auf eine beliebeige Stelle der Console zu setzen
char gotoxy(int xpos, int ypos);

char savelist (void);

char loadlist (void);

char back (void);

char sort (void);

char del (void);

char edit (void);

char add (void);

char search (void);

//Frägt die Menüeingabe ab
char askInput (void);

char details (void);

char Liste (void);

char Media (void);



#endif