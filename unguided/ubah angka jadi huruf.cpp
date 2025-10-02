#include <iostream>
#include <string>
using namespace std;

string s(int n) {
    switch (n) {
        case 1: return "satu"; case 2: return "dua"; case 3: return "tiga";
        case 4: return "empat"; case 5: return "lima"; case 6: return "enam";
        case 7: return "tujuh"; case 8: return "delapan"; case 9: return "sembilan";
        default: return "";
    }
}

string k(int a) {
    if (a == 0) return "nol";
    if (a == 100) return "seratus";
    if (a >= 10 && a <= 19) {
        if (a == 10) return "sepuluh";
        if (a == 11) return "sebelas";
        if (a == 12) return "dua belas";
        if (a == 13) return "tiga belas";
        if (a == 15) return "lima belas";
        return s(a % 10) + " belas";
    }
    if (a >= 20 && a <= 99) return s(a / 10) + " puluh " + s(a % 10);
    return s(a);
}

int main() {
    int n;
    cout << "Input angka (0-100): ";
    cin >> n;
    if (n < 0 || n > 100) {
        cout << "Angka di luar batas." << endl;
    } else {
        cout << n << " : " << k(n) << endl;
    }
    return 0;
}