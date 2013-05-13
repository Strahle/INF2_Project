#include "Liste.h"

static Node * ankerAnfang, * ankerEnde;
static Node * actualPos; //Hier ist das Aktuelle Element gespeichert

//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
//Gibt das erste Element der Knoten zurück
Node * initList ()
{
	int i;
	Node * myNode;
	for (i = 0; i < 2; i++)
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

/*
	löscht alle elemente in der liste
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
//Frägt alle Paramenter des neuem Items ab
//Fügt am Ende der Liste ein neues Element hinzu
//Fügt der Datei den neuen Datensatz hinzu
{

}
*/

/*
	Löscht das Element aus der Liste

*/
void deleteItem (Node * element)
{
	free(element);
	//TODO: Pointer von prev und next anpassen
	//In main muss zusätzlich zu deleteItem auch deleteItemFromFile aufgerufen werden
}


/*
Frägt die zu suchenden Parameter ab
Sucht in der Datei nach den Parametern
Gibt den Knoten des Search ankers zurück

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

/*
Frägt den Wert nach dem Sortiert werden soll
Sortiert die Datei nach den Kriterien
	0		unsigned int index;
	1		char titel[TITLE_LENGTH];
	2		char verlag[MAX_VERLAG_LENGTH];
	3		double isbn;
	4		time_t erscheinungsdatum;
	5		char genre;
	6		int pos;
*/
int sortList(Node * startNode, char row)
{
	switch (row)
	{
		case 0:
			return intSortList(startNode);
		case 1:
			return charSortList(startNode);
		case 2:
			return charSortList(startNode);
		case 3:
			return doubleSortList(startNode);
		case 4:
			return intSortList(startNode);
		case 5:
			return charSortList(startNode);
		case 6:
			return intSortList(startNode);
		default:
			break;
	}
	return -1;
}

/*
sortier Algorythmus für ints
*/
static int intSortList(Node * curNode)
{
	Node * ankerAnfang_ = curNode;
	Node * ankerEnde_ = curNode->prev;

	do
	{
		if(curNode->details->index <= curNode->prev->details->index) //nichts tuen und ein element weiter schalten
		{
			curNode = curNode->next;
		}
		else //elemente tauschen
		{
			switchNodes(curNode , curNode->next);

		}
	}
	while(curNode != ankerAnfang_);
}


//switchtes position of the nodes
void switchNodes(Node * node1 , Node * node2)
{
	Node tmpNode1 = *node1;
	Node tmpNode2 = *node2;

	if(node2->next == node1)
	{

		node2->prev->next = node1;
		//node2->next->prev = node1;
		node2->prev = node1;
		node2->next = tmpNode1.next;

		//node1->prev->next = node2;
		node1->next->prev = node2;
		node1->prev = tmpNode2.prev;	
		node1->next = node2;

		return;
	}
	else if(node1 == node2->prev)
	{
		//edit node1 to pars of node2
		node1->prev->next = node2;
		node1->prev = node2;
		node1->prev = node2;
		node1->next = node2->next;

		//edot node2 to pars of node1
		node2->next = node1;
		node2->next->prev = node1;
		node2->prev = tmpNode1.prev;
		node2->next = node1;
		return;
	}
	else
	{
		node1->prev->next = node2;
		node1->next->prev = node2;
		node1->prev = node2->prev;	
		node1->next = node2->next;

		node2->prev->next = node1;
		node2->next->prev = node1;
		node2->prev = tmpNode1.prev;
		node2->next = tmpNode1.next;	
		return;
	}
}


int charSortList(Node * curNode)
{
	return 1;
}


int doubleSortList(Node * curNode)
{
	return 1;
}