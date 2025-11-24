# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE </h1>
<p align="center">Muhammad Shabrian Fadly - 103112400087</p>

## Dasar Teori
Queue atau dalam bahasa Indonesia yang berarti antrean adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah “First In, First Out” (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.

Caranya bekerja adalah seperti jejeran orang yang sedang menunggu antrean di supermarket di mana orang pertama yang datang adalah yang pertama dilayani (First In, First Out). Pada struktur data ini, urutan pertama (data yang akan dikeluarkan) disebut Front atau Head. Sebaliknya, data pada urutan terakhir (data yang baru saja ditambahkan) disebut Back, Rear, atau Tail. Proses untuk menambahkan data pada antrean disebut dengan Enqueue, sedangkan proses untuk menghapus data dari antrean disebut dengan Dequeue. 

Struktur data queue memiliki sejumlah kelebihan. Pertama, queue sangat berguna dalam penjadwalan tugas dan manajemen antrian pada sistem komputer. Dalam sistem operasi, struktur ini digunakan untuk mengatur proses berdasarkan urutan kedatangan. Kedua, queue memudahkan pengaturan eksekusi tugas-tugas yang datang secara berurutan, seperti dalam layanan pelanggan berbasis giliran[51].


## Guided 

### 1.Guided 1

```C++
//queue.h
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct queue {
 address head;
 address tail;
};

bool isEmpty (queue Q);
void createQueue(queue &Q);
address alokasi (int angka);
void dealokasi (queue &node);
void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif

```

```C++
//queue.cpp

#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}

```
 
```C++
//main.cpp
#include "queue.h"
#include <iostream>


int main(){
queue Q;
address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
createQueue(Q);

nodeA = alokasi(1);
nodeB = alokasi(2);
nodeC = alokasi(3);
nodeD = alokasi(4);
nodeE = alokasi(5);

enQueue(Q, nodeA);
enQueue(Q, nodeB);
enQueue(Q, nodeC);
enQueue(Q, nodeD);
enQueue(Q, nodeE);

cout << endl;


cout << "Queue setelah enQueue" << endl;
viewQueue(Q);
cout << endl;

deQueue(Q);
deQueue(Q);
cout << endl;

cout << "Queue setelah deQueue 2 kali--" << endl;
viewQueue(Q);
cout << endl;

updateQueue (Q, 2);
updateQueue (Q, 1);
updateQueue(Q, 4);
cout << endl;

cout <<" Queue setelah update" << endl;
viewQueue(Q);
cout << endl;

searchData(Q,4);
searchData(Q,9);

return 0;
}

```

Program guided 1 ini menampilkan implementasi queue menggunakan linked list. Setiap elemen disimpan dalam node yang saling terhubung, sehingga ukuran antrean tidak dibatasi kapasitas array. Proses enqueue menambahkan node di bagian belakang, sedangkan dequeue menghapus node dari bagian depan. Program ini juga menyediakan fitur untuk memperbarui nilai data pada posisi tertentu serta melakukan pencarian data di dalam antrean.
### 2.Guided 2
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5
struct Queue
{
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q,int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
```C++
//queue.cpp
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}

```

```C++
//main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout <<"\n Enqueue 3 elemen"<<endl;
    enqueue (Q,5);
    printInfo (Q);
    enqueue (Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);

cout << "\n Dequeue 1 Elemen" << endl;
cout << "Elemen keluar: " << dequeue(Q) << endl;
printInfo(Q);

cout << "\n Enqueue 1 Elemen" << endl;
enqueue(Q, 4);
printInfo(Q);

cout << "\nDequeue 2 Elemen" << endl;
cout << "Elemen keluar: " << dequeue(Q) << endl;
cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

return 0;
};
```
Program Guided 2 mengimplementasikan queue menggunakan array circular. Struktur ini memakai head, tail, dan count untuk melacak posisi elemen secara efisien. Enqueue dilakukan dengan memanfaatkan pergerakan indeks melingkar, sehingga tidak ada kebutuhan untuk menggeser elemen meski tail mencapai batas array. Dequeue juga bekerja dengan pola yang sama, memindahkan head ke indeks berikutnya secara modular.

## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”: Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
```C++
//stack.h
#ifndef QUEUE_H
#define QUEUE_H

const int MAXQ = 5;
typedef int infotype;

struct Queue {
    infotype info[MAXQ];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif


```

```C++
//stack.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q){
    return Q.tail == -1;
}

bool isFullQueue(const Queue &Q){
    return Q.tail == MAXQ - 1;
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh" << endl;
        return;
    }
    Q.tail++;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[0];

    // geser
    for (int i = 0; i < Q.tail; i++){
        Q.info[i] = Q.info[i+1];
    }

    Q.tail--;
    return x;
}

void printInfo(const Queue &Q){
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (!isEmptyQueue(Q)){
        for (int i = 0; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}

```

```C++
//main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}

```



### Output Unguided 1 :

![Output Unguided1](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan8/Output%20Unguided1.png)

Program Unguided 1 menerapkan queue berbasis array yang bersifat linier. Pada saat dequeue dijalankan, elemen-elemen digeser ke depan untuk menjaga posisi head tetap berada pada indeks nol. Metode ini lebih sederhana namun kurang efisien ketika antrean berisi banyak elemen, karena operasi penggeseran memakan waktu lebih besar.


### 2.Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).


```C++
//queue.h
#ifndef QUEUE_H
#define QUEUE_H

const int MAXQ = 5;
typedef int infotype;

struct Queue {
    infotype info[MAXQ];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif

```

```C++
//queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q){
    return Q.tail == -1;
}

bool isFullQueue(const Queue &Q){
    return (Q.head == 0 && Q.tail == MAXQ-1);
}

void shiftLeft(Queue &Q){
    int j = 0;
    for (int i = Q.head; i <= Q.tail; i++){
        Q.info[j++] = Q.info[i];
    }
    Q.head = 0;
    Q.tail = j - 1;
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh" << endl;
        return;
    }

    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
        Q.info[Q.tail] = x;
        return;
    }

    if (Q.tail == MAXQ - 1 && Q.head > 0){
        shiftLeft(Q);
    }

    Q.tail++;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail){
        Q.head = 0;
        Q.tail = -1;
    } else {
        Q.head++;
    }
    return x;
}

void printInfo(const Queue &Q){
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (!isEmptyQueue(Q)){
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}

```
```C++
//main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}

```

### Output Unguided 2 :
![Output Unguided2](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan8/Output%20Unguided2.png)

Program Unguided 2 merupakan pengembangan dari queue linear dengan penambahan mekanisme shiftLeft. Saat tail mencapai batas array tetapi masih tersedia ruang kosong di bagian depan, elemen-elemen akan digeser ke posisi awal sehingga antrean tetap dapat menerima data baru. Pendekatan ini mengurangi terjadinya kondisi "penuh semu" dan membuat pemanfaatan array lebih efisien dibanding queue linear biasa.

### 3.Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).
```C++
//queue.h
#ifndef QUEUE_H
#define QUEUE_H

const int MAXQ = 5;
typedef int infotype;

struct Queue {
    infotype info[MAXQ];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif

```

```C++
//queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q){
    return (Q.tail == -1);
}

bool isFullQueue(const Queue &Q){
    if (isEmptyQueue(Q)) return false;
    return ((Q.tail + 1) % MAXQ) == Q.head;
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "Queue penuh" << endl;
        return;
    }

    if (isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
        Q.info[Q.tail] = x;
        return;
    }

    Q.tail = (Q.tail + 1) % MAXQ;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail){
        Q.head = 0;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAXQ;
    }

    return x;
}

void printInfo(const Queue &Q){
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (!isEmptyQueue(Q)){
        int i = Q.head;
        while (true){
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % MAXQ;
        }
    }

    cout << endl;
}

```
```C++
//main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    enqueue(Q,9); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}

```

### Output Unguided 3 :

![Output Unguided3](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan8/Output%20Unguided3.png)

Program Unguided 3 menerapkan circular queue, sehingga indeks head dan tail dapat kembali ke posisi awal ketika mencapai batas array. Tidak ada proses penggeseran karena seluruh pergerakan diatur menggunakan operasi modulo.

## Kesimpulan
Dari praktikum ini, memperkenalkan berbagai cara mengimplementasikan struktur data queue, mulai dari linked list, queue linear, queue dengan mekanisme shift, hingga circular queue. Setiap pendekatan memiliki karakteristik dan tingkat efisiensinya masing-masing. Linked list menawarkan fleksibilitas ukuran yang dinamis, sementara array linear memberikan struktur yang lebih sederhana. Mekanisme shift memperbaiki keterbatasan queue linear, sedangkan circular queue memberikan solusi paling efisien untuk menghindari penggeseran elemen dan mengoptimalkan penggunaan ruang.

## Referensi
[1] Dicoding Indonesia. (2021, July 5). Struktur data queue: Pengertian, fungsi, dan jenisnya. Dicoding Blog. https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/

<br>[2] Trijayanti, A., Aulia, I., Khairunisa, N., Purba, F. A. H., & Gunawan, I. (2025). Implementasi struktur data antrian queue dalam sistem penjadwalan proses pada sistem operasi. Jurnal Publikasi Teknik Informatika (JUPTI), 4(2), 48–53. https://doi.org/10.55606/jupti.v4i2.4170