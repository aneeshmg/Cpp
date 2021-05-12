// online median ie median of streaming data
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
void online_median(istringstream &sin) {
    // min heap - stores the larger part of the array
    priority_queue<T, vector<T>, greater<T>> H;
    // max heap - stores the smaller part of the stream
    priority_queue<T, vector<T>, less<T>> L;

    T x;

    while (sin >> x) {
        if (L.empty() == false && x > L.top()) {
            H.emplace(x);
        } else {
            L.emplace(x);
        }
        if (H.size() > L.size() + 1) {
            L.emplace(H.top());
            H.pop();
        } else if (L.size() > H.size() + 1) {
            H.emplace(L.top());
            L.pop();
        }

        if (H.size() == L.size()) {
            cout << 0.5 * (H.top() + L.top()) << endl;
        } else {
            cout << (H.size() > L.size() ? H.top() : L.top()) << endl;
        }
    }
}

int main() {

    // use two heaps - one min and one max
}