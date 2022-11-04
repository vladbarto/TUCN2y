#include <iostream>
using namespace std;
void listArray(int A[], int n)
{
    printf("A: ");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void i_BINARY_INSERT_POS(int A[], int high_index, int *new_pos)
{
    int n = sizeof(A)/sizeof(A[0]);
    //Operation opComp = p.createOperation("insertbinar-comp", n);
    //Operation opAtrib = p.createOperation("insertbinar-atrib", n);
    int low = 0, high = high_index;
    while(low != high)
    {
        int mid = (low + high) / 2; //pe indecsi. nu numaram
        //opComp.count();
        if(A[high_index] > A[mid])
        {
            low = mid+1;
        }
        else
        {
            //opComp.count();
            if(A[high_index] < A[mid])
            {
                high = mid;
            }
        }
    }
    *new_pos = low;
}
void r_BINARY_INSERT_POS(int A[], int high_index, int *new_pos)
{
    int n = sizeof(A)/sizeof(A[0]);
    //Operation opComp = p.createOperation("insertbinar-comp", n);
    //Operation opAtrib = p.createOperation("insertbinar-atrib", n);
    int low = 0, high = high_index;
    if(low > high)
    *new_pos = low;
}
void insertion(int A[], int n, bool cautaBinarRecursiv)
{
    //Operation opComp = p.createOperation("A-comp", n);
    //Operation opAtrib = p.createOperation("A-atrib", n);
    int high_index = 1;
    int aux;
    int new_pos;
    while(high_index <= n-1)
    {
        if(cautaBinarRecursiv == false)
        {
            new_pos = high_index;
            i_BINARY_INSERT_POS(A, high_index, &new_pos);
        }
        else
        {
            new_pos = -1;
            r_BINARY_INSERT_POS(A, high_index, &new_pos);
        }
        //opAtrib.count();
        aux = A[high_index];
        for (int i = high_index; i >= new_pos + 1; i--)
        {
            //opAtrib.count();
            A[i] = A[i - 1];
        }
        //opAtrib.count();
        A[new_pos] = aux;
        high_index++;
    }
}

void demo()
{
    int A[] = {27, 9, 3, 30, 45, 4, 12};
    //int A[]={27, 9, 8, 30, 28};
    int n = sizeof(A)/sizeof(A[0]);
    insertion(A, n, true);
    listArray(A, n);
}
int main() {
    demo();
    return 0;
}
