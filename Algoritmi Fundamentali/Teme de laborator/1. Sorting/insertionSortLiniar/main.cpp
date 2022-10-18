#include <iostream>
#include <stdlib.h>
#include "Profiler.h"
using namespace std;

Profiler p("insertionLiniar");

void listA(int [], int);
void LINEAR_INSERT_POS(int A[], int high_index, int *new_pos)
{
    /*
    * partea de sir sortat este in intervalul [0, high_index-1]
    * asta inseamna ca A[high_index] este primul element din partea nesortata
    ** pe care noi il luam si il inseram in partea sortata
    */
    //2 3 6 5 7 9   6

    for(int i = high_index - 1; i >= 0 && A[i] > A[*new_pos]  ; i--)
        if(A[i] < A[high_index])
        {
            *new_pos = i;
        }
}
void insertion(int A[], int n)
{
    Operation opComp = p.createOperation("A-comp", n);
    Operation opAtrib = p.createOperation("A-atrib", n);

    int high_index = 1;
    int aux;
    int new_pos;
    while(high_index <= n-1)
    {
        new_pos = high_index;
        LINEAR_INSERT_POS(A, high_index, &new_pos);
        /**printf("Log: vectorul ");listA(A, n);
        printf(" log: noua pozitie = %d, high_index = %d\n", new_pos, high_index);
        printf("\n new step\n");*/
        aux = A[high_index];
        for (int i = high_index; i >= new_pos + 1; i--)
            A[i] = A[i - 1];
        A[new_pos] = aux;
        high_index++;
    }
}
void listA(int A[], int n)
{
    printf("A: ");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void demo()
{
    int A[7] = {27, 9, 8, 30, 28, 4, 12};
    int n = sizeof(A)/sizeof(A[0]);
    insertion(A, n);
    listA(A, n);
}
int main() {
    demo();
    return 0;
}

