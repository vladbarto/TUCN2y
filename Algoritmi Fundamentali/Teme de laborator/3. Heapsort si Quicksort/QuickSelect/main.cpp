/*
 * ce intrebam?
 * aici in quickselect, cu acel +1
 * graficul la heapsort
 * nu am facut documentatia
 * lasa-ma te rog pana luni
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int partitionHoare(int arr[], int indexI, int indexF){
    //where I stands for Initial, F for Final
    int x = arr[indexI];
    int i = indexI - 1;
    int j = indexF + 1;
    while(i <= j){
        do{
            j--;
        }while(!(arr[j] <= x)); //adica do.. while(arr[j] > x)
        do{
            i++;
        }while(!(arr[i] >= x)); //adica do.. while(arr[i] < x)
        if(i < j)
        {
            swap(arr[i], arr[j]);
        }
        else
        {
            return j;
        }
    }
}
int random(int a, int b)
{
    int x = rand()%2;
    if(x == 0)
        return a;
    else
        return b;
}
int Randomized_Partition(int arr[], int p, int r)//efectiv din Cormen
{
    int i = random(p, r);
    swap(arr[r], arr[i]);
    return partitionHoare(arr, p, r);
}
int Randomized_Select(int A[], int p, int r, int i) // return the ith smallest elem. of A[p..r]
{
    if (p == r)
        return A[p];
    int q = Randomized_Partition(A,p,r); // compute pivot
    int k = q-p+1; // number of elements <= pivot
    if (i+1 == k)//aici era i == k initial
        return A[q]; // found ith smallest element
    else
    {
        if (i < k)
            return Randomized_Select(A,p,q-1,i);
        else Randomized_Select(A,q+1,r, i-k);
    }
}

void demo()
{
    //int arr[] = {25, 11, 38, 8, 51, 34, 29};
    int arr[] = {25, 11, 38, 8, 51};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = Randomized_Select(arr, 0, n-1, 0);
    int y = Randomized_Select(arr, 0, n-1, 1);
    int z = Randomized_Select(arr, 0, n-1, 2);
    int a = Randomized_Select(arr, 0, n-1, 3);
    int b = Randomized_Select(arr, 0, n-1, 4);//.
    int c = Randomized_Select(arr, 0, n-1, 5);
    int d = Randomized_Select(arr, 0, n-1, 6);
    int e = Randomized_Select(arr, 0, n-1, 7);
    //cout<<y<<endl;
    printf("%d %d %d <%d> %d %d %d %d", x, y, z, a, b, c, d, e);
}
int main() {
    printf("Hallo Leute!\n");
    //
    demo();
    return 0;
}
