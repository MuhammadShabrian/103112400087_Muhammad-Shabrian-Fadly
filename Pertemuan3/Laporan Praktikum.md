# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT) </h1>
<p align="center">Muhammad Shabrian Fadly - 103112400087</p>

## Dasar Teori

Tipe Data Abstrak (ADT) adalah model konseptual yang mendefinisikan serangkaian operasi dan perilaku untuk suatu struktur data, tanpa menentukan bagaimana operasi tersebut diimplementasikan atau bagaimana data diorganisasikan dalam memori. Definisi ADT hanya menyebutkan operasi apa yang akan dilakukan, tetapi tidak menyebutkan bagaimana operasi tersebut akan diimplementasikan. Kata kunci "Abstrak" digunakan karena kita dapat menggunakan tipe data ini untuk melakukan berbagai operasi. ADT terdiri dari tipe data primitif, tetapi logika operasinya tersembunyi. Beberapa contoh ADT adalah Stack, Queue, List dll.

Linked list adalah suatu bentuk struktur data yang berupa sekumpulan elemen data yang bertipe sama dimana tiap elemen saling berkaita atau dihubungkan dengan elemen lain melalui suatu pointer ,Pointer adalah alamat elemen data yang tersimpan di memori. Mengacu elemen dengan pointer membuat elemen bersebelahan secara logik, meskipun Linked list menyimpan elemen di lokasi memori yang tidak teratur, dengan setiap elemen memiliki referensi ke elemen berikutnya.[487]

Array berdimensi 2 adalah suatu kumpulan data terstruktur yang terdiri dari dua dimensi atau dua indeks, yaitu baris dan kolom. Array berdimensi 2 dapat digunakan untuk menyimpan data yang terstruktur dalam bentuk matriks atau tabel. Deklarasi Array berdimensi 2 dilakukan dengan menentukan tipe data elemen yang disimpan, nama variabel Array, dan ukuran Array pada setiap dimensi.[486]


## Guided 

### 1.Guided 1

```C++
#include<iostream>

using namespace std;

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "input nim :";
    cin >> m.nim;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}

float rata2 (mahasiswa m){
    return (float)(m.nilai1 + m.nilai2) / 2;
}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout<<"nilai rata-rata = "<< rata2(mhs) << endl;
    system ("pause");
    return 0;
}
```

Program C++ ini meminta pengguna untuk menginput data mahasiswa berupa NIM dan dua nilai, lalu menghitung nilai rata-ratanya. Program ini memperkenalkan konsep struct sebagai bentuk dasar dari ADT (Abstract Data Type) yang menyimpan data dan fungsi secara terpisah tapi saling berhubungan.

## Unguided 

### 1. Buatlah program untuk menyimpan data mahasiswa dengan jumlah maksimum 10 data. Setiap mahasiswa memiliki atribut: Nama, NIM, Nilai UTS, Nilai UAS, Nilai Tugas. Hitung nilai akhir mahasiswa dengan rumus: nilai akhir = 0.3 * UTS + 0.4 * UAS + 0.3 * Tugas.

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << mhs[i].nama
             << " | NIM: " << mhs[i].nim
             << " | Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}

```
### Output Unguided 1 :
![Output Unguided1](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan3/Output%20Unguided1.png)

Program C++ ini menyimpan data maksimal 10 mahasiswa, termasuk nama, NIM, nilai UTS, UAS, dan tugas. Setelah data diinput, program menghitung nilai akhir tiap mahasiswa berdasarkan rumus tertentu dan menampilkannya. 

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h", Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp", Cobalah hasil implementasi ADT pada file "main.cpp"
```C++
//pelajaran.h
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(pelajaran pel);

#endif
 
```

```C++
//pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

```C++
//main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

![Output Unguided2](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan3/Output%20Unguided2.png)

Pada unguided2 ini, dibuat ADT pelajaran menggunakan tiga file terpisah: pelajaran.h, pelajaran.cpp, dan main.cpp. Tujuannya biar kode lebih rapi dan terstruktur. File header mendefinisikan bentuk datanya, file cpp berisi implementasi fungsinya, dan file main digunakan untuk menguji hasilnya.


### 3.Buatlah program dengan ketentuan: 2 buah array 2D integer berukuran 3×3 dan 2 buah pointer integer, fungsi/prosedur yang menampilkan isi sebuah array integer 2D, fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu, fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer



```C++
#include <iostream>
using namespace std;

const int N = 3;

void tampilArray(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void tukarArrayPosisi(int a[N][N], int b[N][N], int x, int y) {
    int temp = a[x][y];
    a[x][y] = b[x][y];
    b[x][y] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[N][N] = { {1,2,3},{4,5,6},{7,8,9} };
    int B[N][N] = { {9,8,7},{6,5,4},{3,2,1} };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "Array B sebelum ditukar:\n";
    tampilArray(B);

    tukarArrayPosisi(A, B, 1, 1);

    cout << "\nSetelah pertukaran posisi (1,1):\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "Array B:\n";
    tampilArray(B);

    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;
    cout << "\nSebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(p1, p2);
    cout << "Setelah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}


```



### Output Unguided 3 :
![Output Unguided3](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan3/Output%20Unguided3.png)

Program ini menggunakan dua array 2D berukuran 3x3 dan dua pointer. Program bisa menampilkan isi array, menukar elemen pada posisi tertentu antara dua array, serta menukar nilai yang ditunjuk oleh dua pointer

## Kesimpulan
Dari praktikum ini, menunjukkan bahwa penerapan Abstract Data Type (ADT) membuat program lebih teratur dan mudah dipahami. Dengan memisahkan antara data dan proses pengolahannya, struktur program menjadi lebih rapi dan efisien. Penggunaan struct, pointer, dan array memperjelas bagaimana data saling terhubung dan dapat diolah dengan lebih fleksibel. Secara keseluruhan, konsep ADT membantu membangun program yang terstruktur, jelas, dan mudah dikembangkan.

## Referensi
[1] Setiyawan. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH : Journal Education and Technology, Vol. 5, No. 2, 486-487. 
Diakses dari https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263/pdf
<br>[2] GeeksforGeeks. (2025, 28 Maret). Abstract Data Types. 
Diakses dari https://www.geeksforgeeks.org/dsa/abstract-data-types/
<br>[3]TutorialsPoint. (2023, 5 Oktober). Abstract Data Type in Data Structures. 
Diakses dari https://www.tutorialspoint.com/abstract-data-type-in-data-structures
