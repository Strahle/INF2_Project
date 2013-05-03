#define NAME_LEN (16+1)


#pragma once
#ifndef STUDLISTE_H_
#define STUDLISTE_H_
typedef struct student {
    char name[NAME_LEN];    /* Nachname,  Vorname */
    int id;		    /* Identit�t, Matr. Nr. */
} Student;

typedef struct studlist { 
    Student * p;            /* Zeiger auf Nutzlast */ 
    struct studlist * next; /* N�chster in Liste */
} StudList;


void list_Insert (
    StudList ** list,   /* Zu f�llende Liste */
    const char * name,  /* Name des Studenten */    
    const int id        /* Matr.Nr. */
);

Student *               /* Ret: Gefund. Student oder NULL */
list_SearchId(
    const StudList * l, /* Zu durchsuch. Liste */
    const int id        /* Ident., die gesucht wird */
);

void list_Print (const StudList * l, FILE * f);
Student * list_SearchIdRec (const StudList * l, const int id);
/* Ausgabe der Liste in Datei f */

#endif