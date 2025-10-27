# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN KEDUA) </h1>
<p align="center">Muhammad Shabrian Fadly - 103112400087</p>

## Dasar Teori

Linked list adalah suatu bentuk struktur data yang berupa sekumpulan elemen data yang bertipe sama dimana tiap elemen saling berkaita atau dihubungkan dengan elemen lain melalui suatu pointer ,Pointer adalah alamat elemen data yang tersimpan di memori. Mengacu elemen dengan pointer membuat elemen bersebelahan secara logik, meskipun Linked list menyimpan elemen di lokasi memori yang tidak teratur, dengan setiap elemen memiliki referensi ke elemen berikutnya.[487]. Salah satu keunggulan utama linked list adalah kemampuannya untuk mengatasi perubahan ukuran secara dinamis. Ketika kita ingin menambahkan atau menghapus elemen dari linked list, kita dapat melakukannya dengan mudah tanpa mempengaruhi elemen-elemen lain dalam struktur data tersebut.

Singly Linked list adalah Daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya. simpul yang saling terhubung satu sama lain dengan menggunakan pointer. Setiap simpul dalam singly Linked list memiliki dua bagian, yaitu data dan pointer yang menunjuk ke simpul berikutnya. Singly Linked list hanya memiliki satu arah, yaitu dari simpul awal (head) ke simpul akhir (tail).[487]

Pengertian Array dalam ilmu komputer adalah suatu tipe data terstruktur yang dapat menyimpan banyak data dengan suatu nama yang sama dan menempati tempat, di memori yang berurutan (kontinu) serta bertipe data sama , Elemen-elemen dalam Array diakses menggunakan indeks, yang dimulai dari 0 untuk elemen pertama.[486]

Pencarian Linier dapat dilakukan pada barisan bilangan yang terurut secara menaik (ascending) atau menurun (descending) ataupun tidak terurut.  Pencarian Linier dilakukan dengancara membandingkan data yang dicari (X) dengandata dalam  barisan A[1]  ...  A[n]dengan dimulai dari  data elemen pertama pada barisan A. Jika perbandingan bernilai sama, maka pencariandihentikan dan dinyatakan sukses.[4]

Pencarian Biner hanya dapat dilakukan pada barisan bilangan yang telah diurutkan baiksecara menaik (ascending) maupun menurun(descending).Pencarian Biner melakukanpencarian data X dalam barisan A[1] ... A[n]dengan dimulai dari data tengah pada barisan A.Jika nilai data X sama  dengan nilai data tengah barisan A, maka pencarian dihentikan dan dinyatakan sukses.[4]

## Guided 

### 1.Guided 1

```C++
//listBuah.h
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga ;

};

typedef buah dataBuah;
typedef struct node *address;
struct node
{
    dataBuah isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi (address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

void updateFirst(linkedlist L);
void updateLast(linkedlist L);
void updateAfter(linkedlist List, address prev);

#endif


```

```C++
//listBuah.cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
```C++
//main.cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi ("jeruk", 100, 3000);
    nodeB = alokasi ("Apel", 75, 4000);
    nodeC = alokasi ("Pir", 87, 5000);
    nodeD = alokasi ("Semangka", 43, 11500);
    nodeE = alokasi ("Durian", 15, 31450);

insertFirst (List, nodeA);
insertLast(List, nodeB);
insertAfter(List, nodeC, nodeA);
insertAfter(List, nodeD, nodeC);
insertLast(List, nodeE);

cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
printList(List);
cout << "jumlah node : " << nbList(List) << endl;
cout << endl;

updateFirst(List);
updateLast(List);
updateAfter(List ,nodeD);

cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
printList(List);
cout << "jumlah node : " << nbList(List) << endl;
cout << endl;


return 0;

}
```
Pada guided1 ini, program dasar Singly Linked List yang mengelola data buah (nama, jumlah, harga). Fungsinya terdiri dari membuat list, menambah (di awal, akhir, tengah), menghapus (di awal, akhir, tengah), menampilkan isi list, juga menghitung jumlah node. Fokus utama bagian kedua ini adalah fitur update untuk mengganti data di node pertama, node terakhir, dan node setelah node tertentu.

### 2.Guided 2
```C++
#include <iostream>
using namespace std;

struct Node
{
 int data;
 Node* next;
};

Node* linearSearch(Node* head, int key){
Node* current = head;
while(current != nullptr) {
    if (current->data == key) {
        return current; 
    }
    current = current->next;
};
return nullptr;
}

void append(Node*&head, int value){
    Node* newNode = new Node {value, nullptr};
    if(!head) head = newNode;
    
    else {
        Node* temp = head;
        while (temp -> next) temp = temp -> next;
        temp ->next = newNode;
        

    }
}

