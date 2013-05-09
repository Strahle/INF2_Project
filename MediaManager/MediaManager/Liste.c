#include "Liste.h"

static Node * ankerAnfang, * ankerEnde;
static Node * actualPos; //Hier ist das Aktuelle Element gespeichert

//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
//Gibt das erste Element der Knoten zur�ck
Node * initList ()
{
	int i;
	Node * myNode;
	for (i = 0; i < NUM_ELEMENTS_TO_LOAD; i++)
	{
		myNode = (Node*) malloc(sizeof(myNode)); //SPeicher holen
		//myNode = (Node*)loadFromFile("f0",myNode , 'A'); //TODO: FUnktionsaufruf richtig machen
		if(myNode == NULL) //Wenn ein Null Element zur�ckgegeben wird funktion beenden
		{
			return ankerAnfang;
		}
		if(ankerAnfang == NULL && ankerEnde == NULL) //Gilt nur f�r den ersten Knoten
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

//TODO: FUnktion die Anker Anfang zur�ck gibt

/*
	l�scht alle elemente in der liste
*/
void deinit()
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

/* TODO: Muss in Fileedit da neues element direkt an dateiende geschrieben wird und die liste danach neu gelesen wird
	- und erst nach reinit der liste in liste auftaucht
void addItem (char * Pfad, Details * Detail) //muss diese funktion nicht in FileEdit?
//Fr�gt alle Paramenter des neuem Items ab
//F�gt am Ende der Liste ein neues Element hinzu
//F�gt der Datei den neuen Datensatz hinzu
{

}
*/

/*
	L�scht das Element aus der Liste

*/
void deleteItem (Node * element)
{
	free(element);
	//TODO: Pointer von prev und next anpassen
	//In main muss zus�tzlich zu deleteItem auch deleteItemFromFile aufgerufen werden
}


/*
Fr�gt die zu suchenden Parameter ab
Sucht in der Datei nach den Parametern
Gibt den Knoten des Search ankers zur�ck

Node * searchItem (char * Pfad)
{
	Node * foundItem = NULL;
	return foundItem;
}
*/

/*

TODO: muss das nicht in file edit?

void changeItem (char * Pfad, Node * List)
{
	old = new;
}
*/


//Fr�gt den Wert nach dem Sortiert werden soll
//Sortiert die Datei nach den Kriterien TODO: muss diese funktion nicht auch in die datei?
/* TODO: Liste wird nur in der Datei sortiert
void sortList (char * Pfad)
{

}
*/