#include <iostream>
#include <stdio.h>
#include "Profiler.h"
#define MAX_SIZE 100

Profiler p("secondMin");

int main() {
    //zona de declaratii variabile
    int v[MAX_SIZE];
    int n;
    int i = 0, x;
    FILE *pi = NULL; //pi - pointer la fisierul de Input
    FILE *po = NULL; // po - pointer la fisierul de Output

    //zona de Profiler
    Operation opComp = p.createOperation("A-comp", n);
    Operation opAtrib= p.createOperation("A-atrib", n);


    //zona de citire
    printf("n="); scanf("%d", &n);
    pi = fopen("input.txt", "r");
    po = fopen("output.txt", "w");

    //Verificam daca s-au putut deschide fisierele
    if(pi == NULL)
        printf("Nu s-a putut deschide fisierul de intrare\n");
    else
        printf("status: input.txt ready to use\n");

    if(po == NULL)
        printf("Nu s-a putut deschide fisierul de iesire\n");
    else
        printf("status: output.txt ready to use\n");

    //Demaram procedura de citire a numerelor din input.txt
    for (i = 0; i < n; i++)
    {
        fscanf(pi, "%d", &x);
        v[i] = x;
    }

    //list_v
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    //salvez vectorul in ordine inversa in output.txt
    for(int i = n-1; i > -1; i--)
        fprintf(po, "%d ", v[i]);

    return 0;
}
