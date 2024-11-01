#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> mounts(n);
    for(long long i = 0; i < n; i++) {
        cin >> mounts[i];
    }

    vector<vector<long long>> adj(n);
    for(long long i = 0; i < m; i++) {
        long long s, e;
        cin >> s >> e;
        adj[s-1].push_back(e-1); 
    }

    vector<long long> dp(n, LLONG_MIN);
    dp[0] = 0; 

    for (long long curr = 0; curr < n; curr++) {
        for (long long next : adj[curr]) { 
            long long change = mounts[next] - mounts[curr];
            if (change > 0) {
                dp[next] = max(dp[next], dp[curr] - 2 * change);
            } else {
                dp[next] = max(dp[next], dp[curr] - change);
            }
        }
    }

    long long maxEnergy = *max_element(dp.begin(), dp.end());
    cout << maxEnergy;

    return 0;
}