#include "Doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        (L.last)->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else {
        if (P == L.first && P == L.last) {
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) {
            L.first = P->next;
            (L.first)->prev = Nil;
        } else if (P == L.last) {
            L.last = P->prev;
            (L.last)->next = Nil; P->prev = Nil;
        } else {
            address Prec = P->prev;
            address Succ = P->next;
            Prec->next = Succ; Succ->prev = Prec;
            P->next = Nil; P->prev = Nil;
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}