#include <stdio.h>
#include <stdlib.h>

int size;

typedef struct Node
{
    int key;
    struct Node* next;
} Node;

Node* hashTable[100];

void Insert(int key)
{
    int index = key%size;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->next=NULL;
    
    if(hashTable[index]==NULL)
    {
        hashTable[index] = newNode;
    }else
    {
        newNode->next=hashTable[index];
        hashTable[index] = newNode;
    }
}

void Display()
{
    int i = 0;
    for(i=0;i<size;i++)
    {
        printf("key - %d :",i);
        Node* temp = hashTable[i];
        while(temp!=NULL)
        {
            printf("%d->",temp->key);
            temp=temp->next;
        }
            printf("NULL\n");
    }
}

void Search(int element)
{
    int i = 0;
    for(i=0;i<size;i++)
    {
        Node* temp = hashTable[i];
        while(temp!=NULL)
        {
        if(temp->key==element)
        {
            printf("Element found at %d",i);
            return;
        } else
        {
           temp=temp->next;
        }
        }
    }
    printf("Element not found");
    return;
}

int main()
{
    int choice = 0;
    
    printf("\nEnter array size : ");
    scanf("%d",&size);
    
    do
    {
        printf("\nEnter your choice:\n1. Insert\n2. Display\n3. Search\n4. Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
               int element;
               printf("\nEnter element to be inserted :");
               scanf("%d",&element);
               Insert(element);
               break;
            case 2:
               Display();
               break;
            case 3:
               int value;
               printf("Enter element to be searched");
               scanf("%d",&value);
               Search(value);
               break;
            case 4:
               printf(">>>EXITING<<<");
               break;
            default :
               printf("\nINVALID OPTION");
               break;
        }
    }while(choice!=4);
    return 0;
}
