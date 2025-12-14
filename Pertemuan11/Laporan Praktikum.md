# <h1 align="center">Laporan Praktikum Modul 13 - MULTI LINKED LIST </h1>
<p align="center">Muhammad Shabrian Fadly - 103112400087</p>

## Dasar Teori
Multi List adalah struktur data yang terdiri dari beberapa linked list yang saling berelasi atau terhubung satu sama lain. Struktur ini digunakan ketika suatu elemen memiliki daftar elemen lain yang terkait dengannya.

Multiple Linked List terdiri dari beberapa kumpulan Linked List yang terpisah, tetapi dapat diakses bersamaan. Setiap kumpulan Linked List berisi simpul-simpul yang terkait dalam satu himpunan.

Jenis Linked List ini memungkinkan pengaturan data dalam kelompok-kelompok terpisah dan menjaga struktur yang rapi dan terorganisir. Dengan pemahaman tentang perbedaan jenis-jenis Linked List ini, kita dapat membuat pilihan yang tepat dalam menggunakan struktur data yang sesuai dengan kebutuhan aplikasi. Multilist dapat digunakan untuk objek yang berhubungan dengan satu ke banyak, misalkan dosen pembimbing akademik akan membimbing beberapa mahasiswa, sementara satu mahasiswa hanya memiliki 1 dosen pembibing akademiknya,


## Guided 

### 1.Guided 1

```C++
//multilist.h
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>

using namespace std;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild
{
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;

};

struct listAnak
{
    NodeChild first;
    NodeChild last;
};

struct nodeParent
{
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk
{
    NodeParent first;
    NodeParent last;
};

void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeprev);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void printStrukturMLL(listInduk &LInduk);

#endif

```

```C++
//multilist.cpp
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```
```C++
#include "multilist.h"
#include <iostream>


using namespace std;

int main(){
listInduk LInduk;
createListInduk(LInduk);

NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
insertLastParent(LInduk, K01);
NodeParent K02 = alokasiNodeParent("K02", "Minuman");
insertLastParent(LInduk, K02);
NodeParent K03 = alokasiNodeParent("K03", "Dessert");
insertLastParent(LInduk, K03);


cout << endl;
NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
insertLastChild(K01->L_Anak, M01);
NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
insertLastChild(K01->L_Anak, M02);
NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
insertLastChild(K02->L_Anak, D02);
NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
insertLastChild(K02->L_Anak, D01);
NodeChild S01 = alokasiNodeChild("S01", "Puding Coklat");
insertLastChild(K03->L_Anak, S01);
printStrukturMLL(LInduk);
cout << endl;
findChildByID(LInduk, "D01");
cout << endl;
deleteAfterChild(K01-> L_Anak, M01);
cout << endl;
deleteAfterParent(LInduk, K02);
cout << endl;
printStrukturMLL(LInduk);
cout << endl;
return 0;
}

```

Program guided 1 ini mengimplementasikan struktur Multi Linked List untuk mengelola data kategori makanan sebagai parent dan data makanan sebagai child. Setiap kategori dapat memiliki lebih dari satu makanan. Program mendukung operasi pembuatan list, penambahan dan penghapusan parent maupun child, pencarian data child berdasarkan ID, serta penampilan keseluruhan struktur data. Penghapusan parent dilakukan secara aman dengan menghapus seluruh child yang terkait terlebih dahulu.


## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :
```C++
//multill.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

struct nodeChild;
struct nodeParent;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void printMLLStructure(listParent &LParent);

#endif
```

```C++
//multill.cpp
#include "MultiLL.h"
#include <iomanip>

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = NULL;
    newNode->prev = NULL;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = tail;
    newNode->isidata.bobot = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void printMLLStructure(listParent &LParent) {
    NodeParent currentParent = LParent.first;
    int parentCount = 1;
    
    while (currentParent != NULL) {
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Golongan : " << currentParent->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << currentParent->isidata.namaGolongan << endl;
        
        if (isEmptyChild(currentParent->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild currentChild = currentParent->L_Child.first;
            int childCount = 1;
            
            while (currentChild != NULL) {
                cout << "- Child " << childCount << " :" << endl;
                cout << "    ID Hewan : " << currentChild->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << currentChild->isidata.namaHewan << endl;
                cout << "    Habitat : " << currentChild->isidata.habitat << endl;
                cout << "    Ekor : " << (currentChild->isidata.ekor ? "1" : "0") << endl;
                cout << fixed << setprecision(1);
                cout << "    Bobot : " << currentChild->isidata.bobot << endl;
                
                currentChild = currentChild->next;
                childCount++;
            }
        }
        
        cout << endl;
        currentParent = currentParent->next;
        parentCount++;
    }
}
```

