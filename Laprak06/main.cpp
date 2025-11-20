#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    
    Push(S, 3);  
    Push(S, 4);
    Push(S, 2);
    Push(S, 9);  

    cout << "Stack Awal" << endl;
    printInfo(S);

    cout << endl << "Balik Stack" << endl;
    balikStack(S);

    cout << "Stack Setelah Dibalik" << endl;
    printInfo(S);

    return 0;
}
