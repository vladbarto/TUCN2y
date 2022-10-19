/* Bartolomei Vlad, 30229, 2022-2023
* Title: bubblesort
* AM IMPLEMENTAT ALGORITMUL BUBBLESORT
* - Evaluare complexitate -
* Average case: O(nlogn)
* Best case: O(n)
* Worst case: O(nlogn)
 Am observat ca timpul de rulare a fost undeva la 143 de secunde, in jur de 4 minute.
 In cazul favorabil (best), sirul este sortat deja crescator, astfel ca algoritmul vine doar ca si constatator si nu mai face nicio atribuire,
 in timp ce numarul de atribuiri este liniar.
 In schimb, in cazul defavorabil (worst), algoritmul are de facut atat o gramada de comparatii, cat si o gramada de atribuiri.
 Ce mai observ este ca diferenta intre worst si best este prapastioasa!
*/

#include <iostream>
#include <stdlib.h>
#include "Profiler.h"
#include <stdbool.h>

#define MAX_SIZE 10000
#define STEP_SIZE 10
#define NR_TESTS 5

using namespace std;

Profiler p("bubble");

void listA(int [], int);
void bubblesort(int A[], int n)
{
    Operation atrib = p.createOperation("bubblesort-atrib", n);
    Operation comp  = p.createOperation("bubblesort-comp", n);
    int aux;
    int x = 0;
    bool swapped_flag;
    do
    {
        swapped_flag = false;
        for(int i = 0; i < n-1; i++)
        {
            comp.count(); // compara de fiecare data cand intreaba (if)
            if(A[i] > A[i+1])
            {
                atrib.count(3); // se fac 3 atribuiri, in speta o interschimbare
                aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
                swapped_flag = true;
            }
        }
       // n = n-1;
       x++;
       // if (x == n)
          //  break;
    }while (swapped_flag == true);
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
    int n = 7;
    int A[7] = {27, 9, 8, 30, 28, 4, 12};
    bubblesort(A, n);
    listA(A, n);
}

void perf(int order)
{
    int A[MAX_SIZE];
    int n;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE)
        for(int test = 0; test < NR_TESTS; test++)
        {
            FillRandomArray(A, n, 10, 50000, false, order);
            bubblesort(A, n);
        }
    p.divideValues("bubblesort-atrib", NR_TESTS);
    p.divideValues("bubblesort-comp", NR_TESTS);
    p.addSeries("total", "bubblesort-atrib", "bubblesort-comp");

    p.showReport();
}

void perf_all()
{
    perf(UNSORTED);
    p.reset("Best");
    perf(ASCENDING);
    p.reset("Worst");
    perf(DESCENDING);
    p.showReport();
}
int main()
{
    //demo();
    perf_all();
    return 0;
}
