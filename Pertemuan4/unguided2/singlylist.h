#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* address;

struct List {
    address first;
};


void createList(List &L);
address alokasi(int x);
void dealokasi(address p);
void insertFirst(List &L, address p);
void printInfo(List L);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(address Prec);
int nbList(List L);
void deleteList(List &L);

#endif
