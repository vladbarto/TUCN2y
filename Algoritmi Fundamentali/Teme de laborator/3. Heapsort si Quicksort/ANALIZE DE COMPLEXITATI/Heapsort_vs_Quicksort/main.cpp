#include <iostream>
#include <stdlib.h>
#include "Profiler.h"
#define MAX_SIZE 10000
#define STEP_SIZE 100
#define NR_TESTS 5
Profiler p("Quicksort_vs_Heapsort");
using namespace std;
/*
 * Vlad-Alexandru Bartolomei, grupa 30229, CTI 2021-2025
 */
void listArray(int Array[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", Array[i]);
    }
    printf("\n");
}
///HeapSort
int left(int i)
{
    return 2 * i + 1;
}
int right(int i)
{
    return 2 * i + 2;
}
int indexOfMax(int H[], int a, int b, int c, int n)
{
    Operation Atrib = p.createOperation("heapsortAtrib", n);
    Operation Comp = p.createOperation("heapsortComp", n);
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
    Operation Atrib = p.createOperation("heapsortAtrib", n);
    Operation Comp = p.createOperation("heapsortComp", n);
    int dreapta;
    if (right(nodStart) > n - 1)
        dreapta = left(nodStart);
    else
        dreapta = right(nodStart);
    int largest = indexOfMax(H, nodStart, left(nodStart), dreapta, n);
    if (largest != nodStart)
    {
        Atrib.count(3);
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
void HEAPSORT(int H[], int n)
{
    Operation Atrib = p.createOperation("heapsortAtrib", n);
    BUILD_HEAP_bottomUp(H, n);
    int i;
    for (i = n - 1; i >= 1; i--)
    {
        Atrib.count(3);
        swap(H[i], H[0]);
        n--;
        if (n > 1)
            maxHeapify(H, n, 0);//unde 0 - nodul de pornire in heap
    }
}
void demo_heapsort()
{
    //int H[] = { 16, 10, 24 , 9, 33, 6, 48, 5 };
    int H[] = {9, 3, 12, 5, 7, 2, 9, 5};
    //int H[] = { 5,4,3,2,1,2,6,1,3 };
    //int H[] = { 1,2,3,4,5,6,7,8 };
    //int H[] = { 1,1,2,2,2,3,4,4,4,5 };
    int n = sizeof(H) / sizeof(n);
    HEAPSORT(H, n);
    for(int i = 0; i < n; i++)
        printf("%d ", H[i]);
}
///QuickSort
int partitionHoare(int arr[], int indexI, int indexF, int n){
    //where I stands for Initial, F for Final
    Operation Atrib = p.createOperation("quicksortAtrib", n);
    Operation Comp = p.createOperation("quicksortComp", n);
    Atrib.count();
    int x = arr[indexI];
    int i = indexI - 1;
    int j = indexF + 1;
    while(i <= j){
        do{
            j--;
            Comp.count();
        }while(!(arr[j] <= x));
        do{
            i++;
            Comp.count();
        }while(!(arr[i] >= x));
        if(i < j)
        {
            Atrib.count(3);
            swap(arr[i], arr[j]);
        }
        else
        {
            return j;
        }
    }
}
void partitionHoareUpdated(int arr[], int indexI, int indexF){
    int x = arr[(indexI + indexF)/2];
    int i = indexI;
    int j = indexF;
    do{
        while(arr[i] < x)
            i++;
        while(arr[j] > x)
            j--;
        if(i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }while(j < i);
}
void QUICKSORT(int arr[], int low, int high, int n){
    //low, high = indexes of the very first, and very last element respectively
    int inter; // inter, as in intermediate index
    if(low < high){
        inter = partitionHoare(arr, low, high, n);
        QUICKSORT(arr, low, inter, n);
        QUICKSORT(arr, inter + 1, high, n);
    }
}
void demo_quicksort(){
    int arr[] = {9, 3, 12, 5, 7, 2, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    QUICKSORT(arr, 0, n - 1, n);
    listArray(arr, n);
}
void copySir(int src[], int dest[], int n)
{
    for(int i = 0; i < n; i++)
        dest[i] = src[i];
}
void perf()
{
    int arr[MAX_SIZE], arrcopy[MAX_SIZE];
    int n;

    for (n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE) {
        for (int test = 0; test < NR_TESTS; test++) {
            FillRandomArray(arr, n);

            copySir(arr, arrcopy, n);
            QUICKSORT(arrcopy, 0, n-1, n);
            HEAPSORT(arr, n);
        }
    }
    p.divideValues("quicksortAtrib", NR_TESTS);
    p.divideValues("quicksortComp", NR_TESTS);
    p.addSeries("quicksort", "quicksortAtrib", "quicksortComp");

    p.divideValues("heapsortAtrib", NR_TESTS);
    p.divideValues("heapsortComp", NR_TESTS);
    p.addSeries("heapsort", "heapsortAtrib", "heapsortComp");

    p.createGroup("total", "quicksort", "heapsort");
    p.createGroup("atribuiri", "quicksortAtrib", "heapsortAtrib");
    p.createGroup("comparatii", "quicksortComp", "heapsortComp");

    p.showReport();
}
int main() {
    perf();
    return 0;
}
