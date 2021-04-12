#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {

    stack<int> s;

    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);

    cout << s.size() << endl;
    print(s);
}