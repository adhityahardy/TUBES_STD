#include "relasi.h"

void createListRelasi(List_relasi &L){
    firstRelasi(L) = NULL;
}
address_relasi alokasiRelasi(address_child C){
    address_relasi R = new elmlist_relasi;
    child(R) = C;
    nextRelasi(R) = NULL;
    return R;
}

void dealokasiRelasi(address_relasi R){
    delete R;
}

void insertRelasi(List_relasi &L, address_relasi R){
        if(firstRelasi(L) != NULL){
            nextRelasi(R) = firstRelasi(L);
            firstRelasi(L) = R;
        } else {
            firstRelasi(L) = R;
        }
}

void deleteFirstRelasi(List_relasi &L, address_relasi &R){
    R = firstRelasi(L);
    firstRelasi(L) = nextRelasi(R);
    nextRelasi(R) = NULL;
}

void deleteAfterRelasi(List_relasi &L, address_relasi Prec, address_relasi &R){
    if (Prec != NULL && nextRelasi(Prec) != NULL){
        R = nextRelasi(Prec);
        nextRelasi(Prec) = nextRelasi(R);
        nextRelasi(R) = NULL;
    }
}
