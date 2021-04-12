#include <iostream>
#include <queue>

using namespace std;

void print(queue<int> s) {
    while (!s.empty()) {
        cout << s.front() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {

    // self explanatory - also has access to other methods like back(), size(), etc
    queue<int> s;

    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);

    cout << s.size() << endl;
    print(s);
}