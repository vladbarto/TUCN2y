#include <stdio.h>
#include <stdlib.h>
#include "Profiler.h"

Profiler p("secondMin");

void listA(int [], int);
void BINARY_INSERT_POS(int A[], int high_index, int *new_pos)
{
    int low = 0, high = high_index;
    while(low != high)
    {
        int mid = (low + high) / 2;
        if(A[high_index] > A[mid])
        {
            low = mid+1;
        }
        else if(A[high_index] < A[mid])
        {
            high = mid;
        }
    }
    *new_pos = low;
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
        new_pos = -1;
        BINARY_INSERT_POS(A, high_index, &new_pos);
        /**printf("Log: vectorul ");listA(A, n);
        printf(" log: noua pozitie = %d, high_index = %d\n", new_pos, high_index);
        printf("\n new step\n");*//
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

int main() {
    int n = 7;
    int A[7] = {27, 9, 8, 30, 28, 4, 12};
    int new_pos = -1;
    insertion(A, n);
    listA(A, n);
    return 0;
}
