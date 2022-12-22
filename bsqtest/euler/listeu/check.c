#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
} *stnode;

void createNodeList(int num)
{
    struct node *fnNode, *tmp;
    int i;
    stnode = (struct node *)malloc(sizeof(struct node));
    stnode-> num = num;      
    stnode-> nextptr = NULL;
    tmp = stnode;
    fnNode = (struct node *)malloc(sizeof(struct node));
    fnNode->num = num;
    fnNode->nextptr = NULL; 
    tmp->nextptr = fnNode; 
    tmp = tmp->nextptr;
} 

void NodeInsertatBegin(int num)
{
    struct node *fnNode;
    
    fnNode = (struct node*)malloc(sizeof(struct node));

    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->num = num; 
        fnNode->nextptr = stnode; 
        stnode = fnNode; 
    }
}

void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   // prints the data of current node
            tmp = tmp->nextptr;                 // advances the position of current node
        }
    }
}
 
int main()
{
    int n,num;
    createNodeList(9);
    displayList();
    NodeInsertatBegin(8);
    displayList();

    return 0;
}