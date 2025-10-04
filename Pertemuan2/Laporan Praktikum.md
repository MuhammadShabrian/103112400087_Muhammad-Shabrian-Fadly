# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Muhammad Shabrian Fadky - 103112400087</p>

## Dasar Teori
Data merupakan suatu fakta-fakta tertentu sehingga menghasilkan kesimpulan dalam menarik suatu kesimpulan. Data adalah representasi dari fakta dunia nyata yang disimpan, direkam, direpresentasikan tidak hanya dalam bentuk teks tetapi juga dalam bentuk suara, sinyal maupun simbol.

Struktur data adalah merepresentasikan data pada memory secara logika dan setiap variabel di dalam program dikarakterisasikan secara eksplisit atau implisit. Sebagai dasar teknik dari database, Struktur data diperlukan dalam perencanaan algoritma dan penyusunan program[1].

Struktur data membantu memahami hubungan antara data dan memungkinkan untuk mencari dan memanipulasi data dengan lebih efisien sesuai dengan kebutuhan aplikasi yang diimplementasikan. Dengan menggunakan struktur data yang tepat, programer dapat mengoptimalkan kinerja aplikasi dan mengatasi kompleksitas data yang tinggi.

Array
Array merupakan sebuah variabel yang menyimpan sekumpulan data yang memiliki tipe sama atau Array juga dapat disebut sebagai kumpulan dari nilai-nilai data bertipe sama dalam urutan tertentu yang memakai sebuah nama yang sama. Setiap data tersebut menempati alamat memori atau lokasi yang berbeda-beda dan selanjutnya disebut dengan elemen array. Elemen array sendiri dapat diakses melalui indeks yang terdapat di dalamnya.

Array Multidimensi
Array Multidimensi merupakan array yang serupa dengan array satu dimensi maupun array dua dimensi, namun array multidimensi dapat memiliki memori yang lebih besar. Biasanya array multidimensi digunakan untuk menyebut array dengan dimensi lebih dari dua atau array yang mempunyai lebih dari dua subskrip, seperti untuk menyebut array tiga dimensi, empat dimensi, lima dimensi dan seterusnya.

Pointer
pointer adalah variabel yang menyimpan alamat memori dari suatu nilai atau objek. Ini memungkinkan kita untuk mengakses dan memanipulasi nilai atau objek tersebut dengan cara yang lebih efisien dan fleksibel.

Fungsi dan Prosedur
Fungsi merupakan suatu program terpisah dalam blok sendiri yang berfungsi sebagai subprogram (program bagian). Sama seperti halnya dengan prosedur, namun tetap ada perbedaannya yaitu fungsi mempunyai pengembalian nilai / mengembalikan sebuah nilai (memiliki return value) dari tipe tertentu (tipe dasar atau tipe bentukan). Prosedur merupakan suatu program terpisah dalam blok sendiri yang berfungsi sebagai subprogram (program bagian). Prosedur biasanya bersifat suatu aktifitas seperti mencari bilangan prima dari sekumpulan bilangan atau mencari bilangan genap dari sekumpulan bilangan ,dsb.

## Guided 

### 1.

```C++
#include<iostream>
using namespace std;

int main(){
    int arr [5];

    for (int i = 0; i < 5; i++)
    {
     cout << "masukkan vakeu indeks ke-" << i << " : "; 
     cin >> arr[i];
    }
    int j = 0;
    while (j < 5)
    {
     cout << " isi indeks ke-" << j << " - " << arr[j] << endl;
     j++;
    }
    cout << endl;
    
    return 0;
} 
```
Program C++ ini meminta input dari pengguna untuk mengisi nilai-nilai pada array, lalu menampilkan kembali semua isi array menggunakan perulangan for dan while.

### 2.

```C++
#include<iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}
int main() {
    int arrA[2][2] ={ {1, 2}, {3, 4}
    };
    int arrB [2][2] = { {2, 3}, {4, 5}
    };
    int arrC [2][2] =  {0};
    int arrD [2][2] =  {0};
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
        
    }
    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
            
            
        }
        
    }
    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program C++ ini melakukan operasi penjumlahan dan perkalian dua matriks 2x2, kemudian menampilkan hasilnya dengan menggunakan fungsi tampilkanHasil.
### 3.

```C++
#include<iostream>
using namespace std;

int main(){
    int arr []={10,20,30,40,50};
    int* ptr = arr;
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Elemen array ke-" << i+1 << " menggunakan pointer " << *(ptr+i) << endl;
    }
    for (int i = 0; i < 5; i++)
{
    cout << "Elemen array ke-" << i+1 << " menggunakan indeks: " << arr[i] << endl;
}
return 0;
}

```
Program C++ ini menampilkan elemen-elemen array dengan dua cara, yaitu menggunakan pointer dan menggunakan indeks array secara langsung.

### 4.

```C++
#include<iostream>
using namespace std;

