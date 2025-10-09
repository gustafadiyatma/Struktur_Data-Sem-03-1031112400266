#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Input 2 float: ";
    cin >> a >> b;

    cout << "\nJumlah: " << a + b << endl;
    cout << "Kurang: " << a - b << endl;
    cout << "Kali:   " << a * b << endl;
    if (b != 0) {
        cout << "Bagi:   " << a / b << endl;
    } else {
        cout << "Bagi:   Error (bagi nol)" << endl;
    }

    return 0;
}