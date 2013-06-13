#include "Liste.h"

static Node * ankerAnfang=NULL, * ankerEnde=NULL;
static Node * actualPos; //Hier ist das Aktuelle Element gespeichert

Node * searchForIndex (Node * Knot, int Index)
{
	Node * Element;
	Element = getAnkerAnfang(Knot);
	while (Element != NULL)
	{
		if (Element -> nodeDetails -> index == Index)
		{
			return Element;
		}
		Element = Element -> next;
	}
	return NULL;
}

//löscht alle elemente in der liste
//Setzt anker Anfang/Ende auf Null;
void deinit(Node * delList)
{
	Node * nodeToDelete = delList;
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

//Initalisiert die Liste
//Dabei wird die Alte Liste gelöscht
Node * initList ()
{
	deinit(ankerAnfang);
	return NULL;
}

//Returns ankerAnfang of list
Node * getAnkerAnfang(Node * myNode)
{
	if(myNode != NULL)
	{
		while(myNode->prev != NULL)
		{
			myNode = myNode->prev;
		}
	}
	return myNode;
}

//Returns ankerEnde of list
Node * getAnkerEnde(Node * myNode)
{
	if(myNode != NULL)
	{
		while(myNode->next != NULL)
		{
			myNode = myNode->next;
		}
	}
	return myNode;
}

//Fügt am Ende der Liste ein neues Element hinzu
//By Success returns added node else null
Node * addItem (Details * strDetails)
{
	int i;
	Details * myDetails=NULL;
	Node * myNode;

	if(strDetails == NULL)
	{
		return NULL;
	}

	myNode = (Node*) calloc(1,sizeof(Node)); //SPeicher für node holen
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

//Fügt am Ende der Liste ein neues Element hinzu
//By Success returns added node else null
//After each search you have to clean memmory with deinit() function
//and a returned element form addItemSearchList
Node * addItemSearchList(Details * strDetails, Node * nodeFromCurrentList)
{
	int i;
	Details * myDetails=NULL;
	static Node * searchAnkerAnfang = NULL, * searchAnkerEnde = NULL;
	Node * myNode;
	
	//Return NULL if Someone Trys to add Null element
	if(strDetails == NULL)
	{
		return NULL;
	}

	myNode = (Node*) calloc(1,sizeof(Node)); //SPeicher für node holen
	myDetails = (Details*) calloc(1,sizeof(Details)); //speicher für details holen
	*myDetails = *strDetails;

	myNode->nodeDetails = myDetails;

	if(searchAnkerAnfang == NULL && searchAnkerEnde == NULL) //Gilt nur für den ersten Knoten
	{
		searchAnkerAnfang = myNode;
		searchAnkerEnde = myNode;

		myNode->next = NULL;
		myNode->prev = NULL;
	}
	else
	{
		searchAnkerEnde->next = myNode;	//aktuelles element in letztes elemnt speichern
		myNode->prev = searchAnkerEnde;	//letztes element in prev ablegen
		myNode->next = NULL; 
	}
	searchAnkerEnde = myNode;
	return searchAnkerEnde;
}

//Sucht nach Titel und gibt ankerAnfang der Neuen Liste zurück
Node * searchItem (Node * nNode, char * searchStr)
{
	Node * tmpAnkerAnfang, * tmpAnkerEnde, * myNode, * searchAnkerEnde = NULL;
	tmpAnkerAnfang = getAnkerAnfang(nNode);
	tmpAnkerEnde = getAnkerEnde(nNode);

	myNode = tmpAnkerAnfang;
	while(myNode != NULL)
	{
		if(strstr(myNode->nodeDetails->titel, searchStr) != NULL)
		{
			searchAnkerEnde = addItemSearchList(myNode->nodeDetails,myNode);
		}
		myNode = myNode->next;
	}

	return getAnkerAnfang(searchAnkerEnde);
}

//	Löscht das gegebene Element aus der Liste
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

//Ändert details einer Node
//Details will copied to nodeToChange
void changeItem (Node * nodeToChange, Details * newDetails)
{
	*nodeToChange->nodeDetails = *newDetails;
}

//switchtes position of the nodes
//sets node2 in position of node 1 and vise versa
//pointers off the sourrounding elements get changed
static void swapNodesRingBuffer(Node * node1 , Node * node2)
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
	node1->nodeDetails = tmpDetails2;
	node2->nodeDetails = tmpDetails1;
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
		while(curNode != tmpAnkerEnde)
		{
			if (compareFunction(curNode->nodeDetails , curNode->next->nodeDetails)) //compare elements
			{
				swapNodes(curNode, curNode->next); //swap element
				curNode = curNode->next; //Go to next element
			}
			else
			{
				curNode = curNode->next; //go to next element
			}
		}
		tmpAnkerEnde = curNode->prev; //set tmpAnkerEnde to last Moved Element so the list will be shorter

	}while(curNode->prev != NULL);
}

//Compare Functions for BubbleSort
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
		if ( a->titel[i] == b->titel[i] ) ; //do nothing
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
		if ( a->titel[i] == b->titel[i] ) ; //do nothing
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