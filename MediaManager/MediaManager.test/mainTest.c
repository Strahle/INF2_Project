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
#include "studlist.h"
#include "testStudlist.h"


int main(void)
{
	int n;
	int i, id, start,j;
	Student * p;
	CU_pSuite Suite1 = NULL;
	CU_pTest Test1 = NULL,Test2 = NULL,Test3 = NULL;

	//CU_UNIT init Stuff


	if(CUE_NOMEMORY == CU_initialize_registry())
	{
		printf("\nInit der Test. Reg fehlgeschlagen");
		return EXIT_FAILURE;
	}

	Suite1 = CU_add_suite("Searches" ,NULL ,NULL);
	//add suits here


	Test1 = CU_add_test(Suite1 , "Test fuer kurze liste",test_kurze_list_searchId);
	//Add Tests here

	CU_automated_run_tests();
	CU_list_tests_to_file();

	getchar();
	return 0;
}