#include <iostream>
#include <math.h>
using namespace std;
int main() {
    char i;
    cout << "Введите 1 из вариантов (L, i, a):" << endl;
    cin >> i;
    if (i == 'L') {
        cout << "Levin Vlad";
    }
    else if (i == 'i') {
        double a, b, c, diskr;
        cout << "Введите 3 множителя:" << endl;
        cin >> a >> b >> c;
        if (a == 0 and b == 0 and c == 0) {
            cout << "x = любое рациональное число";
        }
        else {
            diskr = b * b - 4 * a * c;
            if (diskr < 0) {
                cout << "нет корней" << diskr;
            }
            else if (diskr == 0) {
                cout << "ответ: x = " << (-1 * b) / (2 * a);
            }
            else {
                cout << "ответ: x1 = " << (-1 * b - sqrt(diskr)) / (2 * a) << endl << "x2 = " << (-1 * b + sqrt(diskr)) / (2 * a);
            }
        }
    }
    else if (i == 'a') {
        int number;
        cout << "Введите число:" << endl;
        cin >> number;
        if (number % 4 == 0) {
            cout << number << " - делится на 11" << endl;
        }
        else {
            cout << number << " - не делится на 11" << endl;
        }
    }
    else {
        cout << "Такого варианта нет";
    }
}
