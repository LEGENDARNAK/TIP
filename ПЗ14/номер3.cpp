#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

template <typename T>
class MinStack {
private:
    struct Node {
        T val;
        T min_val;
        Node* next;

        Node(const T& v, const T& m, Node* n) : val(v), min_val(m), next(n) {}
    };

    Node* top_node;

public:
    MinStack() : top_node(nullptr) {}

    ~MinStack() {
        while (!empty()) {
            pop();
        }
    }
\
    void push(const T& x) {
        if (empty()) {
            top_node = new Node(x, x, nullptr);
        } else {
            T current_min = min(x, top_node->min_val);
            top_node = new Node(x, current_min, top_node);
        }
    }

    void pop() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        Node* temp = top_node;
        top_node = top_node->next;
        delete temp;
    }

    T top() const {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return top_node->val;
    }

    T getMin() const {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return top_node->min_val;
    }

    bool empty() const {
        return top_node == nullptr;
    }
};

int main() {
    MinStack<int> st;
    st.push(5);
    st.push(2);
    st.push(8);
    st.push(1);

    cout << "Минимум: " << st.getMin() << "\n";
    st.pop();
    cout << "Минимум после pop: " << st.getMin() << "\n";

    return 0;
}