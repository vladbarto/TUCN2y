#include <iostream>
using namespace std;
typedef struct Node{
    int key;
    struct Node *next;
}NodeT;
typedef struct List{
    NodeT *head;
    NodeT *tail;
    int size;
}ListT;
void createEmpty(List *lista)
{
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}
void printList(List lista)
{
    NodeT *p = lista.head;
    while(p != NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
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
    lista->size = lista->size + 1;
}
void generateKLists
void KWAYMERGE(int a[], int k)
{

}
int main() {
    ListT lista;

    createEmpty(&lista);
    insertLast(&lista, 2);
    insertLast(&lista, 3);
    insertLast(&lista, 1);
    printList(lista);

    insertLast(&lista, 7);
    insertLast(&lista, 10);
    printList(lista);

    return 0;
}
