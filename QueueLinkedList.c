#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int maxsize = 5;//max size of queue is 5
int size = 0;

struct Node* head = NULL;

void enqueue(int value)
{
   if(size==maxsize)
   {
      printf("The queue is full\n");
      return;
   }
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   if(head==NULL)
   {
      newNode->data=value;
      newNode->next=NULL;
      head=newNode;
   }
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
   size++;
   printf("Enqueued %d ,now size of queue is %d\n",value,size);
}
void dequeue()
{
   if(head==NULL)
   {
      printf("THE QUEUE IS EMPTY\n");
      return; 
   } 
   struct Node* temp = head;
   head=head->next;
   printf("Dequeue element %d now size is %d\n",temp->data,size-1);
   free(temp);
   size--;
  
}
void display()
{
   if(head==NULL)
    {
        printf("THE QUEUE IS EMPTY\n");
        return;
    }
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}

void main()
{

   int choice;
   do
   {
       printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           {
               int value;
               printf("\nEnter the value : ");
               scanf("%d",&value);
               enqueue(value);
               break;
           }
           case 2:
           {
               dequeue();
               break;
           }
           case 3:
           {
               display();
               break;
           }
           case 4:
           {
               printf("...EXITING...");
               break;
           }
           default :
           {
               printf("INVALID OPTION");
           }
       }
   }while(choice!=4);
  
   return;

}