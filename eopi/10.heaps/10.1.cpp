// merge multiple sorted arrays
#include <iostream>
#include <vector>
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
vector<T> merge_arrays(const vector<vector<T>> &S) {
    priority_queue<pair<T, int>, vector<pair<T, int>>, Compare<T>> min_heap;
    vector<int> S_idx(S.size(), 0);

    for (int i = 0; i < S.size(); ++i) {
        if (S[i].size() > 0) {
            min_heap.emplace(S[i][0], i);
            S_idx[i] = 1;
        }
    }

    vector<T> ret;

    while (!min_heap.empty()) {
        pair<T, int> p = min_heap.top();
        ret.emplace_back(p.first);
        // add the smallest element into heap if possible
        if (S_idx[p.second] < S[p.second].size()) {
            min_heap.emplace(S[p.second][S_idx[p.second]++], p.second);
        }
        min_heap.pop();
    }

    return ret;
}

int main() {

    // quite simplistic..(check out what the idx does)
}