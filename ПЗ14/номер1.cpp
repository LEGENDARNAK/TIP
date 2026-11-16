#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stack<char> st;
    bool ok = true;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                ok = false;
                break;
            }
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                st.pop();
            } else {
                ok = false;
                break;
            }
        }
    }

    if (ok && st.empty()) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    return 0;
}