#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "studlist.h"


Student * list_SearchId (const StudList * l, const int id)
{
	
    while (l != NULL)
       {if (l->p->id == id)
            return(l->p);
	else 
	    l = l->next;
       }
    return(NULL);
}


Student * list_SearchIdRec (const StudList * l, const int id)
{
	
    if(l == NULL)
	{
		return NULL;
	}
	else
	{
		if (l->p->id == id)
		{
            return(l->p);
		}
		else 
		{
			return list_SearchIdRec (l->next, id);	
		}
	}
}

Student * student_new (const char * name,  const int id)
{
    Student * ret;
    ret = (Student *) calloc(1, sizeof(Student));
    if( ! ret)
    {
        fprintf(stderr, 
        "Panic No space left in person_new\n");
        exit(1);
    }
    strncpy_s(ret->name,sizeof(ret->name), name, sizeof(name));
    ret->id = id;
    
    return ret;
}

StudList * list_newNode()
{
    StudList * ret = (StudList *) calloc(1, sizeof(StudList));
    if(! ret )
    {
        fprintf(stderr, 
		"Panic No space left in list_new\n");
        exit(1);
    }
    return ret;
}

void list_Insert(StudList ** l, 
                 const char * name, const int id)
{
    StudList * next = *l;
    
    /* Neuen Knoten einfuegen: */
    *l = list_newNode();    
    (*l)->p = student_new(name, id);
    (*l)->next = next;
}


void list_Print(const StudList * l, FILE * f)
{
    while (l != NULL)
    {
        fprintf(f,"%06d %s\n", l->p->id,l->p->name); 
		l = l->next;
    }
}
