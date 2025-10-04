#include<iostream>
using namespace std;

int main(){
    int arr [5];

    for (int i = 0; i < 5; i++)
    {
     cout << "masukkan nilai indeks ke-" << i << " : "; 
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