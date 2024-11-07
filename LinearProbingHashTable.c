#include <stdio.h>
#include <stdlib.h>

int size;
int hashTable[100];

void Insert(int key)
{
    int index = key % size;

    for (int i = 0; i < size; i++)
    {
        int newIndex = (index + i) % size; // Proper linear probing calculation
        if (hashTable[newIndex] == -1) // Empty slot check
        {
            hashTable[newIndex] = key;
            return;
        }
    }
    printf("Table is full\n");
}

void Display()
{
    printf("Hash Table:\n");
    for (int i = 0; i < size; i++)
    {
        if (hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : NULL\n", i);
    }
}

void Search(int element)
{
    int index = element % size;

    for (int i = 0; i < size; i++)
    {
        int newIndex = (index + i) % size;
        if (hashTable[newIndex] == element)
        {
            printf("Element found at index %d\n", newIndex);
            return;
        }
        if (hashTable[newIndex] == -1) // Stop search if an empty slot is found
            break;
    }
    printf("Element not found\n");
}

int main()
{
    int choice;

    printf("Enter size of hash table: ");
    scanf("%d", &size);

    // Initialize hash table with -1 for empty slots
    for (int i = 0; i < size; i++)
        hashTable[i] = -1;

    do
    {
        printf("\nEnter your choice:\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: {
                int element;
                printf("Enter element to be inserted: ");
                scanf("%d", &element);
                Insert(element);
                break;
            }
            case 2:
                Display();
                break;
            case 3: {
                int value;
                printf("Enter element to be searched: ");
                scanf("%d", &value);
                Search(value);
                break;
            }
            case 4:
                printf(">>> EXITING <<<\n");
                break;
            default:
                printf("INVALID OPTION\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
