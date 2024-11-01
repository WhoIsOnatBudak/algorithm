#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    int f;

    cin>>n>>f;

    vector<vector<pair<int,int>>> v(n+1);

    for(int i = 0 ; i < f ; i++){
        int a;
        int b;
        int c;
        cin>>a>>b>>c;
        
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector<int> airport;
    airport.push_back(0);
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin>>temp;
        airport.push_back(temp);
    }
    int s;
    int d;
    cin>>s>>d;
    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> cost(n+1,INT32_MAX);
    cost[s] = 0;
    pq.push(s);

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();

        for(int i = 0 ; i < v[cur].size() ; i++){
            int nextC = v[cur][i].second + cost[cur] + airport[v[cur][i].first];
            if(nextC < cost[v[cur][i].first]){
                pq.push(v[cur][i].first);
                cost[v[cur][i].first] = nextC;
            }
        }
    }
    if(cost[d] == INT32_MAX){
        cout<<-1;
        return 0;
    }
    cout<<cost[d];


    return 0;
}
