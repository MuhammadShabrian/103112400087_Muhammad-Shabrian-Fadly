#include "stack.h"

void runSoalA3(StackMahasiswa &StackMhs) {
    cout << "\n===============  Eksekusi Soal Nomor 3 Bagian A ==============\n";

    createStack(StackMhs);
    cout << "1) Stack kosong telah dibuat.\n";

    Mahasiswa mhs[6];
    mhs[0] = {"11111", "Venti", 75.7, 95.5, 81.9};
    mhs[1] = {"22222", "Xiao", 87.4, 88.8, 82.4};
    mhs[2] = {"33333", "Kazuha", 92.3, 88.8, 82.4};
    mhs[3] = {"44444", "Wanderer", 95.5, 86.5, 93.6};
    mhs[4] = {"55555", "Lynette", 77.7, 65.4, 79.4};
    mhs[5] = {"66666", "Chasca", 99.9, 93.6, 87.3};

    for (int i = 0; i < 6; i++) {
        push(StackMhs, mhs[i]);
    }

    view(StackMhs);

    Mahasiswa mhsPop;
    pop(StackMhs, mhsPop);
    cout << "   -> Mahasiswa yang di-pop: " << mhsPop.Nama << endl;
    view(StackMhs);
    Mahasiswa mhsUpdate = {"77777", "Shenzou", 99.9, 88.8, 77.7};
    update(StackMhs, 3, mhsUpdate); 
    hitungNilaiAkhir(StackMhs);    
    view(StackMhs);
    cout << "\n--- Hasil Searching NilaiAkhir 85.5 sampai 95.5 ---\n";
    viewMaxNilaiAkhir(StackMhs, 85.5, 95.5);
    cout << "\n==============  Eksekusi Soal Nomor 3 Bagian A Selesai ==============\n";
}

void runSoalB3(StackMahasiswa &StackMhs) {
    cout << "\n===============  Eksekusi Soal Nomor 3 Bagian B ==============\n";
    cout << "Melakukan pemanggilan prosedur hitungNilaiAkhir().\n";
    hitungNilaiAkhir(StackMhs);
    view(StackMhs);
    cout << "\n============== Eksekusi Soal Nomor 3 Bagian B Selesai ==============\n";
}


int main() {
    StackMahasiswa StackMhs;
    
    runSoalA3(StackMhs);
    runSoalB3(StackMhs);

    return 0;
}

