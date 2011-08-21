/**
Lab Program 3
Postfix Evaluation Using Stack
Author SkyKOG
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>

int stack[20];
int top;

void push(int);
int pop();
void eval(char post[20]);

void main()
{
	char post[20];
	top=-1;
	printf("Enter Postfix Expression : ");
	gets(post);
	eval(post);
	printf("\nThe Evaluated Answer Is : %d",pop());
	getch();
}
void push(int ele)
{
	stack[++top]=ele;
}

int pop()
{
	return (stack[top--]);
}

void eval(char post[20])
{
	char ch;
	int i,b,a;
	for(i=0;post[i];i++)
	{
		ch=post[i];
		if(isdigit(ch))
			push(ch-'0');
		else
		{  
			b=pop();
			a=pop();
			switch(ch)
			{
			case '+':push(a+b);
				break;
			case '-':push(a-b);
				break;
			case '*':push(a*b);
				break;
			case '/':if(b==0)
					 {
						 printf("Devide By Zero");
						 getch();
						 exit(0);
					 }
					 push(a/b);
			default:printf("Invalid Operation");
			}
		}
	}
}


	
