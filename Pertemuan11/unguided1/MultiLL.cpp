#include "MultiLL.h"
#include <iomanip>

bool isEmptyParent(listParent &LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild &LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent newNode = new nodeParent;
    newNode->isidata.idGolongan = idGol;
    newNode->isidata.namaGolongan = namaGol;
    newNode->next = NULL;
    newNode->prev = NULL;
    createListChild(newNode->L_Child);
    return newNode;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild newNode = new nodeChild;
    newNode->isidata.idHewan = idHwn;
    newNode->isidata.namaHewan = namaHwn;
    newNode->isidata.habitat = habitat;
    newNode->isidata.ekor = tail;
    newNode->isidata.bobot = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void printMLLStructure(listParent &LParent) {
    NodeParent currentParent = LParent.first;
    int parentCount = 1;
    
    while (currentParent != NULL) {
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Golongan : " << currentParent->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << currentParent->isidata.namaGolongan << endl;
        
        if (isEmptyChild(currentParent->L_Child)) {
            cout << "(tidak ada child)" << endl;
        } else {
            NodeChild currentChild = currentParent->L_Child.first;
            int childCount = 1;
            
            while (currentChild != NULL) {
                cout << "- Child " << childCount << " :" << endl;
                cout << "    ID Hewan : " << currentChild->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << currentChild->isidata.namaHewan << endl;
                cout << "    Habitat : " << currentChild->isidata.habitat << endl;
                cout << "    Ekor : " << (currentChild->isidata.ekor ? "1" : "0") << endl;
                cout << fixed << setprecision(1);
                cout << "    Bobot : " << currentChild->isidata.bobot << endl;
                
                currentChild = currentChild->next;
                childCount++;
            }
        }
        
        cout << endl;
        currentParent = currentParent->next;
        parentCount++;
    }
}