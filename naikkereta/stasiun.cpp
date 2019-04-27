#include "stasiun.h"

void createList(List_stasiun &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_stasiun alokasi(infotype_stasiun x) {
    address_stasiun P = new elmlist_stasiun;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_stasiun &L, address_stasiun P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo(List_stasiun L) {
    address_stasiun P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(P)<<endl;
        P = next(P);
    }
}


address_stasiun findElm(List_stasiun L, infotype_stasiun x) {
    address_stasiun P = first(L);
    while(P != NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_stasiun &Prec, address_stasiun P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}
