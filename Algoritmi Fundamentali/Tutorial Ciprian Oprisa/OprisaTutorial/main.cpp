/* Bartolomei Vlad, 30229, 2022-2023
*Nume prenume gruoa
*am implementat 3 variante pentru...
* am observat ca pe average case cel mai rapid algoritm a fost...
* pe worst case cel mai rapid algoritm a fost v2
* ...
* zi complexitatile
*/

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

void secondMin_v3(const int v[], int n, int *min, int *min2)
{
    Operation opComp = p.createOperation("v3-comp", n);
    Operation opAtrib = p.createOperation("v3-atrib", n);
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
        if(v[i] < *min2)
        {
            opComp.count();
            if(v[i] < *min)
            {
                opAtrib.count(2);
                *min2 = *min;
                *min = v[i];
            }
            else
            {
                opAtrib.count();
                *min2 = v[i];
            }
        }
    }
}

typedef struct _Game{
    int outcome; //indicele castigatorului
    struct _Game *winner;
    struct _Game *loser;
}Game;

void secondMin_v4(const int v[], int n, int *min, int *min2)
{
    Game games[2*MAX_SIZE];
    int i, j;
    ///initialise the leafs
    for(i = 0; i < n; i++)
    {
        games[i].outcome = i;
        games[i].winner = games[i].loser = NULL;
    }
    i = 0; j = n;
    while (j - i + 1)
    {
        if(v[games[i].outcome] < v[games[i+1].outcome])
        {
            games[j].outcome = games[i].outcome;
            games[j].winner = &games[i];
            games[j].loser = &games[i+1];
        }
        else
        {
            games[j].outcome = games[i+1].outcome;
            games[j].winner = &games[i+1];
            games[j].loser = &games[i];
        }
        i+=2;
        j++;
    }

    *min=v[games[j-1].outcome];
    *min2=v[games[j-1].loser->outcome];
    Game *g = games[j-1].winner;
    while(g->loser != NULL)
    {
        if(v[g->loser->outcome] < *min2)
        {
            *min2 = v[g->loser->outcome];
        }
        g = g->winner;
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
    printf("v2: min = %d, min2 = %d\n", min, min2);
    secondMin_v3(v, n, &min, &min2);
    printf("v3: min = %d, min2 = %d\n", min, min2);
    secondMin_v4(v, n, &min, &min2);
    printf("v4: min = %d, min2 = %d\n", min, min2);
}

void test()
{
    int v[MAX_SIZE];
    int n;
    int min = 0, min2 = 0;
    int pass = 0, fail = 0;
    for(int testx=0; testx<1000;testx++)
    {
       n = 2 + (rand()%(MAX_SIZE - 2));
       FillRandomArray(v, n);
       secondMin_v4(v, n, &min, &min2);
       sort(v+n);
       if(v[0]==min && v[1]==min2)
       {
           pass++;
       }
       else
       {
           fail++;
       }
    }
}

void perf(int order)
{
    int v[MAX_SIZE];
    int n;
    int min = 0, min2 = 0;
    for(n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE){
            for(int test = 0; test < NR_TESTS; test++){
                FillRandomArray(v, n, 10, 50000, false, order);
                secondMin_v1(v, n, &min, &min2);
                secondMin_v2(v, n, &min, &min2);
                secondMin_v3(v, n, &min, &min2);
            }
    }

    p.divideValues("v1-atrib", NR_TESTS);
    p.divideValues("v1-comp", NR_TESTS);
    p.addSeries("v1", "v1-atrib", "v1-comp");

    p.divideValues("v2-atrib", NR_TESTS);
    p.divideValues("v2-comp", NR_TESTS);
    p.addSeries("v2", "v2-atrib", "v2-comp");

    p.divideValues("v3-atrib", NR_TESTS);
    p.divideValues("v3-comp", NR_TESTS);
    p.addSeries("v3", "v3-atrib", "v3-comp");

    p.createGroup("atribuiri", "v1-atrib", "v2-atrib", "v3-atrib");
    p.createGroup("comparatii", "v1-comp", "v2-comp", "v3-comp");
    p.createGroup("total", "v1", "v2", "v3");

    p.showReport();
}

void perf_all()
{
    perf(UNSORTED);
    p.reset("best");
    perf(ASCENDING);
    p.reset("worst");
    perf(DESCENDING);
    p.showReport();
}
int main() {
    printf("--no servus ^.^-- \n");
    printf("check project file for the graphs\n");
    //demo();
    test();
    //perf_all();
    return 0;
}
