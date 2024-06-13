#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    vector<int> CT(x, 0);
    vector<vector<pair<int, int>>> adj(x);

    for (int i = 0; i < x; i++) {
        string temp;
        cin >> temp;
        if (temp == "CT") {
            CT[i] = 1;
        }
    }

    for (int i = 0; i < y; i++) {
        int f, s, w;
        cin >> f >> s >> w;
        f--; s--; // Convert to zero-based indexing
        adj[f].emplace_back(w, s);
        adj[s].emplace_back(w, f);
    }

    priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<>> pq;
    vector<bool> inMST(x, false);
    pq.push({0, {0,0}}); // Start from the first node with weight 0

    int edgeCount = 0;
    int CT_T_connections = 0;
    int totalWeight = 0;

    vector<int> parent(x, -1);

    while (!pq.empty()) {
        int weight = pq.top().first;
        int art= pq.top().second.first;
        int dest = pq.top().second.second;

        pq.pop();

        if (inMST[dest]) continue;
        inMST[dest] = true;
        totalWeight += weight;
        edgeCount++;

        
        CT_T_connections += art;
        

        for (int i = 0 ; i < adj[dest].size(); i++) {
            int gonder = 0;
            if (!inMST[adj[dest][i].second]) {
                if(CT[dest] != CT[adj[dest][i].second]){
                    gonder = 1;
                }
                pq.push({adj[dest][i].first,{gonder,adj[dest][i].second}});


            }
        }
    }

    if (edgeCount != x) {
        cout << -1 << endl;
    } else {
        cout << CT_T_connections << endl;
    }

    return 0;
}
