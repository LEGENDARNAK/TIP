#include <iostream>
using namespace std;

double fast_pow(double x, long long n) {
    if (n == 0) return 1.0;
    if (n < 0) {
        x = 1.0 / x;
        n = -n;
    }
    
    double res = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            res *= x;
        }
        x *= x;
        n /= 2;
    }
    return res;
}

int main() {
    int num, step;
    cout << "введите возводимое число:\n";
    cin >> num;
    cout << "введите степень:\n";
    cin >> step;
    cout << fixed;
    cout.precision(0);
    cout << fast_pow(10, 12) << endl; 
    return 0;
}