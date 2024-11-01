#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<priority_queue<int, vector<int>, greater<int>>> v(10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            v[i].push(temp);
        }
    }

    int last = -1;
    for (int i = 0; i < n * 10; i++) {
        int cur = -1;
        int print = INT32_MAX;
        bool found = false;

        for (int j = 0; j < 10; j++) {
            if (!v[j].empty() && v[j].top() < print && last != j) {
                cur = j;
                print = v[cur].top();
                found = true;
            }
        }

        if (!found && last != -1 && !v[last].empty()) {
            cur = last;
            print = v[last].top();
        } else if (!found) {
            break;
        }

        v[cur].pop();
        cout << print << " ";
        last = cur;
    }

    return 0;
}
