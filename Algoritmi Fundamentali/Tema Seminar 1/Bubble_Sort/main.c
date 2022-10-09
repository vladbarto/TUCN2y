#include <stdio.h>
#include <stdbool.h>
void listA(int [], int);
void bubblesort(int A[], int n)
{
    int aux;
    int x = 0;
    bool swapped_flag;
    do
    {
        listA(A, n);
        swapped_flag = false;
        for(int i = 0; i < n-1; i++)
        {
            printf("  ");listA(A, n);
            if(A[i] > A[i+1])
            {
                aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
                swapped_flag = true;
            }
        }

       // n = n-1;
       x++;
       // if (x == n)
          //  break;
    }while (swapped_flag == true);
}
void listA(int A[], int n)
{
    printf("A: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main() {
    int n = 8;
    int A[8] = {9,3,12,7,5,2,9,5};
    bubblesort(A, n);
    listA(A, n);
    return 0;
}
