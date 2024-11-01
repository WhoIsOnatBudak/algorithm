#include <bits/stdc++.h>
using namespace std;

long long modExp(long long base, long long exp, long long mod) {
    long long ans = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return ans;
}

int main() {
    long long N, M;
    cin >> N >> M;

    long long ust = modExp(2, N, M - 1);
    long long result = modExp(2, ust, M);
    result = (result + 1) % M;

    cout << result << endl;

    return 0;
}
