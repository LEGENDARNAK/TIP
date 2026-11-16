#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("input1.txt");
    ofstream fout("output.txt");
    
    string forbidden = "useragmnt";
    
    string line, result;
    while (getline(fin, line)) {
        for (char c : line) {
            char lower = tolower(c);
            bool remove = false;
            for (char f : forbidden) {
                if (lower == f) { remove = true; break; }
            }
            if (!remove) result += c;
        }
        result += '\n';
    }
    
    if (!result.empty() && result.back() == '\n') result.pop_back();
    
    fout << result;
    
    fin.close();
    fout.close();
    return 0;
}