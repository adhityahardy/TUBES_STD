#include "relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_namakereta P, address_stasiun C) {
    address_relasi Q = new elmlist_relasi;
    stasiun(Q) = C;
    namakereta(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<info(namakereta(P))<<"->"<<info(stasiun(P))<<endl;
        P = next(P);
    }
}


address_relasi findElm(List_relasi L, address_namakereta P, address_stasiun C) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(namakereta(Q)==P && stasiun(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}
