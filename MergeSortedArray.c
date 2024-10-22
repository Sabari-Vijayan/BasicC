//C program to sort two arrays and merge them into single array

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int arr1[4]={1,2,3,4};
    int arr2[6]={5,6,7,8,9,0};
    int newarr[10];
    int i=0,j=0,k=0;
    while(i<4 && j<6)
    {
        if(arr1[i]<arr2[j])
        {
            newarr[k]=arr1[i];
            i++;
            k++;
        }else
        {
          newarr[k]=arr2[j];
          j++;
          k++;
        }
    }
    while(i<4)
    {
        newarr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<6)
    {
        newarr[k]=arr2[j];
        j++;
        k++;
    }
    printf("Array 1:");
     for(i=0;i<4;i++)
    {
        printf("%d",arr1[i]);
    }
    printf("\nArray 2:");
     for(i=0;i<6;i++)
    {
        printf("%d",arr2[i]);
    }
    printf("\nSorted and Merged array :");
    for(i=0;i<10;i++)
    {
        printf("%d",newarr[i]);
    }

    return 0;
}
