#include <iostream>
#include "helper1.cpp"

using namespace std;
int main() {
    int a, b, number;
    cout << "введите 2 катета:";
    cin >> a >> b;
    cout << "гипотенуза треугольника:" << gipotinuza(a, b) << endl;
    cout << "введите число";
    cin >> number;
    cout << "его десяток" << desitok(number);
    return 0;
}