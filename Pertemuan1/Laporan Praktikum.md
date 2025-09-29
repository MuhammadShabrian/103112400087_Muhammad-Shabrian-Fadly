# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Shabrian Fadky - 103112400087</p>

## Dasar Teori
Data merupakan suatu fakta-fakta tertentu sehingga menghasilkan kesimpulan dalam menarik suatu kesimpulan. Data adalah representasi dari fakta dunia nyata yang disimpan, direkam, direpresentasikan tidak hanya dalam bentuk teks tetapi juga dalam bentuk suara, sinyal maupun simbol.

Struktur data adalah merepresentasikan data pada memory secara logika dan setiap variabel di dalam program dikarakterisasikan secara eksplisit atau implisit. Sebagai dasar teknik dari database, Struktur data diperlukan dalam perencanaan algoritma dan penyusunan program[1].

Struktur data membantu memahami hubungan antara data dan memungkinkan untuk mencari dan memanipulasi data dengan lebih efisien sesuai dengan kebutuhan aplikasi yang diimplementasikan. Dengan menggunakan struktur data yang tepat, programer dapat mengoptimalkan kinerja aplikasi dan mengatasi kompleksitas data yang tinggi.


## Guided 

### 1. ...

```C++
#include<iostream>
using namespace std;
int main(){
    int angka;
    cout << "masukkan angka: ";
    cin >> angka;
    cout<<"angka yang dimasukkan" << angka <<endl;
    return 0;
}
```
Program C++ ini digunakan untuk menampilkan teks

### 2. ...

```C++
#include<iostream>
using namespace std;
int main(){
    int angka1, angka2;
    cout<<"masukkan angka1: ";
    cin>> angka1;
    cout<< "masukkan angka2: ";
    cin>> angka2;

    cout<<"penjumlahan = "<< angka1 + angka2 <<endl;
    cout<<"pengurangan = "<< angka1 - angka2 <<endl;
    cout<<"perkalian = "<< angka1 * angka2 <<endl;
    cout<<"pembagian = "<< angka1 / angka2 <<endl;
    cout<< "sisa bagi: "<< angka1 % angka2 <<endl;
    return 0;
}
```
Program C++ ini digunakan untuk melakukan perhitungan dasar
### 3. ...

```C++
#include<iostream>
using namespace std;
int main(){
    int angka1, angka2 ;
    cout<<"masukkan angka 1:";
    cin>>angka1;
    cout<<"masukkan angka 2: ";
    cin >> angka2;

    if (angka1 < angka2){
        cout<< angka1 <<"kurang dari " << angka2 <<endl;
    }
    else {
        cout << angka1 << " lebih dari" << angka2 <<endl;

    }
    if (angka1 == angka2){
        cout<< angka1 << " sama dengan " << angka2 <<endl;
    }
    else if (angka1 != angka2){
        cout<< angka1 << " angka berbeda " << angka2 <<endl;
    }

    int pilihan;
    cout << "menu" << endl;
    cout << "1. penjumlahan"<< endl;
    cout << "2. pengurangan"<< endl;
    cout << "masukkan pilihan: ";
    cin >> pilihan;
    switch (pilihan) {
    case 1:
    cout << "penjumlahan" << angka1 + angka2 << endl;
    cout << endl;
    break;
    case 2: 
    cout <<"pengurangan : " << angka1 - angka2 << endl;
    cout << endl;
    break;
    default:
    cout << "pilihan salah" << endl;
    return 0;
}
}
```
Program C++ ini digunakan untuk melakukan percabangan dengan if-else dan switch case

### 4. ...

```C++
#include<iostream>
using namespace std;
int main(){
    int angka1;
    cout<< "masukkan angka 1 : ";
    cin>> angka1;
    
    for (int i = 0; i <= angka1; i++){
        cout<< i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1)
    {
     cout << j << " - ";
     j--;
    }
    cout << endl;

    int k = 10;
    do
    {
        cout << k << " - ";
    } while (k < angka1);
    
    return 0;
}

```
Program C++ ini digunakan untuk melakukan perulangan

### 5. ...

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 3;
struct rapot {
    string nama;
    float nilai;
    
};

rapot siswa [MAX];
for (int i = 0; i < MAX; i++){
    cout << "masukkan nama siswa: ";
    cin >> siswa[i].nama;
    cout << "masukkan nilai siswa: ";
    cin >> siswa[i].nilai;
    cout << endl;
}
int j = 0;
while (j < MAX)
{
    cout << "nama siswa : " << siswa[j].nama <<", nilai : " << siswa[j].nilai << endl;
    j++; 
}
return 0; 
}

```
Program ini berfungsi untuk menerima input nama dan nilai dari 3 siswa, lalu menampilkan kembali data tersebut ke layar menggunakan struktur data struct dan array.


## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
#include<iostream>
using namespace std;

int main(){
    float angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2: ";
    cin >> angka2;

    cout<<"penjumlahan = "<< angka1 + angka2 <<endl;
    cout<<"pengurangan = "<< angka1 - angka2 <<endl;
    cout<<"perkalian = "<< angka1 * angka2 <<endl;
    cout<<"pembagian = "<< angka1 / angka2 <<endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
Pertemuan1/Output Guided1.png

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
