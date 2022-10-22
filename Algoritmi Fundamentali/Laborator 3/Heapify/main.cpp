#include <bits/stdc++.h>
using namespace std;
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
int indexOfMin(int H[], int a, int b, int c)
{//a, b si c sunt indecsii (see call)
    int minimum = H[a], minIndex = a;
    if (H[b] < minimum)
        minimum = H[b], minIndex = b;
    else
    if (H[c] < minimum)
        minimum = H[c], minIndex = c;
    return minIndex;
}
int indexOfMax(int H[], int a, int b, int c)
{//a, b si c sunt indecsii (see call)
    int maximum = H[a], maxIndex = a;
    if (H[b] > maximum)
        maximum = H[b], maxIndex = b;
    else
        if (H[c] > maximum)
            maximum = H[c], maxIndex = c;
    return maxIndex;
}
void minHeapify(int H[], int n, int i)
{
    int smallest = indexOfMin(H, i, left(i), right(i));
    int aux;
    if(smallest != i)
    {
        //swap(H[i], H[smallest]);
        aux = H[i]; H[i] = H[smallest]; H[smallest] = aux;
        if(smallest < n/2)
            minHeapify(H, n, smallest);
    }
}
void maxHeapify(int H[], int n, int i)//i este nodul apelat
{
    int largest = indexOfMax(H, i, left(i), right(i));
    int aux = H[i];
    if(largest != i)
    {
        //swap(H[i], H[largest]);
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
    int sequence[9], size = 0, aux = 0, index;
    while(size < n)
    {
        sequence[size] = H[size];
        if(size > 0)
        {
                index = size;
                while(index > 0)
                {
                    if(typeOfHeap == 0)
                    {
                        if(sequence[index] > sequence[index/2]) //daca valoarea fiului nou este mai mare decat valoarea parintelui
                        {
                            aux = sequence[index];
                            sequence[index] = sequence[index/2];
                            sequence[index/2] = aux;
                        }
                    }
                    else
                    {
                        if(sequence[index] < sequence[index/2]) //daca valoarea fiului nou este mai mica decat valoarea parintelui
                        {
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
    for(int i = 0; i < n; i++)
        H[i] = sequence[i];
}
void HEAPSORT(int H[], int n, int typeOfHeap)
{
    BUILD_HEAP_bottomUp(H, n, typeOfHeap); ///O(n)
    int aux = 0;
    for(int i = n-1; i >= 1; i--) //n-1 times
    {
        listHeap(H, n);
        printf("%d.<%d> ",i, H[0]);
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
    int H[] = {35, 33, 42, 10, 19, 27, 44, 26, 31};
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
    //BUILD_HEAP_bottomUp(H, n, 0);
    HEAPSORT(H, n, 0);

}
int main() {
    demo_HeapSort();
    return 0;
}
