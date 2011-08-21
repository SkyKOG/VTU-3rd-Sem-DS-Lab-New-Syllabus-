/**
Lab Program 1
Circular Polynomial Addition
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int exp;
    int coef;
    struct Node* link;
}Node;

typedef struct
{
    Node* first;
    Node* last;
}Polynomial;

Polynomial Insert(Polynomial P, int exp, int coef);
Polynomial Input(Polynomial P);
void Print(Polynomial P);
Polynomial Add(Polynomial A, Polynomial B, Polynomial C);

void main()
{
    Polynomial a, b, c;
    a.first = b.first = c.first = NULL;

    a = Input(a);
    b = Input(b);

    printf("\n\nPolynomial A : ");
    Print(a);

    printf("\nPolynomial B : ");
    Print(b);

    c = Add(a, b, c);

    printf("\n\nAdding A and B, Polynomial C : ");
    Print(c);

    getch();
}

Polynomial Insert(Polynomial P, int exp, int coef)
{
    if(P.first==NULL)
    {
        P.first = P.last =(Node *)malloc(sizeof(Node));
        P.last->link = P.first;
    }
	else
    {
        P.last->link =(Node *)malloc(sizeof(Node));
        P.last = P.last->link;
        P.last->link = P.first;
    }

    P.last->exp = exp;
    P.last->coef = coef;

    return P;
}

Polynomial Input(Polynomial P)
{
    int degree, coef, i;
    printf("\nEnter the degree of the polynomial: ");
    scanf("%d", &degree);

    printf("\n");
    for(i = degree; i >= 0; i--)
    {
        printf("Enter the co-efficent of x^%d: ", i);
        scanf("%d", &coef);
        P = Insert(P, i, coef);
    }

    return P;
}

void Print(Polynomial P)
{
    Node* temp = P.first;
    do
    {
        if(temp->coef == 0)
        {
            temp = temp->link;
            continue;
        }

        printf("%+dx^%d ", temp->coef, temp->exp);
        temp = temp->link;
    }while(temp != P.first);

    printf("\n");
}

Polynomial Add(Polynomial A, Polynomial B, Polynomial C)
{
    Node* tempA = A.first;
    Node* tempB = B.first;
    do
    {
        if(tempA->exp > tempB->exp)
        {
            C = Insert(C, tempA->exp, tempA->coef);
            tempA = tempA->link;
        }

        else if(tempA->exp == tempB->exp)
        {
            C = Insert(C, tempA->exp, tempA->coef + tempB->coef);
            tempA = tempA->link;
            tempB = tempB->link;
        }

        else
        {
            C = Insert(C, tempB->exp, tempB->coef);
            tempB = tempB->link;
        }

    }while(tempA != A.first || tempB != B.first);

    return C;
}