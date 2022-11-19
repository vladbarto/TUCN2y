#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;
int h;
int h2 = 1;
int h3 = 1;
typedef struct M_ary_pointer {
    int key;
    int nr_children;
    M_ary_pointer **children;//children tre sa fie ARRAY DE POINTERI catre noduri din astea
} M_ary_Tree_Node;
typedef struct tip3_pointer {
    int cheie;
    struct tip3_pointer *stg;
    struct tip3_pointer *frtdrt;//frate dreapta
} tip3;

void preetyPrint1(int pi[], int sought_parent, int n) {
    for (int i = 0; i < n; i++) {
        if (pi[i] == sought_parent) {
            h++;
            cout << setw(3 * h) << i + 1 << "\n";
            preetyPrint1(pi, i + 1, n);
            h--;
        }
    }
}

void preetyPrint2(M_ary_Tree_Node *root) {
    if (root != NULL) {
        //printf("Current node: %d\n", root->key);
        cout << setw(3 * h2) << root->key << endl;
        if (root->nr_children > 0) {
            h2++;
            for (int i = 0; i < root->nr_children; i++) {
                preetyPrint2(root->children[i]);
            }
            h2--;
        }
    }
}

void preetyPrint3(tip3 *radacina) {
    if (radacina != NULL) {
        cout << setw(3 * h3) << radacina->cheie << endl;
        h3++;
        if(radacina->stg != NULL)
            preetyPrint3(radacina->stg);
        h3--;
        if(radacina->frtdrt != NULL)
            preetyPrint3(radacina->frtdrt);
    }
}

void demo() {
    int pi[] = {2, 7, 5, 2, 7, 7, -1, 5, 2};
    int n = sizeof(pi) / sizeof(int);
    preetyPrint1(pi, -1, n);
}

M_ary_Tree_Node *create_obj(int key) {
    M_ary_Tree_Node *node = (M_ary_Tree_Node *) malloc(1 * sizeof(M_ary_Tree_Node));
    node->key = key;
    node->nr_children = 0;
    node->children = NULL;
    return node;
}

tip3 *create_nod_intern(int key) {
    tip3 *nod = (tip3 *) malloc(sizeof(tip3));
    nod->cheie = key;
    nod->stg = NULL;
    nod->frtdrt = NULL;
    return nod;
}

void foreach_create_obj(M_ary_Tree_Node *structura[], int n) {
    for (int i = 0; i < n; i++) {
        structura[i] = create_obj(i + 1);
    }
}

void Transformata1(M_ary_Tree_Node **root) {
    int pi[] = {2, 7, 5, 2, 7, 7, -1, 5, 2};
    //int pi[]={3,3,-1,7,7,1,3};
    int n = sizeof(pi) / sizeof(int);
    M_ary_Tree_Node *Mway[n];//array de pointeri catre noduri
    foreach_create_obj(Mway, n);
    int *numar = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        numar[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (pi[i] == -1)
            continue;
        numar[pi[i] - 1]++;
    }
    for (int i = 0; i < n; i++) {
        if (pi[i] == -1) {
            printf("pozitia radacinii in PI=%d\n", i);
            *root = Mway[i];//daca dam de -1, inseamna ca stim (am gasit) radacina
            continue;
        }
        if (Mway[pi[i] - 1]->children == NULL) {
            //aloc spatiul pentru array-ul de pointeri de copii
            Mway[pi[i] - 1]->children = (M_ary_Tree_Node **) malloc(numar[pi[i] - 1] * sizeof(M_ary_Tree_Node *));
            //aloc spatiu pentru fiecare pointer
            for (int j = 0; j < numar[pi[i] - 1]; j++) {
                Mway[pi[i] - 1]->children[j] = (M_ary_Tree_Node *) malloc(sizeof(M_ary_Tree_Node *));
            }
        }
        if (numar[pi[i] - 1] > 0) {
            //sunt la pozitia i. Pun pe pi[i]-1 copilul aferent
            Mway[pi[i] - 1]->children[Mway[pi[i] - 1]->nr_children] = Mway[i];
            Mway[pi[i] - 1]->nr_children = Mway[pi[i] - 1]->nr_children + 1;
        }
    }
    //Acuma ar fi frumos sa si eliberez Mway[]
    //for(int i = 0; i < n; i++)
    //free(Mway[i]);
    //free(Mway);
}

void Transformata2(M_ary_Tree_Node *root, tip3 *radacina) {
    if (root->nr_children > 0) {
        radacina->stg = create_nod_intern(root->children[0]->key);
        tip3 **copiiNoiArr = (tip3 **) malloc(root->nr_children * sizeof(tip3 *));
        tip3 *nodCurent = radacina->stg;
        copiiNoiArr[0] = nodCurent;
        for (int i = 1; i < root->nr_children; i++) {
            nodCurent->frtdrt = create_nod_intern(root->children[i]->key);
            nodCurent = nodCurent->frtdrt;
            copiiNoiArr[i] = nodCurent;
        }
        for (int i = 0; i < root->nr_children; i++) {
            Transformata2(root->children[i], copiiNoiArr[i]);
        }
        free(copiiNoiArr);
    }
}

int main() {
    //demo();
    M_ary_Tree_Node *root;
    tip3 *radacina;

    Transformata1(&root);
    //preetyPrint2(root);

    radacina = create_nod_intern(root->key);

    Transformata2(root, radacina);
    preetyPrint3(radacina);
    return 0;
}
