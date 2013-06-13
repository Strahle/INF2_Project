#include "Eingabe.h"

int askIndex (void)
{
	int Index = 0;

	setColor(0,15);

	//Menü löschen
	if (clrRange(22, 3) == 0)
	{
		return 0;
	}

	//Footer anzeigen
	Footer(2);

	gotoxy(0,24);

	printf("Bitte waehlen Sie ein Element aus (Index): ");

	setColor(0,14);
	scanf_s("%i", &Index); fflush(stdin);

	if (Index == 'e')
	{
		exit;
	}

	return Index;
}


//Diese Funktion fragt alle Items für einen neuen Struct ab. Benötigt wird ein char, welches das Medium übergibt*/
Details * addItemInput (char medium)
{	
	time_t rawtime;
	Details * detail_new;
	struct tm * timeinfo;

	//char medium = 'd';

	char titel[TITLE_LENGTH];
	char regisseur[ MAX_VERLAG_LENGTH];
	char verlag[ MAX_VERLAG_LENGTH];
	double ISBN;
	int i;
	int Jahr, Monat, Tag;
	int a,b,c;
	char genre_neu;
	char text [MAX_TEXT_LENGTH];

	detail_new = (Details*) malloc (sizeof (Details));
	timeinfo = (struct tm*) malloc (sizeof (struct tm));



	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(2);
	gotoxy(0,4);
	printf("Bitte geben Sie einen Titel ein (max 50 Zeichen): ");
	gotoxy(0,0);
	gotoxy(0,23);
	fgets(titel, (TITLE_LENGTH), stdin);
	fflush(stdin);

	if (titel[0] == '0' && titel[1] == '\n')
	{
		return 0;
	}

	else if (titel[0] == 'e' && titel[1]  == '\n')
	{
		exit (0);
	}

	titel[strlen(titel)-1] ='\0';
	strcpy_s(detail_new->titel, sizeof(titel), titel);
	clrPosition(23,0,80);
	clrPosition(4,0,80);



	switch (medium)
	{
	case '1':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Autor ein (max 50 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
			fflush(stdin);

			if (regisseur[0] == '0' && regisseur[1] == '\n')
			{
				return 0;
			}

			else if (regisseur[0] == 'e' && regisseur[1] == '\n')
			{
				exit (0);
			}

			regisseur[strlen(regisseur)-1] ='\0';
			strcpy_s(detail_new->regisseur, sizeof(regisseur) ,regisseur);
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;
		}

	case '2':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Interpreten ein (max 50 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
			fflush(stdin);

			if (regisseur[0] == '0' && regisseur[1] == '\n')
			{
				return 0;
			}

			else if (regisseur[0] == 'e' && regisseur[1] == '\n')
			{
				exit (0);
			}

			regisseur[strlen(regisseur)-1] ='\0';
			strcpy_s(detail_new->regisseur, sizeof(regisseur) ,regisseur);
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;
		}

	case '3':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Regisseur ein (max 50 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
			fflush(stdin);

			if (regisseur[0] == '0' && regisseur[1] == '\n')
			{
				return 0;
			}

			else if (regisseur[0] == 'e' && regisseur[1] == '\n')
			{
				exit (0);
			}

			regisseur[strlen(regisseur)-1] ='\0';
			strcpy_s(detail_new->regisseur, sizeof(regisseur) ,regisseur);
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;
		}
	}




	switch (medium)//Bücher =1, CD=2, DVD=3
	{
	case '1':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Verlag ein (max 50 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
			fflush(stdin);

			if (verlag[0] == '0' && verlag[1] == '\n')
			{
				return 0;
			}

			else if (verlag[0] == 'e' && verlag[1] == '\n')
			{
				exit (0);
			}
			verlag[strlen(verlag)-1] ='\0';
			strcpy_s(detail_new->verlag, sizeof(verlag) ,verlag);
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;
		}

	case '2':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie ein Label ein (max 50 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
			fflush(stdin);

			if (verlag[0] == '0' && verlag[1] == '\n')
			{
				return 0;
			}

			else if (verlag[0] == 'e' && verlag[1] == '\n')
			{
				exit(0);
			}
			verlag[strlen(verlag)-1] ='\0';
			strcpy_s(detail_new->verlag, sizeof(verlag) ,verlag);
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;
		}

	case '3':
		{


			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie ein Studio ein (max 50 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
			fflush(stdin);

			if (verlag[0] == '0' && verlag[1] == '\n')
			{
				return 0;
			}

			else if (verlag[0] == 'e' && verlag[1] == '\n')
			{
				exit(0);
			}
			verlag[strlen(verlag)-1] ='\0';
			strcpy_s(detail_new->verlag, sizeof(verlag) ,verlag);
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;
		}
	}



	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(2);
	clrPosition(4,0,80);
	gotoxy(0,4);
	printf("Bitte geben Sie die ISBN-Nummer ein : ");
	gotoxy(0,0);
	gotoxy(0,23);

	for (i=0; ;i++){

		scanf_s ("%lf", &ISBN);
		fflush(stdin);
		clrPosition(23,0,80);

		if (ISBN == 'e')
		{
			exit(0);
		}
		else if (ISBN == 0)
		{
			return 0;
		}

		else if (ISBN >= 1000000000 && ISBN <= 1000000000000)
		{
			detail_new->isbn = ISBN;
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;
		}

		else
		{
			clrPosition(23,0,80);
			setColor(fehlerBackground,fehlerFond);
			printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
			setColor(standBackground,standFond);
		}
	}



	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(2);
	gotoxy(0,4);
	printf("Bitte geben Sie das Erscheinungsjahr ein: ");
	gotoxy(0,23);

	for (a=0; ;a++){

		scanf_s ("%i", &Jahr);
		fflush(stdin);
		clrPosition(23,0,80);

		if (Jahr == 'e')
		{
			exit(0);
		}

		else if (Jahr == 0)
		{
			return 0;
		}

		else if (Jahr <= 1900 || Jahr >= 2147483647)
		{
			clrPosition(22,0,80);
			setColor(fehlerBackground,fehlerFond);
			printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
			setColor(standBackground,standFond);
		}

		else	
		{
			break;
		}
	}

	clrPosition(4,0,80);
	gotoxy(0,4);
	printf("Bitte geben Sie das Erscheinungsmonat ein: ");
	gotoxy(0,0);
	gotoxy(0,23);

	for (b=0; ;a++){
		scanf_s ("%i", &Monat);
		fflush(stdin);
		clrPosition(23,0,80);

		if (Monat == 'e')
		{
			exit(0);
		}

		else if (Monat == 0)
		{
			return 0;
		}

		else if (Monat <= 0 || Monat > 12)
		{
			clrPosition(22,0,80);
			setColor(fehlerBackground,fehlerFond);
			printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
			setColor(standBackground,standFond);
		}

		else 
		{
			break;
		}
	}

	clrPosition(4,0,80);
	gotoxy(0,4);
	printf("Bitte geben Sie das Erscheinungstag ein: ");
	gotoxy(0,0);
	gotoxy(0,23);

	for (c=0; ;c++){

		scanf_s ("%i", &Tag);
		fflush(stdin);
		clrPosition(23,0,80);

		if (Tag == 'e')
		{
			exit(0);
		}

		else if (Tag == 0)
		{
			return 0;
		}

		else if (Tag <= 0 || Tag > 31)
		{
			clrPosition(22,0,80);
			setColor(fehlerBackground,fehlerFond);
			printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
			setColor(standBackground,standFond);
		}

		else 
		{
			break;
		}
	}

	time(&rawtime);
	localtime_s (timeinfo, &rawtime);
	timeinfo->tm_year = Jahr - 1900;
	timeinfo->tm_mon = Monat - 1;
	timeinfo->tm_mday = Tag;
	detail_new->erscheinungsdatum = mktime ( timeinfo );
	clrPosition(23,0,80);
	clrPosition(4,0,80);



	switch (medium)
	{
	case '1':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,22);
			setColor(sonderBackground,sonderFond);
			printf("1: Sachbuch\t\t2: Kinderbuch\t\t3: Comic\t\t\t4: Thriller\t\t5: Horror\t\t6: M\x84""rchen\t\t\t7: Biographie\t\t8: Abenteuer");
			setColor(standBackground,standFond);
			break;
		}

	case '2':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,22);
			setColor(sonderBackground,sonderFond);
			printf("1: Rock\t\t\t2: Pop\t\t\t3: Klassik\t\t\t4: Hip-Hop\t\t5: Techno\t\t6: Dance\t\t\t7: Metal\t\t8: House");
			setColor(standBackground,standFond);
			break;
		}
	case '3':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,22);
			setColor(sonderBackground,sonderFond);
			printf("1: Aktion\t\t2: Drama\t\t3: Kom\x94""die\t\t\t4: Krimi\t\t5: Doku\t\t\t6: Zeichentrick\t\t\t7: Science-Fiktion\t8: Thriller");
			setColor(standBackground,standFond);
			break;

		}
	}

	gotoxy(0,4);
	printf ("Bitte geben Sie ein Genre ein: ");

	for (i=0; ;i++)
	{
		gotoxy(0,0);
		gotoxy(0,21);
		genre_neu = getchar();
		fflush(stdin);
		clrPosition(21,0,80);

		if(genre_neu == 'e')
		{
			exit (0);
		}

		else if (genre_neu == '0')
		{
			return 0;
		}

		else if (genre_neu >= '1' && genre_neu <= '8')
		{
			detail_new->genre = genre_neu;
			break;
		}

		else 
		{
			clrPosition(21,0,80);
			gotoxy(0,21);
			setColor(fehlerBackground,fehlerFond);
			printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
			setColor(standBackground,standFond);
		}
	}

	clrPosition(21,0,80);
	clrPosition(22,0,80);
	clrPosition(23,0,80);
	clrPosition(4,0,80);



	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(2);
	gotoxy(0,4);
	printf("Bitte geben Sie einen Text ein (max 1024 Zeichen): ");
	gotoxy(0,0);
	gotoxy(0,6);
	fgets (text, (MAX_TEXT_LENGTH), stdin);
	fflush(stdin);

	if (text[0] == '0' && text[1] == '\n')
	{
		return 0;
	}

	else if (text[0] == 'e' && text[1] == '\n')
	{
		exit (0);
	}

	text[strlen(text)-1] ='\0';
	strcpy_s(detail_new->text, sizeof(text) ,text);

	//Der eingegebene Text wird nach Ende der Funktion vollständig vom Bildschirm gelöscht

	return detail_new;
	detail_new =NULL;
	free(detail_new);
	timeinfo = NULL;
	free(timeinfo);
}



