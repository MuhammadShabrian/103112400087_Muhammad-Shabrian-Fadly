#include "Stack.h"


void createStack(StackMahasiswa &StackMhs) {
    StackMhs.Top = -1;
}

bool isEmpty(StackMahasiswa StackMhs) {
    return StackMhs.Top == -1;
}

bool isFull(StackMahasiswa StackMhs) {
    return StackMhs.Top == MAX - 1;
}

void push(StackMahasiswa &StackMhs, Mahasiswa mhsBaru) {
    if (isFull(StackMhs)) {
        cout << "\n Gagal: Stack penuh! Tidak bisa push data baru.\n";
    } else {
        StackMhs.Top++;
        StackMhs.dataMhs[StackMhs.Top] = mhsBaru;
        cout << "\n Berhasil: Data Mahasiswa " << mhsBaru.Nama << " telah di-push.\n";
    }
}

void pop(StackMahasiswa &StackMhs, Mahasiswa &mhsKeluar) {
    if (isEmpty(StackMhs)) {
        cout << "\n Gagal: Stack kosong! Tidak bisa pop data.\n";
        mhsKeluar.NIM = ""; 
    } else {
        mhsKeluar = StackMhs.dataMhs[StackMhs.Top];
        StackMhs.Top--;
        cout << "\n Berhasil: Data Mahasiswa " << mhsKeluar.Nama << " telah di-pop.\n";
    }
}

void peek(StackMahasiswa StackMhs, Mahasiswa &mhsTeratas) {
    if (isEmpty(StackMhs)) {
        cout << "\n Gagal: Stack kosong! Tidak ada data untuk di-peek.\n";
        mhsTeratas.NIM = "";
    } else {
        mhsTeratas = StackMhs.dataMhs[StackMhs.Top];
        cout << "\n Data teratas (Peek):\n";
        cout << "   Nama: " << mhsTeratas.Nama << endl;
        cout << "   NIM: " << mhsTeratas.NIM << endl;
        if (mhsTeratas.NilaiAkhir > 0) {
            cout << "   NilaiAkhir: " << fixed << setprecision(2) << mhsTeratas.NilaiAkhir << endl;
        }
    }
}

void update(StackMahasiswa &StackMhs, int posisi, Mahasiswa mhsUpdate) {
    if (posisi < 1 || posisi > MAX) {
        cout << "\n Gagal: Posisi update tidak valid (1-" << MAX << ").\n";
        return;
    }
    
    int index = StackMhs.Top - (posisi - 1); 

    if (index >= 0 && index <= StackMhs.Top) {
        StackMhs.dataMhs[index] = mhsUpdate;
        cout << "\n Berhasil: Data Mahasiswa pada posisi " << posisi 
             << " (Nama: " << mhsUpdate.Nama << ") telah diupdate.\n";
    } else {
        cout << "\n Gagal: Posisi " << posisi << " melebihi jumlah elemen saat ini (" << StackMhs.Top + 1 << ").\n";
    }
}

void hitungNilaiAkhir(StackMahasiswa &StackMhs) {
    for (int i = 0; i <= StackMhs.Top; i++) {
        StackMhs.dataMhs[i].NilaiAkhir = 
            (0.20 * StackMhs.dataMhs[i].NilaiUTS) +
            (0.40 * StackMhs.dataMhs[i].NilaiTugas) +
            (0.40 * StackMhs.dataMhs[i].NilaiUAS);
    }
    cout << "\n Semua NilaiAkhir Mahasiswa telah dihitung.\n";
}

void view(StackMahasiswa StackMhs) {
    cout << "\n==============  Data Mahasiswa di Stack ==============\n";
    if (isEmpty(StackMhs)) {
        cout << "Stack kosong.\n";
        cout << "=======================================================\n";
        return;
    }
    
    cout << setw(5) << left << "No"
         << setw(10) << left << "NIM"
         << setw(15) << left << "Nama"
         << setw(8) << left << "UTS"
         << setw(8) << left << "Tugas"
         << setw(8) << left << "UAS"
         << setw(12) << left << "NilaiAkhir"
         << endl;
    cout << "------------------------------------------------------------------\n";

    for (int i = StackMhs.Top; i >= 0; i--) {
        Mahasiswa mhs = StackMhs.dataMhs[i];
        cout << setw(5) << left << (StackMhs.Top - i + 1)
             << setw(10) << left << mhs.NIM
             << setw(15) << left << mhs.Nama
             << setw(8) << left << fixed << setprecision(1) << mhs.NilaiUTS
             << setw(8) << left << fixed << setprecision(1) << mhs.NilaiTugas
             << setw(8) << left << fixed << setprecision(1) << mhs.NilaiUAS
             << setw(12) << left << fixed << setprecision(2) << mhs.NilaiAkhir
             << endl;
    }
    cout << "=======================================================\n";
}

void viewMaxNilaiAkhir(StackMahasiswa StackMhs, float NilaiAkhirMin, float NilaiAkhirMax) {
    cout << "\n=========  Mahasiswa NilaiAkhir " << fixed << setprecision(1) << NilaiAkhirMin 
         << " - " << NilaiAkhirMax << " =========\n";
    
    if (isEmpty(StackMhs)) {
        cout << "Stack kosong.\n";
        cout << "=======================================================\n";
        return;
    }

    bool found = false;
    for (int i = StackMhs.Top; i >= 0; i--) {
        Mahasiswa mhs = StackMhs.dataMhs[i];
        if (mhs.NilaiAkhir >= NilaiAkhirMin && mhs.NilaiAkhir <= NilaiAkhirMax) {
            found = true;
            cout << "No: " << (StackMhs.Top - i + 1)
                 << ", Nama: " << mhs.Nama
                 << ", NilaiAkhir: " << fixed << setprecision(2) << mhs.NilaiAkhir
                 << " (Posisi ke-" << (StackMhs.Top - i + 1) << " dari atas)\n";
        }
    }

    if (!found) {
        cout << "Tidak ditemukan Mahasiswa dengan NilaiAkhir dalam rentang tersebut.\n";
    }
    cout << "=======================================================\n";
}
