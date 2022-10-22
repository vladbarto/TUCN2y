#include <iostream>
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}
int indexOfMax(int a, int b, int c)
{
    if(a > b)
}
void maxHeapify(int H[], int i)
{
    int largest = indexOfMax(i, left(i), right(i));
    if(largest != i)
    {
        swap(H[i], H[largest]);
        maxHeapify(H, largest);
    }
}
int main() {

    return 0;
}
