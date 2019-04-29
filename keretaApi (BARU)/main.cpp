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

    printParent(Kereta);
    printChild(Stasiun);
    cout<<endl;

    connect(Kereta,Stasiun,1,2);
    connect(Kereta,Stasiun,4,7);
    connect(Kereta,Stasiun,5,9);
    cout<<checkConnection(Kereta,Stasiun,1,2);
    cout<<checkConnection(Kereta,Stasiun,4,7);
    cout<<checkConnection(Kereta,Stasiun,5,9);
}
