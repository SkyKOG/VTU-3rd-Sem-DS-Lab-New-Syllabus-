/**
Lab Program 5 
Simple Class Simulation 1
Author SkyKOG
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class EMPLOYEE {
	int Employee_Number,Basic_Salary,All_Allowances,IT,Net_Salary;
	char Employee_Name[20];
	
	public:
		void accept();
		void calc();
		void display();
};

int main()
{   	
	system("cls");
	EMPLOYEE emp[20];
	int n;
	cout<<"Enter Number Of Employees : ";
	cin>>n;
	for(int i=0 ; i < n; i++)
	{
		cout<<"\nEnter Details for Emp : "<<i+1<<"\n";
		emp[i].accept();
	}

	cout<<"\n\nNumber\tName\tBasic\tIT\tNet\tAll Allowances\n\n";
	for(int i=0 ; i < n ; i++)
	{
		emp[i].display();
	}
	
	getch();
	return 0;
}

void EMPLOYEE::accept()
{
	cout<<"Number : ";
	cin>>Employee_Number;
	cout<<"Name : ";
	cin>>Employee_Name;
	cout<<"Basic : ";
	cin>>Basic_Salary;
	calc();
}

void EMPLOYEE::calc()
{
	All_Allowances=1.23*Basic_Salary;
	IT=0.3*(Basic_Salary+All_Allowances);
	Net_Salary=Basic_Salary+All_Allowances-IT;
}

void EMPLOYEE::display()
{
	cout<<Employee_Number<<"\t"<<Employee_Name<<"\t"<<Basic_Salary;
	cout<<"\t"<<IT<<"\t"<<Net_Salary<<"\t"<<All_Allowances<<"\n";
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