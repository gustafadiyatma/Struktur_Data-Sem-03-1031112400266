#include <iostream>
using namespace std;

int main() {
    float celsius, fahrenheit;
    cout << "Tulis sedingin apa Neraka: ";
    cin >> celsius;
    fahrenheit = (9.0 / 5.0) * celsius + 32;
    cout << "Kalau di Fahrenheit itu " << fahrenheit << " derajat";
    cout << "Lu dingin banget sih";
    return 0;
}
