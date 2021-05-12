// looks like a math problem - find a + b*sqrt(2) - k smallest
#include <iostream>
#include <queue>
#include <math.h>
#include <memory>
#include <unordered_set>

using namespace std;

class Num {
    public:
        int a_, b_;
        double val_;

    Num(const int &a, const int &b) : a_(a), b_(b), val_(a + b * sqrt(2)) {}

    const bool operator<(const Num &n) const {
        return val_ > n.val_;
    }

    const bool operator==(const Num &n) const {
        return a_ == n.a_ && b_ == n.b_;
    }
};

class HashNum {
    public:
        const size_t operator()(const Num &n) const {
            return hash<int>()(n.a_) ^ hash<int>()(n.b_);
        }
};

vector<Num> generate_first_k(const int &k) {
    priority_queue<Num, vector<Num>> min_heap;

    vector<Num> smallest;
    unordered_set<Num, HashNum> hash;

    min_heap.emplace(0, 0);
    hash.emplace(0, 0);

    while (smallest.size() < k) {
        Num s(min_heap.top());
        smallest.emplace_back(s);
        hash.erase(s);
        min_heap.pop();

        // add the next two numbers derivd from s
        Num c1(s.a_ + 1, s.b_), c2(s.a_, s.b_ + 1);
        if (hash.emplace(c1).second)
            min_heap.emplace(c1);
        if (hash.emplace(c2).second)
            min_heap.emplace(c2);
    }

    return smallest;
}

int main() {

    //
}