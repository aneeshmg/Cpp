#include <iostream>
#include <queue>

using namespace std;

void print(priority_queue<int, vector<int>, greater<int>> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {

    // self explanatory - also has access to other methods like back(), size(), etc
    // pqueues are internally implemented as max-heap
    priority_queue<int, vector<int>, greater<int>> s; //can also be priority_queue<int> s;, "greater" is just a comparitor and can be overloaded

    s.push(1);
    s.push(7);
    s.push(5);
    s.push(2);
    s.push(3);

    cout << s.size() << endl;
    print(s);
}