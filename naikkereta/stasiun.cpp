#include "stasiun.h"

void createList(List_stasiun &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_stasiun alokasi2(infotype_stasiun S) {
    address_stasiun P = new elmlist_stasiun;
    info(P) = S;
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

void insertAfter(address_stasiun &Prec, address_stasiun P){
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void insertLast(List_stasiun &L, address_stasiun P){
    if (first(L) == NULL){
        insertFirst(L,P);
    } else {
        next(last(L)) = P;
        prev(P)       = last(L);
        last(L)       = P;
    }
}

void printInfo(List_stasiun L){
    address_stasiun P = first(L);
    while(P !=NULL) {
        cout<<info(P)<<endl;
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

void deleteFirst(List_stasiun &L, address_stasiun &P){
    P = first(L);
    if  (first(L)!= last(L));
    {
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}



void deleteAfter(List_stasiun &L, address_stasiun &Prec, address_stasiun P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}


void deleteLast(List_stasiun &L, address_stasiun &P){
    P = last(L);
    last(L) = prev(P);
    next(last(L)) = NULL;
    prev(P) = NULL;
}
