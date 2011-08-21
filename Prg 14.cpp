/**
Lab Program 14
Binary Tree Operations
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <process.h>

using namespace std;

class BIN_TREE {

	struct node
	{
		node *l;
		node *r;
		int data;
	}*p;

	public:
		BIN_TREE();
		void insert(int);
		void insertmain(node **,int);
		void display(int);
		void inorder(node *);
		void preorder(node *);
		void postorder(node *);
		
};

BIN_TREE::BIN_TREE()
{
	p=NULL;
}

void main()
{
	BIN_TREE obj;
	int ch,ele;
	while(true)
	{
		system("cls");
		cout<<"1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\n\nEnter Selection : ";
		cin>>ch;
		switch(ch)
		{
		case 1:cout<<"\nEnter Element To Insert : ";
			cin>>ele;
			obj.insert(ele);
			break;
		case 2:obj.display(2);
			break;
		case 3:obj.display(3);
			break;
		case 4:obj.display(4);
			break;
		case 5:exit(0);
			break;
		default:cout<<"Invalid Selection";
		}
		getch();
	}
}

void BIN_TREE::insert(int ele)
{
	insertmain(&p,ele);
}

void BIN_TREE::insertmain(struct node **q,int ele)
{
	if((*q)==NULL)
	{
		(*q)=new node;
		(*q)->l=NULL;
		(*q)->r=NULL;
		(*q)->data=ele;
		return;
	}
	
	else
	{
		if(ele==(*q)->data)
		{
			cout<<"Duplication Not Allowed";
			getch();
			return;
		}
		else
		{
			if(ele<((*q)->data))
				insertmain(&((*q)->l),ele);
			else
				insertmain(&((*q)->r),ele);
		}
	}
	return;
}

void BIN_TREE::display(int ch)
{
	switch(ch)
	{
	case 2:cout<<"\nPreorder Traversal : ";
		preorder(p);
		break;
	case 3:cout<<"\nInorder Traversal : ";
		inorder(p);
		break;
	case 4:cout<<"\nPostorder Traversal : ";
		postorder(p);
		break;
	}
}

void BIN_TREE::preorder(node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		preorder(p->l);
		preorder(p->r);
	}
}

void BIN_TREE::inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->l);
		cout<<p->data<<" ";
		inorder(p->r);
	}
}

void BIN_TREE::postorder(node *p)
{
	if(p!=NULL)
	{
		postorder(p->l);
		postorder(p->r);
		cout<<p->data<<" ";
	}
}



/*
License
=======
    Copyright © 2011 SkyKOG

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/