#include <iostream>
#include "namakereta.h"
#include "parent.h"
#include "child.h"
#include "relasi.h"


using namespace std;
/*
Nama : Komang Triolascarya
NIM  : 1301180055

Nama : Adhitya Aldira Hardy
NIM  : 1301184036
*/

List_parent Kereta;
List_child Stasiun;
List_relasi Relasi;

address_parent P;
address_child C;
address_relasi R;
int IDKereta;
int IDStasiun;

void menu();
void displayMenu();
void runMenu (int menu);

int main(){
    List_child(Stasiun);
    List_parent(Kereta);
    List_relasi(Relasi);
    createListParent(Kereta);
    createListChild(Stasiun);
    createListRelasi(Relasi);
    menu();
    return 0;
}

void menu()
{
    int option;
    do {
        displayMenu();
        cin >> option;
        runMenu(option);
    } while (option!=0);
}

void displayMenu(){
    cout << " ================================================================" << endl;
    cout << "                  Selamat Datang di Stasiun Bandung              "     << endl;
    cout << " =============================MENU===============================" << endl;
    cout << " ||  1.  Masukkan Nama Kereta                                  ||" << endl;
    cout << " ||  2.  Lihat semua Kereta                                    ||" << endl;
    cout << " ||  3.  Masukkan Stasiun yang Dituju                          ||" << endl;
    cout << " ||  4.  Lihat Stasiun                                         ||" << endl;
    cout << " ||  5.  Rute yang ditempuh                                    ||" << endl;
    cout << " ||  6.  Lihat Rute                                            ||" << endl;
    cout << " ||  7.  Delete Kereta                                         ||" << endl;
    cout << " ||  8.  Delete Stasiun                                        ||" << endl;
    cout << " ||  9.  Lihat Semua Perjalanan                                ||" << endl;
    cout << " || 10.  Stasiun yang Paling Banyak Dikunjungi                 ||" << endl;
    cout << " || 11.  Kereta Api yang Paling Sering Mengunjungi Stasiun     ||" << endl;
    cout << " ||  0.  Exit                                                  ||" << endl;
    cout << " ================================================================" << endl;
    cout << " Masukan Pilihan Anda : ";
}

void runMenu (int menu){
    system("CLS");
    switch (menu) {
    case 1 :
        cout << "=============================================" << endl;
        cout << " Silahkan Masukkan Kereta yang Ingin dinaiki " << endl;
        cout << "=============================================" << endl;
        insertParent(Kereta);
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 2 :
        cout << "=============================================" << endl;
        cout << "                  Kereta                     " << endl;
        cout << "=============================================" << endl;
        printParent(Kereta);
        cout << endl;
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 3 :
        cout << "=============================================" << endl;
        cout << " Silahkan Masukkan Stasiun yang ingin dituju " << endl;
        cout << "=============================================" << endl;
        insertChild(Stasiun);
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 4 :
        cout << "=============================================" << endl;
        cout << "                Stasiun                      " << endl;
        cout << "=============================================" << endl;
        printChild(Stasiun);
        cout << endl;
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 5 :
        cout << "=============================================" << endl;
        cout << "        Silahkan Masukkan Rute Anda          " << endl;
        cout << "=============================================" << endl;
        int IDKereta;
        int IDStasiun;
        cout<<"Masukkan ID Kereta yang ingin di connect"<<endl;
        cin>>IDKereta;
        cout<<"Masukkan ID Stasiun yang ingin di connect"<<endl;
        cin>>IDStasiun;
        connect(Kereta,Stasiun,IDKereta,IDStasiun);
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 6 :
        cout << "=============================================" << endl;
        cout << "                   Rute                      " << endl;
        cout << "=============================================" << endl;
        int idk;
        cout<<"Masukkan ID Kereta untuk melihat Rute"<<endl;
        cin>>idk;
        printChildOfParent(Kereta,Stasiun,idk);
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 7 :
        cout << "=============================================" << endl;
        cout << "          Silahkan Masukkan ID Kereta        " << endl;
        cout << "=============================================" << endl;
        deleteParent(Kereta);
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 8 :
        cout << "=============================================" << endl;
        cout << "          Silahkan Masukkan ID Stasiun       " << endl;
        cout << "=============================================" << endl;
        deleteChild(Kereta, Stasiun);
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 9 :
        cout << "=============================================" << endl;
        cout << "               Semua Perjalanan              " << endl;
        cout << "=============================================" << endl;
        printAll(Kereta,Stasiun);
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 10 :
        cout << "=============================================" << endl;
        cout << "    Stasiun yang Paling Banyak Dikunjungi    " << endl;
        cout << "=============================================" << endl;
        printAll(Kereta,Stasiun);
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 11 :
        cout << "===================================================" << endl;
        cout << " Kereta Api yang Paling Sering Mengunjungi Stasiun " << endl;
        cout << "===================================================" << endl;
        printAll(Kereta,Stasiun);
        cout << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    case 0 :
        break;
    default :
        cout << "                 Salah Input"                  << endl;
        cout << "=============================================" << endl << flush;
        system("PAUSE");
        break;
    }
    system("CLS");
}
