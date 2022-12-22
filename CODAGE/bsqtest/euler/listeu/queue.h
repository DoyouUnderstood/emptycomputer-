#ifndef __QUEUE__H__
#define __QUEUE__H__

	/* Définition du type Booléen */
	typedef enum
	{
		false,
		true
	}Bool;

	/* Définition d'une File */
	typedef struct QueueElement
	{
		int value;
		struct QueueElement *next;
	}QueueElement, *Queue;

	/* Paramètres de la File */
	static QueueElement *first = NULL;
	static QueueElement *last = NULL;
	static int nb_elements = 0;

	/* Prototypes */
	Bool is_empty_queue(void);
	int queue_length(void);
	int queue_first(void);
	int queue_last(void);
	void print_queue(void);
	void push_queue(int x);
	void pop_queue(void);
	void clear_queue(void);

#endif