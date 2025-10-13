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