Node* binarySearch(Node* head, int key){
    int size = 0;
    for (Node* current = head; current; current= current -> next) size++;
    Node *start = head;
    Node* end = nullptr;
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        for (int i = 0; i < mid; i++) midNode = midNode -> next;
        if (midNode -> data == key) return midNode;
        if (midNode -> data < key){
            start = midNode -> next;
        }
        else{
            end = midNode;
        }
        size = size / 2;
    }
    return nullptr;
    
    
}
int main (){
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);


    Node* result = binarySearch(head, 40);
 cout << (result ? "Found" : "Not Found") << endl;
return 0;
}

```
Pada guided2 ini, berisi dua fungsi pencarian: Linear Search dan Binary Search pada Linked List. Program utamanya hanya menjalankan Binary Search untuk mencari nilai 40 dalam list terurut 10, 20, 30, 40, 50. 

### 3. Guided 3
```C++
#include <iostream>
using namespace std;

struct Node
{
 int data;
 Node* next;
};

Node* linearSearch(Node* head, int key){
Node* current = head;
while(current != nullptr) {
    if (current->data == key) {
        return current; 
    }
    current = current->next;
};
return nullptr;
}

void append(Node*&head, int value){
    Node* newNode = new Node {value, nullptr};
    if(!head) head = newNode;
    
    else {
        Node* temp = head;
        while (temp -> next) temp = temp -> next;
        temp ->next = newNode;
        

    }
}
int main (){
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);

    Node* result = linearSearch(head, 20);
 cout << (result ? "Found" : "Not Found") << endl;
return 0;
}

```

Pada guided 3 ini, program dasar yang berfokus pada implementasi Linear Search pada Linked List. Kode utama memanggil fungsi pencarian untuk mencari nilai 20 di list 10, 20, 30, menunjukkan alur dasar pencarian sekuensial dari awal list.

## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu: Membuat linked list dengan menambahkan node di akhir, Mengimplementasikan binary search pada linked list, Menampilkan detail proses pencarian dan hasil akhir

```C++
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    cout << "Linked List: ";
    while (current) {
        cout << current->data;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }

    Node* start = head;
    int current_size = size;
    int iteration = 1;
    int offset = 0; 

    cout << "\nProses Pencarian:" << endl;

    while (current_size > 0) {
        int mid_offset = current_size / 2;
        int mid_index = offset + mid_offset;
        
        Node* midNode = start;
        for (int i = 0; i < mid_offset; i++) {
            midNode = midNode->next;
        }

        cout << "Iterasi " << iteration++ << ": Mid = " << midNode->data 
             << " (indeks " << mid_index << ", alamat: " << midNode << ")";

        if (midNode->data == key) {
            cout << " DITEMUKAN!" << endl;
            return midNode;
        } else if (midNode->data < key) {
            start = midNode->next;
            offset = mid_index + 1;
            current_size = current_size - mid_offset - 1;
            cout << " -> Cari di bagian kanan" << endl;
        } else {
            current_size = mid_offset; 
            cout << " -> Cari di bagian kiri" << endl;
        }
    }

    cout << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}


void runTugas1() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60); 

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    displayList(head);

    int key1 = 40;
    cout << "Mencari nilai: " << key1 << endl;
    Node* result1 = binarySearch(head, key1);

    cout << "\nHasil: Nilai " << key1;
    if (result1) {
        cout << " DITEMUKAN pada linked list" << endl;
        cout << "Alamat node: " << result1 << endl;
        cout << "Data node: " << result1->data << endl;
        cout << "Node berikutnya: " << (result1->next ? to_string(result1->next->data) : "NULL") << endl;
    } else {
        cout << " TIDAK DITEMUKAN dalam linked list" << endl;
    }

    cout << "\n==============================\n" << endl;

    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    Node* result2 = binarySearch(head, key2);

    cout << "\nHasil: Nilai " << key2;
    if (result2) {
        cout << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result2 << endl;
        cout << "Data node: " << result2->data << endl;
        cout << "Node berikutnya: " << (result2->next ? to_string(result2->next->data) : "NULL") << endl;
    } else {
        cout << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }
}

