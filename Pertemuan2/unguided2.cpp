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
