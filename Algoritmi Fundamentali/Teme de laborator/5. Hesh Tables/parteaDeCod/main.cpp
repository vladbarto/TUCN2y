#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[30];
}Entry;
void printHash(Entry [], int, int);
float getFactorUmplere(int n, int m)
{
    //m - size of hesh table (more like capacity)
    //n - how many elements are there in the table
    return n/m;
}
int h1(int key, int m){
    return key%m;
}
int h(int key, int nrOfTries, int m){
    //alegem c1 si c2 a.i. sa fie prime intre ele
    int c1=8;
    int c2=9;
    return (h1(key, m) + c1*nrOfTries + c2*nrOfTries*nrOfTries)%m;
    //Avand structura Entry, noi vom trimite functiei doar element.id, care e un int;
    //astfel, nu mai trimitem si valoarea;
}
void hashInsert(Entry *tabela, int *size, int capacity, Entry element){
    int i = 0;
    //while(T[h(element.key, i, capacity)].)
    tabela.T[h(element.id, i, capacity)] = element;
    *size++;
    //size = n; capacity = m;
    printHash(T, capacity, *size);
}
void printHash(Entry T[], int capacity, int size)
{
    for(int i = 0; i < capacity; i++)
        printf("[%d, %s] ", T[i].id, T[i].name);
    printf("; Size of Hash Table is %d\n", size);
}
void EntryConstructor(Entry *element, int id, char name[])
{
    element->id = id;
    strcpy(element->name, name);
}
void keepReading()
{
    int id;
    char name[30];
    char temp[30];
    EntryArray T = (EntryArray*)malloc(10*sizeof(Entry));
    Entry element;
    bool stop;
    do
    {
        stop = false;
        printf("id >");
        scanf("%s", temp);
        id = atoi(temp);
        if(id == 0)
            stop = true;
        else
        {
            printf("name >");
            scanf("%s", name);
            element.id = id;
            strcpy(element.name, name);
            hashInsert(T, &T.size, capacity, element);//TODO: VEZI AICI
        }
    }while(stop == true);
    printf("Citirea s-a incheiat");
}
void demo(){
    int m = 10;
    int T[m];
    int size = 0; //=n, cate elemente avem in tabela
    int capacity = m;//cate elemente putem baga

}
int main() {

    return 0;
}
