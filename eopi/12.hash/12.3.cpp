// find nearest occurance
#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

int find_nearest_repitition(const vector<string> &s) {
    unordered_map<string, int> string_to_loc;

    int closest_dist = numeric_limits<int>::max();

    for (int i = 0; i < s.size(); ++i) {
        auto it = string_to_loc.find(s[i]);
        if (it != string_to_loc.end()) {
            closest_dist = min(closest_dist, i - it->second);
        }
        string_to_loc[s[i]] = i;
    }

    return closest_dist;
}

int main() {

    // fairly straight forward
}