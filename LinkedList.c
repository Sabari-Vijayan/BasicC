#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

//Function for inserting at beginning
void ISB(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next=head;
    newNode->data=value;
    head=newNode;
}

//Function for inserting at end
void ISE(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(head==NULL)
    ISB(value);
    else
    {
        struct Node* temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newNode->data=value;
        newNode->next=NULL;
        temp->next=newNode;
    }
}

//Function for deleting an element from the beginning
void DFB()
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

//Function for deleting an element from the end
void DFE()
{
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY");
        return;
    }
    else if(head->next==NULL)
    {
         printf("DELETED ELEMENT %d",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        struct Node* temp = head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        printf("DELETED ELEMENT %d",(temp->next)->data);
        free(temp->next);
        temp->next=NULL;
    }
}

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
         printf("%d-->",temp->data);
         temp=temp->next;
      }
      printf("NULL");
   }
}

int main() 
{

   int choice=0;
   printf("\n1. Insert at beginning\n2. Insert at ending\n3. Delete from beginning\n4. Delete from ending\n5. Display\n6. Exit\n");
  
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
               ISB(item);
               display();
               break;
           }
           case 2:
           {
               int item;
               printf("Enter value");
               scanf("%d",&item);
               ISE(item);
               display();
               break;
           }
           case 3:
           {
               DFB();
               break;
           }
           case 4:
           {
               DFE();
               break;
           }
           case 5:
           {
               printf("\n");
               display();
               break;
           }
           case 6:
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
   }while(choice!=6);
return 0;
}