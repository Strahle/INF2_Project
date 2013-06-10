#pragma once
#ifndef BLOCK_H_
	#define BLOCK_H_

#include "Ausgabe.h"
#include "Eingabe.h"
#include "FileEdit.h"
#include "Liste.h"
#include "Menue.h"
#include "Tools.h"

//Initialisiert alle Funktionen
void init (void);

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

//Löscht den Bildschirm
void clrscreen(void);



#endif