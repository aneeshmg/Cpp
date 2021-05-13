// completion search - dafuq is dis??
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

double completion_search(vector<double> &A, const double &budget) {
    sort(A.begin(), A.end());

    // calculate prefix sums of A
    vector<double> prefix_sum;
    partial_sum(A.cbegin(), A.cend(), back_inserter(prefix_sum));

    // costs[i] represents the total payroll if the cap is A[i]
    vector<double> costs;
    for (int i = 0; i < prefix_sum.size(); ++i) {
        costs.emplace_back(prefix_sum[i] + (A.size() - i - 1) * A[i]);
    }

    auto lower = lower_bound(costs.cbegin(), costs.cend(), budget);
    if (lower == costs.cend())
        return -1.0; // budget too large
    if (lower == costs.cbegin())
        return budget / A.size();
    int idx = lower - costs.cbegin() - 1;

    return A[idx] + (budget - costs[idx]) / (A.size() - idx - 1);
}

int main() {

    // fairly simple, clever

} 