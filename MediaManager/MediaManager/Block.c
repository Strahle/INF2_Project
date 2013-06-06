#include "Block.h"

#include <stdio.h>

void init (void)
{
	initList(); //Darf keinen Rückgabewert mehr haben
	//initFileEdit();
}

char aksMedia (void)
{
	//Media Menü aufrufen
	if (MediaMenue() == 1)
		{
			return 1;
		}
	//switch (askInput())
	//{
	//case 0: return 1;
	//break;
	//case 1:
	//break;
	//case 2:
	//break;
	//}
}