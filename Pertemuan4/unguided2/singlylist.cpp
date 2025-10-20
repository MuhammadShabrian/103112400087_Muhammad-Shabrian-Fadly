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


void deleteFirst(List &L) {
    if (L.first != nullptr) {
        address p = L.first;
        L.first = L.first->next;
        dealokasi(p);
    }
}

void deleteLast(List &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            dealokasi(L.first);
            L.first = nullptr;
        } else {
            address q = L.first;
            while (q->next->next != nullptr)
                q = q->next;
            address p = q->next;
            q->next = nullptr;
            dealokasi(p);
        }
    }
}

void deleteAfter(address Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        address p = Prec->next;
        Prec->next = p->next;
        dealokasi(p);
    }
}

int nbList(List L) {
    int count = 0;
    address p = L.first;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.first != nullptr)
        deleteFirst(L);
}
