#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cout << "Input N: ";
    cin >> N;
    cout << "output:" << endl;

    for (int i = N; i >= 1; --i) {
        for (int sp = 0; sp < N - i; ++sp) cout << " ";
        for (int j = i; j >= 1; --j) cout << j;
        cout << "*";
        for (int k = 1; k <= i; ++k) cout << k;
        cout << endl;
    }

    // Baris terakhir
    for (int sp = 0; sp < N; ++sp) cout << " ";
    cout << "*" << endl;

    return 0;
}