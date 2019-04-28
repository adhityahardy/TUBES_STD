#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "relasi.h"
#include "child.h"
#include "parent.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

#define nextRelasi(R) R->nextRelasi
#define firstRelasi(L) L.firstRelasi
#define child(R) R->child
#define parent(R) R->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi nextRelasi;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi firstRelasi;
};

void createListRelasi(List_relasi &L);
void insertRelasi(List_relasi &L, address_relasi R);
void deleteFirstRelasi(List_relasi &L, address_relasi &R);
void deleteLastRelasi(List_relasi &L, address_relasi &R);
void deleteAfterRelasi(address_relasi Prec, address_relasi &R);
address_relasi alokasiRelasi(address_parent P , address_child C);

#endif // RELASI_H_INCLUDED
