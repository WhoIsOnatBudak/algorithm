#include <bits/stdc++.h>

#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            if (c == '0') {
                grid[i][j] = 0;
            }
            else {
                grid[i][j] = -1;
            }
        }
    }
    int ans = LLONG_MAX;
    int comp = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != 0) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (q.size()) {
                auto [r, c] = q.front();
                q.pop();
                if (grid[r][c] != 0) continue;

                grid[r][c] = comp;
                if (r & 1) {
                    if (c > 0) {
                        q.push({r, c - 1});
                    }
                    if (c < m - 1) {
                        q.push({r, c + 1});
                    }
                    if (r > 0 && c > 0) {
                        q.push({r - 1, c - 1});
                        q.push({r - 1, c});
                    }
                    if (r > 0 && c == 0) {
                        q.push({r - 1, c});
                    }
                    if (r < n - 1 && c > 0) {
                        q.push({r + 1, c - 1});
                        q.push({r + 1, c});
                    }
                    if (r < n - 1 && c == 0) {
                        q.push({r + 1, c});
                    } 
                }
                else {
                    if (c > 0) {
                        q.push({r, c - 1});
                    }
                    if (c < m - 1) {
                        q.push({r, c + 1});
                    }
                    if (r > 0 && c < m - 1) {
                        q.push({r - 1, c + 1});
                        q.push({r - 1, c});
                    }
                    if (r > 0 && c == m - 1) {
                        q.push({r - 1, c});
                    }
                    if (r < n - 1 && c < m - 1) {
                        q.push({r + 1, c + 1});
                        q.push({r + 1, c});
                    }
                    if (r < n - 1 && c == m - 1) {
                        q.push({r + 1, c});
                    }
                }
            }
            comp++;
        }
        
    }
    ans = min(ans, comp - 1);
    map<int, set<int>> mp;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != -1) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (q.size()) {
                auto [r, c] = q.front();
                q.pop();
                if (grid[r][c] != -1) {
                    if (grid[r][c] != comp)
                        mp[comp].insert(grid[r][c]);
                    continue;
                }
                grid[r][c] = comp;
                if (r & 1) {
                    if (c > 0) {
                        q.push({r, c - 1});
                    }
                    if (c < m - 1) {
                        q.push({r, c + 1});
                    }
                    if (r > 0 && c > 0) {
                        q.push({r - 1, c - 1});
                        q.push({r - 1, c});
                    }
                    if (r > 0 && c == 0) {
                        q.push({r - 1, c});
                    }
                    if (r < n - 1 && c > 0) {
                        q.push({r + 1, c - 1});
                        q.push({r + 1, c});
                    }
                    if (r < n - 1 && c == 0) {
                        q.push({r + 1, c});
                    } 
                }
                else {
                    if (c > 0) {
                        q.push({r, c - 1});
                    }
                    if (c < m - 1) {
                        q.push({r, c + 1});
                    }
                    if (r > 0 && c < m - 1) {
                        q.push({r - 1, c + 1});
                        q.push({r - 1, c});
                    }
                    if (r > 0 && c == m - 1) {
                        q.push({r - 1, c});
                    }
                    if (r < n - 1 && c < m - 1) {
                        q.push({r + 1, c + 1});
                        q.push({r + 1, c});
                    }
                    if (r < n - 1 && c == m - 1) {
                        q.push({r + 1, c});
                    }
                }
            }
            comp++;
        }
    }
    ans = min(ans, comp - ans);
    int x = 0;
    vector<int> used(comp);
    vector<vector<int>> adj(comp);
    for (auto &p : mp) {
        int cnt = p.second.size();
        if (cnt > 1) {
            x++;
        }
        cout<<cnt<<" ";
    }
    x++;
    ans = min (ans, x);
    cout << ans << '\n';
     
    return 0;
}