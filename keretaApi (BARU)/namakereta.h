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
void connect(List_parent &P,List_child C,int idPrnt,int idChld);
bool checkConnection(List_parent P, List_child C, int idPrnt, int idChld);
void disconnect (List_parent &P, List_child C, int idPrnt, int idChld);
void printAll (List_parent P, List_child C);
void printChildOfParent (List_parent P, List_child C, int idPrnt);
void deleteChild (List_parent &P, List_child &C);
void deleteParent (List_parent &P);

#endif // NAMAKERETA_H_INCLUDED
