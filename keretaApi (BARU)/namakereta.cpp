#include "namakereta.h"

void insertParent(List_parent &L)
{
    int ID;
    string nama_kereta;
    cout<<"ID: ";
    cin>>ID;
    cout<<"Nama Kereta: ";
    cin>>nama_kereta;

    address_parent P = alokasiParent(ID,nama_kereta);
    if(SearchIdParent(L,ID) == NULL){
        if(firstParent(L) == NULL || ID_Parent(P) < ID_Parent(firstParent(L))){
            insertFirstParent(L,P);
        } else if (ID_Parent(P) > ID_Parent(lastParent(L))){
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
void cobacoba(List_parent L){
    cout<<"mem";
}
