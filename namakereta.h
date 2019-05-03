#ifndef NAMAKERETA_H_INCLUDED
#define NAMAKERETA_H_INCLUDED

#include <iostream>
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

void insertParent(List_parent &L);
void insertChild(List_child &L);
void printParent(List_parent L);
void printChild(List_child L);
void connect(List_parent &P,List_child C,int IDP,int IDC);
bool checkConnection(List_parent P, List_child C,int IDP, int IDC);
void disconnect (List_parent &P, List_child C, int IDP, int IDC);
void printAll (List_parent P, List_child C);
void printChildOfParent (List_parent P, List_child C, int IDP);
void deleteChild (List_parent &P, List_child &C);
void deleteParent (List_parent &P);
void stasiunTerbanyak(List_child L, List_relasi R);
void keretaTerbanyak(List_parent L, List_relasi R);
int jumlahStasiun(address_parent Q, List_relasi L);
int jumlahKereta(address_child Q, List_relasi L);
bool cekDulu (address_child C, address_parent P, List_relasi L);
void duakaliStasiun (List_parent P, List_relasi R, List_child C);
#endif // NAMAKERETA_H_INCLUDED
