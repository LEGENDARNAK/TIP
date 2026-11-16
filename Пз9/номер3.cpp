#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string toBinary(long long n) {
    if (n == 0) return "0";
    string bin;
    while (n > 0) {
        bin = char('0' + n % 2) + bin;
        n /= 2;
    }
    return bin;
}

int main() {
    ifstream fin("input3.txt");
    ofstream fout("output.txt");
    
    string s;
    getline(fin, s);
    if (!s.empty() && s.back() == '\r') s.pop_back();
    
    string result;
    int i = 0;
    int n = s.size();
    
    while (i < n) {
        if (isdigit((unsigned char)s[i])) {
            // Собираем всё число целиком
            long long num = 0;
            while (i < n && isdigit((unsigned char)s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            result += toBinary(num);
        } else {
            result += s[i];
            i++;
        }
    }
    
    fout << result;
    
    fin.close();
    fout.close();
    return 0;
}