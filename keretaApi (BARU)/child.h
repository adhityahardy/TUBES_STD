#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define nama_Child(A) A->nama_Child
#define ID_Child(A) A->ID_Child
#define nextChild(P) P->nextChild
#define prevChild(P) P->prevChild
#define firstChild(L) L.firstChild
#define lastChild(L) L.lastChild

using namespace std;

typedef struct elmlist_child *address_child;

struct elmlist_child{
    string nama_Child;
    int ID_Child;
    address_child nextChild;
    address_child prevChild;
};

struct List_child{
    address_child firstChild;
    address_child lastChild;
};

void createListChild(List_child &L);
void insertFirstChild(List_child &L, address_child P);
void insertLastChild(List_child &L, address_child P);
void insertAfterChild(address_child Prec, address_child P);
void deleteFirstChild(List_child &L, address_child &P);
void deleteLastChild(List_child &L, address_child &P);
void deleteAfterChild(List_child &L, address_child Prec, address_child &P);
void dealokasi(address_child &P);
address_child alokasiChild(int ID_Child, string namaChild);
address_child SearchIdChild(List_child L, int ID_Child);

#endif // CHILD_H_INCLUDED
