///Proiectant: Bartolomei Vlad, gr. 30229, 2022-23
///Documentatie

///Bubble Sort
/*
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
///Insertion Sort, varianta liniara
/*
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
*/
///Selection Sort
/*
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
#include <stdbool.h>

#define MAX_SIZE 10000
#define STEP_SIZE 10
#define NR_TESTS 5
//936.312 s
using namespace std;

Profiler p("bubble");
void listA(int [], int);
//selectionSort
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

//insertionSort, varianta liniara
void LINEAR_INSERT_POS(int A[], int high_index, int *new_pos)
{
    int n = sizeof(A)/sizeof(A[0]);
    Operation opComp = p.createOperation("insertliniar-comp", n);
    Operation opAtrib = p.createOperation("insertliniar-atrib", n);
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
void insertionL(int A[], int n)
{
    Operation opComp = p.createOperation("insertliniar-comp", n);
    Operation opAtrib = p.createOperation("insertliniar-atrib", n);
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

//insertionSort, varianta binara
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
void insertionB(int A[], int n)
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

//bubbleSort
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
    //insertionL(A, n);
    //insertionB(A, n);
    //selection(A, n);
    listA(A, n);
}
void copySir(int A[], int B[], int n)
{
    for(int i = 0; i < n; i++)
        B[i] = A[i];
}
void perf(int order, int permuta)
{
    int A[MAX_SIZE], A_copy[MAX_SIZE];
    int n;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE)
        for(int test = 0; test < NR_TESTS; test++)
        {
            FillRandomArray(A, n, 10, 50000, false, order);
            copySir(A, A_copy, n);
            bubblesort(A, n);
            copySir(A_copy, A, n);
            insertionL(A, n);
            copySir(A_copy, A, n);
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
    p.divideValues("bubblesort-atrib", NR_TESTS);
    p.divideValues("bubblesort-comp", NR_TESTS);
    p.addSeries("x", "bubblesort-atrib", "bubblesort-comp");

    p.divideValues("selection-atrib", NR_TESTS);
    p.divideValues("selection-comp", NR_TESTS);
    p.addSeries("y", "selection-atrib", "selection-comp");

    p.divideValues("insertliniar-atrib", NR_TESTS);
    p.divideValues("insertliniar-comp", NR_TESTS);
    p.addSeries("z", "insertliniar-atrib", "insertliniar-comp");

    p.createGroup("Atribuiri", "bubblesort-atrib", "selection-atrib", "insertliniar-atrib");
    p.createGroup("Comparatii", "bubblesort-comp", "selection-comp", "insertliniar-comp");
    p.createGroup("total", "x", "y", "z");
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
