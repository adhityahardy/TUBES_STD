#include <iostream>
#include "namakereta.h"
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

List_parent Kereta;
List_child Stasiun;

List_relasi Relasi;
address_parent P;
address_child C;
address_relasi R;
int IDKereta;
int IDStasiun;

int main(){
    createListParent(Kereta);
    createListChild(Stasiun);

    insertParent(Kereta);
    insertParent(Kereta);
    insertParent(Kereta);

    insertChild(Stasiun);
    insertChild(Stasiun);
    insertChild(Stasiun);

    cout<<endl;
    cout<<"Hasilnya"<<endl;

    printParent(Kereta);cout<<endl;
    printChild(Stasiun);cout<<endl;
    cout<<endl;

    connect(Kereta,Stasiun,1,2);
    connect(Kereta,Stasiun,1,7);
    connect(Kereta,Stasiun,1,9);
    connect(Kereta,Stasiun,4,7);
    connect(Kereta,Stasiun,4,9);
    connect(Kereta,Stasiun,5,9);
    cout<<checkConnection(Kereta,Stasiun,1,2)<<endl;
    cout<<checkConnection(Kereta,Stasiun,1,7)<<endl;
    cout<<checkConnection(Kereta,Stasiun,1,9)<<endl;
    cout<<checkConnection(Kereta,Stasiun,4,7)<<endl;
    cout<<checkConnection(Kereta,Stasiun,4,9)<<endl;
    cout<<checkConnection(Kereta,Stasiun,5,9)<<endl;

    cout<<endl;

    printChildOfParent(Kereta,Stasiun,1);cout<<endl;
    printChildOfParent(Kereta,Stasiun,4);cout<<endl;
    printChildOfParent(Kereta,Stasiun,5);cout<<endl;

    cout<<endl;

    disconnect(Kereta,Stasiun,4,9);

    deleteChild(Kereta,Stasiun);

    printChild(Stasiun);cout<<endl;
    cout<<endl;

    deleteParent(Kereta);

    printParent(Kereta);cout<<endl;
    cout<<endl;

    //printAll(Kereta,Stasiun);
}
