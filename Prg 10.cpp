/**
Lab Program 10
Heap Operations
Author SkyKOG
*/

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <Windows.h>

void heaper(int,int*);
void insert(int,int*,int*);
void display(int *,int);

void main()
{
	int arr[20]={1000},ele,n=0,ch;
	
	while(true)
	{
		system("cls");
		printf("1. Insert Into Heap\n2. Display Array\n3. Exit\n\nEnter Selection : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter Element to Insert : ");
			scanf("%d",&ele);
			insert(ele,arr,&n);
			display(arr,n);
			break;
			case 2:display(arr,n);
				break;
			case 3:exit(0);
				break;
			default:printf("Invalid Selection");
				break;
		}
		getch();
	}
}

void display(int *arr,int n)
{
	int i;
	printf("\n\nThe Contents of The Heap are as follows : ");
	for(i=1;i<=n;i++)
	{
		printf("%d ",arr[i]);
	}
}

void insert(int ele,int *arr,int *n)
{
	(*n)++;
	arr[*n]=ele;
	heaper(*n,arr);
}

void heaper(int i,int *arr)
{
	int val;
	val=arr[i];
	while(arr[i/2]<=val)
	{
		arr[i]=arr[i/2];
		i=i/2;
	}
	arr[i]=val;
}			