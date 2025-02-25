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




int main()
{
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


    int ans = 0;


    vector<int> visited(n,-1);

    for(int i = 0 ; i < compcount ; i++){
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

                for(int j = 0 ; j < adj2[cur].size() ; j++){

                    if(visited[adj2[cur][j]] == -1){

                        q.push({adj2[cur][j],cost+1});

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

                for(int j = 0 ; j < adj2[cur].size() ; j++){

                    if(visited[adj2[cur][j]] == 1){

                        q.push({adj2[cur][j],cost+1});

                    }
                    
                }
            }

            ans+= max;
            


        }
    }
    int ekle = 0;
    vector<int> lastvisited(compcount,-1);

    for(int i = 0 ; i < compcount; i++){
        if(lastvisited[i] == -1){
            ekle++;

            queue<int> q;

            q.push(i);

            while(!q.empty()){
                int cur = q.front();
                q.pop();
                lastvisited[cur] = 1;
                for(int j = 0 ; j < adj2[cur].size() ; j++){

                    if(lastvisited[adj2[cur][j]] == -1){
                        q.push(adj2[cur][j]);
                    }
                }
                
            }
        }
    }


    cout<<ekle+ans-1<<"\n";
    //cout<<ans;


    


    
    return 0;
}