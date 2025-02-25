#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<vector<long long>> dp(n+1, vector<long long>(3, 0));
    vector<int> v(n);

    for (long long i = 0; i < n; i++) {
        cin >> v[i];
    }

    int left = 0, right = 0;
    long long sum = 0;

    while (right < n) {
        sum += v[right];
        while (sum > k && left <= right) {
            sum -= v[left];
            left++;
        }
        if (sum == k) {
            dp[right + 1][0] = (dp[right][0] + 1) % mod;
            dp[right + 1][1] = (dp[left][0] + dp[right][1]) % mod;
            dp[right + 1][2] = (dp[left][1] + dp[right][2]) % mod;
        } else {
            dp[right + 1][0] = dp[right][0];
            dp[right + 1][1] = dp[right][1];
            dp[right + 1][2] = dp[right][2];
        }
        right++;
    }

    cout << dp[n][2] << endl;

    return 0;
}
