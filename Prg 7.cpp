/**
Lab Program 7 
Operator Overloading - Stack Class 
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <process.h>
#include <windows.h>

#define MAX 5

using namespace std;

class STACK {

	int top;
	int arr[MAX];

	public:
		STACK();
		STACK operator + (int);
		STACK operator -- ();
		friend void operator <<(ostream &,STACK &);

};

void main()
{
	STACK s1;
	int ch,ele;
	
	while(true)
	{
		system("cls");
		cout<<"1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter Your Choice : ";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"\nEnter The Element to Push : ";
			cin>>ele;
			s1 = s1 + ele;
			cout<<"\n"<<s1;
			break;
		case 2:s1 = --s1;
			cout<<"\n"<<s1;
			break;
		case 3:cout<<"\n"<<s1;
			break;
		case 4:exit(0);
			break;
		default:cout<<"\nInvalid Selection\n";
		}
		getch();
	}
}

STACK::STACK()
{
	top=-1;
}

STACK STACK::operator +(int ele)
{
	if(top==MAX-1)
	{
		cout<<"\nSTACK Overflow";
		return *this;
	}

	arr[++top]=ele;
	return *this;
}


STACK STACK::operator --()
{
	if(top==-1)
	{
		cout<<"\nSTACK Underflow\n";
		return *this;
	}

	cout<<"\nThe Popped Element is : "<<arr[top--]<<"\n";
	return *this;
}


void operator <<(ostream &out,STACK &s)
{
	if(s.top==-1)
	{
		out<<"\nSTACK Empty";
		return;
	}

	cout<<"\nThe Current Contents of STACK Are : ";
	for(int i = s.top ; i >= 0 ; i--)
	{
		out<<s.arr[i]<<" ";
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