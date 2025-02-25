#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100005;
const int LOG = 17;

vector<int> adj[MAX_NODES];
int parent[MAX_NODES][LOG];
int node_depth[MAX_NODES];

void preprocess(int node, int par) {
    parent[node][0] = par;
    for (int i = 1; i < LOG; ++i) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        } else {
            parent[node][i] = -1;
        }
    }
    for (int neighbor : adj[node]) {
        if (neighbor != par) {
            node_depth[neighbor] = node_depth[node] + 1;
            preprocess(neighbor, node);
        }
    }
}

int find_lca(int u, int v) {
    if (node_depth[u] < node_depth[v]) swap(u, v);
    int diff = node_depth[u] - node_depth[v];
    for (int i = 0; i < LOG; ++i) {
        if (diff & (1 << i)) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int get_kth_ancestor(int node, int k) {
    for (int i = 0; i < LOG; ++i) {
        if (k & (1 << i)) {
            node = parent[node][i];
        }
    }
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_nodes, num_queries;
    cin >> num_nodes >> num_queries;

    for (int i = 1; i < num_nodes; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(parent, -1, sizeof(parent));
    node_depth[1] = 0;
    preprocess(1, -1);

    while (num_queries--) {
        int start, end, k;
        cin >> start >> end >> k;

        int comman = find_lca(start, end);
        int distt = node_depth[start] - node_depth[comman];
        int distt2 = node_depth[end] - node_depth[comman];

        if (k <= distt + 1) {
            cout << get_kth_ancestor(start, k - 1) << "\n";
        } else {
            k -= (distt + 1);
            cout << get_kth_ancestor(end, distt2 - k) << "\n";
        }
    }

    return 0;
}
