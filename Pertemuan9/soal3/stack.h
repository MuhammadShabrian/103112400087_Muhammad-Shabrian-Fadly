#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 6; 

struct Mahasiswa {
    string NIM;
    string Nama;
    float NilaiUTS;
    float NilaiTugas;
    float NilaiUAS;
    float NilaiAkhir;
};

struct StackMahasiswa {
    Mahasiswa dataMhs[MAX];
    int Top;
};

void createStack(StackMahasiswa &StackMhs);
bool isEmpty(StackMahasiswa StackMhs);
bool isFull(StackMahasiswa StackMhs);
void push(StackMahasiswa &StackMhs, Mahasiswa mhsBaru);
void pop(StackMahasiswa &StackMhs, Mahasiswa &mhsKeluar);
void peek(StackMahasiswa StackMhs, Mahasiswa &mhsTeratas);
void update(StackMahasiswa &StackMhs, int posisi, Mahasiswa mhsUpdate);
void hitungNilaiAkhir(StackMahasiswa &StackMhs);
void view(StackMahasiswa StackMhs);
void viewMaxNilaiAkhir(StackMahasiswa StackMhs, float NilaiAkhirMin, float NilaiAkhirMax);

#endif