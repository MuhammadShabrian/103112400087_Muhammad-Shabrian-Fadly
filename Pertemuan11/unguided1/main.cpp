#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);
    
    cout << "=== SOAL 1: INSERT DATA DAN PRINT ===" << endl;
    cout << "======================================" << endl;
    
    insertLastParent(LParent, allocNodeParent("G001", "Aves"));
    insertLastParent(LParent, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LParent, allocNodeParent("G003", "Pisces"));
    insertLastParent(LParent, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LParent, allocNodeParent("G005", "Reptil"));
    
   
    NodeParent parentAves = LParent.first;
    insertLastChild(parentAves->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(parentAves->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));
    
    NodeParent parentMamalia = LParent.first->next;
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(parentMamalia->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));
    
    NodeParent parentAmfibi = LParent.first->next->next->next;
    insertLastChild(parentAmfibi->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));
    
    printMLLStructure(LParent);
    
    return 0;
}