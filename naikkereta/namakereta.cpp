#include "namakereta.h"

void createList(List_namakereta &L){
    first(L) = NULL;
}

address_namakereta alokasi(infotype_namakereta X){
    address_namakereta P = new elmlist_namakereta;
    info(P) = X;
    next(P) = NULL;
    return P;
}

void insertFirst(List_namakereta &L, address_namakereta P){
     address_namakereta Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void printInfo(List_namakereta L){
      address_namakereta P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P)<<endl;
            P = next(P);
        } while((P)!=first(L));
    }
}

address_namakereta findElm(List_namakereta L, infotype_namakereta X){
      address_namakereta P = first(L);
    do {
        if(info(P) == X) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