```C++
//main.cpp
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);
    
    cout << "=== SOAL 1: INSERT DATA DAN PRINT ===" << endl;
    cout << "======================================" << endl;
    
    insertLastParent(LParent, allocNodeParent("G001", "Aves"));
    insertLastParent(LParent, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LParent, allocNodeParent("G003", "Pisces"));
    insertLastParent(LParent, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LParent, allocNodeParent("G005", "Reptil"));
    
   
    NodeParent parentAves = LParent.first;
    insertLastChild(parentAves->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(parentAves->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));
    
    NodeParent parentMamalia = LParent.first->next;
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));
    
    NodeParent parentAmfibi = LParent.first->next->next->next;
    insertLastChild(parentAmfibi->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));
    
    printMLLStructure(LParent);
    
    return 0;
}
```



### Output Unguided 1 :

![Output Unguided1](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan11/Output%20Unguided1.png)

Program Unguided 1 ini untuk merepresentasikan golongan hewan dan data hewan. Setiap golongan dapat memiliki beberapa data hewan dengan atribut tertentu. Fokus utama program ini adalah proses penambahan data dan penampilan struktur Multi Linked List secara terorganisir untuk menunjukkan hubungan satu ke banyak.


### 2.Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.

```C++
//multill.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

struct nodeChild;
struct nodeParent;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void printMLLStructure(listParent &LParent);
void searchHewanByEkor(listParent &LParent, bool tail);

#endif

```

```C++
//multill.cpp
#include "MultiLL.h"
#include <iomanip>

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = NULL;
    newNode->prev = NULL;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = tail;
    newNode->isidata.bobot = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void printMLLStructure(listParent &LParent) {
    NodeParent currentParent = LParent.first;
    int parentCount = 1;
    
    while (currentParent != NULL) {
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Golongan : " << currentParent->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << currentParent->isidata.namaGolongan << endl;
        
        if (isEmptyChild(currentParent->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild currentChild = currentParent->L_Child.first;
            int childCount = 1;
            
            while (currentChild != NULL) {
                cout << "- Child " << childCount << " :" << endl;
                cout << "    ID Hewan : " << currentChild->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << currentChild->isidata.namaHewan << endl;
                cout << "    Habitat : " << currentChild->isidata.habitat << endl;
                cout << "    Ekor : " << (currentChild->isidata.ekor ? "1" : "0") << endl;
                cout << fixed << setprecision(1);
                cout << "    Bobot : " << currentChild->isidata.bobot << endl;
                
                currentChild = currentChild->next;
                childCount++;
            }
        }
        
        cout << endl;
        currentParent = currentParent->next;
        parentCount++;
    }
}

void searchHewanByEkor(listParent &LParent, bool tail) {
    cout << "\n=== HASIL PENCARIAN HEWAN DENGAN EKOR " << (tail ? "TRUE" : "FALSE") << " ===" << endl;
    NodeParent currentParent = LParent.first;
    bool found = false;
    
    while (currentParent != NULL) {
        NodeChild currentChild = currentParent->L_Child.first;
        
        while (currentChild != NULL) {
            if (currentChild->isidata.ekor == tail) {
                cout << "Golongan: " << currentParent->isidata.namaGolongan << endl;
                cout << "  ID Hewan: " << currentChild->isidata.idHewan << endl;
                cout << "  Nama Hewan: " << currentChild->isidata.namaHewan << endl;
                cout << "  Habitat: " << currentChild->isidata.habitat << endl;
                cout << fixed << setprecision(1);
                cout << "  Bobot: " << currentChild->isidata.bobot << " kg" << endl;
                cout << endl;
                found = true;
            }
            currentChild = currentChild->next;
        }
        currentParent = currentParent->next;
    }
    
    if (!found) {
        cout << "Tidak ditemukan hewan dengan ekor " << (tail ? "TRUE" : "FALSE") << endl;
    }
}
```
```C++
//main.cpp
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);
    
    cout << "=== SOAL 2: INSERT DATA, PRINT, DAN SEARCH ===" << endl;
    cout << "===============================================" << endl;
    
    insertLastParent(LParent, allocNodeParent("G001", "Aves"));
    insertLastParent(LParent, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LParent, allocNodeParent("G003", "Pisces"));
    insertLastParent(LParent, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LParent, allocNodeParent("G005", "Reptil"));
    
    NodeParent parentAves = LParent.first;
    insertLastChild(parentAves->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(parentAves->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));
    
    NodeParent parentMamalia = LParent.first->next;
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));
    
    NodeParent parentAmfibi = LParent.first->next->next->next;
    insertLastChild(parentAmfibi->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));
    
    printMLLStructure(LParent);
    
    searchHewanByEkor(LParent, false);
    
    return 0;
}
```

### Output Unguided 2 :

![Output Unguided2](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan11/Output%20Unguided2.png)

Program Unguided 2 ini merupakan pengembangan dari Unguided 1 dengan menambahkan fitur pencarian data hewan berdasarkan atribut ekor. Selain menampilkan struktur Multi Linked List, program mampu menelusuri seluruh data child pada setiap parent untuk menampilkan hewan yang memenuhi kriteria pencarian tertentu.

### 3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah menjadi seperi ini :
```C++
//multill.h
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

struct nodeChild;
struct nodeParent;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void printMLLStructure(listParent &LParent);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void deleteListChild(listChild &LChild);
void deleteParentByID(listParent &LParent, string idGolongan);

#endif
```

