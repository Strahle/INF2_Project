#include "Eingabe.h"

//char gotoxy(int xpos, int ypos)
//{
//	COORD scrn;    
//	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
//	scrn.X = xpos; scrn.Y = ypos;
//	SetConsoleCursorPosition(hOuput,scrn);
//	return -1;
//} 
//
//char clrPosition(char Line, char position ,char space)
//{
//	int i;
//	gotoxy(position,Line);
//	for (i = 1; i <= space; i++)
//	{
//		printf(" ");
//	}
//	return -1;
//}
//
//char setColor(char backColor, char fondColor)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),	backColor * 16 + fondColor);
//	return -1;
//}
//
//
//char Footer(boolean back)
//{
//	setColor(sonderBackground,sonderFond);
//	if(back)
//	{
//		gotoxy(55,24);
//		printf("99: Zur\x81""ck\t");
//	}
//	else
//	{
//		gotoxy(72,24);
//	}
//	printf("-1: exit\n");
//
//	setColor(standBackground,standFond);
//	return;
//}

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
	Footer(1);
	gotoxy(0,4);
	printf("Bitte geben Sie einen Titel ein (max 50 Zeichen): ");
	gotoxy(0,0);
	gotoxy(0,23);
	fflush(stdin);

	fgets(titel, (TITLE_LENGTH), stdin);
	titel[strlen(titel)-1] ='\0';
	clrPosition(23,0,80);
	strcpy_s(detail_new->titel, sizeof(titel) ,titel);

	if (titel[0] == '-' && titel[1] == '1'&& titel[2] == '\n')
	{
		return 0;
	}

	else if (titel[0] == '9' && titel[1] == '9'&& titel[2] == '\n')
	{
	exit (0);
	}
	//printf("%s", detail_new->titel);
	clrPosition(22,0,0);

	switch (medium)//Bücher =1, CD=2, DVD=3
	{
	case '1':
		{
			gotoxy(0,4);
			setColor(0,15);
			printf("Bitte geben Sie einen Autor ein (max 50 Zeichen): ");
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
			regisseur[strlen(regisseur)-1] ='\0';
			fflush(stdin);
			if (regisseur[0] == '-' && regisseur[1] == '1'&& regisseur[2] == '\n')
			{
				return 0;
			}

			else if (regisseur[0] == '9' && regisseur[1] == '9'&& regisseur[2] == '\n')
			{
				exit (0);
			}

			strcpy_s(detail_new->regisseur, sizeof(regisseur) ,regisseur);
			clrPosition(23,0,80); //-> Verknüpfung erstellen
			//printf("%s", detail_new->regisseur);
			break;
		}

	case '2':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Interpreten ein (max 50 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
			regisseur[strlen(regisseur)-1] ='\0';
			fflush(stdin);
			if (regisseur[0] == '-' && regisseur[1] == '1'&& regisseur[2] == '\n')
			{
			return 0;
			}

			else if (regisseur[0] == '9' && regisseur[1] == '9'&& regisseur[2] == '\n')
			{
				exit (0);
			}
			strcpy_s(detail_new->regisseur, sizeof(regisseur) ,regisseur);
			//printf("%s", detail_new->regisseur);
			break;
		}
	case '3':
		{
			
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,4);
			printf("Bitte geben Sie einen Regisseur ein (max 50 Zeichen): ");
			gotoxy(0,23);
			gotoxy(0,0);
			fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
			regisseur[strlen(regisseur)-1] ='\0';
			fflush(stdin);
				clrPosition(23,0,80);
			if (regisseur[0] == '-' && regisseur[1] == '1'&& regisseur[2] == '\n')
			{
				return 0;
			}

			else if (regisseur[0] == '9' && regisseur[1] == '9'&& regisseur[2] == '\n')
			{
				exit (0);
			}
			strcpy_s(detail_new->regisseur, sizeof(regisseur) ,regisseur);
			//printf("%s", detail_new->regisseur);
			break;
		}


	}

	switch (medium)//Bücher =1, CD=2, DVD=3
	{
	case '1':
		{
			gotoxy(0,4);
			printf("Bitte geben Sie einen Verlag ein (max 50 Zeichen): ");
			
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
			verlag[strlen(verlag)-1] ='\0';
			fflush(stdin);
			clrPosition(23,0,80);
			if (verlag[0] == '-' && verlag[1] == '1'&& verlag[2] == '\n')
			{
				return 0;
			}

			else if (verlag[0] == '9' && verlag[1] == '9'&& verlag[2] == '\n')
			{
				exit (0);
			}
			strcpy_s(detail_new->verlag, sizeof(verlag) ,verlag);
			printf("%s", detail_new->verlag);
			break;
		}

	case '2':
		{
			gotoxy(0,4);
			printf("Bitte geben Sie ein Label ein (max 50 Zeichen): ");
			
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
			verlag[strlen(verlag)-1] ='\0';
			fflush(stdin);
				clrPosition(23,0,80);
			if (verlag[0] == '-' && verlag[1] == '1'&& verlag[2] == '\n')
			{
				return 0;
			}

			else if (verlag[0] == '9' && verlag[1] == '9'&& verlag[2] == '\n')
			{
				exit(0);
			}
			strcpy_s(detail_new->verlag, sizeof(verlag) ,verlag);
			printf("%s", detail_new->verlag);
			break;
		}
	case '3':
		{
			clrPosition(4,0,80);
			gotoxy(0,4);
			printf("Bitte geben Sie ein Studio ein (max 50 Zeichen): ");
			
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,0);
			gotoxy(0,23);
			fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
			verlag[strlen(verlag)-1] ='\0';
			fflush(stdin);
				clrPosition(23,0,80);
			if (verlag[0] == '-' && verlag[1] == '1'&& verlag[2] == '\n')
			{
				return 0;
			}

			else if (verlag[0] == '9' && verlag[1] == '9'&& verlag[2] == '\n')
			{
				exit(0);
			}
			strcpy_s(detail_new->verlag, sizeof(verlag) ,verlag);
			//printf("%s", detail_new->verlag);
			break;
		}
	}

	clrPosition(4,0,80);
	gotoxy(0,4);
	printf("Bitte geben Sie die ISBN-Nummer ein : ");

	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(1);
	gotoxy(0,0);
	gotoxy(0,23);
	clrPosition(22,0,80);

	for (i=0; ;i++){

		scanf_s ("%lf", &ISBN);
		fflush(stdin);
		clrPosition(23,0,80);
		if (ISBN == 99)
		{
			exit(0); //-> Verknüpfung erstellen
		}
		else if (ISBN == -1)
		{
			return 0;
		}

		else if (ISBN >= 1000000000 && ISBN <= 1000000000000)
		{
			detail_new->isbn = ISBN;
			//printf("%lf", detail_new->isbn);
			break;
		}
		else
		{
			clrPosition(22,0,80);
			setColor(fehlerBackground,fehlerFond);
			printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
			setColor(standBackground,standFond);
			//clrPosition(22,0,0);


			//printf("Ungueltige Eingabe!");
		}
	}





	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(1);
	gotoxy(0,23);
	clrPosition(22,0,80);

	//time_h
	gotoxy(0,4);
	printf("Bitte geben Sie das Erscheinungsjahr ein: ");
	gotoxy(0,0);
	gotoxy(0,23);

	for (a=0; ;a++){

		scanf_s ("%i", &Jahr);
		fflush(stdin);
		clrPosition(23,0,80);

		if (Jahr == 99)
		{
			exit(0);
		}
		else if (Jahr == (-1))
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

	gotoxy(0,4);
	printf("Bitte geben Sie das Erscheinungsmonat ein: ");
	gotoxy(0,0);
	gotoxy(0,23);

	for (b=0; ;a++){
		scanf_s ("%i", &Monat);
		fflush(stdin);
		clrPosition(23,0,80);

		if (Monat == 99)
		{
			exit(0);
		}
		else if (Monat == (-1))
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

	gotoxy(0,4);
	printf("Bitte geben Sie das Erscheinungstag ein: ");
	gotoxy(0,23);


	for (c=0; ;c++){

		scanf_s ("%i", &Tag);
		fflush(stdin);
		clrPosition(23,0,80);

		if (Tag == 99)
		{
			exit(0);
		}
		else if (Tag == (-1))
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
	detail_new->erscheinungsdatum = mktime ( timeinfo );

	//printf("eingelesene Zeit: %i", ctime_s(detail_new->erscheinungsdatum, sizeof));


	//enum genre_film(aktion = 1, drama = 2, komoedie = 3, krimi = 4, doku = 5, zeichentrick = 6, science-fiktion = 7, thriller = 8);

	clrPosition(4,0,80);
	gotoxy(0,4);
	printf ("Bitte geben Sie ein Genre ein: ");

	switch (medium)
	{
	case '1':
		{
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
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
			Footer(1);
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
			Footer(1);
			gotoxy(0,22);
			setColor(sonderBackground,sonderFond);
			printf("1: Aktion\t\t2: Drama\t\t3: Kom\x94""die\t\t\t4: Krimi\t\t5: Doku\t\t\t6: Zeichentrick\t\t\t7: Science-Fiktion\t8: Thriller");
			setColor(standBackground,standFond);
			break;
			//gotoxy(0,20);
		}//clrPosition(22,0,80);
			//enum genre_film(aktion = 1, drama = 2, komoedie = 3, krimi = 4, doku = 5, zeichentrick = 6, science-fiktion = 7, thriller = 8);
		}
		//enum genre_musik(rock = 1, pop = 2, klassik = 3, hip-hop = 4, techno = 5, dance = 6, metal = 7, house = 8);


		//enum genre_buch(sachbuch = 1, kinderbuch = 2, comic = 3, thriller = 4, horror = 5, maerchen = 6, biografie = 7, abenteuer = 8);

				

		for (i=0; ;i++){
			gotoxy(0,0);
			gotoxy(0,21);
			genre_neu = getchar();
			fflush(stdin);
			clrPosition(21,0,80);

			if(genre_neu == '9')
			{
				exit (0);
			}
			else if (genre_neu == '-')
			{
				return 0;
			}
			else if (genre_neu >= '1' && genre_neu <= '8')
			{
				detail_new->genre = genre_neu;
				//printf("genre: %c", detail_new->genre);
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

		gotoxy(0,24);
		setColor(sonderBackground,sonderFond);
		printf("\t\t\t\t\t\t\t");
		Footer(1);
		gotoxy(0,23);
		clrPosition(21,0,80);
		clrPosition(22,0,80);
		clrPosition(23,0,80);
		gotoxy(0,0);
		gotoxy(0,4);
		printf("Bitte geben Sie einen Text ein (max 1024 Zeichen): ");
		gotoxy(0,6);


		fgets (text, (MAX_TEXT_LENGTH), stdin);
		text[strlen(text)-1] ='\0';
		if (text[0] == '-' && text[1] == '1'&& text[2] == '\n')
		{
			return 0;
		}

		else if (text[0] == '9' && text[1] == '9'&& text[2] == '\n')
		{
			exit (0);
		}
		fflush(stdin);
		strcpy_s(detail_new->text, sizeof(text) ,text);

	return detail_new;
	}



/*Diese Funktion sucht fragt die Sucheingabe des Users ab und speichert sie in den typdef struct Details.
An die Funktion muss ein (int)-Parameter mit der Art des Mediums übergeben werden*/
Node * addoneItemInput (Node * Knot, char ele, char medium, char index)
{	
	time_t rawtime;
	Details * detail_new;
	struct tm * timeinfo;

	int i;

	//char ele = '6';
	//char medium = 'd';

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
	switch (ele) 
	{
	case '1':
		{
			char titel[TITLE_LENGTH];

			gotoxy(0,4);
			printf("Bitte geben Sie einen Titel ein (max 50 Zeichen): ");
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,0);
			gotoxy(0,23);
			fflush(stdin);
			fgets(titel, (TITLE_LENGTH), stdin);
			titel[strlen(titel)-1] ='\0';
			strcpy_s(Knot->nodeDetails->titel, sizeof(titel) ,titel);
			if (titel[0] == '-' && titel[1] == '1'&& titel[2] == '\n')
			{
				return 0;
			}

			else if (titel[0] == '9' && titel[1] == '9'&& titel[2] == '\n')
			{
		exit (0);
			}
			//printf("%s", detail_new->titel);
			return Knot;
			break;
		}

	case '2':
		{
			char regisseur[ MAX_VERLAG_LENGTH];

			switch (medium)//Bücher =1, CD=2, DVD=3
			{
			case '1':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie einen Autor ein (max 50 Zeichen): ");
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
					regisseur[strlen(regisseur)-1] ='\0';
					fflush(stdin);
					if (regisseur[0] == '-' && regisseur[1] == '1'&& regisseur[2] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == '9' && regisseur[1] == '9'&& regisseur[2] == '\n')
					{
						exit;
					}

					strcpy_s(Knot->nodeDetails->regisseur, sizeof(regisseur) ,regisseur);
					//printf("%s", detail_new->regisseur);
					break;
				}

			case '2':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie einen Interpreten ein (max 50 Zeichen): ");
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
					regisseur[strlen(regisseur)-1] ='\0';
					fflush(stdin);
					if (regisseur[0] == '-' && regisseur[1] == '1'&& regisseur[2] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == '9' && regisseur[1] == '9'&& regisseur[2] == '\n')
					{
						exit;
					}
					strcpy_s(Knot->nodeDetails->regisseur, sizeof(regisseur) ,regisseur);
					//printf("%s", detail_new->regisseur);
					break;
				}
			case '3':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie einen Regisseur ein (max 50 Zeichen): ");
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_VERLAG_LENGTH), stdin);
					regisseur[strlen(regisseur)-1] ='\0';
					fflush(stdin);
					if (regisseur[0] == '-' && regisseur[1] == '1'&& regisseur[2] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == '9' && regisseur[1] == '9'&& regisseur[2] == '\n')
					{
						exit (0);
					}
					strcpy_s(Knot->nodeDetails->regisseur, sizeof(regisseur) ,regisseur);
					//printf("%s", detail_new->regisseur);
					break;
				}
			}
return Knot;
			break;

		}

	case '3':
		{
			char verlag[ MAX_VERLAG_LENGTH];

			switch (medium)//Bücher =1, CD=2, DVD=3
			{
			case '1':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie einen Verlag ein (max 50 Zeichen): ");
					
					fflush(stdin);
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					verlag[strlen(verlag)-1] ='\0';
					if (verlag[0] == '-' && verlag[1] == '1'&& verlag[2] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == '9' && verlag[1] == '9'&& verlag[2] == '\n')
					{
						exit (0);
					}
					strcpy_s(Knot->nodeDetails->verlag, sizeof(verlag) ,verlag);
					//printf("%s", detail_new->verlag);
					break;
				}

			case '2':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie ein Label ein (max 50 Zeichen): ");
					fflush(stdin);
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					verlag[strlen(verlag)-1] ='\0';
					if (verlag[0] == '-' && verlag[1] == '1'&& verlag[2] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == '9' && verlag[1] == '9'&& verlag[2] == '\n')
					{
						exit (0);
					}
					strcpy_s(Knot->nodeDetails->verlag, sizeof(verlag) ,verlag);
					//printf("%s", detail_new->verlag);
					break;
				}
			case '3':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie ein Studio ein (max 50 Zeichen): ");
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);
					verlag[strlen(verlag)-1] ='\0';
					if (verlag[0] == '-' && verlag[1] == '1'&& verlag[2] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == '9' && verlag[1] == '9'&& verlag[2] == '\n')
					{
						exit (0);
					}
					strcpy_s(Knot->nodeDetails->verlag, sizeof(verlag) ,verlag);
					//printf("%s", detail_new->verlag);
					break;
				}
			}
			return Knot;
			break;

		}


	case '4':
		{	
			double ISBN;
			int i;

			gotoxy(0,4);
			printf("\nBitte geben Sie die ISBN-Nummer ein : ");

			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,0);
			gotoxy(0,23);
			clrPosition(22,0,80);

			for (i=0; ;i++){


				scanf_s ("%lf", &ISBN);
				fflush(stdin);
				clrPosition(23,0,80);
				if (ISBN == 99)
				{
					exit (0); 
				}
				else if (ISBN == -1)
				{
					return 0; 
				}

				else if (ISBN >= 1000000000 && ISBN <= 1000000000000)
				{
					Knot->nodeDetails->isbn = ISBN;
					//printf("%lf", detail_new->isbn);
					break;
				}
				else
				{
					clrPosition(22,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
					//clrPosition(22,0,0);


					//printf("Ungueltige Eingabe!");
				}
			}

			return Knot;
			break;
		}

	case '5':
		{
			int Jahr, Monat, Tag;
			int a,b,c;

			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,23);
			clrPosition(22,0,80);

			//time_h
			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungsjahr ein: ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (a=0; ;a++){
				
				scanf_s ("%i", &Jahr);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Jahr == 99)
				{
					exit(0);
				}
				else if (Jahr == (-1))
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

			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungsmonat ein: ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (b=0; ;a++){
				scanf_s ("%i", &Monat);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Monat == 99)
				{
					exit (0); //-> Verknüpfung erstellen
				}
				else if (Monat == (-1))
				{
					return 0; //-> Verknüpfung erstellen
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

			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungstag ein: ");
			gotoxy(0,0);
			gotoxy(0,23);


			for (c=0; ;c++){
				
				scanf_s ("%i", &Tag);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Tag == 99)
				{
					exit (0); //-> Verknüpfung erstellen
				}
				else if (Tag == (-1))
				{
					return 0; //-> Verknüpfung erstellen
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

			//printf("eingelesene Zeit: %i", ctime_s(detail_new->erscheinungsdatum, sizeof));
			return Knot;
			break;
		}

	case '6':
		{
			//enum genre_film(aktion = 1, drama = 2, komoedie = 3, krimi = 4, doku = 5, zeichentrick = 6, science-fiktion = 7, thriller = 8);
			char genre_neu;
			int i;
			switch (medium)
			{
			case '1':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
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
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Rock\t\t\t2: Pop\t\t\t3: Klassik\t\t\t4: Hip-Hop\t\t5: Techno\t\t6: Dance\t\t\t7: Metal\t\t8: House");
					setColor(standBackground,standFond);
					break;

			case '3':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Aktion\t\t2: Drama\t\t3: Kom\x94""die\t\t\t4: Krimi\t\t5: Doku\t\t\t6: Zeichentrick\t\t\t7: Science-Fiktion\t8: Thriller");
					setColor(standBackground,standFond);
					break;
					//gotoxy(0,20);
					//clrPosition(22,0,80);
					//enum genre_film(aktion = 1, drama = 2, komoedie = 3, krimi = 4, doku = 5, zeichentrick = 6, science-fiktion = 7, thriller = 8);
				}
				//enum genre_musik(rock = 1, pop = 2, klassik = 3, hip-hop = 4, techno = 5, dance = 6, metal = 7, house = 8);


				//enum genre_buch(sachbuch = 1, kinderbuch = 2, comic = 3, thriller = 4, horror = 5, maerchen = 6, biografie = 7, abenteuer = 8);
				}

			}

			gotoxy(0,4);
			printf ("Bitte geben Sie ein Genre ein: ");
			gotoxy(0,0);
			gotoxy(0,21);


			for (i=0; ;i++){
				genre_neu = getchar();
				fflush(stdin);
				clrPosition(21,0,80);

				if(genre_neu == '9')
				{
					exit(0); //-> Verknüpfung erstellen
				}
				else if (genre_neu == '-')
				{
					return 0; //-> Verknüpfung erstellen
				}
				else if (genre_neu >= '1' && genre_neu <= '7')
				{
					detail_new->genre = genre_neu;
					//printf("genre: %c", detail_new->genre);
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
		}
			break;
		

	case '7':
		{
			char text [MAX_TEXT_LENGTH];

			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,23);
			clrPosition(22,0,80);

			
			gotoxy(0,4);
			printf("Bitte geben Sie einen Text ein (max 1024 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,6);


			fgets (text, (MAX_TEXT_LENGTH), stdin);
			text[strlen(text)-1] ='\0';
			if (text[0] == '-' && text[1] == '1'&& text[2] == '\n')
			{
				return 0;
			}

			else if (text[0] == '9' && text[1] == '9'&& text[2] == '\n')
			{
				exit (0);
			}
			fflush(stdin);
			strcpy_s(Knot->nodeDetails->text, sizeof(text) ,text);


			return Knot;
			break;
		}
			
		}

	}
}