/*Diese Funktion sucht fragt die Sucheingabe des Users ab und speichert sie in den typdef struct Details.
An die Funktion muss ein (char)-Parameter mit der Art des Mediums übergeben werden*/
Node * changeItemDetails (Node * Knot, char ele, char medium, int index)
{	
	time_t rawtime;
	Details * detail_new;
	struct tm * timeinfo;

	char titel[TITLE_LENGTH];
	char regisseur[ MAX_VERLAG_LENGTH];
	char verlag[ MAX_VERLAG_LENGTH];
	double ISBN;
	int i;
	int Jahr, Monat, Tag;
	int a,b,c;
	char genre_neu;
	char text [MAX_TEXT_LENGTH];

	detail_new = (Details*) malloc (sizeof (Details));
	timeinfo = (struct tm*) malloc (sizeof (struct tm));

	while (Knot->prev != NULL);
	{
		Knot = Knot->prev;
	}

	for (i=0; ;i++)
	{
		if (Knot->nodeDetails->index == index)
		{

			break;

		}

		else
		{
			Knot = Knot->next;

		}
	}

	switch (ele) 
	{
	case '1':
		{

			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Titel ein (max 50 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,23);
			fgets(titel, (TITLE_LENGTH), stdin);
			fflush(stdin);

			if (titel[0] == '0' && titel[1] == '\n')
			{
				return 0;
			}

			else if (titel[0] == 'e' && titel[1]  == '\n')
			{
				exit (0);
			}

			titel[strlen(titel)-1] ='\0';
			strcpy_s(Knot->nodeDetails->titel, sizeof(titel) ,titel);
			return Knot;
			break;
		}

	case '2':
		{
			switch (medium)//Bücher =1, CD=2, DVD=3
			{
			case '1':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie einen Autor ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (regisseur[0] == '0' && regisseur[1] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == 'e' && regisseur[1] == '\n')
					{
						exit;
					}

					regisseur[strlen(regisseur)-1] ='\0';
					strcpy_s(Knot->nodeDetails->regisseur, sizeof(regisseur) ,regisseur);
					break;
				}

			case '2':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie einen Interpreten ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (regisseur[0] == '0' && regisseur[1] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == 'e' && regisseur[1] == '\n')
					{
						exit;
					}

					regisseur[strlen(regisseur)-1] ='\0';
					strcpy_s(Knot->nodeDetails->regisseur, sizeof(regisseur) ,regisseur);
					break;
				}

			case '3':
				{					
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie einen Regisseur ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (regisseur[0] == '0' && regisseur[1] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == 'e' && regisseur[1] == '\n')
					{
						exit (0);
					}

					regisseur[strlen(regisseur)-1] ='\0';
					strcpy_s(Knot->nodeDetails->regisseur, sizeof(regisseur) ,regisseur);
					break;
				}
			}

			return Knot;
			break;
		}

	case '3':
		{


			switch (medium)//Bücher =1, CD=2, DVD=3
			{
			case '1':
				{	
					fflush(stdin);
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie einen Verlag ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (verlag[0] == '0' && verlag[1] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == 'e' && verlag[1] == '\n')
					{
						exit (0);
					}
					verlag[strlen(verlag)-1] ='\0';
					strcpy_s(Knot->nodeDetails->verlag, sizeof(verlag) ,verlag);
					break;
				}

			case '2':
				{					
					fflush(stdin);
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie ein Label ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (verlag[0] == '0' && verlag[1] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == 'e' && verlag[1] == '\n')
					{
						exit (0);
					}

					verlag[strlen(verlag)-1] ='\0';
					strcpy_s(Knot->nodeDetails->verlag, sizeof(verlag) ,verlag);
					break;
				}

			case '3':
				{					
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie ein Studio ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (verlag[0] == '0' && verlag[1] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == 'e' && verlag[1] == '\n')
					{
						exit (0);
					}

					verlag[strlen(verlag)-1] ='\0';
					strcpy_s(Knot->nodeDetails->verlag, sizeof(verlag) ,verlag);
					break;
				}
			}

			return Knot;
			break;

		}

	case '4':
		{


			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("\nBitte geben Sie die ISBN-Nummer ein : ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (i=0; ;i++)
			{
				scanf_s ("%lf", &ISBN);
				fflush(stdin);
				clrPosition(23,0,80);

				if (ISBN == 'e')
				{
					exit (0); 
				}

				else if (ISBN == 0)
				{
					return 0; 
				}

				else if (ISBN >= 1000000000 && ISBN <= 1000000000000)
				{
					Knot->nodeDetails->isbn = ISBN;
					break;
				}

				else
				{
					clrPosition(22,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}
			}

			return Knot;
			break;
		}

	case '5':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,23);
			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungsjahr ein: ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (a=0; ;a++){

				scanf_s ("%i", &Jahr);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Jahr == 'e')
				{
					exit(0);
				}

				else if (Jahr == 0)
				{
					return 0;
				}

				else if (Jahr <= 1900 || Jahr >= 2147483647)
				{
					clrPosition(22,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}
				else {break;};
			}

			clrPosition(4,0,80);
			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungsmonat ein: ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (b=0; ;a++)
			{
				scanf_s ("%i", &Monat);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Monat == 'e')
				{
					exit (0); 
				}
				else if (Monat == 0)
				{
					return 0; 
				}

				else if (Monat <= 0 || Monat > 12)
				{
					clrPosition(22,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}
				else {break;}
			}

			clrPosition(4,0,80);
			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungstag ein: ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (c=0; ;c++)
			{
				scanf_s ("%i", &Tag);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Tag == 'e')
				{
					exit (0); 
				}

				else if (Tag == 0)
				{
					return 0; 
				}

				else if (Tag <= 0 || Tag > 31)
				{
					clrPosition(22,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}
				else {break;}
			}

			time(&rawtime);
			localtime_s (timeinfo, &rawtime);
			timeinfo->tm_year = Jahr - 1900;
			timeinfo->tm_mon = Monat - 1;
			timeinfo->tm_mday = Tag;
			Knot->nodeDetails->erscheinungsdatum = mktime ( timeinfo );

			return Knot;
			break;
		}

	case '6':
		{
			switch (medium)
			{
			case '1':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,0);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Sachbuch\t\t2: Kinderbuch\t\t3: Comic\t\t\t4: Thriller\t\t5: Horror\t\t6: M\x84""rchen\t\t\t7: Biographie\t\t8: Abenteuer");
					setColor(standBackground,standFond);
					break;
				}

			case '2':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,0);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Rock\t\t\t2: Pop\t\t\t3: Klassik\t\t\t4: Hip-Hop\t\t5: Techno\t\t6: Dance\t\t\t7: Metal\t\t8: House");
					setColor(standBackground,standFond);
					break;
				}
			case '3':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,0);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Aktion\t\t2: Drama\t\t3: Kom\x94""die\t\t\t4: Krimi\t\t5: Doku\t\t\t6: Zeichentrick\t\t\t7: Science-Fiktion\t8: Thriller");
					setColor(standBackground,standFond);
					break;

				}
			}

			gotoxy(0,4);
			printf ("Bitte geben Sie ein Genre ein: ");
			gotoxy(0,0);
			gotoxy(0,21);

			for (i=0; ;i++)
			{
				genre_neu = getchar();
				fflush(stdin);
				clrPosition(21,0,80);

				if(genre_neu == 'e')
				{
					exit(0);
				}

				else if (genre_neu == '0')
				{
					return 0; 
				}

				else if (genre_neu >= '1' && genre_neu <= '7')
				{
					detail_new->genre = genre_neu;
					break;
				}

				else 
				{
					clrPosition(21,0,80);
					gotoxy(0,21);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}
			}

			return Knot;
			break;
		}




	case '7':
		{			
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Text ein (max 1024 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,6);

			fgets (text, (MAX_TEXT_LENGTH), stdin);
			fflush(stdin);

			if (text[0] == '0' && text[1] == '\n')
			{
				return 0;
			}

			else if (text[0] == 'e' && text[1] == '\n')

			{
				exit (0);
			}

			text[strlen(text)-1] ='\0';
			strcpy_s(Knot->nodeDetails->text, sizeof(text) ,text);
			return Knot;
			break;
		}
	}

	Knot = NULL;
	free (Knot);
	timeinfo = NULL;
	free (timeinfo);
}


