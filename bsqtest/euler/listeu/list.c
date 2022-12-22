#include <stdio.h>
#include <stdlib.h>
	typedef enum
	{
		false,
		true
	}Bool;

typedef struct ListElement
{
	int value;
	struct ListElement *next;
}ListElement, *List;

List new_list(void)
{
	return NULL;
}

Bool is_empty_list(List li)
{
	if(li == NULL)
		return true;

	return false;
}

void print_list(List li)
{
	if(is_empty_list(li))
	{
		printf("Rien a afficher, la Liste est vide.\n");
		return;
	}

	while(li != NULL)
	{
		printf("%d ", li->value);
		li = li->next;
	}

	printf("\n");
}

int list_length(List li)
{
	int size = 0;

	if(is_empty_list(li))
		return size;

	while(li != NULL)
	{
		size++;
		li = li->next;
	}

	return size;
}
 // Ajoute un entier en fin de Liste
List push_back_list(List li, int x)
{
	ListElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		printf("Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;

	if(is_empty_list(li))
		return element;

	ListElement *temp;
	temp = li;

	while(temp->next != NULL)
		temp = temp->next;

	temp->next = element;

	return li;
}

// Ajoute un entier en début de Liste

List push_front_list(List li, int x)
{
	ListElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		printf("Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;

	if(is_empty_list(li))
		element->next = NULL;
	else
		element->next = li;

	return element;
}


//Supprime un entier de la fin de la Liste

List pop_back_list(List li)
{
	if(is_empty_list(li))
		return new_list();

	//Si la liste n'a qu'un seul élément
	if(li->next == NULL)
	{
		free(li);
		li = NULL;

		return new_list();
	}

	ListElement *temp = li;
	ListElement *before = li;

	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}

	before->next = NULL;

	free(temp);
	temp = NULL;

	return li;
}


//Supprime un entier de la tête de la Liste
List pop_front_list(List li)
{
	ListElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	if(is_empty_list(li))
		return new_list();

	element = li->next;

	free(li);
	li = NULL;

	return element;
}
List clear_list(List li)
{
	if(is_empty_list(li))
		return new_list();

	while(li != NULL)
		li = pop_front_list(li);

	return li;
}
int main()
{
	ListElement *list = new_list();
	list = push_back_list(list, 8);
	list = push_front_list(list, 9);
	list = push_front_list(list, 10);
	print_list(list);
}