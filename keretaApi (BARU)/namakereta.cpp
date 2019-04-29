#include "namakereta.h"

void insertParent(List_parent &L){
    int ID;
    string namaKereta;
    cout<<"ID Kereta: ";
    cin>>ID;
    cout<<"Nama Kereta: ";
    cin>>namaKereta;

    address_parent P = alokasiParent(ID,namaKereta);
    if(SearchIdParent(L,ID) == NULL){
        if(firstParent(L) == NULL || ID_Parent(P) < ID_Parent(firstParent(L))){
            insertFirstParent(L,P);
        } else if(ID_Parent(P) > ID_Parent(lastParent(L))){
            insertLastParent(L,P);
        } else {
            address_parent Q = firstParent(L);
            while(ID_Parent(nextParent(Q)) < ID_Parent(P)){
                Q = nextParent(Q);
            }
            insertAfterParent(L,Q,P);
        }
    } else {
        dealokasiParent(P);
    }
}

void printParent(List_parent L){
    if(firstParent(L) != NULL){
        address_parent P = firstParent(L);
        while(P != NULL){
            cout<<nama_Parent(P)<<" - ";
            P = nextParent(P);
        }
    } else {
       cout<<"Tidak ada data "<<endl;
    }
}

void insertChild(List_child &L){
    int ID;
    string namaStasiun;
    cout<<"ID Stasiun: ";
    cin>>ID;
    cout<<"Nama Stasiun: ";
    cin>>namaStasiun;

    address_child C = alokasiChild(ID,namaStasiun);
    if(SearchIdChild(L,ID) == NULL)
    {
        if(firstChild(L) == NULL || ID_Child(C) < ID_Child(firstChild(L))){
            insertFirstChild(L,C);
        } else if(ID_Child(C) > ID_Child(lastChild(L))){
            insertLastChild(L,C);
        }else
        {
            address_child Q = firstChild(L);
            while(ID_Child(nextChild(Q)) < ID_Child(C)){
                Q = nextChild(Q);
            }
            insertAfterChild(L,Q,C);
        }
    } else {
        dealokasiChild(C);
    }
}

void printChild(List_child L){
    if(firstChild(L) != NULL){
        address_child C = firstChild(L);
        while(C != NULL){
            cout<<nama_Child(C)<<" - ";
            C = nextChild(C);
        }
    } else {
       cout<<"Tidak ada data "<<endl;
    }
}
void connect(List_parent &P, List_child C, int IDP, int IDC){
    address_parent Prnt = SearchIdParent(P,IDP);
    address_child Chld = SearchIdChild(C,IDC);
    if(Prnt != NULL && Chld != NULL)
    {
        address_relasi R = alokasiRelasi(Chld);
        insertRelasi(childList(Prnt),R);
    }
}

bool checkConnection(List_parent P, List_child C,int IDP, int IDC){
    address_parent Prnt = SearchIdParent(P,IDP);
    address_child Chld = SearchIdChild(C,IDC);
    if(Prnt != NULL && Chld != NULL){
        address_relasi R = firstRelasi(childList(Prnt));
        while(R != NULL){
            if(Chld == child(R)){
                return true;
            }
            R = nextRelasi(R);
        }
    }
    return false;
}

void disconnect (List_parent &P, List_child C, int IDP, int IDC){
}
void printAll (List_parent P, List_child C){
}
void printChildOfParent (List_parent P, List_child C, int IDP){
}
void deleteChild (List_parent &P, List_child &C){
}
void deleteParent (List_parent &P){
}
