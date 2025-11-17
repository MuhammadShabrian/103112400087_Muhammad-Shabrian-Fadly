# <h1 align="center">Laporan Praktikum Modul 7 - STACK </h1>
<p align="center">Muhammad Shabrian Fadly - 103112400087</p>

## Dasar Teori

Stack adalah kumpulan elemen yang hanya dapat ditambah dan atau dihapus dari satu ujung (gerbang) yang sama, seolah-olah bertumpuk. Stack mempunyai sifat LIFO (Last In First Out) yang berarti elemen terakhir masuk akan pertama keluar yang direpresentasikan menggunakan Linked List dan array yang disajikan Single Stack atau Double Stack[2357].
Stack sering digunakan dalam berbagai konteks pemrograman. Misalnya pada saat panggilan fungsi (call stack) dan rekursi, setiap pemanggilan fungsi disimpan dalam stack hingga fungsi tersebut selesai dieksekusi. Contoh lain adalah undo/redo di aplikasi, evaluasi ekspresi matematika, serta pengecekan kesetaraan tanda kurung. Semua kasus ini memanfaatkan sifat LIFO stack agar data terkelola dengan teratur.

Berikut operasi dasar yang biasa diterapkan pada stack:
Push: Menambahkan elemen baru ke bagian atas stack. Misalnya, menumpuk buku baru di atas tumpukan.
Pop: Menghapus elemen di puncak stack dan mengembalikan nilainya. Artinya, buku yang paling atas diambil keluar.
Peek/Top: Melihat (mengintip) elemen teratas tanpa menghapusnya. Seperti mengintip buku paling atas tanpa mengambilnya.
IsEmpty: Memeriksa apakah stack kosong atau tidak. Cocok seperti mengecek apakah masih ada piring di tumpukan.
Size: Mengembalikan jumlah elemen dalam stack. Berguna untuk mengetahui seberapa tinggi tumpukan saat ini.


## Guided 

### 1.Guided 1

```C++
//stack.h
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi (address &node);
void push (stack &listStack, address nodeBaru);
void pop (stack &listStack);
void update (stack &listStack, int posisi);
void view (stack listStack);
void searchData (stack listStack, int data);
#endif


```
```C++
//stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

```C++
//main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;
 
    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}