/*Die Funktion deleteItemInput fragt ab welches Element einer Liste gelöscht werden soll. Benötigt wird ein char, welcher das Medium an die Funktion übergibt.*/
Node *  deleteItemInput (Node * Knot, char medium)
{
	//char itemdelete;
	//char medium ='b';

	char itemdelete;

	//char medium ='b';
	int control;
	int a, b, help = 0;

	/*switch (medium)
	{	
	case '1':
	{
	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	printf("\t\t\t\t\t\t\t");
	Footer(1);
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
	Footer(1);
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
	Footer(1);
	gotoxy(0,22);
	setColor(sonderBackground,sonderFond);
	printf("1: Titel\t\t2: Regisseur\t\t3: Studio\t\t\t4: ISBN\t\t\t5: Erscheinungsdatum\t6: Genre\t\t\t7: Text");
	setColor(standBackground,standFond);
	break;
	}
	}*/

	gotoxy(0,24);
	setColor(sonderBackground,sonderFond);
	Footer(1);
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

			if (itemdelete == 99)
			{
				return NULL;
			}

			else if (itemdelete == e)
			{
				exit 0;
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
						clrPosition(0,23,80);
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
		{						//printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
			gotoxy(0,0);
			gotoxy(0,4);
			clrPosition(4,0,0);
			printf("Soll das Element wirklich geloescht werden? (J/N) "); 
			clrPosition(23,0,80);
			gotoxy(0,23);

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
					//goto weiter;
				}
				else if (control == 'n' || control == 'N')
				{
					help = 1;
					break;
					//goto anfang;
				}
				else if (control == '9')
				{
					printf("Exit"); //-> Verknüpfung erstellen
				}

				else if (control == '-')
				{
					printf("Back"); //-> Verknüpfung erstellen
				}


				else 
				{
					clrPosition(21,0,0);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
					help = 2;
					break;
					//goto start;
				}
			}

			if (help ==2)
			{
				break;
			}

		}

		if (help ==2)
		{
			help = 0;
			break;
		}
	}
}


