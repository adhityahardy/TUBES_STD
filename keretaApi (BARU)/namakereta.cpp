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
       cout<<"Tidak Ada Data"<<endl;
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
    if(SearchIdChild(L,ID) == NULL){
        if(firstChild(L) == NULL || ID_Child(C) < ID_Child(firstChild(L))){
            insertFirstChild(L,C);
        } else if(ID_Child(C) > ID_Child(lastChild(L))){
            insertLastChild(L,C);
        } else {
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
       cout<<"Tidak Ada Data"<<endl;
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
    address_parent Prnt = SearchIdParent(P,IDP);
    address_child Chld = SearchIdChild(C,IDC);
    if(Prnt != NULL && Chld != NULL){
        address_relasi R = firstRelasi(childList(Prnt));
        if(child(R) == Chld){
            deleteFirstRelasi(childList(Prnt), R);
            dealokasiRelasi(R);
        } else {
            address_relasi Q = R;
            while(Q != NULL && Chld == child(nextRelasi(Q))){
                Q = nextRelasi(Q);
            }
            deleteAfterRelasi(childList(Prnt),Q,R);
            dealokasiRelasi(R);
        }
    }
}

void printAll (List_parent P, List_child C){
    address_parent Q = firstParent(P);
    address_relasi R;
    while(Q != NULL){
        cout<<nama_Parent(Q)<<" - ";
        R = firstRelasi(childList(Q));
        if(R != NULL){
            while(R != NULL){
                cout<<nama_Child(child(R))<<endl;
                R = nextRelasi(R);
            }
        } else {
            cout<<"Tidak ada Data";
        }
        Q = nextParent(Q);
    }
    cout<<endl;
}

void printChildOfParent (List_parent P, List_child C, int IDP){
address_parent Prnt = SearchIdParent(P,IDP);
    if (Prnt != NULL )
    {
        cout<< "Kereta dengan nama "<< nama_Parent(Prnt)<< " akan berangkat menuju : " <<endl;
        address_relasi R = firstRelasi(childList(Prnt));
        if (R != NULL){
            while (R!=NULL){
            cout<< nama_Child(child(R)) << ", ";
            R = nextRelasi(R);
            }
        } else {
            cout<< " Kereta belum ada tujuan";
        }
    } else {
            cout<< " Kereta tidak ditemukan ";
    }
}

void deleteParent (List_parent &P){
    int ID;
    cout << "Masukkan ID Kereta yang ingin dihapus : ";
    cin >> ID;
    address_parent Prnt = SearchIdParent(P,ID);
    if (Prnt != NULL){
        address_relasi temp, relasi = firstRelasi(childList(Prnt));
        while (relasi != NULL){
            temp = relasi;
            relasi = nextRelasi(relasi);
            deleteFirstRelasi(childList(Prnt),temp);
            dealokasiRelasi(temp);
        }
        if (Prnt == firstParent(P)){
            deleteFirstParent(P,Prnt);
        } else if (Prnt == lastParent(P)){
            deleteLastParent(P,Prnt);
        } else {
            address_parent prec = prevParent(Prnt);
            deleteAfterParent(P, prec, Prnt);
        }
        dealokasiParent(Prnt);
        cout << "Kereta berhasil dihapus "<<endl;
    } else {
        cout << "ID Kereta tidak ditemukan "<<endl;
    }
}

void deleteChild(List_parent &P, List_child &C){
    int ID;
    cout << "Masukkan ID Stasiun yang ingin dihapus : ";
    cin >> ID;
    address_child prec, Chld = SearchIdChild(C, ID);
    if (Chld != NULL){
        address_parent Prnt = firstParent(P);
        while (Prnt != NULL){
            address_relasi temp, relasi = firstRelasi(childList(Prnt));
            while (relasi != NULL){
                if(child(relasi) == Chld){
                    relasi = nextRelasi(relasi);
                    deleteFirstRelasi(childList(Prnt),temp);
                    dealokasiRelasi(temp);
                } else if (nextRelasi(relasi) != NULL && child(nextRelasi(relasi)) == Chld){
                    deleteAfterRelasi(childList(Prnt),relasi,temp);
                    dealokasiRelasi(temp);
                } else {
                    relasi = nextRelasi(relasi);
                }
                Prnt = nextParent(Prnt);
            }
        }
            if (Chld == firstChild(C)){
                deleteFirstChild(C,Chld);
            } else if (Chld == lastChild(C)){
                deleteLastChild(C,Chld);
            } else {
                prec = prevChild(Chld);
                deleteAfterChild(C, prec, Chld);
            }
        dealokasiChild(Chld);
        cout << "Stasiun berhasil dihapus "<<endl;
    } else {
            cout << "Stasiun tidak ditemukan";
    }
}
