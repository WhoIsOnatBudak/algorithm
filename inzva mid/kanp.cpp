#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> weights(N);
    vector<int> profits(N);
    vector<int> amounts(N);

    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> profits[i] >> amounts[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= C; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= amounts[i - 1]; k++) {
                if (j >= weights[i - 1] * k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1] * k] + k * profits[i - 1]);
                } else {
                    break;
                }
            }
        }
    }

    cout << dp[N][C] << endl;

    return 0;
}
