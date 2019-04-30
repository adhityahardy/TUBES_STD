#include "relasi.h"

void createListRelasi(List_relasi &L){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    firstRelasi(L) = NULL;
}
address_relasi alokasiRelasi(address_child C){
    /*
    Nama : Adhitya Aldira Hardy
    NIM  : 1301184036
    */
    address_relasi R = new elmlist_relasi;
    child(R) = C;
    nextRelasi(R) = NULL;
    return R;
}

void dealokasiRelasi(address_relasi R){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    delete R;
}

void insertRelasi(List_relasi &L, address_relasi R){
    /*
    Nama : Adhitya Aldira Hardy
    NIM  : 1301184036
    */
        if(firstRelasi(L) != NULL){
            nextRelasi(R) = firstRelasi(L);
            firstRelasi(L) = R;
        } else {
            firstRelasi(L) = R;
        }
}

void deleteFirstRelasi(List_relasi &L, address_relasi &R){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    R = firstRelasi(L);
    firstRelasi(L) = nextRelasi(R);
    nextRelasi(R) = NULL;
}

void deleteAfterRelasi(List_relasi &L, address_relasi Prec, address_relasi &R){
    /*
    Nama : Adhitya Aldira Hardy
    NIM  : 1301184036
    */
    if (Prec != NULL && nextRelasi(Prec) != NULL){
        R = nextRelasi(Prec);
        nextRelasi(Prec) = nextRelasi(R);
        nextRelasi(R) = NULL;
    }
}
