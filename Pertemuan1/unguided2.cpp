#include <iostream>
#include <string>
using namespace std;

string satuan(int n) {
    string arr[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    return arr[n];
}

string puluhan(int n) {
    if (n < 10) return satuan(n);
    else if (n == 10) return "sepuluh";
    else if (n == 11) return "sebelas";
    else if (n < 20) return satuan(n % 10) + " belas";
    else {
        int p = n / 10;
        int s = n % 10;
        string res = satuan(p) + " puluh";
        if (s != 0) res += " " + satuan(s);
        return res;
    }
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Masukkan angka harus antara 0 sampai 100!" << endl;
        return 1;
    }

    if (angka == 100) {
        cout << "seratus" << endl;
    } else {
        cout << puluhan(angka) << endl;
    }

    return 0;
}
