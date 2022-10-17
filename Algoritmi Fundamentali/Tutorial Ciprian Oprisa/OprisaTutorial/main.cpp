#include <iostream>
#include <stdlib.h>
#include "Profiler.h"
//Sa se determine cel mai mic element si al doilea cel mai mic element dintr-un vector dat.

Profiler p("secondMin");

#define MAX_SIZE 10000
#define STEP_SIZE 100
#define NR_TESTS 50

void secondMin_v1(const int v[], int n, int *min, int *min2)
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
        opComp.count();
        if(i != pmin)
        {
            if(v[i] < *min2){
                opAtrib.count();
                *min2 = v[i];
            }
        }
    }
}

void secondMin_v2(const int v[], int n, int *min, int *min2)
{
    Operation opComp = p.createOperation("v2-comp", n);
    Operation opAtrib = p.createOperation("v2-atrib", n);
    opComp.count();
    if(v[0] < v[1]){
        opAtrib.count(2);
        *min = v[0];
        *min2 = v[1];
    }
    else{
        opAtrib.count(2);
        *min = v[1];
        *min2 =  v[0];
    }

    for(int i = 2; i < n; i++)
    {
        opComp.count();
        if(v[i] < *min)
        {
            opAtrib.count(2);
            *min2 = *min;
            *min = v[i];
        }else{
            opComp.count();
            if(v[i] < *min2)
            {
                opAtrib.count();
                *min2 = v[i];
            }
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
    secondMin_v2(v, n, &min, &min2);
    printf("v1: min = %d, min2 = %d\n", min, min2);
}

void perf()
{
    int v[MAX_SIZE];
    int n;
    int min = 0, min2 = 0;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE){
            for(int test = 0; test < NR_TESTS; test++){
                FillRandomArray(v, n);
                secondMin_v1(v, n, &min, &min2);
                secondMin_v2(v, n, &min, &min2);
            }
    }

    p.divideValues("v1-atrib", NR_TESTS);
    p.divideValues("v1-comp", NR_TESTS);
    p.addSeries("v1", "v1-atrib", "v1-comp");

    p.divideValues("v2-atrib", NR_TESTS);
    p.divideValues("v2-comp", NR_TESTS);
    p.addSeries("v2", "v2-atrib", "v2-comp");

    p.createGroup("atribuiri", "v1-atrib", "v2-atrib");
    p.createGroup("comparatii", "v1-comp", "v2-comp");
    p.createGroup("total", "v1", "v2");

    p.showReport();
}
int main() {
    printf("--no servus ^.^-- \n");
    printf("check project file for the graphs\n");
    //demo();
    perf();
    return 0;
}
