#include "testListe.h"

		
//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
//Gibt das erste Element der Knoten zurück
Node * testInitList (Node ** Pfad);

//Frägt alle Paramenter des neuem Items ab
//Fügt am Ende der Liste ein neues Element hinzu
// Hier muss noch der Header rein ToDO
//Fügt der Datei den neuen Datensatz hinzu
void testAddItem (char * Pfad, Details * Detail);

//Löscht den Datensatz in der Datei
//Löscht das Element aus der Liste
void testDeleteItem (char * Pfad, Node * List);

//Frägt die zu suchenden Parameter ab
//Sucht in der Datei nach den Parametern
//Speichert die Ergebnisse in einer Liste
Node * testSearchItem (char * Pfad);

//Frägt das Element ab das geändert weren soll
//Frägt nach dem zu ändernden Parameter/n
//Ändert die Werte in der Datei
void testChangeItem (char * Pfad, Node * List);


//switchtes position of the nodes
void testSwitchNodes(void)
{
	Node * ankerAnfang, * ankerEnde;
	int i;
	Node * myNode1 , * myNode2, * myNode3, * myNode4;

	myNode1 = (Node*) malloc(sizeof(Node)); //SPeicher holen
	myNode2 = (Node*) malloc(sizeof(Node)); //SPeicher holen
	myNode3 = (Node*) malloc(sizeof(Node)); //SPeicher holen
	myNode4 = (Node*) malloc(sizeof(Node)); //SPeicher holen
	//CU_ASSERT_PTR_NOT_NULL_FATAL(myNode1);	//Sicherstellen das Speicher alloziert wurde
	//CU_ASSERT_PTR_NOT_NULL_FATAL(myNode2);	//Sicherstellen das Speicher alloziert wurde
	//CU_ASSERT_PTR_NOT_NULL_FATAL(myNode3);	//Sicherstellen das Speicher alloziert wurde

	strncpy_s(myNode1->titel, 50, "Node 1", 10);
	strncpy_s(myNode2->titel, 50, "Node 2", 10);
	strncpy_s(myNode3->titel, 50, "Node 3", 10);
	strncpy_s(myNode4->titel, 50, "Node 4", 10);
	//CU_ASSERT_STRING_EQUAL_FATAL(myNode1->titel , "Node 1");
	//CU_ASSERT_STRING_EQUAL_FATAL(myNode2->titel , "Node 2");
	//CU_ASSERT_STRING_EQUAL_FATAL(myNode2->titel , "Node 3");

	ankerAnfang = myNode1;

	myNode1->pos = 1;
	myNode2->pos = 2;
	myNode3->pos = 3;
	myNode4->pos = 4;

		
	myNode1->next = myNode2;
	myNode1->prev = myNode4;

	myNode2->next = myNode3;
	myNode2->prev = myNode1;

	myNode3->next = myNode4;
	myNode3->prev = myNode2;

	myNode4->next = myNode1;
	myNode4->prev = myNode3;

	switchNodes(myNode1, myNode2);
	switchNodes(myNode3, myNode4);
	
	//printf("ankerAnfang->prev %i: %s\n", ankerAnfang->prev->pos, ankerAnfang->prev->titel);
	printf("1:%i: %s\n", ankerAnfang->pos, ankerAnfang->titel);
	printf("2:%i: %s\n", ankerAnfang->next->pos, ankerAnfang->next->titel);
	printf("3:%i: %s\n", ankerAnfang->next->next->pos, ankerAnfang->next->next->titel);
	printf("4:%i: %s\n", ankerAnfang->next->next->next->pos, ankerAnfang->next->next->next->titel);
	printf("1:%i: %s\n", ankerAnfang->next->next->next->next->pos, ankerAnfang->next->next->next->next->titel);


	switchNodes(myNode2, myNode3);
		//printf("ankerAnfang->prev %i: %s\n", ankerAnfang->prev->pos, ankerAnfang->prev->titel);
	printf("1:%i: %s\n", ankerAnfang->pos, ankerAnfang->titel);
	printf("2:%i: %s\n", ankerAnfang->next->pos, ankerAnfang->next->titel);
	printf("3:%i: %s\n", ankerAnfang->next->next->pos, ankerAnfang->next->next->titel);
	printf("4:%i: %s\n", ankerAnfang->next->next->next->pos, ankerAnfang->next->next->next->titel);
	printf("1:%i: %s\n", ankerAnfang->next->next->next->next->pos, ankerAnfang->next->next->next->next->titel);


}

int testIntSortList(Node * curNode)
{

}
int testCharSortList(Node * curNode)
{

}
int testDoubleSortList(Node * curNode)
{


}