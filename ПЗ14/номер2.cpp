#include <iostream>
#include <string>
#include <unordered_set>
#include <cwctype>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wcin.imbue(locale("ru_RU.UTF-8"));
    wcout.imbue(locale("ru_RU.UTF-8"));

    wstring line;
    getline(wcin, line);

    unordered_set<wstring> seen;
    wstring current_word;

    for (size_t i = 0; i < line.size(); ++i) {
        wchar_t ch = line[i];

        bool is_hyphen_inside = (ch == L'-') && !current_word.empty() && 
                                (i + 1 < line.size()) && iswalnum(line[i + 1]);

        if (iswalnum(ch) || is_hyphen_inside) {
            current_word += towlower(ch);
        } else {
            if (!current_word.empty()) {
                if (seen.find(current_word) == seen.end()) {
                    seen.insert(current_word);
                    wcout << current_word << L'\n';
                }
                current_word.clear();
            }
        }
    }

    if (!current_word.empty() && seen.find(current_word) == seen.end()) {
        wcout << current_word << L'\n';
    }

    return 0;
}