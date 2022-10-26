// Heaps-refacut.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
* Performance Analysis
* PENTRU AVERAGE CASE:
    Atribuiri: dreptele clar nu se suprapun; exista o diferenta sesizabila. De la 500 pana la 50000 de atribuiri, overall.
        bottomUp : theta(n)
        topDown: theta(nlogn), mai multe atribuiri in cod
    Comparatii: aici diferenta se mareste
        topDown: se mentine aceeasi rata de crestere, theta(nlogn)
        bottomUp: observam din nou faptul ca sunt necesare mai putine comparatii decat la o constructie Top-Down
    Concluzia overall este simpla: constructia de heap Bottom-up este mai economa decat Top-Down

* PENTRU WORST CASE: TopDown Build e cu mult mai costisitoare decat BottomUp
    Atribuiri: aici numarul pentru topdown creste cam cu aceeasi rata ca si la comparatii (tot pentru topDown). Numarul de atribuiri pt BottomUp ramane similar, conform
            graficului, cu cel din cazul mediu statistic
    Comparatii: pentru o dimensiune a sirului de 30000 de elemente, bottomUp scoate undeva la 100000 de comparatii. TopDown, in schimb, pe la 4000000!
    Concluzie: un Build Topdown are o limita superioara mult mai generoasa decat o constructie BottomUp, astfel fiind mai greu de marginit.

*/

#include <iostream>
//#include "Profiler.h"
#include <stdlib.h>
#include "../../../../../../VisualStudioProjects/Heaps/Profiler.h"
using namespace std;
using namespace Profiler;
Profiler p("Heaps");
#define MAX_SIZE 50000
#define STEP_SIZE 100
#define NR_TESTS 5

