#include <iostream>
#include <string>

using namespace std;

constexpr int STK_MAX = 1000;

class Stack{
    int _top;
    char buf[STK_MAX];

public:
    Stack() {
        _top = 0;
    }

    void push(char c) {
        if (!isFull()) {
            buf[_top] = c;
            _top++;
        }
    }

    char pop() {
        if (isEmpty()) {
            return '@';
        }
        _top--;
        return buf[_top];
    }

    char top() {
        if (isEmpty()) {
            return '@';
        }
        return buf[_top - 1];
    }

    bool isEmpty() {
        return _top == 0;
    }

    bool isFull() {
        return _top == STK_MAX;
    }
};

inline void push_all(Stack& stk, std::string line) {
    for (char c : line) {
        stk.push(c);
    }
}

inline void pop_all(Stack& stk) {
    while (!stk.isEmpty()) {
        cout << stk.pop();
    }
    cout << endl;
}
