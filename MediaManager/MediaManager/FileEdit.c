#include "FileEdit.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

static char * filePath;
static FILE * pFileDetails = NULL;
static int position = -1;


//initialisiert FileEdit (position = 0)
char initFileEdit (void)
{
	if (position == 0)
	{
		return 0;
	}
	position = 0;
	return 1;
}

//setzt filePath + öffnet File
char setFilePath(char * pfad)
{
	errno_t err;

	filePath = pfad;

	if ((err = fopen_s (&pFileDetails, filePath, "a+b")) !=0)
	{
		return 0;
	}
	return 1;
}

//schließt File
char closeFile (void)
{
	errno_t err;

	if ((err = fclose (pFileDetails)) != 0)
	{
		return 0;
	}
	pFileDetails = NULL;
	free (pFileDetails);

	return 1;
}

//schließt, löscht und öffnet file anschließend
char removeFile (void)
{
	errno_t err;

	if ((err = fclose (pFileDetails))!= 0)
	{
		return 0;
	}
	if ((err = remove (filePath)) != 0)
	{
		return 0;
	}
	if ((err = fopen_s (&pFileDetails, filePath, "a+b")) != 0)
	{
		return 0;
	}
	return 1;
}


//Fügt der Datei einen neuen Datensatz hinzu
char saveToFile (Details * nodeDetails)
{
	int filesize;
	int pos;

	filesize = ftell (pFileDetails);
	pos = filesize / (sizeof (struct strDetails));
	nodeDetails->index = pos;

	fwrite (nodeDetails,1,sizeof(Details),pFileDetails);

	return 1;
}

//Lädt einen Datensatz aus der Datei
//gibt NULL zurück, wenn kein Element mehr vorhanden ist
Details * loadFromFile (void)
{	
	Details * currentDetails = NULL;
	int skip = -1;
	int fileSize;

	fseek (pFileDetails, 0L, SEEK_END);
	fileSize = ftell (pFileDetails);

	skip = position * sizeof (Details);

	fseek (pFileDetails, skip, SEEK_SET);
	
	if (skip >= fileSize)
	{
		return NULL;
	}

	currentDetails = (struct strDetails *) malloc (sizeof (struct strDetails));

	fread (currentDetails, 1, sizeof (Details), pFileDetails);

	position++;

	return currentDetails;
}

