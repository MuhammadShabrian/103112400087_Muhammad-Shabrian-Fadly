#include<iostream>
#include"mahasiswa.h"
#include<cstdlib>

using namespace std;
int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout<<"nilai rata-rata = "<< rata2(mhs) << endl;
    system ("pause");
    return 0;
}