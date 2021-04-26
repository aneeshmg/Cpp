// stack sort
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
void insert(stack<T> &S, const T &e) {
    if (S.empty() || S.top() <= e) {
        S.push(e);
    } else {
        T f = S.top();
        S.pop();
        insert(S, e);
        S.push(f);
    }
}

template <typename T>
void sort(stack<T> &S) {
    if (!S.empty()) {
        T e = S.top();
        S.pop();
        sort(S);
        insert(S, e);
    }
}

int main() {

    // fairly straightforward > utilizing recursion nicely
    // test in rev
}