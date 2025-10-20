#include "Singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(int x) {
    address p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void dealokasi(address p) {
    delete p;
}

void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

void printInfo(List L) {
    address p = L.first;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