int cariMAX (int arr[], int ukuran) {
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmetika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumlah = " << totalJumlah << endl;
    
    int totalKali = 1;
    for (int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "total perkalian = " << totalKali << endl;
}

int main (){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++)
    {
        cout << "masukkan nilai array ke-" << i << " : "; 
        cin >> arr[i];
    }
    cout <<endl;

    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;
    operasiAritmetika(arr, ukuran);
    
}

```
Program C++ ini mencari nilai terbesar dalam array serta menghitung total penjumlahan dan perkalian seluruh elemen array menggunakan fungsi terpisah.



## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case


```C++
#include <iostream>
using namespace std;

const int N = 3;

void tampilMatriks(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void kurangMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] - B[i][j];
}


void kaliMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int matriksA[N][N] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int matriksB[N][N] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int hasil[N][N];
    int pilihan;

    do {
        cout << "\n Pilih program \n";
        cout << "1. Penjumlahan Matriks\n";
        cout << "2. Pengurangan Matriks\n";
        cout << "3. Perkalian Matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil Penjumlahan Matriks:\n";
                tampilMatriks(hasil);
                break;
            case 2:
                kurangMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil Pengurangan Matriks:\n";
                tampilMatriks(hasil);
                break;
            case 3:
                kaliMatriks(matriksA, matriksB, hasil);
                cout << "\nHasil Perkalian Matriks:\n";
                tampilMatriks(hasil);
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}

```

### Output Unguided 1 :
![Output Unguided1](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan2/Output%20Unguided1.png)

Program C++ ini menampilkan menu untuk melakukan operasi penjumlahan, pengurangan, dan perkalian dua matriks 3x3 menggunakan prosedur berbeda untuk setiap operasi.

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut:1. Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan luas (beri nilai 0). 2. Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar yang menunjuk ke variabel lebar. 3.Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar. 4. Cetak nilai luas ke layar. 5. Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui pointer ptrPanjang dan ptrLebar. 6. Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa nilainya telah berubah.

```C++
#include <iostream>
using namespace std;

int main() {
    int panjang = 10, lebar = 5, luas = 0;
    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    luas = (*ptrPanjang) * (*ptrLebar);
    cout << "Luas persegi panjang = " << luas << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    cout << "\nNilai setelah diubah melalui pointer:\n";
    cout << "Panjang = " << panjang << endl;
    cout << "Lebar   = " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    int keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\nLuas baru = " << luas << endl;
    cout << "Keliling  = " << keliling << endl;

    return 0;
}
 
```
### Output Unguided 2 :
![Output Unguided2](https://github.com/MuhammadShabrian/103112400087_Muhammad-Shabrian-Fadly/blob/main/Pertemuan2/Output%20Unguided2.png)

Program C++ ini menghitung luas dan keliling persegi panjang menggunakan pointer untuk mengakses dan mengubah nilai variabel panjang dan lebar.


## Kesimpulan
Dari praktikum ini, dapat dipahami bahwa penggunaan array, pointer, fungsi, dan prosedur berperan penting dalam membuat program yang efisien dan terstruktur. Pemahaman terhadap konsep tersebut membantu menyusun logika program dengan cara yang lebih jelas dan mudah dipahami, sehingga proses pengolahan data bisa berjalan lancar. Penerapan konsep struktur data dalam bahasa C++ juga menunjukkan bagaimana data dapat diatur dan dimanfaatkan dengan efektif untuk menghasilkan program yang rapi dan fungsional.

## Referensi
[1] Saragih, R. A., Surya, Syahrozi, H., Gunawan, I., & Sembiring, H. (2023). Data dan Struktur Data dalam Perancangan Algoritma Efisien. Jurnal Komputer dan Informatika STIKOM Tunas Bangsa, 5(1), 1-2. 
https://www.scribd.com/document/511818478/Jurnal-Struktur-Data
<br>[2] Naraindyah, R.A.(2024), Struktur Data: Pengertian, Fungsi, dan Penerapannya
https://terapan-ti.vokasi.unesa.ac.id/post/struktur-data-pengertian-fungsi-dan-penerapannya
<br>[3] MateriDosen. 2017. "Array Multidimensi Dimensi C++, Lengkap Contoh Program dan Penjelasan". https://www.materidosen.com/2017/06/array-multidimensi-dimensi-c-lengkap.html.
<br>[4] Patria, Ratna. 2024. "Pointer adalah: Mengupas Tuntas Pointer dalam Bahasa Pemrograman C++". DomaiNesia. https://www.domainesia.com/berita/pointer-adalah/#Pengertian_Pointer_adalah.
<br>[5] MateriDosen. 2017. "Perbedaan Fungsi dan Prosedur dalam Bahasa C & C++". https://www.materidosen.com/2017/01/perbedaan-fungsi-dan-prosedur-dalam.html.

