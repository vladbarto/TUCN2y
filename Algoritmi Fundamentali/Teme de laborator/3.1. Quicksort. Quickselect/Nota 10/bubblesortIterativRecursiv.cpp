#include <iostream>
#include <stdlib.h>
#include "Profiler.h"
#include <stdbool.h>

#define MAX_SIZE 10000
#define STEP_SIZE 10
#define NR_TESTS 5
#define NO_TESTS_TIMP 100

using namespace std;
/*
 * Complexities: Recusiv si Iterativ da O(n^2)
 * Dupa cum se poate vedea si pe grafic, ambele curbe cresc exponential. Totusi, in cazul atribuirilor,
 * se vede ca varianta Recursiva pune mai multe probleme (atribuie de mai multe ori).
 * Ceea ce observam  la categoria Comparatii este prezenta exclusiva a unei curbe, in aparenta. Daca analizam cu atentie
 * ambele coduri, vedem ca este acelasi numar de comparatii si aceeasi comparatie (A[i]>A[i+1]?)
 */
Profiler p("bubble");

void listA(int [], int);
void bubbleSort_iterativ(int A[], int n)
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
void bubbleSort_iterativ_in_timp(int A[], int n)
{
    Operation op = p.createOperation("iterativ-in-timp", n);
    int aux;
    int x = 0;
    bool swapped_flag;
    do
    {
        swapped_flag = false;
        for(int i = 0; i < n-1; i++)
        {
            op.count(); // compara de fiecare data cand intreaba (if)
            if(A[i] > A[i+1])
            {
                op.count(3); // se fac 3 atribuiri, in speta o interschimbare
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
void bubbleSort_iterativ_simplu(int A[], int n)
{
    int aux;
    int x = 0;
    bool swapped_flag;
    do
    {
        swapped_flag = false;
        for(int i = 0; i < n-1; i++)
        {
            if(A[i] > A[i+1])
            {
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
void bubbleSort_recursiv(int A[], int n, int n_profiler){
    // Base case
    Operation atrib2 = p.createOperation("recurs-atrib", n_profiler);
    Operation comp2 = p.createOperation("recurs-atrib", n_profiler);
    if (n == 1)
        return;
    bool swapped_flag = false;
    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i=0; i<n-1; i++)
    {
        comp2.count();
        if (A[i] > A[i+1]){
            atrib2.count(3);
            swap(A[i], A[i+1]);
            swapped_flag = true;
        }
    }

    // Check if any recursion happens or not
    // If any recursion is not happen then return
    if (swapped_flag == false)
        return;

    // Largest element is fixed,
    // recur for remaining array
    bubbleSort_recursiv(A, n-1, n_profiler);
}
void bubbleSort_recursiv_in_timp(int A[], int n, int n_profiler){
    // Base case
    Operation op = p.createOperation("recursiv-timp", n_profiler);
    if (n == 1)
        return;
    bool swapped_flag = false;
    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i=0; i<n-1; i++)
    {
        op.count();
        if (A[i] > A[i+1]){
            op.count(3);
            swap(A[i], A[i+1]);
            swapped_flag = true;
        }
    }

    if (swapped_flag == false)
        return;
    bubbleSort_recursiv(A, n-1, n_profiler);
}
void bubbleSort_recursiv_simplu(int A[], int n, int n_profiler){
    if (n == 1)
        return;
    bool swapped_flag = false;
    for (int i=0; i<n-1; i++)
    {
        if (A[i] > A[i+1]){
            swap(A[i], A[i+1]);
            swapped_flag = true;
        }
    }

    if (swapped_flag == false)
        return;
    bubbleSort_recursiv(A, n-1, n_profiler);
}
void listA(int A[], int n)
{
    printf("A: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void demo_iter()
{
    int n = 7;
    int A[7] = {27, 9, 8, 30, 28, 4, 12};
    bubbleSort_iterativ(A, n);
    listA(A, n);
}
void demo_recurs()
{
    int n = 7;
    int A[7] = {27, 9, 8, 30, 28, 4, 12};
    bubbleSort_recursiv(A, n, n);
    listA(A, n);
}
void copyarr(int src[], int dest[], int dimens)
{
    for(int i = 0; i < dimens; i++)
        dest[i] = src[i];
}
void perf()
{
    int A[MAX_SIZE];
    int copyA[MAX_SIZE];
    int n;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE)
    {
        for(int test = 0; test < NR_TESTS; test++)
        {
            FillRandomArray(A, n);
            copyarr(A, copyA, n);
            bubbleSort_iterativ(copyA, n);
            bubbleSort_recursiv(A, n, n);
        }
    }
    p.divideValues("bubblesort-atrib", NR_TESTS);
    p.divideValues("bubblesort-comp", NR_TESTS);
    p.addSeries("total iterativ", "bubblesort-atrib", "bubblesort-comp");

    /*p.divideValues("recurs-atrib", NR_TESTS);
    p.divideValues("recurs-comp", NR_TESTS);
    p.addSeries("total recursiv", "recurs-atrib", "recurs-comp");

    p.createGroup("atribuiri", "bubblesort-atrib", "recurs-atrib");
    p.createGroup("comparatii", "bubblesort-comp", "recurs-comp");
    p.createGroup("overall", "atribuiri", "comparatii");*/
    p.showReport();
}
void perf_in_time(){
    int A[MAX_SIZE];
    int copyA[MAX_SIZE];
    int n;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE)
    {
        FillRandomArray(A, n);
        copyarr(A, copyA, n);
        bubbleSort_iterativ_in_timp(copyA, n);
        copyarr(A, copyA, n);
        bubbleSort_recursiv_in_timp(copyA, n, n);

        p.startTimer("bubblesort_iterativ timp", n);
        for(int test = 0; test < NO_TESTS_TIMP; test++)
        {
            copyarr(A, copyA, n);
            bubbleSort_iterativ_simplu(copyA, n);
        }
        p.stopTimer("bubblesort_iterativ timp", n);

        /*p.startTimer("bubblesort_recursiv timp", n);
        for(int test = 0; test < NO_TESTS_TIMP; test++)
        {
            copyarr(A, copyA, n);
            bubbleSort_recursiv_simplu(copyA, n, n);
        }
        p.stopTimer("bubblesort_recursiv timp", n);*/
    }
    p.divideValues("iterativ-in-timp", NO_TESTS_TIMP);
    //p.divideValues("recursiv-in-timp", NO_TESTS_TIMP);
    //p.createGroup("Bubblesort timp", "bubblesort_iterativ timp", "bubblesort_recursiv timp");
    //p.createGroup("Bubblesort operatii", "iterativ-in-timp", "recursiv-in-timp");
    p.showReport();
}
int main()
{
    demo_iter();
    demo_recurs();
    //perf();
    perf_in_time();
    return 0;
}