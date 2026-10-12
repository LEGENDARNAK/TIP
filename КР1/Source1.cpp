#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Введите множитель" << endl;
    cin >> n;
    cout << "ответ на выражение 6n(n^2 - 2n - 4)" << endl << 6 * n * n * n - 12 * n * n - 24 * n;
    return 0;
}