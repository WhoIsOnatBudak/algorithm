//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int primMST(int N, vector<vector<pair<int, int>>> &adj, vector<int> &used) {
    vector<bool> inMST(N + 1, false);
    vector<int> minEdge(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mstWeight = 0;

    minEdge[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        mstWeight += w;
        used.push_back(w);
        inMST[u] = true;

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v] && weight < minEdge[v]) {
                minEdge[v] = weight;
                pq.push({weight, v});
            }
        }
    }
    
    return mstWeight;
}

int main() {
// write your code here

    int node;
    int edge;
    int k;

    vector<vector<pair<int, int>>> adj(node + 1);
    vector<int> joker(k);

    
    for (int i = 0; i < edge; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> used;

    int ans = primMST(node,adj,used);

    sort(used.begin(),used.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; ++i) {
        cout<<ans<<" ";
        int temp;   
        cin>>temp;
        pq.push(temp);




    }




	return 0;
}
