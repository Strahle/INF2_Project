#include "Liste.h"

static Node * ankerAnfang=NULL, * ankerEnde=NULL;
static Node * actualPos; //Hier ist das Aktuelle Element gespeichert

/*
	löscht alle elemente in der liste
*/
void deinit()
{
	Node * nodeToDelete;
	while(ankerAnfang != NULL)
	{
		nodeToDelete = ankerAnfang; //next als tmp speichern
		if(ankerAnfang->next != NULL)
		{
			ankerAnfang = ankerAnfang->next;
		}
		deleteItem(nodeToDelete);
	}
	ankerAnfang = NULL;
	ankerEnde = NULL;
}

//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
//Gibt das erste Element der Knoten zurück
Node * initList ()
{
	deinit();
	//int i;
	//Node * myNode;
	//for (i = 0; i < 2; i++)
	//{
	//	myNode = (Node*) malloc(sizeof(myNode)); //SPeicher holen
	//	//myNode = (Node*)loadFromFile("f0",myNode , 'A'); //TODO: FUnktionsaufruf richtig machen
	//	if(myNode == NULL) //Wenn ein Null Element zurückgegeben wird funktion beenden
	//	{
	//		return ankerAnfang;
	//	}
	//	if(ankerAnfang == NULL && ankerEnde == NULL) //Gilt nur für den ersten Knoten
	//	{
	//		ankerAnfang = myNode;
	//		ankerEnde = myNode;

	//		myNode->next = myNode;
	//		myNode->prev = myNode;
	//	}
	//	else
	//	{
	//		ankerEnde->next = myNode;	//aktuelles element in letztes elemnt speichern
	//		myNode->prev = ankerEnde;	//letztes element in prev ablegen

	//		myNode->next = ankerAnfang; //Das letzte Element next zeigt auf ankerAnfang
	//		ankerAnfang->prev = myNode; //Das letzte Element prec zeigt immer auf ankerEnde
	//	}
	//}
	return NULL;
}


//Returns anker anfang of list
Node * getAnkerAnfang()
{
	return ankerAnfang;
}

//Returns anker ende of list
Node * getAnkerEnde()
{
	return ankerEnde;
}

//Frägt alle Paramenter des neuem Items ab
//Fügt am Ende der Liste ein neues Element hinzu
//Fügt der Datei den neuen Datensatz hinzu
//returns added node else null
Node * addItem (Details * strDetails)
{
	int i;
	Details * myDetails=NULL;
	Node * myNode;

	if(strDetails == NULL)
	{
		return NULL;
	}

	myNode = (Node*) malloc(sizeof(Node)); //SPeicher für node holen
	myDetails = (Details*) calloc(1,sizeof(Details)); //speicher für details holen
	*myDetails = *strDetails;

	myNode->nodeDetails = myDetails;

	if(ankerAnfang == NULL && ankerEnde == NULL) //Gilt nur für den ersten Knoten
	{
		ankerAnfang = myNode;
		ankerEnde = myNode;

		myNode->next = NULL;
		myNode->prev = NULL;
	}
	else
	{
		ankerEnde->next = myNode;	//aktuelles element in letztes elemnt speichern
		myNode->prev = ankerEnde;	//letztes element in prev ablegen
		myNode->next = NULL; 
	}
	ankerEnde = myNode;
	return ankerEnde;
}


/*
	Löscht das gegebene Element aus der Liste
*/
void deleteItem (Node * element)
{
	if(element == NULL)
	{
		return;
	}
	if(element == ankerAnfang) //wenn anker anfang gelöscht wird muss ankeranfang next neuer ankfer anfang sein
	{
		ankerAnfang = element->next;
		if(element->next == NULL)
		{
			ankerAnfang = NULL;
			ankerEnde = NULL;
		}
		else
		{
			element->next->prev = NULL;
		}
	}
	else if(element == ankerEnde)
	{
		ankerEnde = element->prev;
		element->prev->next = NULL;
	}
	else
	{
		if(element->prev != NULL)
		{
			element->prev->next = element->next;
		}
		if(element->next != NULL)
		{
			element->next->prev = element->prev;
		}
	}
	free(element->nodeDetails);
	free(element);
}

//pointer1 = pointer2
//prüfen ob pt1 NULL ist wenn ja nichts tuen
void setPointerToPointer(void * pt1, void * pt2)
{
	if(pt1 == NULL)
	{
		pt1 = NULL;
	}
	else
	{
		pt1 = pt2;
	}
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
*	Ändert details einer Node
*	Details will copied to nodeToChange
*/
void changeItem (Node * nodeToChange, Details * newDetails)
{
	*nodeToChange->nodeDetails = *newDetails;
}


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
int intSortList(Node * curNode)
{
	while(curNode != NULL && curNode->next != NULL)
	{
		if(curNode->pos >= curNode->next->pos) //nichts tuen und ein element weiter schalten
		{
			curNode = curNode->next;
		}
		else //elemente tauschen
		{
			switchNodes(curNode , curNode->next);
			curNode = ankerAnfang;
		}
	}
}

//switchtes position of the nodes
//sets node2 in position of node 1 and vise versa
//pointers off the sourrounding elements get changed
void switchNodes(Node * node1 , Node * node2)
{
	Node tmpNode1 = *node1; //Copys the node pointers
	Node tmpNode2 = *node2;	//copys the node pointers

	if(node2->next == node1) //if node 2 is after node 1
	{
		//mod for node 2
		node2->prev->next = node1;
		node2->prev = node1;
		node2->next = tmpNode1.next;

		//mod for node 1
		node1->next->prev = node2;
		node1->prev = tmpNode2.prev;	
		node1->next = node2;

		return;
	}
	else if(node1 == node2->prev) //if node 2 is befor node 1
	{
		//edit node1 to pars of node2
		node1->prev->next = node2;
		node1->prev = node2;
		node1->next = node2->next;

		//edot node2 to pars of node1
		node2->next->prev = node1;
		node2->next = node1;
		node2->prev = tmpNode1.prev;
		return;
	}
	else //if node 2 or node 1 are more than 1 node away
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

//quicksort for lists
int listQuicksort(Node * startNode)
{
	int i=0; //num of elements
	Node * tmpAnkerAnfang , * tmpAnkerEnde;
	//find beginning and end of list
		tmpAnkerAnfang = startNode->prev;
		tmpAnkerEnde = startNode->next;
		while(tmpAnkerAnfang != NULL)
		{
			tmpAnkerAnfang = tmpAnkerAnfang->prev;
			i++;
		}
		while(tmpAnkerEnde != NULL)
		{
			tmpAnkerEnde = tmpAnkerEnde->next;
			i++;
		}
	

	



}

//
int listQuicksortSelectPivot(Node * ankerAnfang)
{

}