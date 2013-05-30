#include "testListe.h"

//This function checks all pointers in list for consistence
void testCheckListConsistence(Node * ankerAnfang)
{
	Node * myNode=ankerAnfang;
	CU_ASSERT_PTR_EQUAL(ankerAnfang->prev, NULL); //checks for first element
	CU_ASSERT_PTR_EQUAL(ankerAnfang->next->prev, ankerAnfang); //check for first element
	myNode = myNode->next; //nächste node
	do{
		CU_ASSERT_PTR_EQUAL(myNode , myNode->next->prev); //Zeiger des nächsten element richtig
		CU_ASSERT_PTR_EQUAL(myNode , myNode->prev->next); //Zeiger des vorherigen elemnts richtig
		myNode = myNode->next; //nächste node
	}
	while(myNode->next != NULL);
	CU_ASSERT_PTR_EQUAL(myNode->next , NULL); //checks last element
	CU_ASSERT_PTR_EQUAL(myNode->prev->next, NULL); //checks last element
}

//Get Random Details
Details * CreateRandomDetails(unsigned int seed)
{
	
	Details * myDetails = NULL;
	char cArrTitel[sizeof(myDetails->titel)];
	int i;
	srand(seed);
	//make random titel
	for (i = 0; i < sizeof(myDetails->titel)-2; i++)
	{
		cArrTitel[i] = (rand()%57) + 64;  //modul 62 + 64 matchs ascii signs from A to z
	}
	cArrTitel[sizeof(myDetails->titel)-1] = '\0';

	myDetails = (Details *) calloc(1,sizeof(Details));
	myDetails->pos = rand();
	myDetails->index = rand();
	strcpy_s(myDetails->titel,sizeof(myDetails->titel),cArrTitel);
	//strcpy_s(myDetails->genre,sizeof(myDetails->genre),"Horror");

	return myDetails;
}

//Init function for a list with n elements
//random pos = 0 : List by details.pos 1 to n
//random pos = 1 : List with random elements
Node * initListeWithNelements(int n, int randomPos)
{
	Node * myNode=NULL;
	Details * myDetails=NULL;
	srand(time(NULL));
	
	if(n <= 0) {
		return NULL;
	}
	
	for (;  n > 0; n--)
	{
		myDetails = CreateRandomDetails(n);
		myNode = addItem(myDetails);
		myNode->pos = n;
	}
	return getAnkerAnfang();
}


void debugOutput(Node * ankerAnfang)
{
	int i=1;
	Node * myNode = ankerAnfang;
	printf("\n====\n");
	while(myNode != NULL)
	{
		if(myNode != NULL && myNode->nodeDetails != NULL)
		{
			printf("%i:%i:%i: %s\n",i, myNode->pos, myNode->nodeDetails->index, myNode->nodeDetails->titel);
		}
		else
		{
			printf("%i:NULL:NULL\n",i);
		}
		myNode = myNode->next;
		i++;
	}
	printf("====\n");
}

//Small system test for list
void testListeSystem(void)
{
	Node * myNode;
	Details * test=NULL;
	test = (Details *) calloc(1,sizeof(Details));
	test->index = 256;
	initList();
	initListeWithNelements(10, 1); //generate list
	myNode = getAnkerAnfang();
	addItem(test);
	debugOutput(myNode);
	testCheckListConsistence(myNode);
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

//switchtes position of the nodes
void testSwitchNodes(void)
{
	
	Node * ankerAnfang=NULL;
	//CU_ASSERT_PTR_NOT_NULL_FATAL(ankerAnfang);	//Sicherstellen das Speicher alloziert wurde

	ankerAnfang = initListeWithNelements(4,0);

	swapNodes(ankerAnfang->next, ankerAnfang->next->next);
	debugOutput(ankerAnfang);
	testCheckListConsistence(getAnkerAnfang());
}

void testIntSortList(void)
{
	Node * ankerAnfang;
	
	ankerAnfang = initListeWithNelements(100,1); //ini liste with 4 elements
	debugOutput(ankerAnfang);
	bubbleSortList(ankerAnfang);
	debugOutput(ankerAnfang);
	getchar();

}
void testCharSortList(void)
{

}
void testDoubleSortList(void)
{


}