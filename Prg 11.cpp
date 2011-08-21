/**
Lab Program 11
Double Linked List Operations
Author SkyKOG
*/

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <windows.h>

struct node 
{
	int item;
	struct node *l;
	struct node *r;
};

struct node *getnode()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	return temp;
}

struct node *addatbeg(struct node *,int);
struct node *del(struct node *);
struct node *addleft(struct node *,int,int);
void display(struct node*);

void main()
{
	struct node *p;
	p=NULL;
	int ele,ch,key=0;
	while(true)
	{
		system("cls");
		printf("1. Insert At Front\n2. Insert to Left\n3. Delete Node\n4. Display\n5. Exit\n\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("\nEnter Element To Insert : ");
			scanf("%d",&ele);
			p=addatbeg(p,ele);
			break;
		case 2:printf("\nEnter Element To Insert : ");
			scanf("%d",&ele);
			printf("\nEnter Key To Search On : ");
			scanf("%d",&key);
			p=addleft(p,ele,key);
			break;
		case 3:p=del(p);
			break;
		case 4:display(p);
			break;
		case 5:exit(0);
			break;
		default:printf("\nInvalid Selection");
		}
		getch();
	}
}

void display(struct node *q)
{
	struct node *r;
	r=q;
	if(r==NULL)
	{
		printf("\nList Is Empty");
		return;
	}
	printf("\nThe Contents of the List Are : ");
	while(r!=NULL)
	{
		printf("%d ",r->item);
		r=r->r;
	}
	printf("\n");
}

struct node *addatbeg(struct node *q,int ele)
{
	struct node *temp,*r;
	temp=getnode();
	temp->item=ele;
	temp->l=NULL;
	temp->r=NULL;
	if(q==NULL)
	{
		q=temp;
		return q;
	}
	temp->r=q;
	q->l=temp;
	q=temp;
	return q;
}

struct node * addleft(struct node *q,int ele,int key)
{
	struct node *r,*temp;
	int flag=0;
	temp=getnode();
	r=q;
	if(r==NULL)
	{
		printf("\nEmpty List");
		return q;
	}
	if(q->item==key)
	{
		q=addatbeg(q,ele);
		return q;
	}
	while(r->r!=NULL)
	{
		if(r->item==key)
		{
			temp->item=ele;
			temp->r=r;
			temp->l=r->l;
			r->l->r=temp;
			r->l=temp;
			flag=1;
		}
		r=r->r;
	}
	if((r->r==NULL)&&(r->item==key))
	{
		temp->item=ele;
		temp->r=r;
		temp->l=r->l;
		r->l->r=temp;
		r->l=temp;
		return q;
	}
	
	if(!flag)
		printf("\nKey Not Found In List");
	return q;
}
struct node * del(struct node *q)
{
	int ele,del,status=0;
	printf("\nEnter Element To Delete : ");
	scanf("%d",&ele);
	struct node *temp;
	temp=q;
	if(temp==NULL)
	{
		status=0;
		printf("\nList Is Empty");
		return NULL;
	}

	if(temp->item==ele)
	{
		status=1;
		q=q->r;
		del=temp->item;
		printf("\nDeleted item is %d",del);
		free(temp);
		return q;
	}
	while(temp->r!=NULL)
	{
		if(temp->item==ele)
		{
			status=1;
			del=temp->item;
			printf("\nDeleted item is %d",del);
			temp->l->r=temp->r;
			temp->r->l=temp->l;
			free(temp);
			return q;
		}
		temp=temp->r;
	}
	if((temp->r==NULL)&&(temp->item==ele))
	{
		temp->l->r=NULL;
		status=1;
		del=temp->item;
		printf("\nDeleted item is %d",del);
		free(temp);
		return q;
	}
	if(!status)
		printf("\nElement Not in List");
	return q;
}