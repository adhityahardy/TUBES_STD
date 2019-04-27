#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "relasi.h"
#include "stasiun.h"
#include "namakereta.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define stasiun(P) P->stasiun
#define namakereta(P) P->namakereta

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_stasiun stasiun;
    address_namakereta namakereta;
};

struct List_relasi{
    address_relasi first;
};


#endif // RELASI_H_INCLUDED
