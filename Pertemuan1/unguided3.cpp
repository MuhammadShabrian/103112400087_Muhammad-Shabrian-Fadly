#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
    
        for (int s = 0; s < i * 2; s++) {
            cout << " ";
        }

        for (int dec = n - i; dec >= 1; dec--) {
            cout << dec << " ";
        }
        cout << "* ";

        for (int asc = 1; asc <= n - i; asc++) {
            cout << asc;
            if (asc != n - i) cout << " ";
        }

        cout << endl;
    }

    return 0;
}
