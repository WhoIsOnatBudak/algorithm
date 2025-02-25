#include<bits/stdc++.h>
using namespace std;

int timer;
const int N = 1e6+5;
bool visited[N];
vector<pair<int, int>> adj[N];     // to, edge_index
bool is_bridge[N];

int tin[N];
int low[N];


void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (auto [to, edge_index] : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {    // back-edge or forward-edge
            low[v] = min(low[v], tin[to]);
        } else {              // tree-edge
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                is_bridge[edge_index] = 1;

                //cout << "Bridge: " << v << ", " << to << "\n";
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

using namespace std;

int main() {
// write your code here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);




    int n,e;

    cin>>n>>e;

    for(int i = 0 ; i < e ; i++){
        int s,x;
        cin>>s>>x;
        s--;
        x--;
        adj[x].push_back({s,i});
        adj[s].push_back({x,i});

    }

    find_bridges(n);



    int compcount = 0;
    vector<int> componentID(n,-1);


    for(int i = 0 ; i < n ; i++){
        if(componentID[i] == -1){
            queue<int> q;
            q.push(i);

            

            while(!q.empty()){
                int cur = q.front();
                q.pop();

                if(componentID[cur] != -1) continue;

                componentID[cur] = compcount;

                for(int j = 0 ; j < adj[cur].size() ; j++){
                    int too   = adj[cur][j].first;
                    int index = adj[cur][j].second;

                    if(is_bridge[index] == 1 || componentID[too] != -1){
                        continue;
                    }
                    
                    q.push(too);
                    
                }


            }
            compcount++;
        }
    }



    vector<int> graphnew(n,-1);
    vector<vector<int>> adj2(N);

    

    for(int i = 0 ; i < n ; i++){
        if(graphnew[i] == -1){
            queue<int> q;
            q.push(i);
            graphnew[i] = 1;

            

            while(!q.empty()){
                int cur = q.front();
                q.pop();

                graphnew[cur] = 1;

                for(int j = 0 ; j < adj[cur].size() ; j++){
                    int too   = adj[cur][j].first;
                    int index = adj[cur][j].second;

                    if(componentID[too] == componentID[cur] || graphnew[too] == 1){
                        continue;
                    }

                    adj2[componentID[too]].push_back(componentID[cur]);
                    adj2[componentID[cur]].push_back(componentID[too]);

                    q.push(too);
                    
                }


            }
        }
    }

    

    

    /*queue<int> q;

    q.push(0);

    vector<int> bakicaz(adj2.size(),0);

    bakicaz[0] = 1;
    int ans = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int timer =0;
        bakicaz[cur] = 1;
        for(int i = 0 ; i < adj2[cur].size(); i++){
            //cout<<adj2[cur][i]<<" ";
            if(bakicaz[adj2[cur][i]] == 0){
                timer++;
                
                q.push(adj2[cur][i]);
            }

        }
        //cout<<"\n";
        if(timer == 0){
            ans++;
        }
    }*/

    int ans = 0;
    for(int i = 0 ; i < adj2.size();i++){
        if(adj2[i].size() == 1){
            ans++;
        }
    }
    cout<<(ans+1)/2;

	return 0;
}
