 /**
Lab Program 13
Operator Overloading & Constructor - Octal Class
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class OCTAL {

	int num,y;

	public : 
		OCTAL(int);
		int convert();
		int operator +(int);
		friend ostream & operator <<(ostream &,OCTAL &);

};

void main()
{
	int x,k;
	cout<<"Enter Number to Be Converted to Octal : ";
	cin>>x;
	
	OCTAL h = x;
	
	cout<<"\nOctal Value : "<<h;
	cout<<"\n\nEnter Number to be Added to the Octal Number : ";
	cin>>k;

	int y = h + k;

	cout<<"\nSum After Adding Number to Octal : "<<y;
	getch();

}

OCTAL::OCTAL(int x)
{
	num=x;
	y=convert();
}

int OCTAL::convert()
{
	int sum=0,rem,product=1,temp=num;
	while(temp>0)
	{
		rem=temp%8;
		sum+=(product*rem);
		product*=10;
		temp/=8;
	}
	return sum;
}

int OCTAL::operator +(int k)
{
	return num+k;
}

ostream & operator <<(ostream &out,OCTAL &obj)
{
	out<<obj.y;
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




