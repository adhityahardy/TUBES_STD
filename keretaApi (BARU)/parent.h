#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define firstParent(L) L.firstParent
#define lastParent(L) L.lastParent
#define ID_Parent(P) P->ID_Parent
#define nextParent(P) P->nextParent
#define prevParent(P) P->prevParent
#define nama_Parent(P) P->nama_Parent

using namespace std;

typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    int ID_Parent;
    string nama_Parent;
    address_parent nextParent;
    address_parent prevParent;
};

struct List_parent {
    address_parent firstParent;
    address_parent lastParent;
};

void createListParent(List_parent &L);
void insertFirstParent(List_parent &L, address_parent P);
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_parent &L, address_parent P);
void deleteFirstParent(List_parent &L, address_parent &P);
void deleteLastParent(List_parent &L, address_parent &P);
void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P);
void dealokasiParent(address_parent &P);;
address_parent SearchIdParent(List_parent L,int ID_Parent);
address_parent alokasiParent(int ID_Parent, string nama_Parent);

#endif // PARENT_H_INCLUDED