int left(int i)
{
    return 2 * i + 1;
}
int right(int i)
{
    return 2 * i + 2;
}
void listHeap(int H[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", H[i]);
    printf("\n");
}
int indexOfMax(int H[], int a, int b, int c, int n)
{
    Operation Atrib = p.createOperation("BottomUpAtrib", n);
    Operation Comp = p.createOperation("BottomUpComp", n);
    Atrib.count();
    int maximum = H[a], maxIndex = a;
    Comp.count(2);
    if (H[b] > maximum && H[b] >= H[c]) //what if un parinte ar avea doi copii cu informatie egala? e.g. 2,3,3
    {
        maxIndex = b;
    }
    else
    {
        Comp.count(2);
        if (H[c] > maximum && H[c] > H[b])
        {
            maxIndex = c;
        }
    }
    return maxIndex;
}
void maxHeapify(int H[], int n, int nodStart)
{
    Operation Atrib = p.createOperation("BottomUpAtrib", n);
    Operation Comp = p.createOperation("BottomUpComp", n);
    int dreapta;
    if (right(nodStart) > n - 1)
        dreapta = left(nodStart);
    else
        dreapta = right(nodStart);
    int largest = indexOfMax(H, nodStart, left(nodStart), dreapta, n);
    if (largest != nodStart)
    {
        Atrib.count();
        swap(H[nodStart], H[largest]);
        if (largest <= n / 2 - 1) //pozitia lui n/2-1 este ultimul nod intern care sigur este parinte
            maxHeapify(H, n, largest);
    }
}
void BUILD_HEAP_bottomUp(int H[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(H, n, i);
}
void BUILD_HEAP_topDown(int H[], int n)
{
    Operation Atrib2 = p.createOperation("TopDownAtrib", n);
    Operation Comp2 = p.createOperation("TopDownComp", n);
    /*
     * Pasul 1: Se creeaza un nod nou la sfarsitul Heap-ului (nod fiu)
     * Pasul 2: Se asigneaza o valoare nodului nou
     * Pasul 3: Se compara valoarea nodului nou cu valoarea parintelui
     * Pasul 4: Daca valoarea parintelui este mai mare(mica, dupa caz) decat valoarea din fiu, atunci se interschimba
     * Pasul 5: Se repeta pasii 3 si 4 pana cand proprietatea de Heap e adevarata
     */
    int* sequence = (int*)malloc(n * sizeof(int));
    int SIZE = 0, aux = 0, index;
    for (SIZE = 0; SIZE < n; SIZE++)
    {
        Atrib2.count();
        sequence[SIZE] = H[SIZE];
        if (SIZE > 0)
        {
            index = SIZE;
            while (index > 0)
            {
                Comp2.count();
                if (sequence[index] > sequence[(index - 1) / 2]) //daca valoarea fiului nou este mai mica decat valoarea parintelui
                {
                    Atrib2.count();
                    swap(sequence[index], sequence[(index - 1) / 2]);
                }
                index = (index - 1) / 2; //continuam cu indexul sa vedem ce se intampla in relatia parinte-bunic s.o.
            }
        }
    }
    //Now we transcribe (transcriem) the 'sequence[]' array into the original 'H[]' array
    for (int i = 0; i < n; i++) {
        Atrib2.count();
        H[i] = sequence[i];
    }
}
void HEAPSORT(int H[], int n)
{
    BUILD_HEAP_bottomUp(H, n);
    int i;
    for (i = n - 1; i >= 1; i--)
    {
        printf("(%d)\n", H[0]);
        swap(H[i], H[0]);
        n--;
        if (n > 1)
            maxHeapify(H, n, 0);
        printf("\n");
    }
    cout << "["; listHeap(H, n);
    printf("(%d)\n", H[i]);
}
void demo_bottomUp()
{
    int H[] = { 16, 10, 24 , 9, 33, 6, 48, 5 };
    //int H[] = { 5,4,3,2,1,2,6,1,3 };
    //int H[] = { 1,2,3,4,5,6,7,8 };
    int n = sizeof(H) / sizeof(n);
    BUILD_HEAP_bottomUp(H, n);
    listHeap(H, n);
}
void demo_topDown()
{
    int H[] = { 16, 10, 24 , 9, 33, 6, 48, 5 };
    //int H[] = { 5,4,3,2,1,2,6,1,3 };
    //int H[] = { 1,2,3,4,5,6,7,8 };
    int n = sizeof(H) / sizeof(n);
    BUILD_HEAP_topDown(H, n);
    listHeap(H, n);
}
void demo_heapsort()
{
    int H[] = { 16, 10, 24 , 9, 33, 6, 48, 5 };
    //int H[] = { 5,4,3,2,1,2,6,1,3 };
    //int H[] = { 1,2,3,4,5,6,7,8 };
    //int H[] = { 1,1,2,2,2,3,4,4,4,5 };
    int n = sizeof(H) / sizeof(n);
    HEAPSORT(H, n);
}
void copySir(int A[], int B[], int n)
{
    for (int i = 0; i < n; i++)
        B[i] = A[i];
}
void perf(int order)
{
    int H[MAX_SIZE], H_copy[MAX_SIZE];
    int n;
    for (n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE) {
        for (int test = 0; test < NR_TESTS; test++) {
            FillRandomArray(H, n, 10, 50000, false, order);
            copySir(H, H_copy, n);
            BUILD_HEAP_bottomUp(H, n);
            copySir(H_copy, H, n);
            BUILD_HEAP_topDown(H, n);
        }
    }

    p.divideValues("BottomUpAtrib", NR_TESTS);
    p.divideValues("BottomUpComp", NR_TESTS);
    p.addSeries("bottomup", "BottomUpAtrib", "BottomUpComp");

    p.divideValues("TopDownAtrib", NR_TESTS);
    p.divideValues("TopDownComp", NR_TESTS);
    p.addSeries("topdown", "TopDownAtrib", "TopDownComp");

    p.createGroup("atribuiri", "BottomUpAtrib", "TopDownAtrib");
    p.createGroup("comparatii", "BottomUpComp", "TopDownComp");
    p.createGroup("total", "bottomup", "topdown");

    p.showReport();
}
void perf_all()
{
    perf(UNSORTED);
    p.reset("Worst");
    perf(ASCENDING);
    p.showReport();
}
int main()
{
    //demo_bottomUp();
    //demo_topDown();
    //demo_heapsort();
    perf_all();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
