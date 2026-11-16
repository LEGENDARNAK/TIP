<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin1("input21.txt");
    ifstream fin2("input22.txt");
    ofstream fout("output.txt");
    
    string X, Y;
    getline(fin1, X);
    getline(fin2, Y);

    if (!X.empty() && X.back() == '\r') X.pop_back();
    if (!Y.empty() && Y.back() == '\r') Y.pop_back();

    if (Y.find(X) != string::npos)
        fout << "yes";
    else
        fout << "no";
    
    fin1.close();
    fin2.close();
    fout.close();
    return 0;
=======
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin1("input21.txt");
    ifstream fin2("input22.txt");
    ofstream fout("output.txt");
    
    string X, Y;
    getline(fin1, X);
    getline(fin2, Y);

    if (!X.empty() && X.back() == '\r') X.pop_back();
    if (!Y.empty() && Y.back() == '\r') Y.pop_back();

    if (Y.find(X) != string::npos)
        fout << "yes";
    else
        fout << "no";
    
    fin1.close();
    fin2.close();
    fout.close();
    return 0;
>>>>>>> 1e271550b0d48e6a97bbb02e84549ba4d20a4d3d
}