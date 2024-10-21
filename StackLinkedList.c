//IMPLEMENTING STACK
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

//Function for inserting an element into the stack
void Insert(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next=head;
    newNode->data=value;
    head=newNode;
}

//Function for deleting an element from the stack
void Delete()
{
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY");
        return;
    }
    else
    {
    struct Node* temp = head;
    printf("DELETED ELEMENT %d",head->data);
    head=head->next;
    free(temp);
    temp=NULL;
    }
}

//Function for displaying the stack
void display()
{
   if(head==NULL)
   {
       printf("\nLIST IS EMPTY.");
       return;
   }
   else
   {
      struct Node* temp = head;
      while(temp!=NULL)
      {
         printf("%d\n",temp->data);
         temp=temp->next;
      }
      printf("NULL");
   }
}

int main() 
{

   int choice=0;
   printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
  
   do
   {
       printf("\nEnter your choice: ");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           {
               int item;
               printf("Enter value");
               scanf("%d",&item);
               Insert(item);
               display();
               break;
           }
           case 2:
           {
               Delete();
               break;
           }
           case 3:
           {
               printf("\n");
               display();
               break;
           }
           case 4:
           {
               printf("...EXITING...");
               break;
           }
           default:
           {
               printf("Invalid option");
               break;
           }
       }
   }while(choice!=4);
return 0;
}
