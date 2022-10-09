#include <stdio.h>
#include <stdlib.h>

void EXTRACT_MIN_POS(int A[], int index, int n, int *reqpos)
{
    //A is sorted in range [0, index-1]
    //A is unsorted in range [index, n)
    *reqpos = index;
    int minimum = A[index];
    for(int i = index+1; i < n; i++) {
        if (minimum > A[i]) {
            minimum = A[i];
            *reqpos = i;
        }
    }
}
void SWAP(int A[], int first_el_index, int *second_el_index)
{
    int aux;
    aux = A[first_el_index];
    A[first_el_index] = A[*second_el_index];
    A[*second_el_index] = aux;
}
void selection(int A[], int n)
{
    int index = 0, required_position;
    while(index < n)
    {
        EXTRACT_MIN_POS(A, index, n, &required_position); //where required_position is more like needed position
        if(index != required_position)
            SWAP(A, index, &required_position);
        index ++;
    }
}
void listA(int A[], int n)
{
    printf("A: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main() {
    int n = 5;
    int A[5] = {27, 5, 9, 3, 7};
    selection(A, n);
    listA(A, n);
    return 0;
}
