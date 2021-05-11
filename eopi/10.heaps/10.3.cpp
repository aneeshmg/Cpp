// stack and queue using heap
#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class Compare {
    public:
        const bool operator()(const pair<T, int> &lhs, const pair<T, int> &rhs) const {
            return lhs.first >rhs.first;
        }
};

template <typename T>
class Stack : public priority_queue<pair<int, T>, vector<pair<int, T>>, Compare<T>> {
    private:
        int order;
        typedef priority_queue<pair<int, T>, vector<pair<int, T>>, Compare<T>> PQ;

    public:
        Stack() : order(0) {}

        const T &top() const {
            return PQ::top().second;
        }

        void push(const T &x) {
            PQ::emplace(order++, x);
        }
};

template <typename T>
class Queue : public priority_queue<pair<int, T>, vector<pair<int, T>>, Compare<T>> {
    private:
        int order;
        typedef priority_queue<pair<int, T>, vector<pair<int, T>>, Compare<T>> PQ;

    public:
        Queue() : order(0) {}

        const T &front() const {
            return PQ::top().second;
        }

        void push(const T &x) {
            PQ::emplace(order--, x);
        }
};

int main() {

    //
}