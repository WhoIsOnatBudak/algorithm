//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

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

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);




    int n,e;

    cin>>n>>e;

    for(int i = 0 ; i < e ; i++){
        int s,x;
        cin>>s>>x;
        adj[x].push_back({s,i});
        adj[s].push_back({x,i});

    }

    find_bridges(n);

    int ans = 0;


    vector<int> visited(n,-1);

    for(int i = 0 ; i < n ; i++){
        if(visited[i] == -1){

            visited[i] = 1;

            queue<pair<int,int>> q;

            q.push({i,0});
            int max = 0;
            int nodemax = 0;
            while(!q.empty()){
                int cur = q.front().first;
                int cost = q.front().second;

                q.pop();

                if(cost > max){
                    nodemax = cur;
                    max = cost;
                }
                visited[cur] =1;

                for(int j = 0 ; j < adj[cur].size() ; j++){

                    if(visited[adj[cur][j].first] == -1){

                        if(is_bridge[adj[cur][j].second] == 1){
                            q.push({adj[cur][j].first,cost+1});
                        }
                        else{
                            q.push({adj[cur][j].first,cost});
                        }
                        

                    }
                    
                }
            }
            

            q.push({nodemax,0});
            max = 0;
            while(!q.empty()){
                int cur = q.front().first;
                int cost = q.front().second;

                q.pop();

                if(cost > max){
                    
                    max = cost;
                }

                visited[cur] = 2;

                for(int j = 0 ; j < adj[cur].size() ; j++){

                    if(visited[adj[cur][j].first] == 1){

                        if(is_bridge[adj[cur][j].second] == 1){
                            q.push({adj[cur][j].first,cost+1});
                        }
                        else{
                            q.push({adj[cur][j].first,cost});
                        }
                        

                    }
                    
                }
            }

            ans+= max;
            


        }
    }
    int ekle = 0;
    vector<int> lastvisited(n,-1);

    for(int i = 0 ; i < n; i++){
        if(lastvisited[i] == -1){
            ekle++;

            queue<int> q;

            q.push(i);

            while(!q.empty()){
                int cur = q.front();
                q.pop();
                lastvisited[cur] = 1;
                for(int j = 0 ; j < adj[cur].size() ; j++){

                    if(lastvisited[adj[cur][j].first] == -1){
                        q.push(adj[cur][j].first);
                    }
                }
                
            }
        }
    }


    cout<<ekle+ans-1<<"\n";

	return 0;
}
