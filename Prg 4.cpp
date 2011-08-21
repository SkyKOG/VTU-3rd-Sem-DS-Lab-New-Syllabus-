/**
Lab Program 4
Implementation of Linear Queue
Author SkyKOG
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

#define MAX 5

struct queue
{
	int arr[MAX];
	int f,r;
};

void insq(struct queue *,int);
void delq(struct queue *);
void display(struct queue *);

void main()
{
	int ch,ele;
	struct queue q;
	q.f=-1;
	q.r=0;
	while(true)
	{
		system("cls");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter Selection : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("\nEnter Element To Insert : ");
			scanf("%d",&ele);
			insq(&q,ele);
			break;
		case 2:delq(&q);
			break;
		case 3:display(&q);
			break;
		case 4:exit(0);
			break;
		default:printf("Invalid Selection");
		}
		getch();
	}
}
void insq(struct queue *q,int ele)
{
	if(q->r==MAX)
	{
		printf("\nQueue Full");
		return;
	}
	q->arr[q->r]=ele;
	q->r++;
	if(q->f==-1)
		q->f=0;
}
void delq(struct queue *q)
{
	if(q->f==-1)
	{
		printf("\nQueue Empty");
		return;
	}
	printf("\nElement Deleted is : %d",q->arr[q->f]);
	q->f++;
	if(q->f==q->r)
	{
		q->f=-1;
		q->r=0;
	}
}
void display(struct queue *q)
{
	int i;
	if(q->f==-1)
	{
		printf("Empty Queue");
		return;
	}
	printf("\nThe Contents of the Queue Are : ");
	for(i=q->f;i<q->r;i++)
	{
		printf("%d ",q->arr[i]);
	}
}