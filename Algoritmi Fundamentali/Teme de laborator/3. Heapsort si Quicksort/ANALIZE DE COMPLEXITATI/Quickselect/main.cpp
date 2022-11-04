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
   ;// return srand(1)%2;
}
int randomised_partition(int arr[], int p, int r)//efectiv din Cormen
{
    int i = random(p, r);
    swap(arr[r], arr[i]);
    return partitionHoare(arr, p, r);
}
int QUICKSELECT(int arr[], int low, int high, int i){
    //i - i.th element, desired rank
    if(low == high)
        return arr[low];
    int q = partitionHoare(arr, low, high);
    int k = q - low + 1;
    if(i == k)
        return arr[q];
    else
    {
        if(i < k)
            return QUICKSELECT(arr, low, q, i);
        else
            return QUICKSELECT(arr, q+1, high, i-k);
    }
}
void demo()
{
    //int arr[] = {25, 11, 38, 8, 51, 34, 29};
    int arr[] = {25, 11, 38, 8, 51};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = QUICKSELECT(arr, 0, n-1, 0);
    int y = QUICKSELECT(arr, 0, n-1, 1);
    int z = QUICKSELECT(arr, 0, n-1, 2);
    int a = QUICKSELECT(arr, 0, n-1, 3);
    int b = QUICKSELECT(arr, 0, n-1, 4);
    int c = QUICKSELECT(arr, 0, n-1, 5);
    int d = QUICKSELECT(arr, 0, n-1, 6);
    int e = QUICKSELECT(arr, 0, n-1, 7);
    //cout<<y<<endl;
    printf("%d %d %d %d %d %d %d %d", x, y, z, a, b, c, d, e);
}
int main() {
    printf("Hallo Leute!\n");
    //demo();
    cout<<rand()%2;
    return 0;
}
