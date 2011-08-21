/**
Lab Program 9
Sparse Martix Search
Author Strider24/SkyKOG
*/

#include <stdio.h>
#include <conio.h>

typedef struct
{
    int row;
    int column;
    int value;
}Element;

void main()
{
    Element E[10];
    int count, key, i;


    printf("Enter the Number of Non Zero Entities In The Sparse Matrix: ");
    scanf("%d", &count);
	printf("\n");

    for(i = 0; i < count; i++)
    {
        printf("\nEnter Data For Element %d in <row,column,value> Format : ",i+1);
        scanf("%d", &E[i].row);        
        scanf("%d", &E[i].column);        
        scanf("%d", &E[i].value);
    }

    printf("\n\nEnter the element to search for : ");
    scanf("%d", &key);

    for(i = 0; i < count; i++)
        if(E[i].value == key)
        {
            printf("\nThe element %d Is Found At Row %d And Column %d", key, E[i].row, E[i].column);
            break;
        }

    if(i == count)
        printf("\nElement Not Found");

	getch();
}