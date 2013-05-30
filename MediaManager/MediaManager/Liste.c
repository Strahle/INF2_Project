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
	/*switch (row)
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
	return -1;*/
}


//switchtes position of the nodes
//sets node2 in position of node 1 and vise versa
//pointers off the sourrounding elements get changed
void swapNodesRingBuffer(Node * node1 , Node * node2)
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

//switchtes position of the nodes
//sets node2 in position of node 1 and vise versa
//pointers off the sourrounding elements get changed
void swapNodes(Node * node1 , Node * node2)
{
	Details * tmpDetails1 = node1->nodeDetails; //Copys the node pointers
	Details * tmpDetails2 = node2->nodeDetails;	//copys the node pointers
	node1->nodeDetails = tmpDetails1;
	node2->nodeDetails = tmpDetails2;
}

//Sortieren nach Index aufsteigend
int sortIndexAsc (Details * a, Details * b)
{
	if ( a->index <  b->index ) return 0;
	if ( a->index >  b->index ) return 1;
	return 0;
}
//Sortieren nach Index absteigend
int sortIndexDesc (Details * a, Details * b)
{
	if ( a->index >  b->index ) return 0;
	if ( a->index <  b->index ) return 1;
	return 0;
}

//Sortieren nach Titel aufsteigend
int sortTitelAsc (Details * a, Details * b)
{
	int i;
	for (i = 0; i < sizeof(a->titel) ; i++)
	{
		if ( a->titel[i] <  b->titel[i] ) return 0;
		if ( a->titel[i] ==  b->titel[i] ) ; //do nothing
		if ( a->titel[i] >  b->titel[i] ) return 1;
	}
	return 0;
}
//Sortieren nach Titel absteigend
int sortTitelDesc (Details * a, Details * b)
{
	int i;
	for (i = 0; i < sizeof(a->titel) ; i++)
	{
		if ( a->titel[i] >  b->titel[i] ) return 0;
		if ( a->titel[i] ==  b->titel[i] ) ; //do nothing
		if ( a->titel[i] <  b->titel[i] ) return 1;
	}
	return 0;
}

//Sortieren nach Verlag aufsteigend
int sortVerlagAsc (Details * a, Details * b)
{
	int i;
	for (i = 0; i < sizeof(a->verlag) ; i++)
	{
		if ( a->verlag[i] <  b->verlag[i] ) return 0;
		if ( a->verlag[i] ==  b->verlag[i] ) ; //do nothing
		if ( a->verlag[i] >  b->verlag[i] ) return 1;
	}
	return 0;
}
//Sortieren nach Verlag absteigend
int sortVerlagDesc (Details * a, Details * b)
{
	int i;
	for (i = 0; i < sizeof(a->verlag) ; i++)
	{
		if ( a->verlag[i] >  b->verlag[i] ) return 0;
		if ( a->verlag[i] ==  b->verlag[i] ) ; //do nothing
		if ( a->verlag[i] <  b->verlag[i] ) return 1;
	}
	return 0;
}

//Sortieren nach Isbn aufsteigend
int sortIsbnAsc (Details * a, Details * b)
{
	if ( a->isbn <  b->isbn ) return 0;
	if ( a->isbn >  b->isbn ) return 1;
	return 0;
}
//Sortieren nach Isbn absteigend
int sortIsbnDesc (Details * a, Details * b)
{
	if ( a->isbn >  b->isbn ) return 0;
	if ( a->isbn <  b->isbn ) return 1;
	return 0;
}

//Sortieren nach Erscheinungsdatum aufsteigend
int sortErscheinungsdatumAsc (Details * a, Details * b)
{
	if ( a->erscheinungsdatum <  b->erscheinungsdatum ) return 0;
	if ( a->erscheinungsdatum >  b->erscheinungsdatum ) return 1;
	return 0;
}
//Sortieren nach Erscheinungsdatum absteigend
int sortErscheinungsdatumDesc (Details * a, Details * b)
{
	if ( a->erscheinungsdatum >  b->erscheinungsdatum ) return 0;
	if ( a->erscheinungsdatum <  b->erscheinungsdatum ) return 1;
	return 0;
}

//Sortieren nach Genere aufsteigend
int sortGenereAsc (Details * a, Details * b)
{
	if ( a->genre <  b->genre ) return 0;
	if ( a->genre >  b->genre ) return 1;
	return 0;
}
//Sortieren nach Genere absteigend
int sortGenereDesc (Details * a, Details * b)
{
	if ( a->genre >  b->genre ) return 0;
	if ( a->genre <  b->genre ) return 1;
	return 0;
}

//Sortieren nach Text aufsteigend
int sortTextAsc (Details * a, Details * b)
{
	int i;
	for (i = 0; i < sizeof(a->text) ; i++)
	{
		if ( a->text[i] <  b->text[i] ) return 0;
		if ( a->text[i] == b->text[i] ) ; //do nothing
		if ( a->text[i] >  b->text[i] ) return 1;
	}
	return 0;
}
//Sortieren nach Text absteigend
int sortTextDesc (Details * a, Details * b)
{
	int i;
	for (i = 0; i < sizeof(a->titel) ; i++)
	{
		if ( a->text[i] >  b->text[i] ) return 0;
		if ( a->text[i] == b->text[i] ) ; //do nothing
		if ( a->text[i] <  b->text[i] ) return 1;
	}
	return 0;
}

//Bubblesort for List
//Input: CompareFunction with Atribute Details and Return 
//0	The element pointed by p1 goes before the element pointed by p2
//>0	The element pointed by p1 goes after the element pointed by p2
void bubbleSortList(int (*compareFunction) (Details *,Details *))
{
	Node * tmpAnkerEnde=NULL, * curNode;
	tmpAnkerEnde = ankerEnde;

	do{ //restarts from beginning
		curNode = ankerAnfang;
		//Moves element to ende
		while(curNode != tmpAnkerEnde) //TODO Bug fix the last element is not sorted
		{
			if (compareFunction(curNode->nodeDetails , curNode->next->nodeDetails)) //compare elements
			{
				swapNodes(curNode, curNode->next); //swap element
				curNode = curNode->next;
			}
			else
			{
				curNode = curNode->next;
			}
		}
		tmpAnkerEnde = curNode->prev;

	}while(curNode->prev != NULL);
}
