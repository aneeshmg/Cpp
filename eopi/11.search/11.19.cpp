// search for majority element in a collection using constant memory
#include <iostream>
#include <vector>
#include <istream>

using namespace std;

string majority_search(istringstream &sin) {
    string candidate, buff;
    int count = 0;

    while (sin >> buff) {
        if (count == 0) {
            candidate = buff;
            count = 1;
        } else if (candidate == buff) {
            ++count;
        } else {
            --count;
        }
    }
    return candidate;
}

int main() {

    // fairly simple, clever

}