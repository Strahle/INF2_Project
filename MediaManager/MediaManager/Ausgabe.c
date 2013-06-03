//test
#include <stdio.h>
#include <time.h>
#include "Ausgabe.h"
#include <math.h>

//Zeigt eine Liste aller Genere an
void showGenere (void)
{
	
	/*Details * myDetails=NULL;
	struct tm * nun = NULL;

		nun = (struct tm *) calloc(1,sizeof(struct tm));
		myDetails = (Details *) calloc(1,sizeof(Details));

		nun->tm_mon = 10;
		nun->tm_year = 113; 

		strcpy_s(myDetails->titel,sizeof(myDetails->titel),"Ich bin ein test um zu gucken ob es geht.23456789");
		strcpy_s(myDetails->text,sizeof(myDetails->text),"So jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir bei achtzig zeichenSo jetzt schreibe ich mal ein paar zeichen und guck wann wir");
		strcpy_s(myDetails->text,sizeof(myDetails->text),"So jetzt schreibe ich mal ein paar zeichen und guck wann wir");
		strcpy_s(myDetails->verlag,sizeof(myDetails->verlag),"Ich bin der Werner Heissenberg Verlag und Kokse be");
		myDetails->isbn = 1234567890123;
		myDetails->genre = '1';
		myDetails->erscheinungsdatum = mktime(nun);

		showDetail(myDetails);*/

}

//Zeigt eine Liste aller Titel an (auf einer Seite)
void showList (Node * Knot , char prev)
{
	// muss auf null abfragen dann kotzt
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

//Zeigt eine Liste mit den Details eines Elementes an
void showDetail (Details * Detail)
{
	int i=0, j,k = 0, start = 0, Test;
	double  ISBN;
	struct tm * nun;
	nun = (struct tm *) calloc(1,sizeof(struct tm));

	localtime_s(nun, &Detail->erscheinungsdatum);
	printf("Titel:\t%s\n",Detail->titel);
	printf("Genre:\t%c\n",Detail->genre);
	printf("Verlag:\t%s\n",Detail->verlag);
	printf("Erscheinungsdatum:  %i.%i\t", nun->tm_mon, nun->tm_year);
	printf("ISBN:  %",Detail->isbn);
	ISBN = Detail->isbn;
	printf("%i-", abs(ISBN/10000000000));
	ISBN = ISBN - (double)(abs(ISBN/10000000000))*10000000000;
	printf("%i-", abs(ISBN/1000000000));
	ISBN = ISBN - (double)(abs(ISBN/1000000000))*1000000000;
	printf("%i-",abs(ISBN/10000000));
	ISBN = ISBN -  (double)(abs(ISBN/10000000))*10000000;
	printf("%i-",abs(ISBN/10));
	ISBN = ISBN -  (double)(abs(ISBN/10))*10;
	printf("%i\n",abs(ISBN));
	printf("Details:\n");

	while(k <= 13 && start <=1023 && Detail->text[start + i] != 0 )
	{
		for (i = 80; i >= 0; i--)
		{
			if (Detail->text[start + i] == ' ' || Detail->text[start + i] == 0 )
			{
				for (j = start; j< (start + i); j ++)
				{
					if (Detail->text[j] > 0)
					{
						printf("%c",Detail->text[j]);
					}
				}
				if (i < 80)
				{
					printf("\n");
				}
				if (Detail->text[start + i] == 0)
				{
					k = 14;
				}
				else
				{
				k += 1;
				}
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