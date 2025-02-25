#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int count;
        cin >> count;

        vector<pair<int, int>> ar;
        map<int, int> check;

        for (int j = 0; j < count; j++) {
            int left, right;
            cin >> left >> right;
            ar.push_back({left, right});
            if (left == right) {
                check[left]++;
            }
        }

        // Create a sorted list of keys and their prefix sums
        vector<int> keys, prefixSums;
        int currentSum = 0;
        for (auto &[key, value] : check) {
            keys.push_back(key);
            currentSum += 1; // Increment count since each key exists
            prefixSums.push_back(currentSum);
        }

        for (int j = 0; j < count; j++) {
            int flag = 0;

            if (ar[j].first == ar[j].second) {
                if (check[ar[j].first] >= 2) {
                    flag = 0;
                } else {
                    flag = 1;
                }
            } else {
                int left = ar[j].first;
                int right = ar[j].second;

                // Find indices of `left` and `right` in `keys` using binary search
                auto leftIt = lower_bound(keys.begin(), keys.end(), left);
                auto rightIt = upper_bound(keys.begin(), keys.end(), right);

                int leftIdx = leftIt - keys.begin();
                int rightIdx = rightIt - keys.begin() - 1;

                int totalKeysInRange = 0;
                if (leftIt != keys.end() && *leftIt <= right) {
                    totalKeysInRange = prefixSums[rightIdx] - (leftIdx > 0 ? prefixSums[leftIdx - 1] : 0);
                }

                int rangeSize = right - left + 1;
                if (totalKeysInRange < rangeSize) {
                    flag = 1;
                }
            }

            if (flag == 0) {
                cout << "0";
            } else if (flag == 1) {
                cout << "1";
            }
        }
        cout << "\n";
    }

    return 0;
}
