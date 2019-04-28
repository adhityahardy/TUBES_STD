#include <iostream>

using namespace std;
#include "namakereta.h"
#include "relasi.h"
#include "stasiun.h"

int main()
{
    List_namakereta LN;
    List_relasi LR;
    List_stasiun LS;
    address_namakereta P;
    address_stasiun S;
    address_relasi R;

    createList(LN);
    createList(LS);
    createList(LR);

    P = alokasi("Argo Parahyangan");
    insertFirst(LN, P);
    P = alokasi("Argo Wilis");
    insertFirst(LN, P);

    cout << "List Nama Kereta(parent)" << endl;
    printInfo(LN);

    S = alokasi2("Bandung");
    insertFirst(LS, S);
    S = alokasi2("Surabaya");
    insertFirst(LS, S);

    cout << endl;

    cout << "List Stasiun(child)" << endl;
    printInfo(LS);

    P = findElm(LN, "Argo Parahyangan");
    S = findElm(LS, "Bandung");
    R = alokasi(P,S);
    insertFirst(LR,R);

    P = findElm(LN, "Argo Wilis");
    S = findElm(LS, "Surabaya");
    R = alokasi(P,S);
    insertFirst(LR,R);

    cout << endl;

    cout << "Setelah direlasikan" << endl;
    printInfo(LR);

    return 0;
}
