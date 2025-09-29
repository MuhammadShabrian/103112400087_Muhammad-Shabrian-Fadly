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

