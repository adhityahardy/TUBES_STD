#include "parent.h"

void createListParent(List_parent &L){
    firstParent(L) = NULL;
    lastParent(L) = NULL;
}

address_parent alokasiParent(int ID_Parent, string nama_Parent){
     address_parent P = new elmlist_parent;
     ID_Parent(P) = ID_Parent;
     nama_Parent(P) = nama_Parent;
     nextParent(P) = NULL;
     prevParent(P) = NULL;
     return P;
}

void dealokasiParent(address_parent &P){
    delete P;
}

void insertFirstParent(List_parent &L, address_parent P){
    if(firstParent(L) == NULL && lastParent(L) == NULL){
        firstParent(L) = P;
        lastParent(L) = P;
    } else {
        nextParent(P) = firstParent(L);
        prevParent(firstParent(L)) = P;
        firstParent(L) = P;
    }
}

void insertLastParent(List_parent &L, address_parent P){
    if(firstParent(L) == NULL && lastParent(L) == NULL){
        insertFirstParent(L,P);
    } else {
        prevParent(P) = lastParent(L);
        nextParent(lastParent(L)) = P;
        lastParent(L) = P;
    }
}
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P){
    if(firstParent(L) != NULL){
        nextParent(P) = nextParent(Prec);
        prevParent(P) = Prec;
        nextParent(Prec) = P;
        prevParent(nextParent(P)) = P;
    }
}
void deleteFirstParent(List_parent &L,address_parent &P){
    if(firstParent(L) != NULL && lastParent(L) != NULL){
        P = firstParent(L);
        if(firstParent(L) != lastParent(L)){
            firstParent(L) = nextParent(firstParent(L));
            prevParent(firstParent(L)) = NULL;
            nextParent(P) = NULL;
        } else if(firstParent(L) == lastParent(L)){
          dealokasiParent(P);
        }
    }
}
void deleteLastParent(List_parent &L, address_parent &P){
    if(firstParent(L) != NULL && lastParent(L) != NULL){
        P = lastParent(L);
        if(firstParent(L) != lastParent(L)){
            lastParent(L) = prevParent(P);
            nextParent(prevParent(P)) = NULL;
            prevParent(P) = NULL;
        } else {
            dealokasiParent(P);
        }
    }
}

void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P){
    P = nextParent(Prec);
    nextParent(Prec) = nextParent(P);
    prevParent(nextParent(P)) = Prec;
    prevParent(P) = NULL;
    nextParent(P) = NULL;
}
address_parent SearchIdParent(List_parent L, int IDP){
    address_parent P = firstParent(L);
    while(P != NULL && ID_Parent(P) != IDP){
        P = nextParent(P);
    }
    return P;
}
