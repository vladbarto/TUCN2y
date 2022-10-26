#include <bits/stdc++.h>
#include "Profiler.h"
using namespace std;
Profiler p("Heap-uri");
#define MAX_SIZE 10000
#define STEP_SIZE 100
#define NR_TESTS 5
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}
void listHeap(int H[], int n)
{
    for(int i = 0; i < n; i++)
        std::cout<<H[i]<<" ";
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
    Operation opComp = p.createOperation("bottomup-c", n);
    Operation opAtrib = p.createOperation("bottomup-a", n);
    int smallest;
    if(i == (n/2 - 1) && right(i) > n - 1)
    {
        smallest = indexOfMin(H, i, left(i), left(i), n);
    }
    else
    {
        smallest = indexOfMin(H, i, left(i), right(i), n);
    }
    opAtrib.count();
    int aux = H[i];
    if(smallest != i)
    {
        //swap(H[i], H[smallest]);
        opAtrib.count(3);
        aux = H[i]; H[i] = H[smallest]; H[smallest] = aux;
        if(smallest < n/2)
            minHeapify(H, n, smallest);
    }
}
void maxHeapify(int H[], int n, int i)//i este nodul apelat
{
    Operation opComp = p.createOperation("bottomup-c", n);
    Operation opAtrib = p.createOperation("bottomup-a", n);
    int largest;
    if(i == (n/2 - 1) && right(i) > n - 1)
        largest = indexOfMax(H, i, left(i), left(i), n);
    else
        largest = indexOfMax(H, i, left(i), right(i), n);
    opAtrib.count();
    int aux = H[i];
    if(largest != i)
    {
        //swap(H[i], H[largest]);
        opAtrib.count(3);
        aux = H[i]; H[i] = H[largest]; H[largest] = aux;
        if(largest < n/2)
            maxHeapify(H, n, largest);
    }
}
void BUILD_HEAP_bottomUp(int H[], int n, int typeOfHeap)
{
    //0 - minHeap, 1 - maxHeap
    for(int i = n/2 - 1; i >= 0; i--)
    {
        if(typeOfHeap == 0)
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
    int sequence[9], size = 0, aux = 0, index;
    while(size < n)
    {
        opAtrib2.count();
        sequence[size] = H[size];
        if(size > 0)
        {
                index = size;
                while(index > 0)
                {
                    if(typeOfHeap == 0)
                    {
                        opComp2.count();
                        if(sequence[index] < sequence[index/2]) //daca valoarea fiului nou este mai mare decat valoarea parintelui
                        {
                            opAtrib2.count(3);
                            aux = sequence[index];
                            sequence[index] = sequence[index/2];
                            sequence[index/2] = aux;
                        }
                    }
                    else
                    {
                        opComp2.count();
                        if(sequence[index] > sequence[index/2]) //daca valoarea fiului nou este mai mica decat valoarea parintelui
                        {
                            opAtrib2.count(3);
                            aux = sequence[index];
                            sequence[index] = sequence[index / 2];
                            sequence[index / 2] = aux;
                        }
                    }
                    index = index/2; //continuam cu indexul sa vedem ce se intampla in relatia parinte-bunic s.o.
                }
        }
        size++;
    }
    //Now we transcribe (transcriem) the 'sequence[]' array into the original 'H[]' array
    for(int i = 0; i < n; i++) {
        opAtrib2.count();
        H[i] = sequence[i];
    }
}
void HEAPSORT(int H[], int n, int typeOfHeap)
{
    BUILD_HEAP_topDown(H, n, typeOfHeap); ///O(n)
    int aux = 0;
    for(int i = n-1; i >= 1; i--) //n-1 times
    {
        //listHeap(H, n);
        printf("<%d> ", H[0]);
        aux = H[0]; H[0] = H[i]; H[i] = aux; ///O(1)
        n--; ///O(1)
        if(typeOfHeap == 0)
            minHeapify(H, n, 0);
        else
            maxHeapify(H, n, 0);
        listHeap(H, n);
    }
    printf("\n");
}
void demo_bottomUp()
{
    //int H[] = {35, 33, 42, 10, 19, 27, 44, 26, 31};
    int H[] = {7, 5, 2, 4, 2, 1, 2, 3};
    int n = sizeof(H)/sizeof(H[0]);
    BUILD_HEAP_bottomUp(H, n, 0);
    listHeap(H, n);
}
void demo_topDown()
{
    int H[] = {35, 33, 42, 10, 19, 27, 44, 26, 31};
    int n = sizeof(H)/sizeof(H[0]);
    BUILD_HEAP_topDown(H, n, 1);
    listHeap(H, n);
}
void demo_HeapSort()
{
    int H[] = {7, 5, 2, 4, 2, 1, 2, 3};
    int n = sizeof(H)/sizeof(H[0]);
    BUILD_HEAP_topDown(H, n, 0);
    //BUILD_HEAP_bottomUp(H, n, 0);
    listHeap(H, n);
    //HEAPSORT(H, n, 0);
}
void copySir(int A[], int B[], int n)
{
    for(int i = 0; i < n; i++)
        B[i] = A[i];
}
void perf()
{
    int H[MAX_SIZE], H_copy[MAX_SIZE];
    int n;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE){
            for(int test = 0; test < NR_TESTS; test++){
                FillRandomArray(H, n);
                copySir(H, H_copy, n);
                BUILD_HEAP_bottomUp(H, n, 1);
                copySir(H_copy, H, n);
                BUILD_HEAP_topDown(H, n, 1);
            }
    }
    p.divideValues("topdown-c", NR_TESTS);
    p.addSeries("topdown", "topdown-a", "topdown-c");

    p.createGroup("atribuiri", "bottomup-a", "topdown-a");
    p.createGroup("comparatii", "bottomup-c", "topdown-c");
    p.createGroup("total", "bottomup", "topdown");

    p.showReport();
}
int main() {
    //demo_HeapSort();
    //demo_bottomUp();
    //demo_topDown();
    perf();
    return 0;
}