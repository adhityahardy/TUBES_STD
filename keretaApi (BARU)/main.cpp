#include <iostream>
#include "namakereta.h"
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

List_parent Kereta;
List_child Stasiun;
address_parent P;
address_child C;
address_relasi R;

int main(){
    createListParent(Kereta);
    createListChild(Stasiun);

    insertParent(Kereta);
    insertParent(Kereta);
    printParent(Kereta);
}
