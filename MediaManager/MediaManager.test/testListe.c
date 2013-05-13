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
		if(ankerEnde == NULL) //Pr�fen ob anker ende gesetzt ist , forschleife z�hlt r�ckw�rts!
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
//Gibt das erste Element der Knoten zur�ck
void testInitList (void);

//Fr�gt alle Paramenter des neuem Items ab
//F�gt am Ende der Liste ein neues Element hinzu
// Hier muss noch der Header rein ToDO
//F�gt der Datei den neuen Datensatz hinzu
void testAddItem (void);

//L�scht den Datensatz in der Datei
//L�scht das Element aus der Liste
void testDeleteItem (void);

//Fr�gt die zu suchenden Parameter ab
//Sucht in der Datei nach den Parametern
//Speichert die Ergebnisse in einer Liste
void testSearchItem (void);

//Fr�gt das Element ab das ge�ndert weren soll
//Fr�gt nach dem zu �ndernden Parameter/n
//�ndert die Werte in der Datei
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