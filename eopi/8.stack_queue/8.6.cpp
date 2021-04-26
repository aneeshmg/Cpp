// sunset view...similar to fill water problem (i think)
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
vector<pair<int, T>> examine_buildings_with_sunset(istringstream &sin) {

    int idx = 0;
    T height;

    // stores (building idx, height) pair  with sunset views
    vector<pair<int, T>> buildings_with_sunset;
    while (sin >> height) {
        while (buildings_with_sunset.empty() == false && height >= buildings_with_sunset.back().second) {
            buildings_with_sunset.pop_back();
        }
        buildings_with_sunset.emplace_back(idx++, height);
    }

    return buildings_with_sunset;
}


int main() {

    // test in rev
}