#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	false,
	true
}Bool;

/* Définition d'un maillon de la DListe */
typedef struct DListNode
{
	int value;
	struct DListNode *back;
	struct DListNode *next;
}DListNode;

/* Définition d'une DListe */
typedef struct DList
{
	int length;
	struct DListNode *begin;
	struct DListNode *end;
}*DList;

//Retourne une DListe vide

DList new_dlist(void)
{
	return NULL;
}

//Teste si une DListe est vide
Bool is_empty_dlist(DList li)
{
	if(li == NULL)
		return true;

	return false;
}

//Retourne la longueur d'une DListe
int dlist_length(DList li)
{
	if(is_empty_dlist(li))
		return 0;

	return li->length;
}

//Retourne le premier élément de la DListe
int dlist_first(DList li)
{
	if(is_empty_dlist(li))
		exit(1);

	return li->begin->value;
}


//Retourne le dernier élément de la DListe
int dlist_last(DList li)
{
	if(is_empty_dlist(li))
		exit(1);

	return li->end->value;
}

//Affiche une DListe
void print_dlist(DList li)
{
	if(is_empty_dlist(li))
	{
		printf("Rien a afficher, la DListe est vide.\n");
		return;
	}

	DListNode *temp = li->begin;

	while(temp != NULL)
	{
		printf("[%d] ", temp->value);
		temp = temp->next;
	}

	printf("\n");
}

//Insère un élément en fin de DListe
DList push_back_dlist(DList li, int x)
{
	DListNode *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;
	element->back = NULL;

	if(is_empty_dlist(li))
	{
		li = malloc(sizeof(*li));

		if(li == NULL)
		{
			fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
			exit(EXIT_FAILURE);
		}

		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->end->next = element;
		element->back = li->end;
		li->end = element;
	}

	li->length++;

	return li;
}

//Insère un élément en début de DListe
DList push_front_dlist(DList li, int x)
{
	DListNode *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;
	element->back = NULL;

	if(is_empty_dlist(li))
	{
		li = malloc(sizeof(*li));

		if(li == NULL)
		{
			fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
			exit(EXIT_FAILURE);
		}

		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->begin->back = element;
		element->next = li->begin;
		li->begin = element;
	}

	li->length++;

	return li;
}
// Retire un élément en fin de DListe
DList pop_back_dlist(DList li)
{
	if(is_empty_dlist(li))
	{
		printf("Rien a supprimer, la DListe est deja vide.\n");
		return new_dlist();
	}

	if(li->begin == li->end)
	{
		free(li);
		li = NULL;

		return new_dlist();
	}

	DListNode *temp = li->end;

	li->end = li->end->back;
	li->end->next = NULL;
	temp->next = NULL;
	temp->back = NULL;

	free(temp);
	temp = NULL;

	li->length--;

	return li;
}

//Retire un élément en début de DListe
DList pop_front_dlist(DList li)
{
	if(is_empty_dlist(li))
	{
		printf("Rien a supprimer, la DListe est deja vide.\n");
		return new_dlist();
	}

	if(li->begin == li->end)
	{
		free(li);
		li = NULL;

		return new_dlist();
	}

	DListNode *temp = li->begin;

	li->begin = li->begin->next;
	li->begin->back = NULL;
	temp->next = NULL;
	temp->back = NULL;

	free(temp);
	temp = NULL;

	li->length--;

	return li;
}

//Nettoie complètement une DListe de ses éléments

DList clear_dlist(DList li)
{
	while(!is_empty_dlist(li))
		li = pop_back_dlist(li);

	return new_dlist();
}
int main()
{
	DList mylist = new_dlist();
	mylist = push_back_dlist(mylist,14);
	mylist = push_back_dlist(mylist,6);
	mylist = push_front_dlist(mylist, 9);
	print_dlist(mylist);
	mylist = pop_back_dlist(mylist);
	print_dlist(mylist);
}