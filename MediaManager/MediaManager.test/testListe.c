#include "testListe.h"


//Init function for a list with n elements
Node * initListeWithNelements(int n, int randomPos)
{
	Node * ankerAnfang=NULL, * ankerEnde=NULL;
	Node * myNode1=NULL , * myNodePrev=NULL, * myNodeNext=NULL;
	srand(time(NULL));
	for (;  n > 0; n--)
	{
		myNodeNext = myNode1;
		myNode1 = (Node*) malloc(sizeof(Node)); //SPeicher holen
		if(ankerEnde == NULL) //Prüfen ob anker ende gesetzt ist , forschleife zählt rückwärts!
		{
			ankerEnde = myNode1;
		}
		else
		{
			myNodeNext->prev = myNode1;
		}
		strncpy_s(myNode1->titel, 50, "Node X", 10);
		if(randomPos)
		{
			myNode1->pos = rand();
		}
		else
		{
			myNode1->pos = n;
		}

		myNode1->next = myNodeNext;
		myNode1->prev = NULL;
	}
	myNode1->prev = ankerEnde;
	ankerEnde->next = myNode1;
	return myNode1;
}
		
//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
//Gibt das erste Element der Knoten zurück
void testInitList (void);

//Frägt alle Paramenter des neuem Items ab
//Fügt am Ende der Liste ein neues Element hinzu
// Hier muss noch der Header rein ToDO
//Fügt der Datei den neuen Datensatz hinzu
void testAddItem (void);

//Löscht den Datensatz in der Datei
//Löscht das Element aus der Liste
void testDeleteItem (void);

//Frägt die zu suchenden Parameter ab
//Sucht in der Datei nach den Parametern
//Speichert die Ergebnisse in einer Liste
void testSearchItem (void);

//Frägt das Element ab das geändert weren soll
//Frägt nach dem zu ändernden Parameter/n
//Ändert die Werte in der Datei
void testChangeItem (void);


void debugOutput(Node * ankerAnfang)
{
	int i=1;
	Node * myNode = ankerAnfang;
	printf("\n====\n");
	do
	{
		printf("%i:%i: %s\n",i, myNode->pos, myNode->titel);
		myNode= myNode->next;
		i++;
	}
	while(ankerAnfang != myNode);
	printf("====\n");
}


//switchtes position of the nodes
void testSwitchNodes(void)
{
	
	Node * ankerAnfang=NULL;
	//CU_ASSERT_PTR_NOT_NULL_FATAL(ankerAnfang);	//Sicherstellen das Speicher alloziert wurde

	ankerAnfang = initListeWithNelements(4,0);

	switchNodes(ankerAnfang->next, ankerAnfang->next->next);
	debugOutput(ankerAnfang);

}

void testIntSortList(void)
{
	Node * ankerAnfang;
	
	ankerAnfang = initListeWithNelements(4,1); //ini liste with 4 elements

	intSortList(ankerAnfang);
	debugOutput(ankerAnfang);
	getchar();

}
void testCharSortList(void)
{

}
void testDoubleSortList(void)
{


}