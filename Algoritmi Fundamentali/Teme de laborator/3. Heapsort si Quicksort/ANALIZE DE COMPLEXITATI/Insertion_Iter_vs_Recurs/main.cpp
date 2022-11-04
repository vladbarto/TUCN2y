#include <iostream>
#include "Profiler.h"
Profiler p("insertionSort");
#define MAX_SIZE 10000
#define STEP_SIZE 100
#define NR_TESTS 5
using namespace std;
void listArray(int A[], int n)
{
    printf("A: ");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void LINEAR_INSERT_POS(int A[], int high_index, int *new_pos)
{
    int n = sizeof(A)/sizeof(A[0]);
    Operation opComp = p.createOperation("atribS", n);
    Operation opAtrib = p.createOperation("compS", n);
    for(int i = high_index-1; i >= 0 && A[i] > A[high_index]; i--)
    {
        opComp.count(); // va numara pentru fiecare iteratie comparatia din for A[i]>A[high_index]
        opComp.count(); // numara comparatia din if-ul de mai jos
        if(A[i] > A[high_index])
        {
            *new_pos = i;
        }
    }
}
void BINARY_INSERT_POS(int A[], int high_index, int *new_pos)
{
    int n = sizeof(A)/sizeof(A[0]);
    Operation opComp = p.createOperation("atribS", n);
    Operation opAtrib = p.createOperation("compS", n);
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
void insertion(int A[], int n, bool cautaBinar)
{
    Operation opComp = p.createOperation("atribS", n);
    Operation opAtrib = p.createOperation("compS", n);
    int high_index = 1;
    int aux;
    int new_pos;
    while(high_index <= n-1)
    {
        if(cautaBinar == false)
        {
            new_pos = high_index;
            LINEAR_INSERT_POS(A, high_index, &new_pos);
        }
        else
        {
            new_pos = -1;
            BINARY_INSERT_POS(A, high_index, &new_pos);
        }
        opAtrib.count();
        aux = A[high_index];
        for (int i = high_index; i >= new_pos + 1; i--)
        {
            opAtrib.count();
            A[i] = A[i - 1];
        }
        opAtrib.count();
        A[new_pos] = aux;
        high_index++;
    }
}

void demo()
{
    int A[] = {27, 9, 3, 30, 45, 4, 12};
    //int A[]={27, 9, 8, 30, 28};
    int n = sizeof(A)/sizeof(A[0]);
    insertion(A, n, true);
    listArray(A, n);
}
void performance()
{
    int A[MAX_SIZE];
    int n;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE){
            for(int test = 0; test < NR_TESTS; test++){
                FillRandomArray(A, n);
                insertion(A, n, true);
            }
    }

    p.divideValues("atribS", NR_TESTS);
    p.divideValues("compS", NR_TESTS);
    p.addSeries("total", "atribS", "compS");

    p.showReport();
}
int main() {
    demo();
    performance();
    return 0;
}
