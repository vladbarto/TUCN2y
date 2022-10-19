/* Bartolomei Vlad, 30229, 2022-2023
* Title: selection sort
* AM IMPLEMENTAT ALGORITMUL DE SORTARE PRIN SELECTIE (SELECTION SORT)
* - Evaluare complexitate -
* Average case: O(nlogn)
  * numarul de atribuiri creste extrem de lent, logaritmic
  * numarul de comparatii creste ceva mai tare, nlogn
* Best case: O(nlogn)
  * se desfasoara cand sirul este deja ordonat (crescator)
  * vedem aici ca numarulde atribuiri este liniar (O(n))
  * dar, din nou, curba comparatiilor (deci si a per-totalului) creste in stil nlogn
* Worst case:
    *astuia nu ii place daca sirul este ordonat fix cum nu trebuie (descrescator)
    *atribuiri: logaritmic; comparatii: nlogn
 Am observat ca acestui algoritm i-a luat undeva la 400 de secunde
*/

#include <iostream>
#include <stdlib.h>
#include "Profiler.h"
using namespace std;
Profiler p("selection");
#define MAX_SIZE 10000
#define STEP_SIZE 100
#define NR_TESTS 5

void EXTRACT_MIN_POS(int A[], int index, int n, int *reqpos)
{
    //A is sorted in range [0, index-1]
    //A is unsorted in range [index, n)
    Operation atrib = p.createOperation("selection-atrib", n);
    Operation comp  = p.createOperation("selection-comp", n);

    *reqpos = index;
    atrib.count(); //o atribuire pentru variabila auxiliara minimum
    int minimum = A[index];
    for(int i = index+1; i < n; i++)
        {
            comp.count();
            if (minimum > A[i]) {
                    atrib.count();
                    minimum = A[i];
                    *reqpos = i;
                }
        }
}
void SWAP(int A[], int first_el_index, int *second_el_index)
{
    int n = sizeof(A)/sizeof(A[0]);
    Operation atrib = p.createOperation("selection-atrib", n);

    int aux;
    atrib.count(3);
    aux = A[first_el_index];
    A[first_el_index] = A[*second_el_index];
    A[*second_el_index] = aux;
}
void selection(int A[], int n)
{
    int index = 0, required_position;
    while(index < n)
    {
        EXTRACT_MIN_POS(A, index, n, &required_position); //where required_position is more like needed position
        if(index != required_position)
            SWAP(A, index, &required_position);
        index ++;
    }
}
void listA(int A[], int n)
{
    printf("A: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void demo()
{
    int n = 5;
    int A[5] = {27, 5, 9, 3, 7};
    selection(A, n);
    listA(A, n);
}

void perf(int order, int permuta)
{
    int A[MAX_SIZE];
    int n;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE)
        for(int test = 0; test < NR_TESTS; test++)
        {
            FillRandomArray(A, n, 10, 50000, false, order);
            //urmatorul if cu blocul de instructiuni aferent va fi necesar doar pentru worst case
            if(permuta == 1)
            {
                int x = A[n-1];
                for(int i = n-1; i > 0; i--)
                {
                    A[i] = A[i-1];
                }
                A[0] = x;
            }
            //gata
            selection(A, n);
        }
    p.divideValues("selection-atrib", NR_TESTS);
    p.divideValues("selection-comp", NR_TESTS);
    p.addSeries("total", "selection-atrib", "selection-comp");

    p.showReport();
}

void perf_all()
{
    perf(UNSORTED, 0);
    p.reset("Best");
    perf(ASCENDING, 0);
    p.reset("Worst");
    perf(ASCENDING, 1);
    p.showReport();
}
int main()
{
    //demo();
    perf_all();
    return 0;
}
