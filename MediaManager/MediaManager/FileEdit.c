#include "FileEdit.h"

static char * filePath;

//Setzt den dateipfad zum laden der liste
void setFilePath(char * pfad)
{
	filePath = pfad;
}

//F�gt der Datei einen neuen Datensatz hinzu
char saveToFile (Node * List, Details * Detail)
{

}

//L�dt einen Datensatz aus der Datei
Details * loadFromFile (Node * List , char Option)
{

}

//Speichert die aktuelle Liste in einer TXT Datei (Titel / Details)
char printListeToFile (Node * List, char Option)
{

}

//Sortiert die akltuelle Liste nach dem Parameter
char sortFile (Node * List, int Option)
{

}

//Sucht in der Datei mit den angegebenen Parametern
Node * searchInFile (Details * Detail)
{

}