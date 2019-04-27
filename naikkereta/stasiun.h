#ifndef STASIUN_H_INCLUDED
#define STASIUN_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef string infotype_stasiun;
typedef struct elmlist_stasiun *address_stasiun;

struct elmlist_stasiun{
    infotype_stasiun info;
    address_stasiun next;
    address_stasiun prev;
};

struct List_stasiun{
    address_stasiun first;
    address_stasiun last;
};

#endif // STASIUN_H_INCLUDED
