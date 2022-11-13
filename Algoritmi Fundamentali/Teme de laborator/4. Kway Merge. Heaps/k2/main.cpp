#include <stdio.h>
#include <stdlib.h>
#include "Profiler.h"
using namespace std;
Profiler pr("kiwi_lists");

typedef struct Node{
    int key;
    struct Node *next;
}NodeT;
typedef struct List{
    NodeT *head;
    NodeT *tail;
    int size;
}ListT;
//construim o structura speciala (ADT) de nod de Heap, care va tine minte o pereche valoare-indexoflist
typedef struct{
    int info;
    int originList;
}Heapisor;
void createEmpty(List *lista)
{
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}
void printList(ListT lista)
{
    NodeT *p = lista.head;
    while(p != NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    if(lista.size==0)
        printf("Canci! Lista e goala ");
    printf("; Size of the current list: %d\n", lista.size);
}
void insertLast(List *lista, int keyToBeInserted)
{
    NodeT *p = (NodeT *) malloc(sizeof(NodeT));
    p->key = keyToBeInserted;
    p->next = NULL;
    if(lista->head == NULL)
    {
        /*empty list*/
        lista->head = p;
        lista->tail = p;
    }
    else
    {
        lista->tail->next = p;
        lista->tail = p;
    }
    lista->size = lista->size + 1;//crestem marimea listei
}
void deleteFirst(ListT *lista){
    if(lista->head != NULL) //lista nu e deja goala
    {
        NodeT *newReference = lista->head;
        lista->head = lista->head->next;
        free(newReference);
        lista->size = lista->size - 1;
    }
}
void golireList(ListT *lista){
    while(lista->head != NULL) //acoperim si cazul in care lista e deja goala, ca efectiv nu intra in while
    {
        deleteFirst(lista);
    }
}
void copyList(ListT src, ListT *dest){
    NodeT *p = src.head;
    while(p != NULL){
        insertLast(dest, p->key);
        p = p->next;
    }
}
void fillRandomList(ListT *lista, int dimens)
{
    createEmpty(lista);
    int a[dimens];
    FillRandomArray(a, dimens, 0, 10, false, ASCENDING);
    for(int i = 0; i < dimens; i++){
        insertLast(lista, a[i]);
    }
}
void fillArrayOfLists(ListT arrayDeListe[], int k_liste){
    int sirDeDimensiuni[k_liste];
    FillRandomArray(sirDeDimensiuni, k_liste, 0, 6, false, UNSORTED);
    ListT lista;
    createEmpty(&lista);

    for(int i = 0; i < k_liste; i++){
        fillRandomList(&lista, sirDeDimensiuni[i]);
        createEmpty(&arrayDeListe[i]);
        copyList(lista, &arrayDeListe[i]);
        golireList(&lista);
    }
}
int left(int i)
{
    return 2 * i + 1;
}
int right(int i)
{
    return 2 * i + 2;
}
int indexOfMin(const Heapisor H[], int a, int b, int c, int n)
{
    //Operation Atrib = p.createOperation("BottomUpAtrib", n);
    //Operation Comp = p.createOperation("BottomUpComp", n);
    //Atrib.count();
    int minimum = H[a].info, minIndex = a;
    //Comp.count(2);
    if (H[b].info < minimum && H[b].info <= H[c].info) //what if un parinte ar avea doi copii cu informatie egala? e.g. 2,3,3
    {
        minIndex = b;
    }
    else
    {
        //Comp.count(2);
        if (H[c].info < minimum && H[c].info < H[b].info)
        {
            minIndex = c;
        }
    }
    return minIndex;
}
void minHeapify(Heapisor H[], int n, int nodStart)
{
    //Operation Atrib = p.createOperation("BottomUpAtrib", n);
    //Operation Comp = p.createOperation("BottomUpComp", n);
    int dreapta;
    if (right(nodStart) > n - 1)
        dreapta = left(nodStart);
    else
        dreapta = right(nodStart);
    int smallest = indexOfMin(H, nodStart, left(nodStart), dreapta, n);
    if (smallest != nodStart)
    {
        //Atrib.count();
        swap(H[nodStart], H[smallest]);
        if (smallest <= n / 2 - 1) //pozitia lui n/2-1 este ultimul nod intern care sigur este parinte
            minHeapify(H, n, smallest);
    }
}
void BUILD_HEAP_bottomUp(Heapisor H[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(H, n, i);
}
void listHeap(int H[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", H[i]);
    printf("\n");
}
void listHeapisor(Heapisor T[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", T[i].info);
    printf("\n");
}
void HEAPSORT(Heapisor H[], int n)
{
    BUILD_HEAP_bottomUp(H, n); //verificat, il construieste bine
    Heapisor *inOrder = (Heapisor *)malloc(n*sizeof(Heapisor));
    int cnt = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        inOrder[cnt] = H[0];
        cnt++;
        swap(H[i], H[0]); //se schimba complet nodurile, asta implicand si valoarea, si originea listelor.
        n--;
        if (n > 1)
            minHeapify(H, n, 0);//unde 0 - nodul de pornire in heap
    }
    inOrder[cnt] = H[0]; //ultima iteratie nu e prinsa in for. Adaugam manual elementul practic maxim ramas in heap
    //deci pe ultima pozitie din inOrder ar trebui sa vina indexul de lista al elementului ramas, deci 0
    //copiem inapoi in heap[] ce am obtinut in inOrder, si actualizam originList pe ultima pozitie (see last comment)
    for(int i = 0; i <= cnt; i++)
        H[i] = inOrder[i];
}
void overwriteHeap(ListT arrayDeListe[], int k_liste, Heapisor heap[], int *sizeofHeap) {
    //deci o sa am doua atribute pentru structura mea noua de Heap`:
    //>heap, in care pun efectiv valorile din liste si pe care fac heapify
    //>originList, in care asociez valoarea cu lista de provenienta. Cum modific ceva in heap, JAP si in originList
    //Acum, parcurgem array-ul de liste si copiem in heap primul element de la fiecare lista,
    //iar in originList punem lista de provenienta
    for (int i = 0; i < k_liste; i++){//parcurgem fiecare lista
        if(arrayDeListe[i].size > 0)//daca lista respectiva nu este nula
        {
            heap[*sizeofHeap].info = arrayDeListe[i].head->key;
            heap[*sizeofHeap].originList = i;
            *sizeofHeap = *sizeofHeap + 1;
        }
    }
}
bool isArrayOfListsEmpty(ListT arrayDeListe[], int k_liste){
    //bool var = true; //pp ca ar fi goala
    //daca gasim macar o lista nenula, var trece in false
    for(int i = 0; i < k_liste; i++)
    {
        if(arrayDeListe[i].size>0)
            return false;
    }
    return true;
}
void KIWIMERGE(ListT arrayDeListe[], int k_liste){
    ListT finalList;
    int sizeofHeap;
    Heapisor heap[k_liste];
    createEmpty(&finalList);
    while(isArrayOfListsEmpty(arrayDeListe, k_liste)==false){
        sizeofHeap = 0; // de fiecare data
        overwriteHeap(arrayDeListe, k_liste, heap, &sizeofHeap);
        HEAPSORT(heap, sizeofHeap);
        ///printf("Heap: ");listHeapisor(heap, sizeofHeap);
        //extragem manual minimul (in sensul ca copiem informatia din root si o punem in lista finala)
        insertLast(&finalList, heap[0].info);
        //ne ducem in lista cu pricina si stergem fizic primul element
        deleteFirst(&arrayDeListe[heap[0].originList]);
        ///for(int i = 0; i < k_liste; i++){
           /// printList(arrayDeListe[i]);
        ///}
        ///printf("Temp final list: "); printList(finalList);
        ///printf("[...]next step:\n");
    }//cand array-ul de liste va fi gol pe fiecare pozitie, e clar ca voi fi gata

    printf("Lista finala este:\n\\");
    printList(finalList);
}
int main() {
    ListT lista;
    createEmpty(&lista);

    //ne citim k - cate k liste vrem
    int k;
    printf("Cate liste vrem sa avem?\n>");
    scanf("%d", &k);

    //cream tabloul de liste
    ListT arrayDeListe[k];

    //umplem cu valori random in range [1-100] tabloul
    fillArrayOfLists(arrayDeListe, k);

    //Vizualizam tabloul de liste format
    for(int i = 0; i < k; i++){
        printList(arrayDeListe[i]);
    }
    printf("*******************\n");

    KIWIMERGE(arrayDeListe, k);
    return 0;
}
