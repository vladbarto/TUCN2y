#include <iostream>
#include <stdlib.h>
#include "Profiler.h"
//Sa se determine cel mai mic element si al doilea cel mai mic element dintr-un vector dat.

Profiler p("secondMin");

void secondMin_v1(int v[], int n, int *min, int *min2)
{
    Operation opComp = p.createOperation("v1-comp", n);
    Operation opAtrib = p.createOperation("v1-atrib", n);

    if(n < 2)
    {
        printf("throw: vectorul are un singur element \n");
    }

    opAtrib.count(); //numara-mi o atribuire aici
    *min = v[0];
    int pmin = 0;
    for(int i = 1; i <= n; i++) //comparatie pe indici, nu numaram
    {
        opComp.count();
        if(v[i] < *min)//numara-mi o comparatie aici
        {
            opAtrib.count(); //numara-mi o atribuire aici
            *min = v[i];
            pmin = i;
        }
    }
    if(pmin == 0)
    {
        *min2 = v[1];
    }
    else
    {
        *min2 = v[0];
    }
    opAtrib.count();
    for(int i = 0; i <= n; i++)
    {
        if(i != min)
        {
            if(v[i] < *min2)
                *min2 = v[i];
        }
    }
}

void demo()
{
    int v[] = {7, 2, 8, 5, 9, 1, 6};
    int n = sizeof(v) / sizeof(v[0]);
    int min = 0, min2 = 0;

    secondMin_v1(v, n, &min, &min2);
    printf("v1: min = %d, min2 = %d\n", min, min2);
}
int main() {
    printf("--no servus ^.^-- \n");
    demo();
    return 0;
}
