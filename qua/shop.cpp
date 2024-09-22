#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast input/output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long countC;
    cin >> countC;
    vector<long long> v(countC + 1);  // Prefix sum array
    v[0] = 0; // Starting prefix sum
    long long res = 0;
    
    // Calculate prefix sums
    for (long long i = 0; i < countC; i++) {
        long long temp;
        cin >> temp;
        res += temp;
        v[i + 1] = res;  // Store the running total
    }
    
    long long Q;
    cin >> Q;
    
    // Prepare output
    stringstream output; // Use stringstream for batched output

    // Process each query
    while (Q--) {
        long long C;
        cin >> C;
        
        // Use lower_bound to find the first index where prefix[k] >= C
        auto it = lower_bound(v.begin(), v.end(), C);
        
        // Convert iterator to index (1-based), subtract 1 to get number of items
        long long max_items = it - v.begin() - 1;

        // Handle cases where there are zero-cost items
        while (max_items < countC && v[max_items] == v[max_items + 1]) {
            max_items++;
        }

        output << max_items << "\n"; // Collect output in stringstream
    }

    cout << output.str(); // Write all output at once
    return 0;
}