/*Die Funktion deleteItemInput fragt ab welches Element einer Liste gelöscht werden soll. Benötigt wird ein char, welcher das Medium an die Funktion übergibt.*/
Node *  deleteItemInput (Node * Knot, char medium)
{

	char itemdelete;
	int control;
	int a, b, c, help = 0;

	/*switch (medium)
	{	
	case '1':
	{
	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(2);
	gotoxy(0,22);
	setColor(sonderBackground,sonderFond);
	printf("1: Titel\t\t2: Autor\t\t3: Verlag\t\t\t4: ISBN\t\t\t5: Erscheinungsdatum\t6: Genre\t\t\t7: Text");
	setColor(standBackground,standFond);
	break;
	}
	case '2':
	{
	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(2);
	gotoxy(0,22);
	setColor(sonderBackground,sonderFond);
	printf("1: Titel\t\t2: Interpret\t\t3: Label\t\t\t4: ISBN\t\t\t5: Erscheinungsdatum\t6: Genre\t\t\t7: Text");
	setColor(standBackground,standFond);
	break;
	}
	case '3':
	{
	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(2);
	gotoxy(0,22);
	setColor(sonderBackground,sonderFond);
	printf("1: Titel\t\t2: Regisseur\t\t3: Studio\t\t\t4: ISBN\t\t\t5: Erscheinungsdatum\t6: Genre\t\t\t7: Text");
	setColor(standBackground,standFond);
	break;
	}
	}*/

	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	Footer(2);
	printf("\t\t\t\t\t\t\t\t");

	for(c=0; ;c++)
	{

		for(a=0; ;a++){

			if (help ==0)
			{
				gotoxy(0,0);
				clrPosition(4,0,80);
				gotoxy(0,4);
				printf("Welches Item soll geloescht werden? ");
				clrPosition(23,0,0);
				gotoxy(0,23);
				//help = 1;
			}	

			scanf_s("%i", &itemdelete);
			fflush(stdin);

			if (itemdelete == 0)
			{
				return NULL;
			}

			else if (itemdelete == 'e')
			{
				exit (0);
			}


			while (Knot->prev != NULL);
			{
				Knot = Knot->prev;
			}

			for (b=0; ;b++)
			{
				if (Knot->nodeDetails->index == itemdelete)
				{
					break;
				}
				else
				{
					Knot = Knot->next;

					if (Knot == NULL)
					{
						clrPosition(23,0,80);
						gotoxy(0,23);
						setColor(fehlerBackground,fehlerFond);
						printf("Das zuloeschende Element ist nicht auffindbar, bitte erneut eingeben: ");
						setColor(standBackground,standFond);
						help = 1;
						break;

					}
				}
			}

			if (help == 0)
			{
				break;
			}

		}
		//(21,0,80);


		for(a = 0; ;a++)
		{		
			if (help != 2)
			{
				gotoxy(0,0);	
				clrPosition(4,0,80);
				gotoxy(0,4);
				printf("Soll das Element wirklich geloescht werden? (J/N) "); 
				clrPosition(23,0,80);
				gotoxy(0,23);
			}

			control = getchar();
			fflush(stdin);
			clrPosition(23,0,80);
			//clrPosition(23,0,80);

			for (b=0; ;a++)
			{
				if (control == 'j' || control =='J')
				{
					gotoxy(0,23);
					printf("Element geloescht!");
					fflush(stdin);
					return Knot;
				}

				else if (control == 'n' || control == 'N')
				{
					help = 3;
					break;
				}
				else if (control == 'e')
				{
					exit (0);
				}

				else if (control == '0')
				{
					return 0;
				}

				else 
				{
					clrPosition(21,0,0);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
					help = 2;
					break;					
				}
			}

			if (help == 3)
			{
				break;
			}

		}

		if (help == 3)
		{
			help = 0;
			break;
		}
	}
	Knot = NULL;
	free (Knot);
}


