// max of a sliding window
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack {
    private:
        stack<pair<T, T>> s;

    public:
        const bool empty(void) const {
            return s.empty();
        }

        const T &max(void) const {
            if (empty() == false) return s.top().second;

            throw length_error("empty stack");
        }

        T pop(void) {
            if (empty() == false) {
                T ret = s.top().first;
                s.pop();
                return ret;
            }
            throw length_error("empty stack");
        }

        void push(const T &x) {
            s.emplace(x, max(x, empty() ? x : s.top().second));
        }
};

template <typename T>
class Queue {
    private:
        Stack<T> A, B;

    public:
        void enqueue(const T &x) {
            A.push(x);
        }

        T dequeue(void) {
            if (B.empty()) {
                while (A.empty() == false) {
                    B.push(A.top());
                    A.pop();
                }
            }
            if (B.empty() == false) return B.pop();

            throw length_error("empty queue");
        }

        const T &max(void) const {
            if (A.empty() == false) {
                return B.empty() ? A.max() : std::max(A.max(), B.max());
            } else { // A.empty() == true
                if (B.empty() == false) {
                    return B.max();
                }
                throw length_error("empty queue");
            }
        }

        T front(void) {
            return A.pop(); // this is wrong
        }
};

class TrafficElement {
    public:
        int time, volume;

    const bool operator<(const TrafficElement &that) const {
        return time < that.time;
    }
    const bool operator==(const TrafficElement &that) const {
        return time == that.time && volume == that.volume;
    }
};

void TrafficVolumes(const vector<TrafficElement> &A, const int &w) {
    Queue<TrafficElement> Q;

    for (int i = 0; i < A.size(); ++i) {
        Q.enqueue(A[i]);
        while (A[i].time - Q.front().time > w) {
            Q.dequeue();
        }
        cout << "Max after inserting " << i << "is " << Q.max().volume << endl;
    }
}

int main() {

    // possibly there is a better approach for this...
    // test in rev
}