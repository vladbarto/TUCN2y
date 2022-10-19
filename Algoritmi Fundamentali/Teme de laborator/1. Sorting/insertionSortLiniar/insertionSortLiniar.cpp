/* Bartolomei Vlad, 30229, 2022-2023
* Titlu: insertion sort
* AM IMPLEMENTAT ALGORITMUL DE INSERTION SORT IN VARIANTA SA DE CAUTARE LINIARA
* Caz mediu favorabil
* Complexitate atribuiri: O(n patrat) <-> deci patratic, deoarece in insertion(A,n) am atribuire in for, care si acela e intr-un while
* Complexitate comparatii: constant. Normal si tehnic vorbind, ar fi trebuit sa fie O(n), pentru ca ar numara in LINEAR_INSERT_POS()
  * de fiecare data cand compara elementul curent comparat cu cel care urmeaza a fi introdus, si mai face la fiecare iteratie
  * o comparatie pentru a iesi mai rapid din for. E.g. partea sortata de vector [2 3 5 7 9 | 6], si urmeaza sa introducem 6.
  * Il compara pe 6 cu 9, 7, ar gasi pozitia lui 7 si acolo ar iesi din for pt eficienta.
  * Ce se observa de fapt: ca nu prea (adica deloc) se fac comparatii. In afara de size = 2, unde da o anomalie, pentru orice alta dimensiune de sir, se intorc 0 (zero) comparatii
* Concl.: Average : O(nlogn)
* Best vs Worst
    Ne este clar ca Best = sir ordonat crescator, iar Worst = sir ordonat descrescator
-------
* Best:
  * atribuiri: O(2n). Se vede clar pe grafic punctul (1000, 2000). Avem ceva liniar
  * comparatii: 0(Zero) pentru orice input
  * rezulta: O(2n).
* Worst:
  * atribuiri: O(n**2), pe baza algoritmului.
  * comparatii: zero, exceptie anomalia care se repeta de la average case
  * rezulta: O(n**2), adica n patrat
* Timp de executie program: 2293.591 s
*/
#include <iostream>
#include <stdlib.h>
#include "Profiler.h"
using namespace std;

Profiler p("insertionLiniar");

#define MAX_SIZE 10000
#define STEP_SIZE 100
#define NR_TESTS 50

void listA(int [], int);
void LINEAR_INSERT_POS(int A[], int high_index, int *new_pos)
{
    int n = sizeof(A)/sizeof(A[0]);
    Operation opComp = p.createOperation("A-comp", n);
    Operation opAtrib = p.createOperation("A-atrib", n);
    /*
    * partea de sir sortat este in intervalul [0, high_index-1]
    * asta inseamna ca A[high_index] este primul element din partea nesortata
    ** pe care noi il luam si il inseram in partea sortata
    */
    //2 3 5 7 9   6
    for(int i = high_index - 1; i >= 0 && A[i] > A[high_index]; i--)
    {
        opComp.count(); // va numara pentru fiecare iteratie comparatia din for A[i]>A[high_index]
        opComp.count(); // numara comparatia din if-ul de mai jos
        if(A[i] > A[high_index])
        {
            *new_pos = i;
        }
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

    p.divideValues("A-atrib", NR_TESTS);
    p.divideValues("A-comp", NR_TESTS);
    p.addSeries("total", "A-atrib", "A-comp");

    p.showReport();
}

void perf_all()
{
    performance(UNSORTED);
    p.reset("Best");
    performance(ASCENDING);
    p.reset("Worst");
    performance(DESCENDING);

    p.showReport();
}
int main() {
    //demo();
    perf_all();
    return 0;
}

