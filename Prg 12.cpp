/**
Lab Program 7
Operator Overloading - date Class
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <process.h>

using namespace std;

class date {

    int dd,mm,yy;

    public :
        void getdata();
        int operator -(date);
        date operator +(int);
        friend ostream & operator <<(ostream &,date &);
};

int main()
{
    int no_of_days,ch;
    date d1,d2;
    while(true)
    {
        system("cls");
        cout<<"1. Diffrence Between 2 dates : \n2. Get New date : \n3. Exit\n\nEnter Selection : ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\n\nEnter date d1 (dd/mm/yy) : ";
                   d1.getdata();
                   cout<<"Enter date d2 (dd/mm/yy) : ";
                   d2.getdata();
                   no_of_days=d1-d2;
                   if(no_of_days<0)
                   {
                       cout<<"\nInvalid dates";
                   }
                   else
					   cout<<"\nThe Number of Days in Between Are : "<<no_of_days;
                   break;
            case 2:cout<<"\n\nEnter date d1 (dd/mm/yy) : ";
                   d1.getdata();
                   cout<<"Enter Days To Add : ";
                   cin>>no_of_days;
                   d2=d1+no_of_days;
                   cout<<"\nThe Required date is : ";
                   cout<<d2;
                   break;
            case 3:exit(0);
                   break;
            default:cout<<"\n\nInvalid Selection";
                   break;
        }
        getch();
    }
    return 0;
}

void date::getdata()
{
    cin>>dd>>mm>>yy;

    if(dd>31||mm>12)
    {
        cout<<"\nInvalid date";
        getdata();
    }
    if(((mm==4)||(mm==6)||(mm==9)||(mm==11))&&(dd>30))
    {
        cout<<"\nInvalid date";
        getdata();
    }
    if((mm==2))
    {
        if((yy%4!=0)&&(dd>28))
        {
            cout<<"\nInvalid date";
            getdata();
        }
        else if((dd>29))
        {
            cout<<"\nInvalid date";
            getdata();
        }
    }
}

int date::operator -(date d2)
{
    int i,n1,n2,ny,d;
    n1=n2=ny=0;

    for(i=1;i<=mm;i++)
    {
        if((i==4)||(i==6)||(i==9)||(i==11))
            n1+=30;
        else if(i==2)
        {
            if(yy%4==0)
                n1+=29;
            else
                n1+=28;
        }
        else
            n1+=31;
    }
    n1+=dd;

    for(i=1;i<=d2.mm;i++)
    {
         if((i==4)||(i==6)||(i==9)||(i==11))
            n2+=30;
        else if(i==2)
        {
            if(d2.yy%4==0)
                n2+=29;
            else
                n2+=28;
        }
        else
            n2+=31;
    }
    n2+=d2.dd;
    ny=(yy-d2.yy)*365;
    d=n1-n2+ny;
    return d;
}

date date::operator +(int n)
{
	while(n>365)
	{
		yy++;
		if(yy%4==0)
			n-=366;
		n-=365;
	}
	while(n>30)
	{
		if((mm==4)||(mm==6)||(mm==9)||(mm==11))
			n-=30;
		else if(mm==2)
		{
			if(yy%4==0)
				n-=29;
			else
				n-=28;
		}
		else
			n-=31;
		mm++;
		if(mm>12)
		{
			yy++;
			mm=1;
		}
	}
	dd+=n;
	if(dd>31)
	{
		if((mm==4)||(mm==9)||(mm==6)||(mm==11))
			dd-=30;
		else if(mm==2)
		{
			if(yy%4==0)
				dd-=29;
			else
				dd-=28;
		}
		else
			dd-=31;
		mm++;
	}
	return *this;
}

ostream & operator<<(ostream &out,date &d3)
{
	out<<d3.dd<<" "<<d3.mm<<" "<<d3.yy;
	return out;
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
