///Bartolomei Vlad
/*
    PENTRU AVERAGE CASE:
    Atribuiri: curbele nu se suprapun, insa exista totusi o diferenta sesizabila. De la 500 pana la 50000 de atribuiri, overall.
        bottomUp : theta(nlogn)
        topDown: theta(tot nlogn), numai ca mai multe atribuiri in cod
    Comparatii: aici diferenta e absolut colosala!
        topDown: se mentine aceeasi rata de crestere, theta(nlogn)
        bottomUp: greu de spus ce complexitate are, dar un lucru e cert: graficul sau creste foarte greu!
            Adica, dupa 50.000 de teste, o constructie bottomUp nu depaseste 10000 de comparatii,
            in timp ce o constructie topDown atinge peste 700000 de comparatii
    Concluzia overall este simpla: constructia de heap Bottom-up este mai economa decat Top-Down
*/

/*
    PENTRU WORST CASE: TopDown Build e cu mult mai costisitoare decat BottomUp
    Atribuiri: aici numarul pentru topdown creste ceva mai greoi decat la comparatii, nevertheless still being extremely expensive.
    Comparatii: pentru o dimensiune a sirului de 35000 de elemente, bottomUp scoate undeva la 20000 de comparatii. TopDown, in schimb, pe la 4000000!
    Concluzie: un Build Topdown are o limita superioara mult mai generoasa decat o constructie BottomUp, astfel fiind mai greu de marginit.
*/
#include <iostream>
#include <stdlib.h>
#include "Profiler.h"
using namespace std;
Profiler p("Heap-uri");
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
        std::cout << H[i] << " ";
    printf("\n");
}
int indexOfMin(int H[], int a, int b, int c, int n)
{//a, b si c sunt indecsii (see call)
    Operation opComp = p.createOperation("bottomup-c", n);
    Operation opAtrib = p.createOperation("bottomup-a", n);
    opAtrib.count();
    int minimum = H[a], minIndex = a;
    opComp.count();
    if (H[b] < minimum)
    {
        opAtrib.count();
        minimum = H[b];
        minIndex = b;
    }
    else
    {
        opComp.count();
        if (H[c] < minimum)
        {
            opAtrib.count();
            minimum = H[c];
            minIndex = c;
        }
    }
    return minIndex;
}
int indexOfMax(int H[], int a, int b, int c, int n)
{//a, b si c sunt indecsii
    Operation opComp = p.createOperation("bottomup-c", n);
    Operation opAtrib = p.createOperation("bottomup-a", n);
    opAtrib.count();
    int maximum = H[a], maxIndex = a;
    opComp.count();
    if (H[b] > maximum)
    {
        opAtrib.count();
        maximum = H[b];
        maxIndex = b;
    }
    else
    {
        opComp.count();
        if (H[c] > maximum) {
            opAtrib.count();
            maximum = H[c];
            maxIndex = c;
        }
    }
    return maxIndex;
}
void minHeapify(int H[], int n, int i)
{
    //Operation opComp = p.createOperation("bottomup-c", n);
    Operation opAtrib = p.createOperation("bottomup-a", n);
    int smallest;
    if (i == (n / 2 - 1) && right(i) > n - 1)
    {
        smallest = indexOfMin(H, i, left(i), left(i), n);
    }
    else
    {
        smallest = indexOfMin(H, i, left(i), right(i), n);
    }
    opAtrib.count();
    int aux = H[i];
    if (smallest != i)
    {
        //swap(H[i], H[smallest]);
        opAtrib.count(3);
        aux = H[i]; H[i] = H[smallest]; H[smallest] = aux;
        if (smallest < n / 2)
            minHeapify(H, n, smallest);
    }
}
void maxHeapify(int H[], int n, int i)//i este nodul apelat
{
    //Operation opComp = p.createOperation("bottomup-c", n);
    Operation opAtrib = p.createOperation("bottomup-a", n);
    int largest;
    if (i == (n / 2 - 1) && right(i) > n - 1)
        largest = indexOfMax(H, i, left(i), left(i), n);
    else
        largest = indexOfMax(H, i, left(i), right(i), n);
    opAtrib.count();
    int aux = H[i];
    if (largest != i)
    {
        //swap(H[i], H[largest]);
        opAtrib.count(3);
        aux = H[i]; H[i] = H[largest]; H[largest] = aux;
        if (largest < n / 2)
            maxHeapify(H, n, largest);
    }
}
void BUILD_HEAP_bottomUp(int H[], int n, int typeOfHeap)
{
    //0 - minHeap, 1 - maxHeap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        if (typeOfHeap == 0)
            minHeapify(H, n, i);
        else
            maxHeapify(H, n, i);
    }
}

