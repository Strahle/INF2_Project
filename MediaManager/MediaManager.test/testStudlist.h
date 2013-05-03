#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "studlist.h"

#define SEARCH_ID_GROSE_LISTE_1 1337 //sollte an pos 0 stehen
#define SEARCH_ID_GROSE_LISTE_2 1338 //sollte an pos 25 stehen
#define SEARCH_ID_GROSE_LISTE_3 1339 // sollte an pos 52 stehen

#define SEARCH_ID_KURZE_LISTE_1 1337 //sollte an pos 3 stehen

#define SEARCH_ID_LEERE_LISTE_1 1337 //sollte an pos 0 stehen

static StudList * l = NULL , * leereListe = NULL, * kurzeListe = NULL, * groseListe = NULL;



void test_kurze_list_searchId(void);
void test_grose_list_searchId(void);
void test_leere_list_searchId(void);