```C++
//multill.cpp
#include "MultiLL.h"
#include <iomanip>

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = NULL;
    newNode->prev = NULL;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = tail;
    newNode->isidata.bobot = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void printMLLStructure(listParent &LParent) {
    NodeParent currentParent = LParent.first;
    int parentCount = 1;
    
    while (currentParent != NULL) {
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Golongan : " << currentParent->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << currentParent->isidata.namaGolongan << endl;
        
        if (isEmptyChild(currentParent->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild currentChild = currentParent->L_Child.first;
            int childCount = 1;
            
            while (currentChild != NULL) {
                cout << "- Child " << childCount << " :" << endl;
                cout << "    ID Hewan : " << currentChild->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << currentChild->isidata.namaHewan << endl;
                cout << "    Habitat : " << currentChild->isidata.habitat << endl;
                cout << "    Ekor : " << (currentChild->isidata.ekor ? "1" : "0") << endl;
                cout << fixed << setprecision(1);
                cout << "    Bobot : " << currentChild->isidata.bobot << endl;
                
                currentChild = currentChild->next;
                childCount++;
            }
        }
        
        cout << endl;
        currentParent = currentParent->next;
        parentCount++;
    }
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent temp = LParent.first;
        LParent.first = LParent.first->next;
        if (LParent.first != NULL) {
            LParent.first->prev = NULL;
        } else {
            LParent.last = NULL;
        }
        deleteListChild(temp->L_Child);
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent temp = NPrev->next;
        NPrev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        deleteListChild(temp->L_Child);
        deallocNodeParent(temp);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        NodeChild temp = LChild.first;
        LChild.first = LChild.first->next;
        deallocNodeChild(temp);
    }
    LChild.last = NULL;
}

void deleteParentByID(listParent &LParent, string idGolongan) {
    NodeParent current = LParent.first;
    
    if (current == NULL) return;
    
    if (current->isidata.idGolongan == idGolongan) {
        deleteFirstParent(LParent);
        return;
    }
    
    while (current->next != NULL) {
        if (current->next->isidata.idGolongan == idGolongan) {
            deleteAfterParent(LParent, current);
            return;
        }
        current = current->next;
    }
}
```
```C++
//main.cpp
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);
    
    cout << "=== SOAL 3: INSERT DATA, DELETE G004, DAN PRINT ===" << endl;
    cout << "====================================================" << endl;
    
    insertLastParent(LParent, allocNodeParent("G001", "Aves"));
    insertLastParent(LParent, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LParent, allocNodeParent("G003", "Pisces"));
    insertLastParent(LParent, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LParent, allocNodeParent("G005", "Reptil"));
    

    NodeParent parentAves = LParent.first;
    insertLastChild(parentAves->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(parentAves->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));
    

    NodeParent parentMamalia = LParent.first->next;
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));
    
    NodeParent parentAmfibi = LParent.first->next->next->next;
    insertLastChild(parentAmfibi->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));
    
    cout << "\n=== SEBELUM DELETE G004 ===" << endl;
    printMLLStructure(LParent);
    

    deleteParentByID(LParent, "G004");
    
    cout << "\n=== SETELAH DELETE G004 ===" << endl;
    printMLLStructure(LParent);
    
    return 0;
}

```

### Output Unguided 3 :
![Output Unguided3](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan11/Output%20Unguided3.png)

Program Unguided 3 ini menambahkan operasi penghapusan data parent berdasarkan ID. Saat sebuah parent dihapus, seluruh data child yang terhubung juga dihapus secara otomatis. Program ini menampilkan kondisi struktur data sebelum dan sesudah proses penghapusan untuk memastikan integritas Multi Linked List tetap terjaga.

## Kesimpulan
Dari praktikum ini, menunjukkan bahwa struktur Multi Linked List efektif digunakan untuk merepresentasikan hubungan data satu ke banyak. Implementasi operasi insert, delete, search, dan traversal membuktikan bahwa Multi Linked List mampu mengelola data secara terstruktur dan fleksibel. Selain itu, pengelolaan memori yang tepat sangat penting untuk menjaga konsistensi data dan mencegah kesalahan saat penghapusan node.

## Referensi
[1] Banjarnahor, J. (2022). Pemanfaatan link list untuk mengatasi database tidak normal. LOFIAN: Jurnal Teknologi Informasi dan Komunikasi, 2(1), 16–23. https://doi.org/10.58918/lofian.v2i1.183 

<br>[2]Kelinci Coklat. (n.d.). 8. Multi List (Struktur Data) [SlideShare presentation]. SlideShare. https://www.slideshare.net/slideshow/8-multi-list-struktur-data/114941552

<br>[3]Annisa. (2023, July 25). Pengertian linked list: Struktur data dalam pemrograman. FIKTI – Teknologi Cerdas. https://fikti.umsu.ac.id/pengertian-linked-list-struktur-data-dalam-pemrograman/
