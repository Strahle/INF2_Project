#include "testListe.h"

//This function checks all pointers in list for consistence
void testCheckListConsistence(Node * ankerAnfang)
{
	Node * myNode=ankerAnfang;
	CU_ASSERT_PTR_EQUAL(ankerAnfang->prev, NULL); //checks for first element
	CU_ASSERT_PTR_EQUAL(ankerAnfang->next->prev, ankerAnfang); //check for first element
	myNode = myNode->next; //n�chste node
	do{
		CU_ASSERT_PTR_EQUAL(myNode , myNode->next->prev); //Zeiger des n�chsten element richtig
		CU_ASSERT_PTR_EQUAL(myNode , myNode->prev->next); //Zeiger des vorherigen elemnts richtig
		myNode = myNode->next; //n�chste node
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
		cArrTitel[i] = (rand()%26) + 64;  //modul 62 + 64 matchs ascii signs from A to z
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
	initList();
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
	return getAnkerAnfang(myNode);
}


void debugOutput(Node * ankerAnfang)
{
	int i=1;
	Node * myNode = getAnkerAnfang(ankerAnfang);
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
	myNode = initListeWithNelements(10, 1); //generate list
	myNode = getAnkerAnfang(myNode);
	addItem(test);
	debugOutput(myNode);
	testCheckListConsistence(myNode);
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
void testSearchItem (void)
{
	Node * ankerAnfang, * foundNodes;
	Details testDetails1, testDetails2, testDetails3;
	strcpy_s(testDetails1.titel,sizeof(testDetails1.titel),"Hallo Welt\0");
	strcpy_s(testDetails2.titel,sizeof(testDetails1.titel),"Hallo World\0");
	strcpy_s(testDetails3.titel,sizeof(testDetails1.titel),"Geht das auch noch?????????? Hallo?\0");
	testDetails1.index = 1337;
	testDetails1.index = 31337;
	testDetails1.index = 313373;
	ankerAnfang = initListeWithNelements(10,1); //ini liste with 4 elements
	addItem(&testDetails1);
	addItem(&testDetails2);
	addItem(&testDetails3);
	debugOutput(ankerAnfang);
	foundNodes = searchItem(ankerAnfang, "allo");
	CU_ASSERT_PTR_NOT_EQUAL_FATAL(foundNodes, NULL);
	debugOutput(foundNodes);

}

//Fr�gt das Element ab das ge�ndert weren soll
//Fr�gt nach dem zu �ndernden Parameter/n
//�ndert die Werte in der Datei
void testChangeItem (void);

//switchtes position of the nodes
void testSwitchNodes(void)
{

	Node * ankerAnfang=NULL;
	//CU_ASSERT_PTR_NOT_NULL_FATAL(ankerAnfang);	//Sicherstellen das Speicher alloziert wurde

	ankerAnfang = initListeWithNelements(4,0);

	swapNodes(ankerAnfang->next, ankerAnfang->next->next);
	debugOutput(ankerAnfang);
	testCheckListConsistence(getAnkerAnfang(ankerAnfang));
}

void testIntSortList(void)
{
	Node * ankerAnfang;
	
	ankerAnfang = initListeWithNelements(30000,1); //ini liste with 4 elements
	//debugOutput(ankerAnfang);
	bubbleSortList(sortTitelAsc);
	//debugOutput(ankerAnfang);
	getchar();
}
void testCharSortList(void)
{

}
void testDoubleSortList(void)
{


}
