#include "child.h"

void createListChild(List_child &L) {
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    firstChild(L) = NULL;
    lastChild(L) = NULL;
}

address_child alokasiChild(int ID_Child, string nama_Child){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    address_child P = new elmlist_child;
    ID_Child(P) = ID_Child;
    nama_Child(P) = nama_Child;
    nextChild(P) = NULL;
    prevChild(P) = NULL;
    return P;
}

void dealokasiChild(address_child &P){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    delete P;
}

void insertFirstChild(List_child &L, address_child P){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
     if(firstChild(L) == NULL && lastChild(L) == NULL){
        firstChild(L) = P;
        lastChild(L) = P;
    } else {
        nextChild(P) = firstChild(L);
        prevChild(firstChild(L)) = P;
        firstChild(L) = P;
    }
}
void insertLastChild(List_child &L, address_child P){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    if(firstChild(L) == NULL && lastChild(L) == NULL){
        insertFirstChild(L,P);
    } else {
        prevChild(P) = lastChild(L);
        nextChild(lastChild(L)) = P;
        lastChild(L) = P;
    }
}

void insertAfterChild(List_child &L, address_child Prec, address_child P){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    prevChild(nextChild(Prec)) = P;
    nextChild(P) = nextChild(Prec);
    prevChild(P) = Prec;
    nextChild(Prec) = P;
}

void deleteFirstChild(List_child &L, address_child &P){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    if(firstChild(L) != NULL && lastChild(L) != NULL){
      P = firstChild(L);
        if(firstChild(L) != lastChild(L)){
            firstChild(L) = nextChild(firstChild(L));
            prevChild(firstChild(L)) = NULL;
            nextChild(P) = NULL;
      } else if(firstChild(L) == lastChild(L)){
            dealokasiChild(P);
      }
    }
}

void deleteLastChild(List_child &L, address_child &P){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    if(firstChild(L) != NULL && lastChild(L) != NULL){
        P = lastChild(L);
            if(firstChild(L) != lastChild(L)){
                lastChild(L) = prevChild(P);
                nextChild(prevChild(P)) = NULL;
                prevChild(P) = NULL;
            } else {
                dealokasiChild(P);
            }
        }
}

void deleteAfterChild(List_child &L, address_child Prec, address_child &P){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    P = nextChild(Prec);
    nextChild(Prec) = nextChild(P);
    prevChild(nextChild(P)) = Prec;
    prevChild(P) = NULL;
    nextChild(P) = NULL;
}

address_child SearchIdChild(List_child L, int IDC){
    /*
    Nama : Komang Triolascarya
    NIM  : 1301180055
    */
    address_child P = firstChild(L);
    while(P != NULL && ID_Child(P) != IDC){
        P = nextChild(P);
    }
    return P;
}
