struct Knoten {
	char Titel [50];
	int Pos;
	Knoten * next;
	Knoten * prev;
}

Knoten * initList (char * Pfad);
//Liest alle Titel und deren Positionen aus der Datei aus und erstellt eine Liste
//Gibt das erste Element der Knoten zur�ck

void addItem (char * Pfad, Details * Detail);
//Fr�gt alle Paramenter des neuem Items ab
//F�gt am Ende der Liste ein neues Element hinzu
//F�gt der Datei den neuen Datensatz hinzu

void deleteItem (char * Pfad, Knoten * List);
//L�scht den Datensatz in der Datei
//L�scht das Element aus der Liste

Knoten * searchItem (char * Pfad);
//Fr�gt die zu suchenden Parameter ab
//Sucht in der Datei nach den Parametern
//Speichert die Ergebnisse in einer Liste

void changeItem (char * Pfad, Knoten * List);
//Fr�gt das Element ab das ge�ndert weren soll
//Fr�gt nach dem zu �ndernden Parameter/n
//�ndert die Werte in der Datei

void sortList (char * Pfad);
//Fr�gt den Wert nach dem Sortiert werden soll
//Sortiert die Datei nach den Kriterien