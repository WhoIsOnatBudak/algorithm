#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;

    vector<pair<int, int>> v(count);
    pair<int, int> dest;
    cin >> dest.first >> dest.second;

    for (int i = 0; i < count; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int half = count / 2;
    vector<pair<int, int>> v1(v.begin(), v.begin() + half);
    vector<pair<int, int>> v2(v.begin() + half, v.end());

    unordered_map<pair<int, int>, unordered_map<int, int>, Hash> m1, m2;

    auto computeSubsets = [](const vector<pair<int, int>>& vec, auto& map) {
        int n = vec.size();
        for (int i = 0; i < (1 << n); i++) {
            pair<int, int> sum = {0, 0};
            int ones = __builtin_popcount(i);
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum.first += vec[j].first;
                    sum.second += vec[j].second;
                }
            }
            map[sum][ones]++;
        }
    };

    computeSubsets(v1, m1);
    computeSubsets(v2, m2);

    vector<int> ans(count + 1, 0);

    for (const auto& [key, value] : m1) {
        auto target = make_pair(dest.first - key.first, dest.second - key.second);
        if (m2.count(target)) {
            for (const auto& [k1, v1] : value) {
                for (const auto& [k2, v2] : m2[target]) {
                    ans[k1 + k2] += v1 * v2;
                }
            }
        }
    }

    for (int i = 1; i <= count; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
