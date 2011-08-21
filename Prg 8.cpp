/**
Lab Program 8
Linked List
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class LIST {
	struct node
	{
		int item;
		node *link;
	}*p;

	public:
		LIST();
		void insert(int);
		int del(int &);
		void display();
		~LIST();
};

int main()
{
	LIST obj;
	int ch,ele,status=0;
	while(true)
	{
		system("cls");
		cout<<"1. Insert At Front\n2. Delete From Front\n3. Display\n4. Exit\n\nEnter Choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1:cout<<"\nEnter Element to Insert : ";
			cin>>ele;
			obj.insert(ele);
			break;
		case 2:ele=obj.del(status);
			if(status==0)
			{
				break;
			}
			cout<<"\nElement Deleted is : "<<ele;
			break;
		case 3:obj.display();
			break;
		case 4:exit(0);
			break;
		default:cout<<"Invalid Selection";
			break;
		}getch();
	}
	return 0;
}

LIST::LIST()
{
	p=NULL;
}

void LIST::insert(int item)
{
	node *q;
	q=new node;
	q->item=item;
	q->link=p;
	p=q;
}

int LIST::del(int &status)
{
	int del;
	node *q;
	if(p==NULL)
	{
		status=0;
		cout<<"List Is Empty";
		return NULL;
	}

	q=p;
	status=1;
	del=p->item;
	p=p->link;
	delete q;
	return del;
}

void LIST::display()
{
	node *q;
	if(p==NULL)
		{
			cout<<"\nEmpty List";
			return;
		}
	cout<<"\n\nCurrent List Status : ";
	for(q=p ; q!=NULL ; q=q->link)
		cout<<q->item<<" ";
}

LIST::~LIST()
{
	node *q;
	if(p==NULL)
		return;
	while(p!=NULL)
	{
		q=p->link;
		delete p;
		p=q;
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
