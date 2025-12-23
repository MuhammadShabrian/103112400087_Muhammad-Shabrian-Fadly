#include <iostream>
#include <string>
using namespace std;

struct NodeChild {
    string idFilm, judul;
    int durasi, tahun;
    float rating;
    NodeChild *next, *prev;
};

struct ListChild {
    NodeChild *first, *last;
};

struct NodeParent {
    string idGenre, namaGenre;
    ListChild childs;
    NodeParent *next, *prev;
};

struct ListParent {
    NodeParent *first, *last;
};

void createListChild(ListChild &L) { L.first = L.last = NULL; }
void createListParent(ListParent &L) { L.first = L.last = NULL; }

NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent* p = new NodeParent;
    p->idGenre = id; p->namaGenre = nama;
    createListChild(p->childs);
    p->next = p->prev = NULL;
    return p;
}

NodeChild* alokasiNodeChild(string id, string judul, int dur, int thn, float rat) {
    NodeChild* c = new NodeChild;
    c->idFilm = id; c->judul = judul; c->durasi = dur; c->tahun = thn; c->rating = rat;
    c->next = c->prev = NULL;
    return c;
}

void insertFirstParent(ListParent &L, NodeParent* p) {
    if (L.first == NULL) L.first = L.last = p;
    else { p->next = L.first; L.first->prev = p; L.first = p; }
}

void insertLastChild(ListChild &L, NodeChild* c) {
    if (L.first == NULL) L.first = L.last = c;
    else { L.last->next = c; c->prev = L.last; L.last = c; }
}

void hapusListChild(ListChild &L) {
    NodeChild* p = L.first;
    while (p) {
        NodeChild* temp = p;
        p = p->next;
        delete temp;
    }
    L.first = L.last = NULL;
}

void deleteAfterParent(ListParent &L, NodeParent* prec) {
    if (prec && prec->next) {
        NodeParent* p = prec->next;
        hapusListChild(p->childs);
        prec->next = p->next;
        if (p->next) p->next->prev = prec;
        else L.last = prec;
        delete p;
    }
}

void printStrukturMLL(ListParent L) {
    NodeParent* p = L.first;
    int i = 1;
    while (p) {
        cout << "=== Parent " << i++ << " ===" << endl;
        cout << "ID Genre: " << p->idGenre << endl;
        cout << "Nama Genre: " << p->namaGenre << endl;
        NodeChild* c = p->childs.first;
        int j = 1;
        while (c) {
            cout << "Child " << j++ << ":" << endl;
            cout << "ID Film: " << c->idFilm << endl;
            cout << "Judul Film: " << c->judul << endl;
            cout << "Durasi Film: " << c->durasi << " menit" << endl;
            cout << "Tahun Tayang: " << c->tahun << endl;
            cout << "Rating Film: " << c->rating << endl;
            c = c->next;
        }
        p = p->next;
        cout << endl;
    }
}

void searchFilmByRatingRange(ListParent L, float min, float max) {
    NodeParent* p = L.first;
    int pi = 1;
    while (p) {
        NodeChild* c = p->childs.first;
        int ci = 1;
        while (c) {
            if (c->rating >= min && c->rating <= max) {
                cout << "Data Film ditemukan pada list child dari node parent " << p->namaGenre << " pada posisi ke-" << ci << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film: " << c->judul << endl;
                cout << "ID Film: " << c->idFilm << endl;
                cout << "Durasi Film: " << c->durasi << " menit" << endl;
                cout << "Tahun Tayang: " << c->tahun << endl;
                cout << "Rating Film: " << c->rating << endl << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre: " << p->idGenre << endl;
                cout << "Nama Genre: " << p->namaGenre << endl;
                cout << "Posisi dalam list parent: posisi ke-" << pi << endl << "========================================" << endl;
            }
            c = c->next; ci++;
        }
        p = p->next; pi++;
    }
}

int main() {
    ListParent LP; createListParent(LP);
    insertFirstParent(LP, alokasiNodeParent("G004", "Romance"));
    insertFirstParent(LP, alokasiNodeParent("G003", "Horror"));
    insertFirstParent(LP, alokasiNodeParent("G002", "Comedy"));
    insertFirstParent(LP, alokasiNodeParent("G001", "Action"));

    NodeParent* p = LP.first;
    insertLastChild(p->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
    p = p->next;
    insertLastChild(p->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(p->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    p = p->next;
    insertLastChild(p->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    p = p->next;
    insertLastChild(p->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(p->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    printStrukturMLL(LP);
    searchFilmByRatingRange(LP, 8.0, 8.5);
    deleteAfterParent(LP, LP.first);
    printStrukturMLL(LP);
    return 0;
}