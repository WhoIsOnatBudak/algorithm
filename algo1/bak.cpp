#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    long n, m;
    cin >> n >> m;

    vector<int> balloons(n);
    vector<int> predictions(m);

    // Input balloon capacities
    for (int i = 0; i < n; ++i) {
        cin >> balloons[i];
    }

    // Input students' predictions
    for (int i = 0; i < m; ++i) {
        cin >> predictions[i];
    }

    // Calculate the maximum possible sum
    int maxSum = accumulate(balloons.begin(), balloons.end(), 0);

    // Create a boolean array to represent reachable sums
    vector<bool> reachable(maxSum + 1, false);
    reachable[0] = true;

    // Update the reachable array based on balloon capacities
    for (int balloon : balloons) {
        for (int sum = maxSum; sum >= balloon; --sum) {
            reachable[sum] = reachable[sum] || reachable[sum - balloon];
        }
    }

    // Output whether each student's prediction is correct or not
    for (int i = 0; i < m; ++i) {
        if (predictions[i] <= maxSum && reachable[predictions[i]]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
