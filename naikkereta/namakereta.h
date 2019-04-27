#ifndef NAMAKERETA_H_INCLUDED
#define NAMAKERETA_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef string infotype_namakereta;
typedef struct elmlist_namakereta *address_namakereta;

struct elmlist_namakereta {
    infotype_namakereta info;
    address_namakereta next;
};

struct List_namakereta {
    address_namakereta first;
};

void createList(List_namakereta &L);
address_namakereta alokasi(infotype_namakereta X);
void insertFirst(List_namakereta &L, address_namakereta P);
void printInfo(List_namakereta L);
address_namakereta findElm(List_namakereta L, infotype_namakereta X);

#endif // NAMAKERETA_H_INCLUDED
