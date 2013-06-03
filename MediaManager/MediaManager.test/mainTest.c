/*	Description: Dies ist die Test Main funktion. Hier werden alle Tests Initalisiert und ausgeführt
 *
 *
 *
 *	Author: Ulf Schmelzer
 */


#include <stdio.h>
#include <stdlib.h>
#include "Cunit\CUnit.h"
#include "Cunit\Automated.h"
#include "Cunit\Console.h"

#include "testListe.h"

#include "studlist.h"
#include "testStudlist.h"

int main(void)
{
	int n;
	int i, id, start,j;

	CU_pSuite Suite1 = NULL;
	CU_pTest Test1 = NULL,Test2 = NULL,Test3 = NULL;

	//CU_UNIT init Stuff
	if(CUE_NOMEMORY == CU_initialize_registry())
	{
		printf("\nInit der Test. Reg fehlgeschlagen");
		return EXIT_FAILURE;
	}

	//add suits here
	Suite1 = CU_add_suite("sortList.h", NULL, NULL);
	

	//Add Tests here
	Test1 = CU_add_test(Suite1 , "Sortieren der Liste mit mit intSortList()",testIntSortList);
	//Test2 = CU_add_test(Suite1 , "Prüft ob das vertauschen von 2 elementen funktioniert",testSwitchNodes);
	//Test3 = CU_add_test(Suite1 , "System test",testListeSystem);
	Test2 = CU_add_test(Suite1 , "System test",testSearchItem);
	

	//CU_automated_run_tests(); //stats an automated test
	CU_console_run_tests();
	//CU_list_tests_to_file(); //saves the test reaults in test data
	return 0;
}