//Speichert die aktuelle Liste in einer TXT Datei (Details)				medium: 1 = Buch;	2 = CD;	  3 = DVD 
char printListeToFile (Node * List, char medium)
{
	struct tm * timeinfo = NULL;
	char currentGenre[50+1];
	errno_t err;
	double ISBN = 0;

	if ((err = fclose (pFileDetails)) != 0)
	{
		return 0;
	}
	if ((err = fopen_s (&pFileDetails, filePath, "a+")) != 0)
	{
		return 0;
	}

	timeinfo = (struct tm *) malloc (sizeof (struct tm));

	while (List->prev != NULL)
	{
		List = List->prev;
	}

	while (1)
	{
		localtime_s(timeinfo, &List->nodeDetails->erscheinungsdatum);

		if ((err = fprintf (pFileDetails, "Index: %d\t", List->nodeDetails->index)) != 0)
		{
			return 0;
		}
		if ((err = fprintf (pFileDetails, "Titel: %s\t\t", List->nodeDetails->titel)) != 0)
		{
			return 0;
		}

		//enum genre_film{aktion = 1, thriller = 2, komoedie = 3, drama = 4, science_fiction = 5, doku = 6, horror = 7, abenteuer = 8};
		//enum genre_musik{rock = 1, pop = 2, jazz = 3, house = 4, klassik = 5, dance = 6, metal = 7, hip_hop = 8};
		//enum genre_buch{abenteuer = 1, thriller = 2, sachbuch = 3, biographie = 4, comic = 5, kinderbuch = 6, maerchen = 7, gedicht = 8};

		switch (medium)
		{
		case 1 :
			switch (List->nodeDetails->genre)
			{
			case 1 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Abenteuer");
				break;
			case 2 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Thriller");
				break;
			case 3 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Sachbuch");
				break;
			case 4 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Biographie");
				break;
			case 5 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Comic");
				break;
			case 6 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Kinderbuch");
				break;
			case 7:
				strcpy_s (currentGenre, sizeof (currentGenre), "Maerchen");
				break;
			case 8 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Gedicht");
				break;
			}


				if ((err = fprintf (pFileDetails, "Autor: %s\t\t", List->nodeDetails->regisseur)) != 0)
			{
				return 0;
			}
			if ((err = fprintf (pFileDetails, "Verlag: %s\t\t", List->nodeDetails->verlag)) != 0)
			{
				return 0;
			}

			break;

		case 2 :
			switch (List->nodeDetails->genre)
			{
			case 1 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Rock");
				break;
			case 2 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Pop");
				break;
			case 3 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Jazz");
				break;
			case 4 :
				strcpy_s (currentGenre, sizeof (currentGenre), "House");
				break;
			case 5 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Klassik");
				break;
			case 6 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Dance");
				break;
			case 7:
				strcpy_s (currentGenre, sizeof (currentGenre), "Metal");
				break;
			case 8 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Hip-Hop");
				break;
			}


				if ((err = fprintf (pFileDetails, "Interpret: %s\t\t", List->nodeDetails->regisseur)) != 0)
			{
				return 0;
			}
			if ((err = fprintf (pFileDetails, "Label: %s\t\t", List->nodeDetails->verlag)) != 0)
			{
				return 0;
			}

			break;

		case 3 :
			switch (List->nodeDetails->genre)
			{
			case 1 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Action");
				break;
			case 2 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Thriller");
				break;
			case 3 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Komoedie");
				break;
			case 4 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Drama");
				break;
			case 5 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Science-Fiction");
				break;
			case 6 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Dokumentation");
				break;
			case 7:
				strcpy_s (currentGenre, sizeof (currentGenre), "Horror");
				break;
			case 8 :
				strcpy_s (currentGenre, sizeof (currentGenre), "Abenteuer");
				break;
			}
			

				if ((err = fprintf (pFileDetails, "Regisseur: %s\t\t", List->nodeDetails->regisseur)) != 0)
			{
				return 0;
			}
			if ((err = fprintf (pFileDetails, "Studio: %s\t\t", List->nodeDetails->verlag)) != 0)
			{
				return 0;
			}
			
			break;
		}

		if ((err = fprintf (pFileDetails, "Genre: %s\t\t", currentGenre)) != 0)
			{
				return 0;
			}
		if ((err = fprintf (pFileDetails, "Erscheinungsdatum: %d. %d. %d\t\t",(timeinfo->tm_mday), (timeinfo->tm_mon + 1), (timeinfo->tm_year + 1900))) != 0)
		{
			return 0;
		}

		ISBN = List->nodeDetails->isbn;
		fprintf (pFileDetails, "ISBN: %i-", abs(ISBN/10000000000));
		ISBN = ISBN - (double)(abs(ISBN/10000000000))*10000000000;
		fprintf (pFileDetails, "%i-", abs(ISBN/1000000000));
		ISBN = ISBN - (double)(abs(ISBN/1000000000))*1000000000;
		fprintf (pFileDetails, "%i-",abs(ISBN/10000000));
		ISBN = ISBN -  (double)(abs(ISBN/10000000))*10000000;
		fprintf (pFileDetails, "%i-",abs(ISBN/10));
		ISBN = ISBN -  (double)(abs(ISBN/10))*10;
		fprintf (pFileDetails, "%i\t\t",abs(ISBN));

		if ((err = fprintf (pFileDetails, "Inhalt: %s", List->nodeDetails->text)) != 0)
		{
			return 0;
		}
		if ((err = fprintf (pFileDetails, "\n")) != 0)
		{
			return 0;
		}

		List = List->next;
		if (List == NULL)
		{
			break;
		}
	}

	timeinfo = NULL;
	free (timeinfo);

	return 1;
}