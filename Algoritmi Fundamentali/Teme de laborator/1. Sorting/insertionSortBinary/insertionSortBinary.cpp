/* Bartolomei Vlad, 30229, 2022-2023
* Title: Insertion sort, varianta cu cautare binara
* - Evaluare complexitate -
* Aici e doar implementare pentru acel bonus considerabil.
*/

#include <iostream>
#include <stdlib.h>
#include "Profiler.h"

Profiler p("insertionBinar");
#define MAX_SIZE 10000
#define STEP_SIZE 100
#define NR_TESTS 1
void listA(int [], int);
void BINARY_INSERT_POS(int A[], int high_index, int *new_pos)
{
    int n = sizeof(A)/sizeof(A[0]);
    Operation opComp = p.createOperation("insertbinar-comp", n);
    Operation opAtrib = p.createOperation("insertbinar-atrib", n);
    int low = 0, high = high_index;
    while(low != high)
    {
        int mid = (low + high) / 2; //pe indecsi. nu numaram
        opComp.count();
        if(A[high_index] > A[mid])
        {
            low = mid+1;
        }
        else
        {
            opComp.count();
            if(A[high_index] < A[mid])
            {
                high = mid;
            }
        }
    }
    *new_pos = low;
}
void insertion(int A[], int n)
{
    Operation opComp = p.createOperation("insertbinar-comp", n);
    Operation opAtrib = p.createOperation("insertbinar-atrib", n);

    int high_index = 1;
    int aux;
    int new_pos;
    while(high_index <= n-1)
    {
        new_pos = -1;
        BINARY_INSERT_POS(A, high_index, &new_pos);
        opAtrib.count(); //numaram o atribuire variabilei aux
        aux = A[high_index];
        for (int i = high_index; i >= new_pos + 1; i--)
        {
            opAtrib.count(); // decalarea sirului se face prin atribuiri
            A[i] = A[i - 1];
        }
        opAtrib.count(); //numaram o atribuire lui A[new_pos]
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
    int n = 7;
    int A[7] = {27, 9, 8, 30, 28, 4, 12};
    insertion(A, n);
    listA(A, n);
}

void performance(int order)
{
    int A[MAX_SIZE];
    int n;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE){
            for(int test = 0; test < NR_TESTS; test++){
                FillRandomArray(A, n, 10, 50000, false, order);
                insertion(A, n);
            }
    }

    p.divideValues("insertbinar-atrib", NR_TESTS);
    p.divideValues("insertbinar-comp", NR_TESTS);
    p.addSeries("total", "insertbinar-atrib", "insertbinar-comp");

    p.showReport();
}

void performance_all()
{
    performance(UNSORTED);
    p.reset("BEST");
    performance(ASCENDING);
    p.reset("WORST");
    performance(DESCENDING);
    p.showReport();
}
int main() {
    demo();
    //performance_all();
    return 0;
}
