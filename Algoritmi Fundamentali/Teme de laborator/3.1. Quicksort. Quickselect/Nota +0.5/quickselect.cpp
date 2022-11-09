#include <iostream>
#include <stdlib.h>

int random(int a, int b);

using namespace std;
int partition(int arr[], int indexI, int indexF/*, int pivot*/){
    //where I stands for Initial, F for Final
    //int x = pivot;
    int x = random(arr[indexF], arr[indexI]);
    int i = indexI - 1;
    int j = indexF + 1;
    while(i <= j){
        do{
            j--;
        }while(!(arr[j] <= x));
        do{
            i++;
        }while(!(arr[i] >= x));
        if(i < j)
            swap(arr[i], arr[j]);
        else
            return j;
    }
}
int random(int a, int b) {
    int x = rand()%2;
    if(x==0)
        return a;
    else
        return b;
}
int quickselect(int arr[], int l, int r, int k){
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
        // If position is same as k
        if (index - l == k - 1)
            return arr[index];
        // If position is more, recur
        // for left subarray
        if (index - l > k - 1)
            return quickselect(arr, l, index - 1, k);
        // Else recur for right subarray
        return quickselect(arr, index + 1, r,
                           k - index + l - 1);
    }

    // If k is more than number of
    // elements in array
    return INT_MAX;
}
/*int quickselect2(int arr[], int low, int high, int k)
{
    if(low == high)
        return arr[low];
    int pivotIndex = random(arr[low], arr[high]);
    pivotIndex = partition(arr, low, high, pivotIndex);
    if(k == pivotIndex)
        return arr[k];
    else
    {
        if (k < pivotIndex)
            high = pivotIndex-1;
        else
            low = pivotIndex+1;
    }
}*/
void demo()
{
    int arr[] = {25, 11, 38, 8, 51};
    //int arr[] = {25, 11, 38, 8, 51};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = quickselect(arr, 0, n-1, 0);
    int y = quickselect(arr, 0, n-1, 1);
    int z = quickselect(arr, 0, n-1, 2);
    int a = quickselect(arr, 0, n-1, 3);
    int b = quickselect(arr, 0, n-1, 4);
    int c = quickselect(arr, 0, n-1, 5);
    int d = quickselect(arr, 0, n-1, 6);
    int e = quickselect(arr, 0, n-1, 7);
    //cout<<y<<endl;
    printf("%d %d %d %d %d %d %d %d", x, y, z, a, b, c, d, e);
}
int main() {
    demo();
    return 0;
}
