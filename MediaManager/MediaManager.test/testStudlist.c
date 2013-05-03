#include "testStudlist.h"
#include "Cunit\CUnit.h"


void test_kurze_list_searchId(void)
{
	//fuellenm der kurzen liste
	list_Insert (&kurzeListe, "No, Dummi", SEARCH_ID_KURZE_LISTE_1 );

	CU_ASSERT_EQUAL(list_SearchId(kurzeListe , SEARCH_ID_KURZE_LISTE_1)->id , SEARCH_ID_KURZE_LISTE_1);
	CU_ASSERT_EQUAL(list_SearchId(kurzeListe , 999) , NULL);
}

void test_grose_list_searchId(void)
{	
	int i=0,id=0;

	//fuellen der Groﬂen Liste
	list_Insert (&groseListe, "No, Dummi", SEARCH_ID_GROSE_LISTE_1 );
	for (i = 0; i < 50; i++)
	{ 
		//verhindern das nicht eine zufallszahl mit selber id eingetragen wird
		do
		{
			id = rand()+1;
		}while (id == SEARCH_ID_GROSE_LISTE_1 || id == SEARCH_ID_GROSE_LISTE_2 || id == SEARCH_ID_GROSE_LISTE_3 || id == 9999);
		if(i == 25)
			list_Insert (&groseListe, "No, Dummi", SEARCH_ID_GROSE_LISTE_2 );
		list_Insert (&groseListe, "Dummy, Yummy", id);
	}
	list_Insert (&groseListe, "No, Dummi", SEARCH_ID_GROSE_LISTE_3 );

	CU_ASSERT_EQUAL(list_SearchId(groseListe , SEARCH_ID_GROSE_LISTE_1)->id , SEARCH_ID_GROSE_LISTE_1);
	CU_ASSERT_EQUAL(list_SearchId(groseListe , SEARCH_ID_GROSE_LISTE_2)->id , SEARCH_ID_GROSE_LISTE_2);
	CU_ASSERT_EQUAL(list_SearchId(groseListe , SEARCH_ID_GROSE_LISTE_3)->id , SEARCH_ID_GROSE_LISTE_3);
	CU_ASSERT_EQUAL(list_SearchId(groseListe , 9999) , NULL);
	CU_ASSERT_NOT_EQUAL(list_SearchId(groseListe , SEARCH_ID_GROSE_LISTE_1) , NULL);
	CU_ASSERT_NOT_EQUAL(list_SearchId(groseListe , SEARCH_ID_GROSE_LISTE_2) , NULL);
	CU_ASSERT_NOT_EQUAL(list_SearchId(groseListe , SEARCH_ID_GROSE_LISTE_3) , NULL);
}

void test_leere_list_searchId(void)
{
	CU_ASSERT_EQUAL(list_SearchId(leereListe , 9999) , NULL);
	//CU_ASSERT_NOT_EQUAL(list_SearchId(leereListe , SEARCH_ID_LEERE_LISTE_1 )->id , SEARCH_ID_LEERE_LISTE_1);
}