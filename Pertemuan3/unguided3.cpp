#include <iostream>
using namespace std;

const int N = 3;

void tampilArray(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void tukarArrayPosisi(int a[N][N], int b[N][N], int x, int y) {
    int temp = a[x][y];
    a[x][y] = b[x][y];
    b[x][y] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[N][N] = { {1,2,3},{4,5,6},{7,8,9} };
    int B[N][N] = { {9,8,7},{6,5,4},{3,2,1} };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "Array B sebelum ditukar:\n";
    tampilArray(B);

    tukarArrayPosisi(A, B, 1, 1);

    cout << "\nSetelah pertukaran posisi (1,1):\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "Array B:\n";
    tampilArray(B);

    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;
    cout << "\nSebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(p1, p2);
    cout << "Setelah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}
