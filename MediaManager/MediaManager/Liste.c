#include "Liste.h"



static Node * ankerAnfang, * ankerEnde;
static Node * actualPos; //Hier ist das Aktuelle Element gespeichert

Node * initList (char * Pfad)
//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
//Gibt das erste Element der Knoten zurück
{
	int i;
	Node * myNode;
	for (i = 0; i < NUM_ELEMENTS_TO_LOAD; i++)
	{
		myNode = (Node*) malloc(sizeof(myNode)); //SPeicher holen
		//myNode = (Node*)loadFromFile("f0",myNode , 'A'); //TODO: FUnktionsaufruf richtig machen
		if(myNode == NULL) //Wenn ein Null Element zurückgegeben wird funktion beenden
		{
			return ankerAnfang;
		}
		if(ankerAnfang == NULL && ankerEnde == NULL) //Gilt nur für den ersten Knoten
		{
			ankerAnfang = myNode;
			ankerEnde = myNode;

			myNode->next = myNode;
			myNode->prev = myNode;
		}
		else
		{
			ankerEnde->next = myNode;	//aktuelles element in letztes elemnt speichern
			myNode->prev = ankerEnde;	//letztes element in prev ablegen

			myNode->next = ankerAnfang; //Das letzte Element next zeigt auf ankerAnfang
			ankerAnfang->prev = myNode; //Das letzte Element prec zeigt immer auf ankerEnde
		}
	}
	return ankerAnfang;
}

//TODO: FUnktion die Anker Anfang zurück gibt

void deinit(char * Pfad)
//löscht alle elemente in der liste
{
	Node * tmpNode;
	char * f0=NULL;
	do
	{
		tmpNode = ankerAnfang->next; //next als tmp speichern
		deleteItem(f0 , ankerAnfang);
		ankerAnfang = tmpNode;		//tmp wieder in anker anfang speichern
	}
	while(tmpNode != NULL);
	return;
}


void addItem (char * Pfad, Details * Detail) //muss diese funktion nicht in FileEdit?
//Frägt alle Paramenter des neuem Items ab
//Fügt am Ende der Liste ein neues Element hinzu
//Fügt der Datei den neuen Datensatz hinzu
{

}

void deleteItem (char * Pfad, Node * List)
//Löscht den Datensatz in der Datei
//Löscht das Element aus der Liste
{
	free(List);
}

Node * searchItem (char * Pfad)
//Frägt die zu suchenden Parameter ab
//Sucht in der Datei nach den Parametern
//Gibt den Knoten des Search ankers zurück
{
	Node * foundItem = NULL;
	return foundItem;
}

void changeItem (char * Pfad, Node * List)
//Frägt das Element ab das geändert weren soll
//Frägt nach dem zu ändernden Parameter/n
//Ändert die Werte in der Datei TODO: muss das nicht in file edit?
{

}

void sortList (char * Pfad)
//Frägt den Wert nach dem Sortiert werden soll
//Sortiert die Datei nach den Kriterien TODO: muss diese funktion nicht auch in die datei?
{

}