/*Siehe changeoneItem*/
Details * searchItemInput (char medium, char ele)
{
	time_t rawtime;
	Details * detail_search;
	struct tm * timeinfo;

	char titel[TITLE_LENGTH];
	char regisseur[ MAX_VERLAG_LENGTH];
	char verlag[ MAX_VERLAG_LENGTH];
	double ISBN;
	int i;
	int Jahr, Monat, Tag;
	int a,b,c;
	char genre_neu;
	char text [MAX_TEXT_LENGTH];

	detail_search = (Details*) malloc (sizeof (Details));
	timeinfo = (struct tm*) malloc (sizeof (struct tm));

	switch (ele) 
	{
	case '1':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Titel ein (max 50 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,23);
			fgets(titel, (TITLE_LENGTH), stdin);
			fflush(stdin);

			if (titel[0] == '0' && titel[1] == '\n')
			{
				return 0;
			}

			else if (titel[0] == 'e' && titel[1]  == '\n')
			{
				exit (0);
			}

			titel[strlen(titel)-1] ='\0';
			strcpy_s(detail_search->titel, sizeof(titel), titel);
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;

		}

	case '2':
		{
			//char regisseur[ MAX_VERLAG_LENGTH];

			switch (medium)//Bücher =1, CD=2, DVD=3
			{
			case '1':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie einen Autor ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (regisseur[0] == '0' && regisseur[1] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == 'e' && regisseur[1] == '\n')
					{
						exit (0);
					}

					regisseur[strlen(regisseur)-1] ='\0';
					strcpy_s(detail_search->regisseur, sizeof(regisseur) ,regisseur);
					clrPosition(23,0,80);
					clrPosition(4,0,80);
					break;

				}

			case '2':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie einen Interpreten ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (regisseur[0] == '0' && regisseur[1] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == 'e' && regisseur[1] == '\n')
					{
						exit (0);
					}

					regisseur[strlen(regisseur)-1] ='\0';
					strcpy_s(detail_search->regisseur, sizeof(regisseur) ,regisseur);
					clrPosition(23,0,80);
					clrPosition(4,0,80);
					break;
				}
			case '3':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie einen Regisseur ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (regisseur[0] == '0' && regisseur[1] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == 'e' && regisseur[1] == '\n')
					{
						exit (0);
					}

					regisseur[strlen(regisseur)-1] ='\0';
					strcpy_s(detail_search->regisseur, sizeof(regisseur) ,regisseur);
					clrPosition(23,0,80);
					clrPosition(4,0,80);
					break;
				}
			}

			break;

		}

	case '3':
		{
			switch (medium)//Bücher =1, CD=2, DVD=3
			{
			case '1':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie einen Verlag ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (verlag[0] == '0' && verlag[1] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == 'e' && verlag[1] == '\n')
					{
						exit (0);
					}
					verlag[strlen(verlag)-1] ='\0';
					strcpy_s(detail_search->verlag, sizeof(verlag) ,verlag);
					clrPosition(23,0,80);
					clrPosition(4,0,80);
					break;
				}

			case '2':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie ein Label ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (verlag[0] == '0' && verlag[1] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == 'e' && verlag[1] == '\n')
					{
						exit(0);
					}

					verlag[strlen(verlag)-1] ='\0';
					strcpy_s(detail_search->verlag, sizeof(verlag) ,verlag);
					clrPosition(23,0,80);
					clrPosition(4,0,80);
					break;
				}

			case '3':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,4);
					printf("Bitte geben Sie ein Studio ein (max 50 Zeichen): ");
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);

					if (verlag[0] == '0' && verlag[1] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == 'e' && verlag[1] == '\n')
					{
						exit(0);
					}
					verlag[strlen(verlag)-1] ='\0';
					strcpy_s(detail_search->verlag, sizeof(verlag) ,verlag);
					clrPosition(23,0,80);
					clrPosition(4,0,80);
					break;
				}
			}

			break;

		}


	case '4':
		{	
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			clrPosition(4,0,80);
			gotoxy(0,4);
			printf("Bitte geben Sie die ISBN-Nummer ein : ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (i=0; ;i++){

				scanf_s ("%lf", &ISBN);
				fflush(stdin);
				clrPosition(23,0,80);

				if (ISBN == 'e')
				{
					exit(0);
				}
				else if (ISBN == 0)
				{
					return 0;
				}

				else if (ISBN >= 1000000000 && ISBN <= 1000000000000)
				{
					detail_search->isbn = ISBN;
					clrPosition(23,0,80);
					clrPosition(4,0,80);
					break;
				}

				else
				{
					clrPosition(23,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}

				break;
			}


	case '5':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungsjahr ein: ");
			gotoxy(0,23);

			for (a=0; ;a++){

				scanf_s ("%i", &Jahr);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Jahr == 'e')
				{
					exit(0);
				}

				else if (Jahr == 0)
				{
					return 0;
				}

				else if (Jahr <= 1900 || Jahr >= 2147483647)
				{
					clrPosition(22,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}

				else	
				{
					break;
				}
			}

			clrPosition(4,0,80);
			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungsmonat ein: ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (b=0; ;a++){
				scanf_s ("%i", &Monat);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Monat == 'e')
				{
					exit(0);
				}

				else if (Monat == 0)
				{
					return 0;
				}

				else if (Monat <= 0 || Monat > 12)
				{
					clrPosition(22,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}

				else 
				{
					break;
				}
			}

			clrPosition(4,0,80);
			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungstag ein: ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (c=0; ;c++){

				scanf_s ("%i", &Tag);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Tag == 'e')
				{
					exit(0);
				}

				else if (Tag == 0)
				{
					return 0;
				}

				else if (Tag <= 0 || Tag > 31)
				{
					clrPosition(22,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}

				else 
				{
					break;
				}
			}

			time(&rawtime);
			localtime_s (timeinfo, &rawtime);
			timeinfo->tm_year = Jahr - 1900;
			timeinfo->tm_mon = Monat - 1;
			timeinfo->tm_mday = Tag;
			detail_search->erscheinungsdatum = mktime ( timeinfo );
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;
		}

	case '6':
		{
			switch (medium)
			{
			case '1':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Sachbuch\t\t2: Kinderbuch\t\t3: Comic\t\t\t4: Thriller\t\t5: Horror\t\t6: M\x84""rchen\t\t\t7: Biographie\t\t8: Abenteuer");
					setColor(standBackground,standFond);
					break;
				}

			case '2':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Rock\t\t\t2: Pop\t\t\t3: Klassik\t\t\t4: Hip-Hop\t\t5: Techno\t\t6: Dance\t\t\t7: Metal\t\t8: House");
					setColor(standBackground,standFond);
					break;
				}
			case '3':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(2);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Aktion\t\t2: Drama\t\t3: Kom\x94""die\t\t\t4: Krimi\t\t5: Doku\t\t\t6: Zeichentrick\t\t\t7: Science-Fiktion\t8: Thriller");
					setColor(standBackground,standFond);
					break;

				}
			}

			gotoxy(0,4);
			printf ("Bitte geben Sie ein Genre ein: ");

			for (i=0; ;i++)
			{
				gotoxy(0,0);
				gotoxy(0,21);
				genre_neu = getchar();
				fflush(stdin);
				clrPosition(21,0,80);

				if(genre_neu == 'e')
				{
					exit (0);
				}

				else if (genre_neu == '0')
				{
					return 0;
				}

				else if (genre_neu >= '1' && genre_neu <= '8')
				{
					detail_search->genre = genre_neu;
					break;
				}

				else 
				{
					clrPosition(21,0,80);
					gotoxy(0,21);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
				}
			}

			clrPosition(21,0,80);
			clrPosition(22,0,80);
			clrPosition(23,0,80);
			clrPosition(4,0,80);
			break;
		}

	case '7':
		{

			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(2);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Text ein (max 1024 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,6);
			fgets (text, (MAX_TEXT_LENGTH), stdin);
			fflush(stdin);

			if (text[0] == '0' && text[1] == '\n')
			{
				return 0;
			}

			else if (text[0] == 'e' && text[1] == '\n')
			{
				exit (0);
			}

			text[strlen(text)-1] ='\0';
			strcpy_s(detail_search->text, sizeof(text) ,text);
			break;
		}

		}
		detail_search = NULL;
		free (detail_search);
		timeinfo = NULL;
		free (timeinfo);
	}
}