```
 
 Program Guided 1 menunjukkan cara kerja stack menggunakan linked list. Setiap data disimpan dalam node yang saling terhubung, dan operasi seperti push, pop, update, search, serta view menggambarkan bagaimana elemen ditambah, dihapus, dan dicari dari tumpukan. Implementasi ini menegaskan bahwa stack berbasis pointer bersifat fleksibel karena ukurannya dapat bertambah sesuai kebutuhan tanpa dibatasi kapasitas tetap.

### 2.Guided 2
```C++
//stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack
{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push (Stack &S, infotype x);
infotype pop (Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);


#endif
```

```C++
//stack.cpp
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
```C++
//main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}

```
Program Guided 2 memperlihatkan implementasi stack menggunakan array. Metode ini lebih sederhana dan cepat karena akses dilakukan langsung melalui indeks. Namun, kapasitasnya terbatas sesuai ukuran array. Fitur tambahan balikStack memperlihatkan proses pembalikan elemen dengan menggunakan beberapa stack bantuan. Secara keseluruhan, program ini menjelaskan cara kerja stack berbasis array yang lebih terstruktur dan mudah dipahami.


## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”: ,Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”
```C++
//stack.h
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX_STACK = 20;

typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif


```

```C++
//stack.cpp
#include <iostream>
#include "stack.h"
using namespace std;

bool isFull(Stack S) {
    return S.top == MAX_STACK - 1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        int x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "[Stack kosong]" << endl;
        return;
    }
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }

    S = temp;
}

```

```C++
//main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}

```



### Output Unguided 1 :
![Output Unguided1](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan7/Output%20Unguided1.png)

Program Unguided 1 memberikan contoh implementasi ADT Stack menggunakan array lengkap dengan fungsi dasar seperti push, pop, printInfo, dan balikStack. Program ini memperkuat pemahaman mengenai mekanisme penyimpanan data secara LIFO (Last In First Out) serta menunjukkan bagaimana elemen dapat dikelola menggunakan struktur tumpukan dengan kapasitas tertentu.


### 2. Tambahkan prosedur pushAscending ( in/out S : Stack, in x : integer)

```C++
//stack.h
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX_STACK = 20;

typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif


```

```C++
//stack.cpp
#include <iostream>
#include "stack.h"
using namespace std;

bool isFull(Stack S) {
    return S.top == MAX_STACK - 1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        int x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "[Stack kosong]" << endl;
        return;
    }
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}


```

```C++
//main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
Stack S;
createStack(S);
pushAscending(S,3);
pushAscending(S,4);
pushAscending(S,8);
pushAscending(S,2);
pushAscending(S,3);
pushAscending(S,9);
printInfo(S);
cout<<"balik stack"<<endl;
balikStack(S);
printInfo(S);
return 0;
}


```

### Output Unguided 2 :

![Output Unguided2](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan7/Output%20Unguided2.png)

Program Unguided 2 menambahkan fungsi pushAscending, yaitu penyisipan elemen ke dalam stack dengan tetap menjaga urutan nilai tertentu. Prosesnya memanfaatkan stack tambahan untuk menampung elemen sementara sebelum dikembalikan ke stack utama. Program ini menggambarkan bagaimana algoritma pengurutan dapat diterapkan pada struktur data stack meskipun stack hanya menyediakan akses dari bagian atas.

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

```C++
//stack.h
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX_STACK = 20;

typedef char infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif

```

```C++
//stack.cpp
#include <iostream>
#include "stack.h"
using namespace std;

bool isFull(Stack S) {
    return S.top == MAX_STACK - 1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        int x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "[Stack kosong]" << endl;
        return;
    }
    for (int i = 0; i <= S.top; i++) {
        cout << S.info[i];
    }
    cout << endl;
}



void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }

    S = temp;
}

void getInputStream(Stack &S) {
    cout << "Masukkan karakter (ENTER untuk berhenti): ";
    char c;

    while (true) {
        c = cin.get();
        if (c == '\n') {
            break;
        }
        push(S, c);
    }
}

```

```C++
//main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}


```

### Output Unguided 3 :

![Output Unguided3](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan7/Output%20Unguided3.png)

Program Unguided 3 menampilkan cara membaca input karakter satu per satu dan memasukkannya ke dalam stack hingga pengguna menekan Enter. Implementasi ini memperlihatkan bahwa stack tidak hanya digunakan untuk angka, tetapi juga dapat menangani karakter atau teks. Program ini sekaligus menunjukkan bagaimana stack dapat digunakan untuk membalik urutan input yang diterima.

## Kesimpulan
Dari praktikum ini, memberikan gambaran yang cukup jelas tentang bagaimana sebuah stack bekerja dan dipakai dalam pemrograman. Konsep dasarnya sederhana: data ditumpuk dari satu arah, dan yang terakhir masuk akan jadi yang pertama keluar. Meski kelihatannya sepele, cara kerja seperti ini ternyata sangat berguna di banyak situasi—mulai dari pengelolaan data, proses pemanggilan fungsi, sampai berbagai logika program yang butuh urutan terbalik. Melalui implementasi stack versi pointer dan versi array, terlihat perbedaan cara penyimpanan datanya. Pointer membuat stack lebih fleksibel karena bisa bertambah sesuai kebutuhan, sementara array memberi struktur yang tetap dan mudah diatur. Keduanya tetap mengikuti prinsip yang sama, hanya cara pengelolaannya saja yang berbeda.

## Referensi
[1] Alfahri, M. R., Hasibuan, N. L., Siagan, R. I. P., & Ramadhani, F. (2024). Sistem Pengelolaan Data Siswa Dinamis dengan Array dan Stack. Jurnal Nalar Teknologi dan Informatika (JNKT I), 7(6). https://doi.org/10.32672/jnkti.v7i6.8424
<br>[2] Prasatya. (2025, 4 Juni). Apa itu Stack dalam Ilmu Pemrograman. CodePolitan. https://www.codepolitan.com/blog/apa-itu-stack-dalam-ilmu-pemrograman/