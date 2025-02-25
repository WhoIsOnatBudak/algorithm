#include <bits/stdc++.h>

#define int long long
#define MOD 1000000007

using namespace std;

void solve() {
    int a, b, l; cin >> a >> b >> l;

    //double dist = abs(b) / sqrt(a * a + 1.0);
    //double r = sqrt(dist * dist + (l / 2.0) * (l / 2.0));


    double r = sqrt(   (abs(b)*abs(b)) / (sqrt(a * a + 1.0)* sqrt(a * a + 1.0)) + l*l /4.0                      );

    

    cout << fixed << setprecision(4) << r<< "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}