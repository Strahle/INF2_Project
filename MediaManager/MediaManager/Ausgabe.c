//test
#include <stdio.h>
#include <time.h>
#include "Ausgabe.h"

//
//#include <string.h>
//#include <time.h>
	//Details *Test = NULL;
	//char mist[51];
 //   time_t Zeitstempel;
 //

	//Details *Test = NULL;
	//strcpy_s(Test->verlag,sizeof(&Test->verlag),"Ich bin der Werner Heissenberg Verlag und Kokse ");
	//strcpy_s(Test->text, sizeof(Test->text -10),"So jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichen");
	//showDetail(Test);

	//MediaMenue ();
	//ListMenue ();
	//ChangeMenue ();
	//SearchMenueResult ();
	//SearchMenue ();
	//SortMenue();
	//showDetailMenue ();







void showGenere (void)
//Zeigt eine Liste aller Genere an
{

}

void showList (Node * Knot , char prev)
//Zeigt eine Liste aller Titel an (auf einer Seite)
{
	int i,j = 1;
	if (prev == 1)
	{
		j = -1;
	}
	
	for (i = 0 ; i <=18; i + j)
	{
		printf("%i: %s\n",Knot->nodeDetails->pos, Knot->nodeDetails->titel);
		Knot = Knot->next;
	}

}

void showDetail (Details * Detail)
//Zeigt eine Liste mit den Details eines Elementes an
{
	int i=0, j,k = 0, start = 0;
	printf("\n\n\n");
	printf("Der Titel:\tIch bin ein test um zu gucken ob es geht.234567890\n");
	printf("Genre:\t1\n");
	printf("Verlag:\t\tIch bin der Werner Heissenberg Verlag und Kokse bla\n");
	printf("Erscheinung\tJuli.19985\t\t");
	printf("ISBN:\t\t123-9875-5412\n");
//	printf("Details:\t\tSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei\n");

//	tm *nun;
 //   nun = localtime(&Detail->erscheinungsdatum);
	//printf("Der Titel:\t%s\n",Detail->titel);
	//printf("Das Genre:\t%s\n",Detail->genre);
	//printf("Der Verlag:\t%s\n",Detail->verlag);
	//printf("Das Erscheinungsdatum:\t%i.%i.%i\n",nun->tm_year, nun->tm_mon, nun->tm_mday);
	//printf("Die ISBN:\t%d\n",Detail->isbn);
//	printf("Details:\t%s\n",Detail->text);

	while(k <= 13 && start <=1023 && Detail->text[start + i] != 0 )
	{
		for (i = 80; i >= 0; i--)
		{
			if (Detail->text[start + i] == ' ' || Detail->text[start + i] == 0 )
			{
				for (j = start; j< (start + i); j ++)
				{
					printf("%c",Detail->text[j]);
				}
				if (i < 80)
				{
					printf("\n");
				}
				k += 1;
				start += (i+1);
				break;
			}
			else if (i == 0)
			{
				for (j = start; j< (start + 80); j ++)
				{
					printf("%c",Detail->text[j]);
				}
				k += 1;
				start += (79);
				break;
			}
		}
	}
}