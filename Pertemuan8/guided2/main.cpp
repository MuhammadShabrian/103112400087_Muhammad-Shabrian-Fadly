#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout <<"\n Enqueue 3 elemen"<<endl;
    enqueue (Q,5);
    printInfo (Q);
    enqueue (Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);

cout << "\n Dequeue 1 Elemen" << endl;
cout << "Elemen keluar: " << dequeue(Q) << endl;
printInfo(Q);

cout << "\n Enqueue 1 Elemen" << endl;
enqueue(Q, 4);
printInfo(Q);

cout << "\nDequeue 2 Elemen" << endl;
cout << "Elemen keluar: " << dequeue(Q) << endl;
cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

return 0;
};