int main() {
    runTugas1();
    return 0;
}
```





### Output Unguided 1 :
![Output Unguided1](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan5/Output%20Unguided1.png)

Program unguided 1 berisi penerapan pencarian biner (binary search) pada struktur data singly linked list. Program ini menggunakan fungsi append() untuk menambahkan elemen baru ke dalam list dan displayList() untuk menampilkan seluruh isi linked list. Proses pencarian dilakukan oleh fungsi binarySearch(), yang mencari data tertentu dengan membandingkan nilai tengah setiap iterasi. Jika nilai yang dicari lebih kecil, pencarian dilanjutkan ke bagian kiri; jika lebih besar, ke bagian kanan. Program juga menampilkan proses pencarian secara bertahap agar pengguna dapat melihat langkah-langkah yang dilakukan hingga data ditemukan atau tidak ditemukan.


### 2. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu: Membuat linked list dengan menambahkan node di akhir, Mengimplementasikan linear search pada linked list, Menampilkan detail proses pencarian dan hasil akhir

```C++
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    cout << "Linked List: ";
    while (current) {
        cout << current->data;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int node_ke = 1;
    
    cout << "\nProses Pencarian:" << endl;

    while (current != nullptr) {
        cout << "Memeriksa node " << node_ke++ << ": " << current->data;
        
        if (current->data == key) {
            cout << " (SAMA)" << endl;
            cout << "DITEMUKAN!" << endl;
            return current;
        } else {
            cout << " (tidak sama)" << endl;
        }
        current = current->next;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    return nullptr;
}

void runTugas2() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    displayList(head);

    int key1 = 30;
    cout << "Mencari nilai: " << key1 << endl;
    Node* result1 = linearSearch(head, key1);

    cout << "\nHasil: Nilai " << key1;
    if (result1) {
        cout << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << result1 << endl;
        cout << "Data node: " << result1->data << endl;
        cout << "Node berikutnya: " << (result1->next ? to_string(result1->next->data) : "NULL") << endl;
    } else {
        cout << " TIDAK DITEMUKAN dalam linked list" << endl;
    }

    cout << "\n==============================\n" << endl;

    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    Node* result2 = linearSearch(head, key2);

    cout << "\nHasil: Nilai " << key2;
    if (result2) {
        cout << " DITEMUKAN pada linked list" << endl;
        cout << "Alamat node: " << result2 << endl;
        cout << "Data node: " << result2->data << endl;
        cout << "Node berikutnya: " << (result2->next ? to_string(result2->next->data) : "NULL") << endl;
    } else {
        cout << " TIDAK DITEMUKAN dalam linked list" << endl;
    }
}

int main() {
     runTugas2();
     return 0;
 }
```

### Output Unguided 2 :
![Output Unguided2](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan5/Output%20Unguided2.png)

Pada unguided 2 ini merupakan implementasi pencarian linear (linear search) pada struktur data singly linked list. Sama seperti sebelumnya, data ditambahkan menggunakan fungsi append() dan ditampilkan dengan displayList(). Pencarian dilakukan dengan fungsi linearSearch(), yang memeriksa setiap node satu per satu dari awal hingga akhir list. Setiap langkah pencarian ditampilkan di layar, termasuk node yang sedang diperiksa dan hasil perbandingannya. Jika data ditemukan, program akan menampilkan informasi detail node tersebut; jika tidak, program menampilkan pesan bahwa data tidak ditemukan. Program ini menunjukkan bahwa pencarian linear lebih sederhana namun membutuhkan waktu lebih lama untuk dataset yang besar.

## Kesimpulan
Dari praktikum ini, praktikum ini membahas cara kerja singly linked list dalam mengelola data secara dinamis menggunakan pointer. Berbagai fungsi yang digunakan, seperti createList() untuk membuat list baru, insertFirst(), insertLast(), dan insertAfter() untuk menambahkan data, serta delFirst(), delLast(), dan delAfter() untuk menghapus data, membantu menunjukkan bagaimana setiap operasi bekerja saling terhubung antar node. Fungsi seperti printList() juga digunakan untuk menampilkan isi list, sementara updateFirst(), updateLast(), dan updateAfter() digunakan untuk memperbarui data tertentu. Selain itu, penerapan pencarian linear dan pencarian biner memperlihatkan perbedaan metode dalam menemukan data di dalam list. Secara keseluruhan, praktikum ini memberikan pemahaman yang jelas tentang bagaimana linked list dapat digunakan untuk mengelola data dengan lebih fleksibel dan efisien dibandingkan struktur data statis seperti array.

## Referensi
[1] Setiyawan. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, Vol. 5, No. 2, 486-487. 
Diakses dari https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263/pdf
<br>[2] Akbar, A. F. (2024, September 03). Memahami konsep dan jenis-jenis linked list dalam struktur data. Program Vokasi Universitas Negeri Surabaya. https://terapan-ti.vokasi.unesa.ac.id/post/memahami-konsep-dan-jenis-jenis-linked-list-dalam-struktur-data
<br>[3] Situmorang, H. (2018). Analisa algoritma pada metoda pencarian linier, biner dan interpolasi. Jurnal Mahajana Informasi, 2(2), 31–41. https://doi.org/10.51544/jurnalmi.v2i2.177