void BUILD_HEAP_topDown(int H[], int n, int typeOfHeap)
{
    /*
     * Pasul 1: Se creeaza un nod nou la sfarsitul Heap-ului (nod fiu)
     * Pasul 2: Se asigneaza o valoare nodului nou
     * Pasul 3: Se compara valoarea nodului nou cu valoarea parintelui
     * Pasul 4: Daca valoarea parintelui este mai mare(mica, dupa caz) decat valoarea din fiu, atunci se interschimba
     * Pasul 5: Se repeta pasii 3 si 4 pana cand proprietatea de Heap e adevarata
     */
    Operation opComp2 = p.createOperation("topdown-c", n);
    Operation opAtrib2 = p.createOperation("topdown-a", n);
    int sequence[n], SIZE = 0, aux = 0, index;
    while (SIZE < n)
    {
        opAtrib2.count();
        sequence[SIZE] = H[SIZE];
        if (SIZE > 0)
        {
            index = SIZE;
            while (index > 0)
            {
                if (typeOfHeap == 0)
                {
                    opComp2.count();
                    if (sequence[index] < sequence[(index-1) / 2]) //daca valoarea fiului nou este mai mare decat valoarea parintelui
                    {
                        opAtrib2.count(3);
                        aux = sequence[index];
                        sequence[index] = sequence[(index-1) / 2];
                        sequence[(index-1) / 2] = aux;
                    }
                }
                else //In functie de ce vrem, heap minim sau heap maxim
                {
                    opComp2.count();
                    if (sequence[index] > sequence[(index-1) / 2]) //daca valoarea fiului nou este mai mica decat valoarea parintelui
                    {
                        opAtrib2.count(3);
                        aux = sequence[index];
                        sequence[index] = sequence[(index-1) / 2];
                        sequence[(index-1) / 2] = aux;
                    }
                }
                index = (index - 1) / 2; //continuam cu indexul sa vedem ce se intampla in relatia parinte-bunic s.o.
            }
        }
        SIZE++;
    }
    //printf("He");listHeap(sequence, SIZE);
    //Now we transcribe (transcriem) the 'sequence[]' array into the original 'H[]' array
    for (int i = 0; i < n; i++) {
        opAtrib2.count();
        H[i] = sequence[i];
    }
}
void HEAPSORT(int H[], int n, int typeOfHeap)
{
    BUILD_HEAP_bottomUp(H, n, typeOfHeap); ///O(n)
    int aux = 0;
    for (int i = n - 1; i >= 0; i--) //n-1 times
    {
        //listHeap(H, n);
        printf("<%d> ", H[0]);
        aux = H[0]; H[0] = H[i]; H[i] = aux; ///O(1)
        n--; ///O(1)
        if (typeOfHeap == 0)
            minHeapify(H, n, 0);
        else
            maxHeapify(H, n, 0);
        listHeap(H, n);
    }
    printf("<%d> ", H[0]);
    printf("\n");
}
void demo_bottomUp()
{
    //int H[] = {35, 33, 42, 10, 19, 27, 44, 26, 31};
    int H[] = { 5, 7, 2, 4, 2, 1, 2, 3 };
    int n = sizeof(H) / sizeof(H[0]);
    listHeap(H, n);
    BUILD_HEAP_bottomUp(H, n, 1);
    listHeap(H, n);
}
void demo_topDown()
{
    //int H[] = { 35, 33, 42, 10, 19, 27, 44, 26, 31 };
    int H[] = {5,4,3,2,1,2,6};
    int n = sizeof(H) / sizeof(H[0]);
    listHeap(H, n);
    BUILD_HEAP_topDown(H, n, 1);
    listHeap(H, n);
}
void demo_HeapSort()
{
    //int H[] = { 7, 5, 2, 4, 2, 1, 2, 3 };
    int H[] = {5,4,3,2,1,2,6};
    int n = sizeof(H) / sizeof(H[0]);
    BUILD_HEAP_topDown(H, n, 1);
    //BUILD_HEAP_bottomUp(H, n, 0);
    listHeap(H, n);
    HEAPSORT(H, n, 1);
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
            BUILD_HEAP_bottomUp(H, n, 1);
            copySir(H_copy, H, n);
            BUILD_HEAP_topDown(H, n, 1);
        }
    }

    p.divideValues("bottomup-a", NR_TESTS);
    p.divideValues("bottomup-c", NR_TESTS);
    p.addSeries("bottomup", "bottomup-a", "bottomup-c");

    p.divideValues("topdown-a", NR_TESTS);
    p.divideValues("topdown-c", NR_TESTS);
    p.addSeries("topdown", "topdown-a", "topdown-c");

    p.createGroup("atribuiri", "bottomup-a", "topdown-a");
    p.createGroup("comparatii", "bottomup-c", "topdown-c");
    p.createGroup("total", "bottomup", "topdown");

    p.showReport();
}
void perf_all()
{
    //p.reset("Average");
    //perf(UNSORTED);
    p.reset("Worst");
    perf(ASCENDING);
    p.showReport();
}
int main() {
    demo_HeapSort();

    //demo_bottomUp();
    //demo_topDown();
    //perf_all();
    return 0;
}
