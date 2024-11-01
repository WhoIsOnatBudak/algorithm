#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS traversal and update energy values
void dfs(int node, vector<int>& mounts, vector<vector<int>>& adj, vector<int>& energy) {
    for (int neighbor : adj[node]) {
        int diff = mounts[node]- mounts[neighbor];  // Calculate the difference

        int new_energy;
        if (diff < 0) {
            new_energy = energy[node] + 2 * diff;  // If negative, multiply by 2
        } else {
            new_energy = energy[node] + diff;  // If positive, just add the difference
        }

        // Update energy if the new value is higher
        if (new_energy > energy[neighbor]) {
            energy[neighbor] = new_energy;
            dfs(neighbor, mounts, adj, energy);  // Recur for the neighbor
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input the mount values
    vector<int> mounts(n);
    for (int i = 0; i < n; i++) {
        cin >> mounts[i];
    }

    // Input the adjacency list
    vector<vector<int>> adj(n);  // Adjacency list for the graph
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        adj[s-1].push_back(e-1);
    }

    // Energy vector initialized with very low values except for node 0
    vector<int> energy(n, INT_MIN);
    energy[0] = 0;  // Start node 0 with energy 0

    // Start DFS from node 0
    dfs(0, mounts, adj, energy);

    // Output the energy of every node
    cout << *max_element(energy.begin(), energy.end()) << endl;

    return 0;
}