/*Siehe changeoneItem*/
Details * searchItemInput (char medium, char ele)
{
	time_t rawtime;
	Details * detail_new;
	struct tm * timeinfo;

	//char ele = '6';
	//medium = 'd';

	detail_search = (Details*) malloc (sizeof (Details));
	timeinfo = (struct tm*) malloc (sizeof (struct tm));

	switch (ele) 
	{
	case '1':
		{
			char titel[TITLE_LENGTH];

			gotoxy(0,4);
			printf("Bitte geben Sie einen Titel ein (max 50 Zeichen): ");
			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,23);
			gotoxy(0,0);
			fgets(titel, (TITLE_LENGTH), stdin);
			fflush(stdin);
			titel[strlen(titel)-1] ='\0';
			strcpy_s(detail_search->titel, sizeof(titel) ,titel);
			//kaste aufrufen (if-abfrage für exit und zurück)
			//samuel muss vernüpfung zurück erstellen
			if (titel[0] == '-' && titel[1] == '1'&& titel[2] == '\n')
			{
				return 0;
			}

			else if (titel[0] == '9' && titel[1] == '9'&& titel[2] == '\n')
			{
				exit (0);
			}
			//printf("%s", detail_search->titel);

			return detail_search;
			break;

		}

	case '2':
		{
			char regisseur[ MAX_regisseur_LENGTH];

			switch (medium)//Bücher =1, CD=2, DVD=3
			{
			case '1':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie einen Autor ein (max 50 Zeichen): ");
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_regisseur_LENGTH), stdin);
					fflush(stdin);
					regisseur[strlen(regisseur)-1] ='\0';
					if (regisseur[0] == '-' && regisseur[1] == '1'&& regisseur[2] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == '9' && regisseur[1] == '9'&& regisseur[2] == '\n')
					{
						exit (0);
					}

					strcpy_s(detail_search->regisseur, sizeof(regisseur) ,regisseur);
					//printf("%s", detail_search->regisseur);
						return detail_search;
					break;
				}

			case '2':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie einen Interpreten ein (max 50 Zeichen): ");
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_regisseur_LENGTH), stdin);
					fflush(stdin);
					regisseur[strlen(regisseur)-1] ='\0';
					if (regisseur[0] == '-' && regisseur[1] == '1'&& regisseur[2] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == '9' && regisseur[1] == '9'&& regisseur[2] == '\n')
					{
						exit (0);
					}
					strcpy_s(detail_search->regisseur, sizeof(regisseur) ,regisseur);
					//printf("%s", detail_search->regisseur);
						return detail_search;
					break;
				}
			case '3':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie einen Regisseur ein (max 50 Zeichen): ");
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (regisseur, (MAX_regisseur_LENGTH), stdin);
					fflush(stdin);
					regisseur[strlen(regisseur)-1] ='\0';
					if (regisseur[0] == '-' && regisseur[1] == '1'&& regisseur[2] == '\n')
					{
						return 0;
					}

					else if (regisseur[0] == '9' && regisseur[1] == '9'&& regisseur[2] == '\n')
					{
						exit (0);
					}
					strcpy_s(detail_search->regisseur, sizeof(regisseur) ,regisseur);
					//printf("%s", detail_search->regisseur);
						return detail_search;
					break;
				}
			}

			break;

		}

	case '3':
		{
			char verlag[ MAX_VERLAG_LENGTH];

			switch (medium)//Bücher =1, CD=2, DVD=3
			{
			case '1':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie einen Verlag ein (max 50 Zeichen): ");
					
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);
					verlag[strlen(verlag)-1] ='\0';
					if (verlag[0] == '-' && verlag[1] == '1'&& verlag[2] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == '9' && verlag[1] == '9'&& verlag[2] == '\n')
					{
						exit (0)
					}
					strcpy_s(detail_search->verlag, sizeof(verlag) ,verlag);
					printf("%s", detail_search->verlag);
						return detail_search;
					break;
				}

			case '2':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie ein Label ein (max 50 Zeichen): ");
					
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);
					verlag[strlen(verlag)-1] ='\0';
					if (verlag[0] == '-' && verlag[1] == '1'&& verlag[2] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == '9' && verlag[1] == '9'&& verlag[2] == '\n')
					{
						exit (0);
					}
					strcpy_s(detail_search->verlag, sizeof(verlag) ,verlag);
					//printf("%s", detail_search->verlag);
						return detail_search;
					break;
				}
			case '3':
				{
					gotoxy(0,4);
					printf("Bitte geben Sie ein Studio ein (max 50 Zeichen): ");
					
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,0);
					gotoxy(0,23);
					fgets (verlag, (MAX_VERLAG_LENGTH), stdin);
					fflush(stdin);
					verlag[strlen(verlag)-1] ='\0';
					if (verlag[0] == '-' && verlag[1] == '1'&& verlag[2] == '\n')
					{
						return 0;
					}

					else if (verlag[0] == '9' && verlag[1] == '9'&& verlag[2] == '\n')
					{
						exit (0);
					}
					strcpy_s(detail_search->verlag, sizeof(verlag) ,verlag);
					//printf("%s", detail_search->verlag);
						return detail_search;
					break;
				}
			}

			break;

		}


	case '4':
		{	
			double ISBN;
			int i;

			gotoxy(0,4);
			printf("\nBitte geben Sie die ISBN-Nummer ein : ");

			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotxy(0,0)
			gotoxy(0,23);
			clrPosition(22,0,80);

			for (i=0; ;i++){


				scanf_s ("%lf", &ISBN);
				fflush(stdin);
				clrPosition(23,0,80);
				if (ISBN == 99)
				{
					exit (0); //-> Verknüpfung erstellen
				}
				else if (ISBN == -1)
				{
					return 0;; //-> Verknüpfung erstellen
				}

				else if (ISBN >= 1000000000 && ISBN <= 1000000000000)
				{
					detail_search->isbn = ISBN;
					//printf("%lf", detail_search->isbn);
					break;
				}
				else
				{
					clrPosition(22,0,80);
					setColor(fehlerBackground,fehlerFond);
					printf("Nicht erlaubte Eingabe. Bitte nochmal eingeben: ");
					setColor(standBackground,standFond);
					//clrPosition(22,0,0);


					//printf("Ungueltige Eingabe!");
				}
			}

				return detail_search;
			break;
		}

	case '5':
		{
			int Jahr, Monat, Tag;
			int a,b,c;



			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,23);
			clrPosition(22,0,80);

			//time_h
			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungsjahr ein: ");
			gotoxy (0,0);
			gotoxy(0,23);

			for (a=0; ;a++){

				scanf_s ("%i", &Jahr);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Jahr == 99)
				{
					exit(0);
				}
				else if (Jahr == (-1))
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

			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungsmonat ein: ");
			gotoxy(0,0);
			gotoxy(0,23);

			for (b=0; ;a++){
				scanf_s ("%i", &Monat);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Monat == 99)
				{
					exit (0);
				}
				else if (Monat == (-1))
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

			gotoxy(0,4);
			printf("Bitte geben Sie das Erscheinungstag ein: ");
			gotoxy(0,0);
			gotoxy(0,23);


			for (c=0; ;c++){

				scanf_s ("%i", &Tag);
				fflush(stdin);
				clrPosition(23,0,80);

				if (Tag == 99)
				{
					exit (0);
				}
				else if (Tag == (-1))
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
			detail_search->erscheinungsdatum = mktime ( timeinfo );

			//printf("eingelesene Zeit: %i", ctime_s(detail_search->erscheinungsdatum, sizeof));
				return detail_search;
			break;
		}

	case '6':
		{
			//enum genre_film(aktion = 1, drama = 2, komoedie = 3, krimi = 4, doku = 5, zeichentrick = 6, science-fiktion = 7, thriller = 8);
			char genre_neu;
			int i;
			switch (medium)
			{
			case '1':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
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
					Footer(1);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Rock\t\t\t2: Pop\t\t\t3: Klassik\t\t\t4: Hip-Hop\t\t5: Techno\t\t6: Dance\t\t\t7: Metal\t\t8: House");
					setColor(standBackground,standFond);
					break;

			case '3':
				{
					gotoxy(0,24);
					setColor(sonderBackground,sonderFond);
					printf("\t\t\t\t\t\t\t");
					Footer(1);
					gotoxy(0,22);
					setColor(sonderBackground,sonderFond);
					printf("1: Aktion\t\t2: Drama\t\t3: Kom\x94""die\t\t\t4: Krimi\t\t5: Doku\t\t\t6: Zeichentrick\t\t\t7: Science-Fiktion\t8: Thriller");
					setColor(standBackground,standFond);
					break;
					//gotoxy(0,20);
					//clrPosition(22,0,80);
					//enum genre_film(aktion = 1, drama = 2, komoedie = 3, krimi = 4, doku = 5, zeichentrick = 6, science-fiktion = 7, thriller = 8);
				}
				//enum genre_musik(rock = 1, pop = 2, klassik = 3, hip-hop = 4, techno = 5, dance = 6, metal = 7, house = 8);


				//enum genre_buch(sachbuch = 1, kinderbuch = 2, comic = 3, thriller = 4, horror = 5, maerchen = 6, biografie = 7, abenteuer = 8);
				}

			}

			gotoxy(0,4);
			printf ("Bitte geben Sie ein Genre ein: "); 
			gotoxy(0,0);
			gotoxy(0,21);


			for (i=0; ;i++){	
				genre_neu = getchar();
				fflush(stdin);
				clrPosition(21,0,80);

				if(genre_neu == '9')
				{
					exit (0);
				}
				else if (genre_neu == '-')
				{
					return 0;
				}
				else if (genre_neu >= '1' && genre_neu <= '8')
				{
					detail_search->genre = genre_neu;
					//printf("genre: %c", detail_search->genre);
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
				return detail_search;
			break;
		}

	case '7':
		{
			char text [MAX_TEXT_LENGTH];

			gotoxy(0,24);
			setColor(sonderBackground,sonderFond);
			printf("\t\t\t\t\t\t\t");
			Footer(1);
			gotoxy(0,23);
			clrPosition(22,0,80);


			gotoxy(0,4);
			printf("Bitte geben Sie einen Text ein (max 1024 Zeichen): ");
			gotoxy(0,0);
			gotoxy(0,6);


			fgets (text, (MAX_TEXT_LENGTH), stdin);
			fflush(stdin);
			text[strlen(text)-1] ='\0';
			if (text[0] == '-' && text[1] == '1'&& text[2] == '\n')
			{
				return 0;
			}

			else if (text[0] == '9' && text[1] == '9'&& text[2] == '\n')
			{
				exit (0);
			}
			fflush(stdin);
			strcpy_s(detail_search->text, sizeof(text) ,text);
			return detail_search;
			break;
		}

	}
}