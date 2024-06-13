#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> returns(n);
    vector<int> constraint(n, -1); // constraint[i] = j means if we choose i, we must also choose j

    for (int i = 0; i < n; i++) {
        cin >> returns[i];
    }

    for (int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        constraint[a] = b;
    }

    

    int maxReturn = 0;

    cout<<maxReturn;

}