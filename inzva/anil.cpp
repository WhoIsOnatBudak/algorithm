//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long node, edge;
    cin >> node >> edge;
    vector<vector<pair<long long, long long>>> v(node + 1);

    for (long long i = 0; i < edge; i++) {
        long long f, t, w;
        cin >> f >> t >> w;
        v[f].push_back({t, w});
        v[t].push_back({f, w});
    }

    long long c1;
    cin >> c1;
    vector<long long> s(node+1, 0);
    for (long long i = 0; i < c1; i++) {
        long long temp;
        cin >> temp;
        s[temp] = 1;
    }

    long long c2;
    cin >> c2;
    vector<long long> f(node+1, 0);
    vector<long long> fv;
    for (long long i = 0; i < c2; i++) {
        long long temp;
        cin >> temp;
        f[temp] = 1;
        fv.push_back(temp);
    }

    vector<vector<pair<long long, long long>>> nv(node + 1);
    for (long long i = 1; i < node + 1; i++) {
        for (long long j = 0; j < v[i].size(); j++) {
            long long baslangic = i;
            long long son = v[i][j].first;
            long long cost = v[i][j].second;

            if (f[son] == 1 && f[baslangic] == 1) {
                continue;
            }
            if (s[baslangic] == 1) {
                baslangic = 0;
            }
            if (s[son] == 1) {
                son = 0;
            }
            if (son == 0 && baslangic == 0) {
                continue;
            }
            nv[baslangic].push_back({son, cost});
            nv[son].push_back({baslangic, cost});
        }
    }

    vector<long long> dist(node + 1, LLONG_MAX);
    dist[0] = 0;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [current_dist, current_node] = pq.top();
        pq.pop();

        if (current_dist > dist[current_node]) continue;

        for (auto &[neighbor, weight] : nv[current_node]) {
            long long new_dist = current_dist + weight;

            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }

    long long max = -1;

    for (long long i = 0; i < fv.size(); i++) {
        long long di = dist[fv[i]];
        if (di == LLONG_MAX) {
            continue;
        }
        if (di > max) {
            max = di;
        }
    }

    cout << max;

    return 0;
}
