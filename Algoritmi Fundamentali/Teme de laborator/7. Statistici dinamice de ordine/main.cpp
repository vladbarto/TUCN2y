#include <stdio.h>
#include <stdlib.h>
typedef struct tipNod{
    int cheie;
    tipNod* left;
    tipNod* right;
    int nrNoduriSubtree;
}tipNod;
enum{STG, DRT};
tipNod* build(int stanga, int dreapta){
    if(stanga <= dreapta) {
        tipNod *nod = (tipNod *) malloc(sizeof(tipNod));
        int mediana = (stanga+dreapta)/2;
        nod->cheie = mediana;
        nod->left = build(stanga, mediana-1);
        nod->right = build(mediana+1, dreapta);
        nod->nrNoduriSubtree = 1;
        if(nod->left!=NULL)
            nod->nrNoduriSubtree += nod->left->nrNoduriSubtree;
        if(nod->right != NULL)
            nod->nrNoduriSubtree += nod->right->nrNoduriSubtree;
        return nod;
    }
    else return NULL;
}
void prettyPrint(tipNod *root){

     if(root != NULL){
        int static nivel = 0;
        for(int i = 0; i < nivel; i++){
            printf("--");
        }
        printf("%d(%d)\n", root->cheie, root->nrNoduriSubtree);
        nivel++;
        prettyPrint(root->left);
        prettyPrint(root->right);
        nivel--;
    }
}
int getNrNoduriSubtree(tipNod* root){
    if(root==NULL)
        return 0;
    else
        return root->nrNoduriSubtree;
}
tipNod* OS_Select(tipNod *root, int i){
    //rank = rank-ul nodului transmis root
    int rank = getNrNoduriSubtree(root->left) + 1;
    if(i == rank)
        return root;
    else
    {
        if(i < rank)
            return OS_Select(root->left, i);
        else
            return OS_Select(root->right, i - rank);
    }
}
tipNod* findPred(tipNod* deUndePornesc){
    //aceasta metoda returneaza parintele predecesorului nodului de sters
    deUndePornesc = deUndePornesc->left;
    while(deUndePornesc->right->right != NULL){
        deUndePornesc = deUndePornesc->right;
    }
    return deUndePornesc;
}
void OS_Delete(tipNod* root, int toBeDeleted){
    tipNod* p=root, *parent;
    int parte;//pe ce parte e copilul de sters? pe stanga sau pe dreapta?
    while(p != NULL){
        if(toBeDeleted == p->cheie)
            break;
        else
        {
            parent = p;
            if(toBeDeleted < p->cheie)
                p = p->left, parte=STG;
            else
                p = p->right, parte=DRT;
        }
    }
    //daca p [nodul de sters] e frunza
    if (p->left == NULL && p->right == NULL){
        free(p);
        if(parte==STG)
            parent->left = NULL;
        else if(parte==DRT)
                parent->right = NULL;
    }
    else
    {
        //daca p [nodul de sters] are un fiu
        if((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL)){
            if(p->left != NULL)
                (parte==STG)?parent->left = p->left : parent->right = p->left;
            else if (p->right != NULL)
                    (parte==STG)?parent->left = p->right : parent->right = p->right;
            free(p);
        }
        //daca p [nodul de sters] are doi fii
        if(p->left != NULL && p->right != NULL){
            //in pred se returneaza parintele nodului predecesor al nodului p [nodul de sters]
            tipNod *pred = findPred(p);
            p->cheie = pred->right->cheie;
            pred->right = NULL;
        }
    }
}
void inorder(tipNod* root){
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->cheie);
        inorder(root->right);
    }
}
void demo1(){
    int n = 11;
    tipNod *root = NULL;
    root = build(1, n);
    prettyPrint(root);
}
void demo2(){
    int n = 11;
    int i = 6;
    tipNod *root = build(1, n);
    printf("al %d-lea cel mai mic element este=%d\n", i, OS_Select(root, i)->cheie);
    //pentru verificare: inorder(root);
    //Selection (i-th selection) = find the node which is the i-th one in inorder traversal
}
void demo3(){
    int n = 11;
    tipNod *root = build(1, n);
    OS_Delete(root, 2);//frunza fara copii
    OS_Delete(root, 4);//nod cu un copil, pe dreapta
    OS_Delete(root, 9);//nod cu 2 copii
    prettyPrint(root);
}
int main() {
    demo1();
    demo2();
    demo3();
    return 0;
}
