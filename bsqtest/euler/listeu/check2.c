#include<stdio.h>  
#include<stdlib.h>    
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;

void empiler(int Valeur)
{
    struct node *q; 
    q = (struct node*)malloc(sizeof(struct node *));
    q->data =  Valeur;
    q->next = head;
    head = q;
}

void beginsert(int item)  
{  
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        ptr->data = item;  
        ptr->next = head;  
        head = ptr;    
    }  
}
void displayList()
{
    struct node *tmp;
    if(head == NULL)
    {
        printf(" No data found in the list.");
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            printf("%d ", tmp->data);   // prints the data of current node
            tmp = tmp->next;                 // advances the position of current node
        }
    }
}
void main ()  
{  
    beginsert(9);
    beginsert(4);
    empiler(8);
    beginsert(3);
    displayList();
}  