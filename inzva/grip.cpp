#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long r;
    long long c;

    cin >> r >> c;

    vector<long long> xr(r);
    vector<long long> xc(c);

    vector<long long> row1;
    long long bak = 0;
    for (long long i = 0; i < c; i++) {
        long long temp;
        cin >> temp;
        bak ^= temp;
        row1.push_back(temp);
    }
    xr[0] = bak;
    bak = 0;
    vector<long long> col1;
    for (long long i = 0; i < r; i++) {
        long long temp;
        cin >> temp;
        bak ^= temp;
        col1.push_back(temp);
    }
    xc[0] = bak;

    for (long long i = 0; i < r; i++) {
        for (long long j = 0; j < c; j++) {
            long long cur;
            cin >> cur;

            if (i == 0 && j > 0) {
                xc[j] = xr[0] ^ row1[j] ^ cur;
            }
            if (j == 0 && i > 0) {
                xr[i] = xc[0] ^ col1[i] ^ cur;
            }

            cout << (xr[i] ^ xc[j] ^ cur) << " ";
        }
        cout << "\n";
    }

    return 0;
}
